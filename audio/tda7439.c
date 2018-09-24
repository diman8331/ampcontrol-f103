#include "tda7439.h"

#include "../i2c.h"

static const AudioGrid grid_n79_0_1  = {-79,  0, 1.00 * 8};   // -79..0dB with 1dB step
static const AudioGrid grid_n14_14_2 = { -7,  7, 2.00 * 8};   // -14..14dB with 2dB step
static const AudioGrid grid_n15_15_1 = {-15, 15, 1.00 * 8};   // -15..15dB with 1dB step
static const AudioGrid grid_n47_0_1  = {-47,  0, 1.00 * 8};   // -47..0dB with 1dB step
static const AudioGrid grid_0_30_2   = {  0, 15, 2.00 * 8};   // 0..30dB with 2dB step

static AudioProc *aProc;

void tda7439Init(AudioProc *audioProc)
{
    aProc = audioProc;
    aProc->inCnt = TDA7439_IN_CNT;
    aProc->setFlag = tda7439SetMute;
    aProc->setInput = tda7439SetInput;

    aProc->item[AUDIO_PARAM_VOLUME].grid = &grid_n79_0_1;
    aProc->item[AUDIO_PARAM_VOLUME].set = tda7439SetSpeakers;

    aProc->item[AUDIO_PARAM_BASS].grid = &grid_n14_14_2;
    aProc->item[AUDIO_PARAM_BASS].set = tda7439SetBMT;

    aProc->item[AUDIO_PARAM_MIDDLE].grid = &grid_n14_14_2;
    aProc->item[AUDIO_PARAM_MIDDLE].set = tda7439SetBMT;

    aProc->item[AUDIO_PARAM_TREBLE].grid = &grid_n14_14_2;
    aProc->item[AUDIO_PARAM_TREBLE].set = tda7439SetBMT;

    aProc->item[AUDIO_PARAM_PREAMP].grid = &grid_n47_0_1;
    aProc->item[AUDIO_PARAM_PREAMP].set = tda7439SetPreamp;

    aProc->item[AUDIO_PARAM_BALANCE].grid = &grid_n15_15_1;
    aProc->item[AUDIO_PARAM_BALANCE].set = tda7439SetSpeakers;

    aProc->item[AUDIO_PARAM_GAIN].grid = &grid_0_30_2;
    aProc->item[AUDIO_PARAM_GAIN].set = tda7439SetInput;
}

void tda7439SetSpeakers(void)
{
    int8_t spLeft = aProc->item[AUDIO_PARAM_VOLUME].value;
    int8_t spRight = aProc->item[AUDIO_PARAM_VOLUME].value;
    int8_t volMin = aProc->item[AUDIO_PARAM_VOLUME].grid->min;

    if (aProc->item[AUDIO_PARAM_BALANCE].value > 0) {
        spLeft -= aProc->item[AUDIO_PARAM_BALANCE].value;
        if (spLeft < volMin)
            spLeft = volMin;
    } else {
        spRight += aProc->item[AUDIO_PARAM_BALANCE].value;
        if (spRight < volMin)
            spRight = volMin;
    }

    i2cAmpStart(TDA7439_I2C_ADDR);
    i2cAmpWrite(TDA7439_VOLUME_RIGHT | TDA7439_AUTO_INC);
    i2cAmpWrite(-spRight);
    i2cAmpWrite(-spLeft);
    i2cAmpStop();
}

void tda7439SetBMT(void)
{
    int8_t val;

    i2cAmpStart(TDA7439_I2C_ADDR);
    i2cAmpWrite(TDA7439_BASS | TDA7439_AUTO_INC);
    for (AudioParam par = AUDIO_PARAM_BASS; par <= AUDIO_PARAM_TREBLE; par++) {
        val = aProc->item[par].value;
        i2cAmpWrite(val > 0 ? 15 - val : 7 + val);
    }
    i2cAmpStop();
}

void tda7439SetPreamp(void)
{
    i2cAmpStart(TDA7439_I2C_ADDR);
    i2cAmpWrite(TDA7439_PREAMP);
    i2cAmpWrite(-aProc->item[AUDIO_PARAM_PREAMP].value);
    i2cAmpStop();
}

void tda7439SetInput(void)
{
    i2cAmpStart(TDA7439_I2C_ADDR);
    i2cAmpWrite(TDA7439_INPUT_SELECT | TDA7439_AUTO_INC);
    i2cAmpWrite(TDA7439_IN_CNT - 1 - aProc->input);
    i2cAmpWrite(aProc->item[AUDIO_PARAM_GAIN].value);
    i2cAmpStop();
}

void tda7439SetMute(void)
{
    if (aProc->flag & AUDIO_FLAG_MUTE) {
        i2cAmpStart(TDA7439_I2C_ADDR);
        i2cAmpWrite(TDA7439_VOLUME_RIGHT | TDA7439_AUTO_INC);
        i2cAmpWrite(TDA7439_SPEAKER_MUTE);
        i2cAmpWrite(TDA7439_SPEAKER_MUTE);
        i2cAmpStop();
    } else {
        tda7439SetSpeakers();
    }
}
