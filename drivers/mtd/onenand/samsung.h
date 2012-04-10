struct mtd_partition s3c_partition_info[] = {
	{
		.name		= "bootloader",
		.offset		= (0),          /* for bootloader */
		.size			= (512*SZ_1K),
		.mask_flags	= MTD_CAP_NANDFLASH,
	},
	{
		.name		= "param",
		.offset		= MTDPART_OFS_APPEND,
		.size			= (1*SZ_1M),
		//.mask_flags	= MTD_CAP_NANDFLASH,
	},
	{
		.name		= "kernel",
		.offset		= MTDPART_OFS_APPEND,
		.size			=(6*SZ_1M),
	},
//	{
//		.name		= "ramdisk",
//		.offset		= MTDPART_OFS_APPEND,
//		.size		= (3*SZ_1M),
//	},
	{
		.name		= "system",
		.offset		= MTDPART_OFS_APPEND,
		.size			= (100*SZ_1M),
	},
	{
		.name		= "cache",
		.offset		= MTDPART_OFS_APPEND,
		.size			= (80*SZ_1M),
		//.size		= (200*SZ_1M),		// iozone test
	},
	{
		.name		= "userdata",
		.offset		= MTDPART_OFS_APPEND,
		.size			= (50*SZ_1M),
//		.size               = MTDPART_SIZ_FULL,
	}

};

