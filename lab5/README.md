### Working Directory
	~/repos/own_module<br>

### Code Style Check
	~/repos/linux-stable/scripts/checkpatch.pl -f ~/repos/own_module/hello1.c
	~/repos/linux-stable/scripts/checkpatch.pl -f ~/repos/own_module/hello2.c
	~/repos/linux-stable/scripts/checkpatch.pl -f ~/repos/own_module/inc/hello1.h

### Building
	cd ~/repos/own_module;export ARCH=arm; export PATH=/opt/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin:$PATH; export CROSS_COMPILE="ccache arm-linux-gnueabihf-";export KDIR=$HOME/repos/linux-stable;make clean;make;cp ~/repos/own_module/hello1.ko ~/repos/busybox/_install/hello1.ko;cp ~/repos/own_module/hello2.ko ~/repos/busybox/_install/hello2.ko;cd ~/repos/busybox/_install; find . | cpio -o -H newc | gzip > ../rootfs.cpio.gz; cd ..

### Starting on emulator
	qemu-system-arm -kernel _install/boot/zImage -initrd rootfs.cpio.gz \
	-machine virt -nographic -m 512 \
	--append "root=/dev/ram0 rw console=ttyAMA0,115200 mem=512M"

### ARMv7 Commands
	insmod hello2.ko
	insmod hello1.ko
	modinfo hello1.ko
	insmod hello2.ko
	modinfo hello2.ko
	rmmod hello2.ko
	insmod hello2.ko linecount=0
	rmmod hello2.ko
	insmod hello2.ko linecount=1
	rmmod hello2.ko
	insmod hello2.ko linecount=3
	rmmod hello2.ko
	insmod hello2.ko linecount=5
	rmmod hello2.ko
	insmod hello2.ko linecount=7
	rmmod hello2.ko
	insmod hello2.ko linecount=10
	cat ~/sys/module/hello2/parameters/linecount
	rmmod hello2.ko
	insmod hello2.ko linecount=11
	rmmod hello2.ko
	rmmod hello1.ko
	poweroff

