#ifndef GLCD_H
#define GLCD_H

#include <inttypes.h>

#include "fonts.h"
#include "../rtc.h"

typedef enum {
    GLCD_Landscape_1,
    GLCD_Portrait_1,
    GLCD_Landscape_2,
    GLCD_Portrait_2,
} GlcdOrientation;

typedef struct {
    const char *label;
    int16_t value;
    int16_t min;
    int16_t max;
    uint8_t icon;
} DispParam;

typedef struct {
    const uint8_t *data;
    uint8_t width;
} CharParam;

typedef struct {
    uint16_t width;
    uint16_t height;
    int16_t x;
    int16_t y;
    uint16_t color;

    void (*showTime)(RTC_type *rtc, char *wday);
    void (*showParam)(DispParam *dp);
    void (*showSpectrum)(uint8_t *dataL, uint8_t *dataR);
} DisplayLayout;

typedef struct {
    void (*clear)(void);
    void (*setBrightness)(uint8_t br);
    void (*drawPixel)(int16_t x, int16_t y, uint16_t color);
    void (*drawFontChar)(CharParam *param);

    DisplayLayout *layout;
    Font font;

    uint8_t bus;
} DisplayDriver;

//Colors
#define RGB_TO_565(x)                   (((x >> 8) & 0xF800) | ((x >> 5) & 0x7E0) | ((x >> 3) & 0x1F))
#define LCD_COLOR_BLACK                 RGB_TO_565(0x000000)
#define LCD_COLOR_NAVI                  RGB_TO_565(0x000080)
#define LCD_COLOR_BLUE                  RGB_TO_565(0x0000FF)
#define LCD_COLOR_GREEN                 RGB_TO_565(0x008000)
#define LCD_COLOR_TEAL                  RGB_TO_565(0x008080)
#define LCD_COLOR_DODGER_BLUE           RGB_TO_565(0x0080FF)
#define LCD_COLOR_LIME                  RGB_TO_565(0x00FF00)
#define LCD_COLOR_SPRING_GREEN          RGB_TO_565(0x00FF80)
#define LCD_COLOR_AQUA                  RGB_TO_565(0x00FFFF)
#define LCD_COLOR_NERO                  RGB_TO_565(0x252525)
#define LCD_COLOR_ECLIPSE               RGB_TO_565(0x3F3939)
#define LCD_COLOR_MAROON                RGB_TO_565(0x800000)
#define LCD_COLOR_PURPLE                RGB_TO_565(0x800080)
#define LCD_COLOR_ELECTRIC_INDIGO       RGB_TO_565(0x8000FF)
#define LCD_COLOR_OLIVE                 RGB_TO_565(0x808000)
#define LCD_COLOR_GRAY                  RGB_TO_565(0x808080)
#define LCD_COLOR_LIGHT_SLATE_BLUE      RGB_TO_565(0x8080FF)
#define LCD_COLOR_CHARTREUSE            RGB_TO_565(0x80FF00)
#define LCD_COLOR_LIGHT_GREEN           RGB_TO_565(0x80FF80)
#define LCD_COLOR_ELECTRIC_BLUE         RGB_TO_565(0x80FFFF)
#define LCD_COLOR_RED                   RGB_TO_565(0xFF0000)
#define LCD_COLOR_DEEP_PINK             RGB_TO_565(0xFF0080)
#define LCD_COLOR_MAGENTA               RGB_TO_565(0xFF00FF)
#define LCD_COLOR_DARK_ORANGE           RGB_TO_565(0xFF8000)
#define LCD_COLOR_LIGHT_CORAL           RGB_TO_565(0xFF8080)
#define LCD_COLOR_FUCHSIA_PINK          RGB_TO_565(0xFF80FF)
#define LCD_COLOR_YELLOW                RGB_TO_565(0xFFFF00)
#define LCD_COLOR_WITCH_HAZE            RGB_TO_565(0xFFFF80)
#define LCD_COLOR_WHITE                 RGB_TO_565(0xFFFFFF)

#define GLCD_MIN_BRIGHTNESS             0
#define GLCD_MAX_BRIGHTNESS             32

void glcdInit(DisplayDriver *driver);

void glcdSetBrightness(uint8_t value);
void glcdPWM();

void glcdWriteNum(int16_t number, uint8_t width, uint8_t lead, uint8_t radix);

void glcdLoadFont(const uint8_t *font);
void glcdSetFontColor(uint16_t color);
void glcdSetFontMult(uint8_t mult);

void glcdSetXY(int16_t x, int16_t y);
void glcdSetX(int16_t x);

void glcdDrawFontChar(CharParam *param);
void glcdWriteChar(uint8_t code);
void glcdWriteString(char *string);

#endif // GLCD_H
