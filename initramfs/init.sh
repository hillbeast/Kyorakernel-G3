#!/sbin/busybox sh

export PATH=/sbin:/system/sbin:/system/bin:/system/xbin

insmod /lib/modules/fsr.ko
insmod /lib/modules/fsr_stl.ko

mount -t proc proc /proc
mount -t sysfs sys /sys

mknod /dev/null c 1 3
mknod /dev/zero c 1 5
mknod /dev/urandom c 1 9
mknod /dev/tty0 c 4 0

#dmesg > /dev/tty0

/sbin/pre-init.sh > /dev/tty0 2>&1

