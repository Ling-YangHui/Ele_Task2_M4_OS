//
// Created by YangHui on 2021/3/24.
//

#include "SSD1306CN.h"

uint8_t SSD1306_PutImage(OtherImage *image, SSD1306_COLOR_t c)
{
    const uint8_t *ch = image->content;
    extern SSD1306_t SSD1306;
    // 计算出占用的位宽
    uint8_t width_8bit = image->width / 8 + (image->width % 8 != 0);
    if (SSD1306_WIDTH <= (SSD1306.CurrentX + image->width) ||
        SSD1306_HEIGHT <= (SSD1306.CurrentY + image->height))
    {
        /* Error */
        return 0;
    }
    for (uint8_t i = 0;i < image->height;i ++)
    {
        for (uint8_t j = 0;j < width_8bit;j ++)
        {
            uint8_t b = ch[i * width_8bit + j];
            uint8_t k_limit = (j == width_8bit - 1) ? image->width - 8 * j : 8;
            for (uint8_t k = 0;k < k_limit; k ++)
            {
                if ((b << k) & 0x80)
                {
                    SSD1306_DrawPixel(SSD1306.CurrentX + j * 8 + k, (SSD1306.CurrentY + i), (SSD1306_COLOR_t) c);
                }
                else
                {
                    SSD1306_DrawPixel(SSD1306.CurrentX + j * 8 + k, (SSD1306.CurrentY + i), (SSD1306_COLOR_t) !c);
                }
            }
        }
    }
    SSD1306.CurrentX += image->width;
}

uint8_t SSD1306_PutCNStr16x16(const uint8_t *ch, SSD1306_COLOR_t c)
{
    extern uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];
    extern SSD1306_t SSD1306;
    if (SSD1306_WIDTH <= (SSD1306.CurrentX + 16) ||
        SSD1306_HEIGHT <= (SSD1306.CurrentY + 16))
    {
        /* Error */
        return 0;
    }
    for (uint8_t i = 0; i < 16; i++)
    {
        uint8_t b = ch[i * 2];
        for (uint8_t j = 0; j < 8; j++)
        {
            if ((b << j) & 0x80)
            {
                SSD1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR_t) c);
            }
            else
            {
                SSD1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR_t) !c);
            }
        }
        b = ch[i * 2 + 1];
        for (uint8_t j = 0; j < 8; j++)
        {
            if ((b << j) & 0x80)
            {
                SSD1306_DrawPixel(SSD1306.CurrentX + j + 8, (SSD1306.CurrentY + i), (SSD1306_COLOR_t) c);
            }
            else
            {
                SSD1306_DrawPixel(SSD1306.CurrentX + j + 8, (SSD1306.CurrentY + i), (SSD1306_COLOR_t) !c);
            }
        }
    }

    /* Increase pointer */
    SSD1306.CurrentX += 16;

    /* Return character written */
    return ch[0];
}