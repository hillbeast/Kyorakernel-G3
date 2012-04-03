#!/bin/sh

echo "Generating initramfs.cpio"
cd initramfs
find . -print0 | cpio --null -ov --format=newc > ../initramfs.cpio
cd ..

if [ -z $1 ]; then
	echo "Kernel will be labelled ($KBUILD_BUILD_VERSION)"
else
	echo "Setting kernel name to ($1)"
	export KBUILD_BUILD_VERSION=$1
fi

echo "Compiling the kernel"
make -j2

echo "Done"
