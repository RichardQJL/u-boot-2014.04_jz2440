/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <garyj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * Configuation settings for the SAMSUNG JZ2440 board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARM920T		/* This is an ARM920T Core */
#define CONFIG_S3C24X0		/* in a SAMSUNG S3C24x0-type SoC */
#define CONFIG_S3C2440		/* specifically a SAMSUNG S3C2440 SoC */
#define CONFIG_JZ2440		/* on a SAMSUNG JZ2440 Board */
#define CONFIG_AUTO_COMPLETE

#define CONFIG_SYS_TEXT_BASE	0x0

#define CONFIG_SYS_ARM_CACHE_WRITETHROUGH

/* input clock of PLL (the JZ2440 has 12MHz input clock) */
#define CONFIG_SYS_CLK_FREQ	12000000

#define CONFIG_CMDLINE_TAG	/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG

/*
 * Hardware drivers
 */
#define CONFIG_DRIVER_DM9000    
#define CONFIG_DM9000_BASE  	0x20000000
#define DM9000_IO               CONFIG_DM9000_BASE
#define DM9000_DATA         	(CONFIG_DM9000_BASE + 4)
/*
 * select serial console configuration
 */
#define CONFIG_S3C24X0_SERIAL
#define CONFIG_SERIAL1		1	/* we use SERIAL 1 on JZ2440 */

/************************************************************
 * USB support (currently only works with D-cache off)
 ************************************************************/
//#define CONFIG_USB_OHCI
//#define CONFIG_USB_OHCI_S3C24XX
//#define CONFIG_USB_KEYBOARD
//#define CONFIG_USB_STORAGE
//#define CONFIG_DOS_PARTITION

/************************************************************
 * RTC
 ************************************************************/
//#define CONFIG_RTC_S3C24X0


#define CONFIG_BAUDRATE		115200

/*
 * BOOTP options
 */
//#define CONFIG_BOOTP_BOOTFILESIZE
//#define CONFIG_BOOTP_BOOTPATH
//#define CONFIG_BOOTP_GATEWAY
//#define CONFIG_BOOTP_HOSTNAME

/*
 * Command line configuration.
 */
#include <config_cmd_default.h>

//#define CONFIG_CMD_BSP
//#define CONFIG_CMD_CACHE
//#define CONFIG_CMD_DATE
//#define CONFIG_CMD_DHCP
//#define CONFIG_CMD_ELF
#define CONFIG_CMD_NAND
#define CONFIG_CMD_PING
//#define CONFIG_CMD_REGINFO
//#define CONFIG_CMD_USB

#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_CMDLINE_EDITING

/* autoboot */
#define CONFIG_BOOTDELAY	3
#define CONFIG_BOOT_RETRY_TIME	-1
#define CONFIG_RESET_TO_RETRY
#define CONFIG_ZERO_BOOTDELAY_CHECK

#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_IPADDR		192.168.0.110
#define CONFIG_SERVERIP		192.168.0.4

#if defined(CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200	/* speed to run kgdb serial port */
#endif

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_PROMPT	"JZ2440 # "
#define CONFIG_SYS_CBSIZE	256
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE	(CONFIG_SYS_CBSIZE + \
				sizeof(CONFIG_SYS_PROMPT)+16)
#define CONFIG_SYS_MAXARGS	16
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE

#define CONFIG_DISPLAY_CPUINFO				/* Display cpu info */

#define CONFIG_SYS_MEMTEST_START	0x30000000	/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		0x33F00000	/* 63 MB in DRAM */

#define CONFIG_SYS_LOAD_ADDR		0x30800000

/* support additional compression methods */
#define CONFIG_BZIP2
#define CONFIG_LZO
#define CONFIG_LZMA

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1          /* we have 1 bank of DRAM */
#define PHYS_SDRAM_1		0x30000000 /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE	0x04000000 /* 64 MB */

#define PHYS_FLASH_1		0x00000000 /* Flash Bank #0 */

#define CONFIG_SYS_FLASH_BASE	PHYS_FLASH_1

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */

#define CONFIG_SYS_FLASH_CFI
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_FLASH_CFI_LEGACY
//#define CONFIG_SYS_FLASH_LEGACY_512Kx16
#define CONFIG_SYS_FLASH_LEGACY_128Kx8
#define CONFIG_FLASH_SHOW_PROGRESS	45

#define CONFIG_SYS_MAX_FLASH_BANKS	1
#define CONFIG_SYS_FLASH_BANKS_LIST     { CONFIG_SYS_FLASH_BASE }
#define CONFIG_SYS_MAX_FLASH_SECT	(128)

#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_OFFSET   0x00040000	/* 256K */
#define CONFIG_ENV_SIZE     0x20000	/* 128K */
#define CONFIG_ENV_RANGE    CONFIG_ENV_SIZE
/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

/*
 * Size of malloc() pool
 * BZIP2 / LZO / LZMA need a lot of RAM
 */
#define CONFIG_SYS_MALLOC_LEN	(4 * 1024 * 1024)

#define CONFIG_SYS_MONITOR_LEN	(448 * 1024)
#define CONFIG_SYS_MONITOR_BASE	CONFIG_SYS_FLASH_BASE

/*
 * NAND configuration
 */
#ifdef CONFIG_CMD_NAND
#define CONFIG_NAND_S3C2440
#define CONFIG_SYS_S3C2440_NAND_HWECC
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		0x4E000000
#endif

/*
 * File system
 */
//#define CONFIG_CMD_FAT
//#define CONFIG_CMD_EXT2
//#define CONFIG_CMD_UBI
//#define CONFIG_CMD_UBIFS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define MTDIDS_DEFAULT              "nand0=jz2440-0"
#define MTDPARTS_DEFAULT            "mtdparts=jz2440-0:256k(u-boot),"   \
									"128k(params)," 	\
									"4m(kernel),"		\
									"-(rootfs)"

#define CONFIG_BOOTARGS "console=ttySAC0,115200 root=/dev/mtdblock3 init=/linuxrc rootfstype=jffs2"
#define CONFIG_BOOTCOMMAND  "nand read 0x30000000 kernel;bootm 0x30000000"

//#define CONFIG_YAFFS2
//#define CONFIG_RBTREE

/* additions for new relocation code, must be added to all boards */
#define CONFIG_SYS_SDRAM_BASE	PHYS_SDRAM_1
#define CONFIG_SYS_INIT_SP_ADDR	(CONFIG_SYS_SDRAM_BASE + 0x1000 - \
				GENERATED_GBL_DATA_SIZE)

#define CONFIG_BOARD_EARLY_INIT_F

#endif /* __CONFIG_H */
