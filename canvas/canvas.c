#include "canvas.h"
#include <string.h>

static const CanvasPalette canvasPalette = {
    .fg = LCD_COLOR_WHITE,
    .bg = LCD_COLOR_BLACK,
    .spCol = LCD_COLOR_ELECTRIC_BLUE,
    .spPeak = LCD_COLOR_WITCH_HAZE,
    .inactive = LCD_COLOR_NERO,
    .active = LCD_COLOR_AQUA,
};

static Canvas canvas = {
    .pal = &canvasPalette,
};

void canvasInit(Canvas **value)
{
    glcdInit(&canvas.glcd);
    *value = &canvas;
}

void canvasClear(void)
{
    glcdShift(0);

    GlcdRect rect = glcdGetRect();

    glcdDrawRect(0, 0, rect.w, rect.h, canvas.pal->bg);

    const int16_t ft = 2;

    if (rect.x >= 2 * ft && rect.y >= 2 * ft) {
        glcdDrawFrame(-ft, -ft, rect.w + 2 * ft, rect.h + 2 * ft, ft, canvas.pal->bg);
        glcdDrawFrame(-2 * ft, -2 * ft, rect.w + 4 * ft, rect.h + 4 * ft, ft, canvas.pal->fg);
    }

    glcdSetFontColor(LCD_COLOR_WHITE);
    glcdSetFontBgColor(canvas.pal->bg);
}

void texteditSet(char *text)
{
    TextEdit *te = &canvas.te;

    strncpy(te->str, text, TE_STR_LEN);
    te->uLen = glcdStrToUStr(te->str, te->uStr);

    // Set active char to edit
    UChar uChar = ' ';
    if (te->uLen) {
        uChar = te->uStr[te->uLen - 1];
    }
    te->sPos = glcdFontSymbolPos(uChar);
    te->lastPos = glcdFontSymbolPos(LETTER_SPACE_CHAR) - 1;
}

void texteditChange(int8_t value)
{
    TextEdit *te = &canvas.te;

    te->sPos += value;

    if (te->sPos < 0)
        te->sPos = 0;
    if (te->sPos > te->lastPos) {
        te->sPos = te->lastPos;
    }
}

void texteditAddChar(void)
{
    TextEdit *te = &canvas.te;

    te->uStr[te->uLen] = glcdFontSymbolCode(te->sPos);
    te->uLen++;
}

void texteditDelChar(void)
{
    TextEdit *te = &canvas.te;

    if (te->uLen > 0) {
        te->uLen--;
    }
}

void texteditApply(void)
{

}
