#!/system/xbin/busybox sh

RecoveryMode=`dmesg | grep "Kernel command" | grep "bootmode=2"`

if [ $RecoveryMode -ne "" ]; then
	echo "Booting kernel into recovery"
	cat /dev/zero > /dev/graphics/fb0
else
	echo "Booting kernel into Android"
fi

