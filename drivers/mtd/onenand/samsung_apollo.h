/* linux/drivers/mtd/onenand/samsung_apollo.h
 *
 * Partition Layout for Samsung Galaxy Apollo (i5800/i5801)
 *
 */

static struct mtd_partition s3c_partition_info[] = {
	{
		.name		= "kernel",
		.offset		= (40 * SZ_256K),
		.size		= (30 * SZ_256K),
	},
	{
		.name		= "system",
		.offset		= MTDPART_OFS_APPEND,
		.size		= (880 * SZ_256K),
	},
	{
		.name		= "data",
		.offset		= MTDPART_OFS_APPEND,
		.size		= (810 * SZ_256K),
	},
	{
		.name		= "cache",
		.offset		= MTDPART_OFS_APPEND,
		.size		= (152 * SZ_256K),
	},
};

