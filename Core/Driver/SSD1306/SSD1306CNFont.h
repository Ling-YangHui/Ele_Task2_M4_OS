//
// Created by YangHui on 2021/3/24.
//

#ifndef ELEDESIGN_TASK2_SSD1306CNFONT_H
#define ELEDESIGN_TASK2_SSD1306CNFONT_H

#include "ssd1306.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OtherImage
{
    const uint8_t *content;
    uint8_t height;
    uint8_t width;
} OtherImage;

/* 汉字: 阳 */
extern OtherImage U9633;
/* 汉字: 之 */
extern OtherImage U4e4b;
/* 汉字: 所 */
extern OtherImage U6240;
/* 汉字: 至 */
extern OtherImage U81f3;
/* 汉字: 万 */
extern OtherImage U4e07;
/* 汉字: 象 */
extern OtherImage U8c61;
/* 汉字: 朝 */
extern OtherImage U671d;
/* 汉字: 辉 */
extern OtherImage U8f89;
/* 汉字: 晚 */
extern OtherImage U665a;
/* 汉字: 安 */
extern OtherImage U5b89;
/* 汉字: ， */
extern OtherImage Uff0c;
/* 汉字: 。 */
extern OtherImage U3002;
/* 徽标：共产党徽标40x40 */
extern OtherImage Communism40x40;
/* 徽标：共产党徽标30x30 */
extern OtherImage Communism30x30;
/* 汉字: 全 */
extern OtherImage U5168;
/* 汉字: 世 */
extern OtherImage U4e16;
/* 汉字: 界 */
extern OtherImage U754c;
/* 汉字: 无 */
extern OtherImage U65e0;
/* 汉字: 产 */
extern OtherImage U4ea7;
/* 汉字: 者 */
extern OtherImage U8005;
/* 汉字: 联 */
extern OtherImage U8054;
/* 汉字: 合 */
extern OtherImage U5408;
/* 汉字: 起 */
extern OtherImage U8d77;
/* 汉字: 来 */
extern OtherImage U6765;


#ifdef __cplusplus
}
#endif
#endif //ELEDESIGN_TASK2_SSD1306CNFONT_H
