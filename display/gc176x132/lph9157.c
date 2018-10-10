#include "lph9157.h"

#include "../dispdrv.h"
#include "../../pins.h"
#include "../../functions.h"

#define LPH9157_WIDTH           132
#define LPH9157_HEIGHT          176
#define LPH9157_PIXELS          (LPH9157_WIDTH * LPH9157_HEIGHT)

static GlcdDriver glcd = {
    .clear = lph9157Clear,
    .drawPixel = lph9157DrawPixel,
    .drawRectangle = lph9157DrawRectangle,
    .drawImage = lph9157DrawImage,
};

static inline void lph9157SendCmd(uint8_t cmd) __attribute__((always_inline));
static inline void lph9157SendCmd(uint8_t cmd)
{
    dispdrvWaitOperation();
    CLR(DISP_SPI_DC);

    dispdrvSendData8(cmd);

    dispdrvWaitOperation();
    SET(DISP_SPI_DC);
}

static void lph9157InitSeq(void)
{
    _delay_ms(50);

    CLR(DISP_SPI_CS);

    lph9157SendCmd(0x01);
    lph9157SendCmd(0x11);
    _delay_ms(20);
    lph9157SendCmd(0x3a);
    dispdrvSendData8(0x05);
    _delay_ms(20);
    lph9157SendCmd(0x36);
    dispdrvSendData8(0x40);
    lph9157SendCmd(0x29);

    dispdrvWaitOperation();
    SET(DISP_SPI_CS);
}

void lph9157SetWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
    lph9157SendCmd(0x2a);
    dispdrvSendData8(y);
    dispdrvSendData8(y + h - 1);

    lph9157SendCmd(0x2b);
    dispdrvSendData8(x);
    dispdrvSendData8(x + w - 1);

    lph9157SendCmd(0x2C);
}

void lph9157Init(GlcdDriver **driver)
{
    *driver = &glcd;
    gc176x132Init(*driver);

    SET(DISP_SPI_RST);

    // Init magic
    lph9157InitSeq();
    SET(DISP_SPI_LED);
}

void lph9157Clear(void)
{
    lph9157DrawRectangle(0, 0, glcd.canvas->width, glcd.canvas->height, glcd.canvas->color);
}

void lph9157Sleep(void)
{
    CLR(DISP_SPI_CS);

    lph9157SendCmd(0x10);
    lph9157SendCmd(0x28);

    dispdrvWaitOperation();
    SET(DISP_SPI_CS);
}

void lph9157Wakeup(void)
{
    CLR(DISP_SPI_CS);

    lph9157SendCmd(0x11);
    lph9157SendCmd(0x29);

    dispdrvWaitOperation();
    SET(DISP_SPI_CS);
}

void lph9157DrawPixel(int16_t x, int16_t y, uint16_t color)
{
    CLR(DISP_SPI_CS);

    lph9157SetWindow(x, y, 1, 1);
    dispdrvSendData16(color);

    dispdrvWaitOperation();
    SET(DISP_SPI_CS);
}

void lph9157DrawRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
    CLR(DISP_SPI_CS);

    lph9157SetWindow(x, y, w, h);
    dispdrvSendFill(w * h, color);

    dispdrvWaitOperation();
    SET(DISP_SPI_CS);
}

void lph9157DrawImage(tImage *img)
{
    uint16_t w = img->width;
    uint16_t h = img->height;
    uint16_t x0 = glcd.canvas->x;
    uint16_t y0 = glcd.canvas->y;

    CLR(DISP_SPI_CS);

    lph9157SetWindow(x0, y0, w, h);
    dispdrvSendImage(img, w, h);

    dispdrvWaitOperation();
    SET(DISP_SPI_CS);
}
