/*
 * Copyright (C) 2015, Jason S. McMullan
 * All right reserved.
 * Author: Jason S. McMullan <jason.mcmullan@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <Adafruit_ST7735.h>

Adafruit_ST7735 gfx = Adafruit_ST7735(10, 8, 11, 13, 9);

void setup()
{
    gfx.initR(INITR_BLACKTAB);
    gfx.fillScreen(ST7735_BLACK);
}

int y;

uint16_t color[] = {
    ST7735_WHITE,
    ST7735_RED,
    ST7735_GREEN,
    ST7735_BLUE,
    ST7735_CYAN,
    ST7735_MAGENTA,
};

void loop()
{
    gfx.drawFastHLine(0, y, gfx.width(), ST7735_BLACK);

    for (int i = 0; i < 6; i++) {
        int val = map(analogRead(i), 0, 1023, 0, gfx.width());
        gfx.drawPixel(val, y, color[i]);
    }

    y = (y + 1) % gfx.height();
    gfx.drawFastHLine(0, y, gfx.width(), ST7735_WHITE);
}

/* vim: set shiftwidth=4 expandtab:  */
