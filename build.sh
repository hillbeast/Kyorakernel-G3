#!/bin/sh

echo "Generating initramfs.cpio"
cd ..
./initramfs.sh
cd Kernel

if [ -z $1 ]; then
	echo "Kernel will be labelled ($KBUILD_BUILD_VERSION)"
else
	echo "Setting kernel name to ($1)"
	export KBUILD_BUILD_VERSION=$1
fi

echo "Compiling the kernel"
make -j2

echo "Done"
