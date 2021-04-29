# 电赛第二次校内测试代码

## 平台和编程依赖

1. 主控芯片：STM32F407VG
2. 操作系统：FreeRTOS (Interface v1.0)
3. 外部驱动程序：
    * AD9910直接波形发生器
    * AD8370放大器
    * SSD1306 OLED显示屏
    
## 项目结构
~~~
CORE
├─Driver //驱动程序库
│  ├─AD8370
│  ├─AD9910
│  ├─HAL_Support // HAL修正支持库和操作系统适配支持库
│  │  └─Retarget
│  └─SSD1306
├─Inc
├─Src
├─Startup
└─User
    ├─FVControl // 电压幅度增益控制
    ├─NVICHandler // 中断控制器
    ├─OSThreadHandler // 操作系统引导
    └─UIControl // UI控制器
~~~

## 开发

[YangHui](https://github.com/Ling-YangHui) AD9910和AD8370芯片驱动程序，操作系统调度

[LingDong](https://github.com/Ling-Dong-YH) 提供操作系统适配支持

[Lutsai](https://github.com/SL-RU) SSD1306驱动库
