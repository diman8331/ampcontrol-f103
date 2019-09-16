#include "amp.h"

#include <stdbool.h>

#include "audio/audio.h"
#include "control.h"
#include "hwlibs.h"
#include "i2c.h"
#include "karadio.h"
#include "pins.h"
#include "swtimers.h"
#include "tuner/tuner.h"

static AmpStatus ampStatus = AMP_STATUS_STBY;
static uint8_t inputStatus = 0x00;
static uint8_t pcf8574Addr = 0x4E;

static void inputDisable(void)
{
    AudioProc *aProc = audioGet();
    uint8_t input = aProc->par.input;

    switch (aProc->par.inType[input]) {
    case IN_TUNER:
        tunerSetPower(false);
        break;
    case IN_KARADIO:
        karadioSetEnabled(false);
        break;
    default:
        break;
    }

    // TODO: Power off current input device
}

static void inputEnable(void)
{
    Tuner *tuner = tunerGet();
    AudioProc *aProc = audioGet();
    uint8_t input = aProc->par.input;

    switch (aProc->par.inType[input]) {
    case IN_TUNER:
        tunerInit();
        tunerSetPower(true);
        tunerSetVolume(tuner->par.volume);
        tunerSetMute(false);
        tunerSetFreq(tuner->par.freq);
        break;
    case IN_KARADIO:
        karadioSetEnabled(true);
        break;
    default:
        break;
    }
}

static void handleInputStatus(void)
{
    i2cBegin(I2C_AMP, pcf8574Addr);
    i2cSend(I2C_AMP, inputStatus);
    i2cTransmit(I2C_AMP);
}

static void inputSetPower(bool value)
{
    AudioProc *aProc = audioGet();
    uint8_t input = aProc->par.input;

    if (value) {
        inputStatus = (uint8_t)(1 << input);
    } else {
        inputStatus = 0x00;
    }

    handleInputStatus();
}

AmpStatus ampGetStatus(void)
{
    return ampStatus;
}

void ampInit(void)
{
    pinsSetMute(true);
    pinsSetStby(true);

    pinsInitAmpI2c();
    inputSetPower(false);    // Power off                                                                                    input device
    pinsDeInitAmpI2c();

    ampStatus = AMP_STATUS_STBY;
    controlReportAmpStatus();
}

void ampExitStby(void)
{
    audioReadSettings();
    tunerReadSettings();

    pinsSetStby(false);     // Power on amplifier

    pinsInitAmpI2c();
    inputSetPower(true);    // Power on input device
    pinsDeInitAmpI2c();

    ampStatus = AMP_STATUS_POWERED;
    swTimSet(SW_TIM_AMP_INIT, 600);
}

void ampEnterStby(void)
{
    swTimSet(SW_TIM_AMP_INIT, SW_TIM_OFF);

    screenSaveSettings();

    audioSetMute(true);
    audioSetPower(false);

    inputDisable();

    ampInit();
}

void ampInitHw(void)
{
    swTimSet(SW_TIM_AMP_INIT, SW_TIM_OFF);

    switch (ampStatus) {
    case AMP_STATUS_POWERED:
        pinsInitAmpI2c();

        audioInit();
        audioSetPower(true);
        inputSetPower(true);

        ampStatus = AMP_STATUS_INPUT_SELECTED;
        swTimSet(SW_TIM_AMP_INIT, 400);
        break;
    case AMP_STATUS_INPUT_SELECTED:
        inputEnable();

        audioSetMute(false);

        ampStatus = AMP_STATUS_ACTIVE;

        swTimSet(SW_TIM_INPUT_POLL, 100);
        controlReportAll();
        break;
    }
}

void ampSetInput(uint8_t value)
{
    swTimSet(SW_TIM_INPUT_POLL, SW_TIM_OFF);

    audioSetMute(true);

    inputDisable();
    inputSetPower(false);
    audioSetInput(value);
    inputSetPower(true);

    ampStatus = AMP_STATUS_INPUT_SELECTED;
    swTimSet(SW_TIM_AMP_INIT, 400);
}