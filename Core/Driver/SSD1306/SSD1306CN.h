//
// Created by YangHui on 2021/3/24.
//

/**
 * @brief SSD1306中文库
 * */

#ifndef ELEDESIGN_TASK2_SSD1306CN_H
#define ELEDESIGN_TASK2_SSD1306CN_H

#ifdef __cplusplus
extern C {
#endif

#include "ssd1306.h"
#include "SSD1306CNFont.h"

uint8_t SSD1306_PutCNStr16x16(const uint8_t *, SSD1306_COLOR_t);
uint8_t SSD1306_PutImage(OtherImage *image, SSD1306_COLOR_t c);

#ifdef __cplusplus
}
#endif

#endif //ELEDESIGN_TASK2_SSD1306CN_H
