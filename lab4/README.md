================ LINUX OUTPUT ================ <br>

andrii@ubuntu:~/repos/busybox$ qemu-system-arm -kernel _install/boot/zImage -initrd rootfs.cpio.gz -machine virt -nographic -m 512 --append "root=/dev/ram0 rw console=ttyAMA0,115200 mem=512M" <br>
[    0.000000] Booting Linux on physical CPU 0x0 <br>
[    0.000000] Linux version 4.19.220 (andrii@ubuntu) (gcc version 8.3.0 (GNU Toolchain for the A-profile Architecture 8.3-2019.03 (arm-rel-8.36))) #1 SMP Wed Dec 8 09:31:35 PST 2021 <br>
[    0.000000] CPU: ARMv7 Processor [412fc0f1] revision 1 (ARMv7), cr=10c5387d <br>
[    0.000000] CPU: div instructions available: patching division code <br>
[    0.000000] CPU: PIPT / VIPT nonaliasing data cache, PIPT instruction cache <br>
[    0.000000] OF: fdt: Machine model: linux,dummy-virt <br>
[    0.000000] Memory policy: Data cache writealloc <br>
[    0.000000] efi: Getting EFI parameters from FDT: <br>
[    0.000000] efi: UEFI not found. <br>
[    0.000000] cma: Reserved 64 MiB at 0x5c000000 <br>
[    0.000000] psci: probing for conduit method from DT. <br>
[    0.000000] psci: PSCIv0.2 detected in firmware. <br>
[    0.000000] psci: Using standard PSCI v0.2 function IDs <br>
[    0.000000] psci: Trusted OS migration not required <br>
[    0.000000] random: get_random_bytes called from start_kernel+0x9c/0x47c with crng_init=0 <br>
[    0.000000] percpu: Embedded 16 pages/cpu s36620 r8192 d20724 u65536 <br>
[    0.000000] Built 1 zonelists, mobility grouping on.  Total pages: 130048 <br>
[    0.000000] Kernel command line: root=/dev/ram0 rw console=ttyAMA0,115200 mem=512M <br>
[    0.000000] Dentry cache hash table entries: 65536 (order: 6, 262144 bytes) <br>
[    0.000000] Inode-cache hash table entries: 32768 (order: 5, 131072 bytes) <br>
[    0.000000] Memory: 407376K/524288K available (12288K kernel code, 1619K rwdata, 4784K rodata, 2048K init, 393K bss, 51376K reserved, 65536K cma-reserved, 0K highmem) <br>

================ ARM OUTPUT ================ <br>

Please press Enter to activate this console. <br>
/ # uname -a <br>
Linux (none) 4.19.220 #1 SMP Wed Dec 8 09:31:35 PST 2021 armv7l GNU/Linux <br>
/ # ls -l <br>
total 0 <br>
drwxrwxr-x    2 1000     1000             0 Dec  8 18:25 bin <br>
drwxrwxr-x    2 1000     1000             0 Dec  8 18:32 boot <br>
drwxrwxr-x    3 1000     1000             0 Dec  9 00:12 dev <br>
drwxrwxr-x    3 1000     1000             0 Dec  8 18:46 etc <br>
lrwxrwxrwx    1 1000     1000            11 Dec  8 18:30 init -> bin/busybox <br>
drwxrwxr-x    3 1000     1000             0 Dec  8 18:37 lib <br>
lrwxrwxrwx    1 1000     1000            11 Dec  8 18:25 linuxrc -> bin/busybox <br>
dr-xr-xr-x   90 root     root             0 Jan  1  1970 proc <br>
drwxrwxr-x    2 1000     1000             0 Dec  8 18:25 root <br>
drwxrwxr-x    2 1000     1000             0 Dec  8 18:25 sbin <br>
dr-xr-xr-x   12 root     root             0 Dec  9 00:12 sys <br>
drwxrwxr-x    2 1000     1000             0 Dec  8 18:25 tmp <br>
drwxrwxr-x    4 1000     1000             0 Dec  8 18:25 usr <br>
/ # dmesg | grep init <br>
[    0.000000] random: get_random_bytes called from start_kernel+0x9c/0x47c with crng_init=0 <br>
[    0.000000] Memory: 407376K/524288K available (12288K kernel code, 1619K rwdata, 4784K rodata, 2048K init, 393K bss, 51376K reserved, 65536K cma-reserved, 0K highmem) <br>
[    0.000000]       .init : 0x(ptrval) - 0x(ptrval)   (2048 kB) <br>
[    0.068118] devtmpfs: initialized <br>
[    0.095454] pinctrl core: initialized pinctrl subsystem <br>
[    0.297055] SCSI subsystem initialized <br>
[    0.608931] Trying to unpack rootfs image as initramfs... <br>
[    3.305866] Freeing initrd memory: 25104K <br>
[    3.581176] SuperH (H)SCI(F) driver initialized <br>
[    3.582677] msm_serial: driver initialized <br>
[    3.583511] STMicroelectronics ASC driver initialized <br>
[    3.585084] STM32 USART driver initialized <br>
[    3.889550] Run /init as init process <br>
/ # busybox --help | head -15 <br>
BusyBox v1.34.1 (2021-12-08 10:23:05 PST) multi-call binary. <br>
BusyBox is copyrighted by many authors between 1998-2015. <br>
Licensed under GPLv2. See source distribution for detailed <br>
copyright notices. <br>

Usage: busybox [function [arguments]...] <br>
   or: busybox --list[-full] <br>
   or: busybox --show SCRIPT <br>
   or: busybox --install [-s] [DIR] <br>
   or: function [arguments]... <br>
   
	BusyBox is a multi-call binary that combines many common Unix
	utilities into a single executable.  Most people will create a
	link to busybox for each function they wish to use and BusyBox
	will act like whatever it was invoked as.
/ # 
