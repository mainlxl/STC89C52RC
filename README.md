# STC89C52RC

### CLion环境准备
1. 插件商店里安装PlatformlO for CLion插件
1. 安装[platformio](https://docs.platformio.org/en/latest/core/index.html),并[配置环境变量](https://docs.platformio.org/en/latest/core/installation/shell-commands.html)
1. 设置->Build, Execution, Deployment->Cmake->添加STC89C52RC编译类型
![step1.png](images/step1.png)
1. 右击`platformio.ini`选择PlatformIO->Update All</br>
![step2.png](images/step2.png)
1. 添加执行任务
![step3.png](images/step3-1.png)
![step3.png](images/step3-2.png)
1. 执行构建![step4-1.png](images/step4-1.png),编译后产物
![step4-2.png](images/step4-2.png)
1. 上传至单片机
   - windows 使用[stc-isp.exe](stc-isp.exe)或者[stcgal](https://github.com/grigorig/stcgal)
   - mac 使用[stcgal](https://github.com/grigorig/stcgal),并安装驱动
1. stcgal烧录命令使用
   - 查看串口号`ls /dev/tty.wchusbser*`
   - stcgal -P stc89 -p /dev/tty.wchusbserialfd120 .pio/build/STC89C52RC/firmware.hex
   > -P 表示使用的是stc89型号</br>
   > -p /dev/tty.wchusbserialfd120 表示`ls /dev/tty.wchusbser*`查询到的usb串口设备号
****

### 模块化
include 放入公共头文件 部分实现放在core

****

### 注意事项:
1. 取反正确方式为：
   - ！符号是位取反（是“位”），只针对位变量。
   - ~符号是按位取反（是“按位”），针对字节变量
1. `sdcc`与`Keil`区别

| `sdcc`与`Keil`区别          | Mac sdcc                      | Windows Keil c             |
|:-------------------------| :---------------------------- | ---------------------------|
| 头文件                      | 8051.h/8052.h                 | reg51.h/reg52.h             |
| IO端口                     | P2_0                          | P2^0                       |
| IO口定义                    | #define LED P2_0              | sbit LED = P2^0             |
| 中断函数                     | void INT0_ISR() __interrupt 0 | void INT0_ISR() interrupt 0 |

### 参考:
- [Mac版下实现51单片机进行开发的环境搭建](https://blog.csdn.net/weixin_46551628/article/details/123791482)
- [关于PlatformIO平台+Clion编写51单片机程序消除引脚波浪线报错的方法](https://blog.csdn.net/liangling11411/article/details/126270581)
- [51单片机在Ubuntu和MacOS下程序开发和下载](https://cloud.tencent.com/developer/article/1796577?from=15425&areaSource=102001.1&traceId=2JrMuHzqaM0zi1_g-qx1Y)