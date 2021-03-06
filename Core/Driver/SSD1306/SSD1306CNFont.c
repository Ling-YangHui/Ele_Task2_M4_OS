//
// Created by YangHui on 2021/3/24.
//

#include "SSD1306CNFont.h"
#define CNChar OtherImage

/*--  文字:  阳  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U9633Char [] = {
        0x00,0x00,0x7C,0x00,0x45,0xFC,0x49,0x04,0x49,0x04,0x51,0x04,0x49,0x04,0x49,0x04,
        0x45,0xFC,0x45,0x04,0x45,0x04,0x69,0x04,0x51,0x04,0x41,0x04,0x41,0xFC,0x41,0x04};
OtherImage U9633= {
        U9633Char,
        16,
        16
};


/*--  文字:  之  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U4e4bChar [] = {
        0x02,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x7F,0xF8,0x00,0x10,0x00,0x20,0x00,0x40,
        0x00,0x80,0x01,0x00,0x02,0x00,0x04,0x00,0x18,0x00,0x24,0x00,0x43,0xFE,0x00,0x00};
OtherImage U4e4b= {
        U4e4bChar,
        16,
        16
};


/*--  文字:  所  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U6240Char [] = {
        0x02,0x08,0x07,0x1C,0x38,0xE0,0x20,0x80,0x20,0x80,0x3E,0x80,0x22,0xFE,0x22,0x88,
        0x22,0x88,0x3E,0x88,0x20,0x88,0x20,0x88,0x41,0x08,0x41,0x08,0x82,0x08,0x04,0x08};
OtherImage U6240= {
        U6240Char,
        16,
        16
};


/*--  文字:  至  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U81f3Char [] = {
        0x00,0x00,0x7F,0xFC,0x02,0x00,0x04,0x00,0x08,0x20,0x10,0x10,0x3F,0xF8,0x00,0x08,
        0x01,0x00,0x01,0x00,0x3F,0xF8,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0xFE,0x00,0x00};
OtherImage U81f3= {
        U81f3Char,
        16,
        16
};


/*--  文字:  万  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U4e07Char [] = {
        0x00,0x00,0x00,0x00,0xFF,0xFE,0x04,0x00,0x04,0x00,0x04,0x00,0x07,0xF0,0x04,0x10,
        0x04,0x10,0x08,0x10,0x08,0x10,0x10,0x10,0x10,0x10,0x20,0x10,0x40,0xA0,0x80,0x40};
OtherImage U4e07= {
        U4e07Char,
        16,
        16
};


/*--  文字:  象  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U8c61Char [] = {
        0x08,0x00,0x1F,0xE0,0x20,0x20,0x7F,0xF8,0xA1,0x08,0x22,0x08,0x3F,0xF8,0x06,0x00,
        0x19,0x10,0x62,0xA0,0x0C,0xC0,0x71,0xA0,0x06,0x90,0x18,0x88,0xE2,0x86,0x01,0x00};
OtherImage U8c61= {
        U8c61Char,
        16,
        16
};


/*--  文字:  朝  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U671dChar [] = {
        0x08,0x00,0x08,0x3E,0xFF,0xA2,0x08,0x22,0x7F,0x22,0x41,0x3E,0x7F,0x22,0x41,0x22,
        0x7F,0x22,0x49,0x3E,0x08,0x22,0xFF,0xA2,0x08,0x42,0x08,0x42,0x08,0x8A,0x09,0x04};
OtherImage U671d= {
        U671dChar,
        16,
        16
};


/*--  文字:  辉  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U8f89Char [] = {
        0x10,0x00,0x13,0xFE,0x92,0x02,0x54,0x44,0x58,0x40,0x13,0xFC,0xFC,0x80,0x28,0xA0,
        0x29,0x20,0x29,0xFC,0x28,0x20,0x28,0x20,0x2B,0xFE,0x4C,0x20,0x48,0x20,0x80,0x20};
OtherImage U8f89= {
        U8f89Char,
        16,
        16
};


/*--  文字:  晚  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U665aChar [] = {
        0x00,0x80,0x00,0x80,0x79,0xF8,0x4A,0x08,0x4C,0x10,0x4B,0xFC,0x4A,0x44,0x7A,0x44,
        0x4A,0x44,0x4B,0xFC,0x48,0xA0,0x48,0xA0,0x79,0x22,0x49,0x22,0x02,0x1E,0x04,0x00};
OtherImage U665a= {
        U665aChar,
        16,
        16
};


/*--  文字:  安  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U5b89Char [] = {
        0x02,0x00,0x01,0x00,0x3F,0xFC,0x20,0x04,0x42,0x08,0x02,0x00,0x02,0x00,0xFF,0xFE,
        0x04,0x20,0x08,0x20,0x18,0x40,0x06,0x40,0x01,0x80,0x02,0x60,0x0C,0x10,0x70,0x08};
OtherImage U5b89= {
        U5b89Char,
        16,
        16
};

/*--  文字:  ，  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t Uff0cChar [] = {
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x10,0x00,0x20,0x00,0x00,0x00};
OtherImage Uff0c= {
        Uff0cChar,
        16,
        16
};

/*--  文字:  。  --*/
/*--  Fixedsys12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U3002Char [] = {
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x18,0x00,0x24,0x00,0x24,0x00,0x18,0x00,0x00,0x00,0x00,0x00};
OtherImage U3002= {
        U3002Char,
        16,
        16
};

const uint8_t communism40x40Content[] = {
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x14,0x00,0x00,0x00,
        0x00,0x09,0x00,0x00,0x00,0x00,0x07,0xA0,0x00,0x00,0x6E,0x05,0x40,0x00,0x01,0x94,
        0x00,0xE8,0x00,0x02,0xF8,0x00,0x50,0x00,0x00,0xC0,0x00,0x64,0x00,0x0E,0xA0,0x00,
        0x36,0x00,0x08,0xF0,0x00,0x0A,0x00,0x15,0x58,0x00,0x1C,0x00,0x2F,0xDC,0x00,0x07,
        0x00,0x18,0x72,0x00,0x0D,0x80,0x0C,0x0E,0x00,0x0E,0x80,0x00,0x0E,0x80,0x02,0x00,
        0x00,0x05,0xC0,0x0D,0x80,0x00,0x03,0x60,0x02,0x80,0x00,0x00,0xE0,0x05,0x00,0x00,
        0x00,0x70,0x03,0x80,0x00,0x00,0x6C,0x05,0x00,0x00,0x00,0x3C,0x05,0x80,0x00,0x00,
        0x0B,0x0B,0x00,0x10,0x00,0x0E,0x16,0x00,0x08,0x00,0x03,0xA9,0x00,0x10,0x00,0x01,
        0x34,0x00,0x0D,0x00,0x00,0xCC,0x00,0x06,0x40,0x01,0xF0,0x00,0x01,0x20,0x0C,0xA4,
        0x00,0x03,0x4C,0xD5,0x9A,0x00,0x02,0xEB,0x6D,0xDC,0x00,0x03,0x56,0xF6,0x0B,0x00,
        0x02,0x85,0x10,0x03,0x80,0x0F,0xC0,0x00,0x01,0x40,0x15,0x80,0x00,0x00,0xF0,0x1A,
        0x00,0x00,0x00,0x70,0x06,0x00,0x00,0x00,0x20,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
OtherImage Communism40x40 = {
        communism40x40Content,
        40
        ,40
};

const uint8_t communism30x30Content[] = {
        0x00,0x01,0xC0,0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x2C,0x00,0x00,0x00,0x0A,0x00,
        0x03,0xF0,0x0F,0x00,0x07,0xE0,0x03,0x80,0x0F,0xC0,0x03,0xC0,0x1F,0x80,0x01,0xC0,
        0x3F,0xC0,0x01,0xC0,0x7F,0xE0,0x01,0xE0,0x3C,0xF0,0x00,0xE0,0x18,0x7C,0x00,0xE0,
        0x00,0x3E,0x00,0x70,0x00,0x1E,0x00,0xA0,0x00,0x0F,0x81,0xF0,0x00,0x07,0x80,0x70,
        0x00,0x03,0xC1,0xF0,0x00,0x01,0xE0,0xF0,0x00,0x00,0xF1,0xA0,0xC0,0x00,0x7E,0xE0,
        0xE0,0x00,0x3B,0xC0,0x78,0x00,0x0F,0x80,0x3C,0x00,0x0F,0xC0,0x1A,0x00,0x1F,0xC0,
        0x1F,0x80,0x5F,0xC0,0x1F,0xE1,0x7E,0xF8,0x3D,0xFF,0xF8,0x78,0x70,0xFE,0xD0,0x3C,
        0xF0,0x2B,0xC0,0x1E,0xE0,0x00,0x00,0x0C
};
OtherImage Communism30x30 = {
        communism30x30Content,
        30
        ,30
};

/*--  文字:  全  --*/
/*--  Fixedsys12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U5168Char [] = {
        0x01,0x00,0x01,0x00,0x02,0x80,0x04,0x40,0x08,0x20,0x10,0x10,0x2F,0xE8,0xC1,0x06,
        0x01,0x00,0x01,0x00,0x1F,0xF0,0x01,0x00,0x01,0x00,0x01,0x00,0x7F,0xFC,0x00,0x00};
OtherImage U5168= {
        U5168Char,
        16,
        16
};


/*--  文字:  世  --*/
/*--  Fixedsys12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U4e16Char [] = {
        0x02,0x20,0x12,0x20,0x12,0x20,0x12,0x20,0x12,0x20,0xFF,0xFE,0x12,0x20,0x12,0x20,
        0x12,0x20,0x12,0x20,0x13,0xE0,0x10,0x00,0x10,0x00,0x10,0x00,0x1F,0xFC,0x00,0x00};
OtherImage U4e16= {
        U4e16Char,
        16,
        16
};


/*--  文字:  界  --*/
/*--  Fixedsys12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U754cChar [] = {
        0x00,0x00,0x1F,0xF0,0x11,0x10,0x11,0x10,0x1F,0xF0,0x11,0x10,0x11,0x10,0x1F,0xF0,
        0x02,0x80,0x0C,0x60,0x34,0x58,0xC4,0x46,0x04,0x40,0x08,0x40,0x08,0x40,0x10,0x40};
OtherImage U754c= {
        U754cChar,
        16,
        16
};


/*--  文字:  无  --*/
/*--  Fixedsys12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U65e0Char [] = {
        0x00,0x00,0x3F,0xF0,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x7F,0xFC,0x04,0x80,
        0x04,0x80,0x04,0x80,0x08,0x80,0x08,0x80,0x10,0x84,0x20,0x84,0x40,0x7C,0x80,0x00};
OtherImage U65e0= {
        U65e0Char,
        16,
        16
};


/*--  文字:  产  --*/
/*--  Fixedsys12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U4ea7Char [] = {
        0x02,0x00,0x01,0x00,0x7F,0xFC,0x00,0x00,0x08,0x20,0x04,0x20,0x04,0x40,0x3F,0xFE,
        0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x40,0x00,0x40,0x00,0x80,0x00};
OtherImage U4ea7= {
        U4ea7Char,
        16,
        16
};


/*--  文字:  者  --*/
/*--  Fixedsys12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U8005Char [] = {
        0x02,0x00,0x02,0x08,0x3F,0xD0,0x02,0x20,0x02,0x40,0xFF,0xFE,0x01,0x00,0x02,0x00,
        0x0F,0xF0,0x18,0x10,0x28,0x10,0x4F,0xF0,0x88,0x10,0x08,0x10,0x0F,0xF0,0x08,0x10};
OtherImage U8005= {
        U8005Char,
        16,
        16
};


/*--  文字:  联  --*/
/*--  Fixedsys12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U8054Char [] = {
        0x00,0x88,0xFC,0x48,0x48,0x50,0x48,0x00,0x79,0xFC,0x48,0x20,0x48,0x20,0x78,0x20,
        0x4B,0xFE,0x48,0x20,0x4C,0x50,0x78,0x50,0xC8,0x88,0x08,0x88,0x09,0x04,0x0A,0x02};
OtherImage U8054= {
        U8054Char,
        16,
        16
};


/*--  文字:  合  --*/
/*--  Fixedsys12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U5408Char [] = {
        0x01,0x00,0x01,0x00,0x02,0x80,0x04,0x40,0x08,0x20,0x30,0x18,0xCF,0xE6,0x00,0x00,
        0x00,0x00,0x1F,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10};
OtherImage U5408= {
        U5408Char,
        16,
        16
};


/*--  文字:  起  --*/
/*--  Fixedsys12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U8d77Char [] = {
        0x08,0x00,0x08,0x00,0x08,0xF8,0x7E,0x08,0x08,0x08,0x08,0x08,0xFE,0xF8,0x08,0x88,
        0x28,0x80,0x28,0x80,0x2E,0x84,0x28,0x84,0x28,0x7C,0x58,0x00,0x4F,0xFE,0x80,0x00};
OtherImage U8d77= {
        U8d77Char,
        16,
        16
};


/*--  文字:  来  --*/
/*--  Fixedsys12;  此字体下对应的点阵为：宽x高=16x16   --*/
const uint8_t U6765Char [] = {
        0x01,0x00,0x01,0x00,0x01,0x00,0x7F,0xFC,0x01,0x00,0x11,0x10,0x09,0x10,0x09,0x20,
        0xFF,0xFE,0x03,0x80,0x05,0x40,0x09,0x20,0x31,0x18,0xC1,0x06,0x01,0x00,0x01,0x00};
OtherImage U6765= {
        U6765Char,
        16,
        16
};