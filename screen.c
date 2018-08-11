#include "screen.h"

#include "display/icons.h"
#include "actions.h"
#include "fft.h"
#include "spectrum.h"

#if defined (_KS0108B)
#include "display/ks0108.h"
#elif defined (_ILI9320)
#include "display/ili9320.h"
#else
#error "Unsupported display driver"
#endif

static DisplayDriver *disp;
static Screen screen = SCREEN_STANDBY;

static uint8_t spLeft[FFT_SIZE / 2];
static uint8_t spRight[FFT_SIZE / 2];

// TODO: Read from backup memory
static int8_t brStby = 1;
static int8_t brWork = 32;

typedef enum {
    LABEL_SUNDAY,
    LABEL_MONDAY,
    LABEL_TUESDAY,
    LABEL_WEDNESDAY,
    LABEL_THURSDAY,
    LABEL_FRIDAY,
    LABEL_SATURDAY,

    LABEL_BRIGNTNESS,

    LABEL_END
} TxtLabel;

const char *txtLabels[LABEL_END] = {
    [LABEL_SUNDAY]          = "  SUNDAY  ",
    [LABEL_MONDAY]          = "  MONDAY  ",
    [LABEL_TUESDAY]         = " TUESDAY  ",
    [LABEL_WEDNESDAY]       = "WEDNESDAY ",
    [LABEL_THURSDAY]        = " THURSDAY ",
    [LABEL_FRIDAY]          = "  FRIDAY  ",
    [LABEL_SATURDAY]        = " SATURDAY ",

    [LABEL_BRIGNTNESS]      = "Brightness",
};

void screenInit(void)
{
#if defined (_KS0108B)
    ks0108Init(&disp);
#elif defined (_ILI9320)
    ili9320Init(&disp);
#endif
    screenClear();
    if (disp->setBrightness) {
        disp->setBrightness(brStby);
    }
}

void screenClear(void)
{
    if (disp->clear) {
        disp->clear();
    }
}

uint8_t screenReadBus(void)
{
    return disp->bus;
}

void screenSet(Screen value)
{
    screen = value;
}

Screen screenGet()
{
    return screen;
}

int8_t screenGetBrightness(uint8_t mode)
{
    if (mode == AMODE_BRIGHTNESS_WORK)
        return brWork;
    else
        return brStby;
}

void screenSetBrightness(uint8_t mode, int8_t value)
{
    if (mode == AMODE_BRIGHTNESS_WORK)
        brWork = value;
    else
        brStby = value;

    if (disp->setBrightness) {
        disp->setBrightness(value);
    }
}

void screenChangeBrighness(uint8_t mode, int8_t diff)
{
    int8_t br = screenGetBrightness(mode);

    br += diff;

    if (br > GLCD_MAX_BRIGHTNESS)
        br = GLCD_MAX_BRIGHTNESS;
    if (br < GLCD_MIN_BRIGHTNESS)
        br = GLCD_MIN_BRIGHTNESS;

    screenSetBrightness(mode, br);
}

void screenTime(RtcMode etm)
{
    RTC_type rtc;
    rtc.etm = etm;

    rtcGetTime(&rtc);

    if (disp->layout->showTime) {
        disp->layout->showTime(&rtc, (char *)txtLabels[LABEL_SUNDAY + rtc.wday]);
    }
}

void screenSpectrum(uint8_t speed)
{
    spGetADC(spLeft, spRight, speed);

    if (disp->layout->showSpectrum) {
        disp->layout->showSpectrum(spLeft, spRight);
    }
}

void screenBrightness()
{
    DispParam dp;

    dp.label = txtLabels[LABEL_BRIGNTNESS];
    dp.value = screenGetBrightness(AMODE_BRIGHTNESS_WORK);
    dp.min = GLCD_MIN_BRIGHTNESS;
    dp.max = GLCD_MAX_BRIGHTNESS;
    dp.icon = ICON24_BRIGHTNESS;

    if (disp->layout->showParam) {
        disp->layout->showParam(&dp);
    }
}
