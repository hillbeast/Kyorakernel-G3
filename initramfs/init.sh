#!/sbin/busybox sh

export PATH=/sbin:/system/sbin:/system/bin:/system/xbin

/sbin/pre-init.sh > /res/pre-init.log 2>&1

