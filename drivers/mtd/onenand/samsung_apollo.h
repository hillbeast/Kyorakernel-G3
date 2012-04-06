/* linux/drivers/mtd/onenand/samsung_apollo.h
 *
 * Partition Layout for Samsung Galaxy 3 (WiP - UNTESTED)
 *
 */

struct mtd_partition s3c_partition_info[] = {

/*This is partition layout from the oneNAND it SHOULD match the pitfile on the second page of the NAND.
   It will work if it doesn't but beware to write below the adress 0x01200000 there are the bootloaders.
   Currently we won't map them, but we should keep that in mind for later things like flashing bootloader
   from Linux. There is a partition 'efs' starting @ 0x00080000 40 256K pages long, it contains data for
   the modem like IMSI we don't touch it for now, but we need the data from it, we create a partition
   for that and copy the data from it. For this you need a image from it and mount it as vfat or copy
   it on a kernel with rfs support on the phone.
   
   Partitions on the lower NAND adresses (as on aries):
   
   0x00000000 - 0x0003FFFF = first stage bootloader
   0x00040000 - 0x0007FFFF = PIT for second stage bootloader
   0x00080000 - 0x00A7FFFF = EFS: IMSI and NVRAM for the modem
   0x00A80000 - 0x00BBFFFF = second stage bootloader
   0x00BC0000 - 0x00CFFFFF = backup of the second stage bootloader (should be loaded if the other fails, unconfirmed!)
   0x00D00000 - 0x011FFFFF = PARAM.lfs config the bootloader
   ^^ As on the aries & p1
   
   #########################################################################################
   #########################################################################################
   ###### NEVER TOUCH THE FIRST 2 256k PAGES! THEY CONTAIN THE FIRST STAGE BOOTLOADER ######
   #########################################################################################
   #########################################################################################
                                                                   
   The below layout is based on output from the serial port, very much likely to change */ 

	{
		.name		= "kernel",
		.offset		= (40*SZ_256K),
		.size		= (30*SZ_256K),
	},
	{
		.name		= "system",
		.offset		= (70*SZ_256K),
		.size		= (880*SZ_256K),
	},
	{
		.name		= "data",
		.offset		= (950*SZ_256K),
		.size		= (810*SZ_256K), // might steal some space from system later
	},
	{
		.name		= "cache",
		.offset		= (1760*SZ_256K),
		.size		= (152*SZ_256K), // *mismatch* 152 should be 150
	},
	{
		.name		= "efs",
		.offset		= (1912*SZ_256K),
		.size		= (28*SZ_256K), // might be nice to give it a bit more space from cache
	},
	{
		.name		= "radio",
		.offset		= (1940*SZ_256K),
		.size		= (64*SZ_256K),
	},
	{	/* The reservoir area is used by Samsung's Block Management Layer (BML)
		to map good blocks from this reservoir to bad blocks in user
		partitions. A special tool (bml_over_mtd) is needed to write
		artition images using bad block mapping.
		Currently, this is required for flashing the "boot" partition,
		as Samsung's stock bootloader expects BML partitions. */
		.name		= "reservoir",
		.offset		= (2004*SZ_256K),
		.size		= (44*SZ_256K),
	},

};
