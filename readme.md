## 环境配置
[参考连接](https://pdos.csail.mit.edu/6.S081/2020/tools.html)
- 实验室设备：阿里云服务器(ubuntu20.04)
环境配置步骤如下:
```
sudo apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu

sudo apt-get remove qemu-system-misc 

sudo apt-get install qemu-system-misc=1:4.2-3ubuntu6
```
如果`riscv64-unknown-elf-gcc --version`配置错误，则安装`sudo apt-get install gcc-riscv64-unknown-elf`

`git clone git://g.csail.mit.edu/xv6-labs-2020`下载工程，`make qemu`构建xv6系统，`ctrl-a x`退出xv6系统