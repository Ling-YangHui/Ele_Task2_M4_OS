//
// Created by YangHui on 2021/3/25.
//

#include "UIControl.h"
#include "../FVControl/FVControl.h"
#include "../Driver/HAL_Support/Retarget/retarget.h"
#include "../../Driver/SSD1306/ssd1306.h"
#include "../../Driver/SSD1306/SSD1306CN.h"

/* TODO: 可能还有放大器的幅度调制需要使用这里的方法，请务必预留空间 */
void setNumber()
{
    static char cache[16] = {0};
    SSD1306_GotoXY(8, 0);
    sprintf(cache, "F:%05.2lfMHz", getFrequency() / 100.0);
    SSD1306_Puts(cache, &Font_8x16, SSD1306_COLOR_WHITE);

    SSD1306_GotoXY(8, 16);
    sprintf(cache, "V:%04dmV", getGenerateVoltage());
    SSD1306_Puts(cache, &Font_8x16, SSD1306_COLOR_WHITE);

    SSD1306_GotoXY(8, 32);
    sprintf(cache, "A:%02ddB", getAmplifier());
    SSD1306_Puts(cache, &Font_8x16, SSD1306_COLOR_WHITE);

    SSD1306_UpdateScreen();
}

void setPointer()
{
    uint16_t startX = 8 + 16;
    uint16_t startY = 0 + 16;
    // 清空第一行
    SSD1306_DrawLine(0, startY, 128, startY, SSD1306_COLOR_BLACK);
    // 清空第二行
    SSD1306_DrawLine(0, startY + 16, 128, startY + 16, SSD1306_COLOR_BLACK);
    // 清空第三行
    SSD1306_DrawLine(0, startY + 16 * 2, 128, startY + 16 * 2, SSD1306_COLOR_BLACK);
    uint8_t position = getPosition();
    // 如果是设置小数点前的电压
    if (position < 2)
        startX += position * 8;
        // 如果是设置小数点后的电压
    else if (position < 4)
        startX += (position + 1) * 8;
        // 如果设置放大器幅度
    else if (position < 8)
    {
        startX += (position - 4) * 8;
        startY += 16;
    }
        // 如果设置放大器增益
    else if (position < 10)
    {
        startX += (position - 8) * 8;
        startY += 32;
    }
    SSD1306_DrawLine(startX, startY, startX + 8, startY, SSD1306_COLOR_WHITE);
    SSD1306_UpdateScreen();
}

void setStarter()
{
    SSD1306_Fill(SSD1306_COLOR_BLACK);
    SSD1306_GotoXY(49, 0);
    SSD1306_PutImage(&Communism30x30, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(16, 31);
    SSD1306_PutImage(&U5168, SSD1306_COLOR_WHITE); //全
    SSD1306_PutImage(&U4e16, SSD1306_COLOR_WHITE); //世
    SSD1306_PutImage(&U754c, SSD1306_COLOR_WHITE); //界
    SSD1306_PutImage(&U65e0, SSD1306_COLOR_WHITE); //无
    SSD1306_PutImage(&U4ea7, SSD1306_COLOR_WHITE); //产
    SSD1306_PutImage(&U8005, SSD1306_COLOR_WHITE); //者
    SSD1306_GotoXY(32, 47);
    SSD1306_PutImage(&U8054, SSD1306_COLOR_WHITE); //联
    SSD1306_PutImage(&U5408, SSD1306_COLOR_WHITE); //合
    SSD1306_PutImage(&U8d77, SSD1306_COLOR_WHITE); //起
    SSD1306_PutImage(&U6765, SSD1306_COLOR_WHITE); //来
    SSD1306_UpdateScreen();
}