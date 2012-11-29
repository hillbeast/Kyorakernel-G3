#!/bin/sh

#echo "Generating initramfs.cpio"
#cd initramfs
#find . -print0 | cpio --null -ov --format=newc > ../initramfs.cpio
#cd ..

if [ -z $1 ]; then
	echo "Kernel will be labelled ($KBUILD_BUILD_VERSION)"
else
	echo "Setting kernel name to ($1)"
	export KBUILD_BUILD_VERSION=$1
fi

echo "Compiling the kernel"
make -j2 CROSS_COMPILE=/home/hillbeast/CodeSourcery/Sourcery_G++_Lite/bin/arm-none-eabi-

echo "Tarballing the kernel"
cp arch/arm/boot/zImage ./
tar cf $KBUILD_BUILD_VERSION-zImage.tar zImage
rm zImage

echo "Done"
