/*
 * Copyright (C) 2010 Broadcom
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/init.h>
#include <linux/irqchip.h>
#include <linux/of_address.h>
#include <linux/clk/bcm2835.h>
<<<<<<< HEAD
#include <linux/broadcom/vc_cma.h>
=======
>>>>>>> upstream/rpi-4.4.y
#include <asm/system_info.h>

#include <asm/mach/arch.h>
#include <asm/mach/map.h>

<<<<<<< HEAD
#include <linux/dma-mapping.h>
=======
/* Use this hack until a proper solution is agreed upon */
static void __init bcm2835_init_uart1(void)
{
	struct device_node *np;

	np = of_find_compatible_node(NULL, NULL, "brcm,bcm2835-aux-uart");
	if (of_device_is_available(np)) {
		np = of_find_compatible_node(NULL, NULL,
					     "bcrm,bcm2835-aux-enable");
		if (np) {
			void __iomem *base = of_iomap(np, 0);

			if (!base) {
				pr_err("bcm2835: Failed enabling Mini UART\n");
				return;
			}

			writel(1, base);
			pr_info("bcm2835: Mini UART enabled\n");
		}
	}
}
>>>>>>> upstream/rpi-4.4.y

static void __init bcm2835_init(void)
{
	struct device_node *np = of_find_node_by_path("/system");
	u32 val;
	u64 val64;
<<<<<<< HEAD
=======
	int ret;
>>>>>>> upstream/rpi-4.4.y

	vc_cma_early_init();
	bcm2835_init_clocks();

<<<<<<< HEAD
=======
	ret = of_platform_populate(NULL, of_default_bus_match_table, NULL,
				   NULL);
	if (ret) {
		pr_err("of_platform_populate failed: %d\n", ret);
		BUG();
	}

>>>>>>> upstream/rpi-4.4.y
	if (!of_property_read_u32(np, "linux,revision", &val))
		system_rev = val;
	if (!of_property_read_u64(np, "linux,serial", &val64))
		system_serial_low = val64;
<<<<<<< HEAD
}

static void __init bcm2835_init_early(void)
{
	/* dwc_otg needs this for bounce buffers on non-aligned transfers */
	init_dma_coherent_pool_size(SZ_1M);
}

static void __init bcm2835_board_reserve(void)
{
	vc_cma_reserve();
=======

	bcm2835_init_uart1();
>>>>>>> upstream/rpi-4.4.y
}

static const char * const bcm2835_compat[] = {
#ifdef CONFIG_ARCH_MULTI_V6
	"brcm,bcm2835",
#endif
#ifdef CONFIG_ARCH_MULTI_V7
	"brcm,bcm2836",
#endif
	NULL
};

DT_MACHINE_START(BCM2835, "BCM2835")
	.init_machine = bcm2835_init,
	.reserve = bcm2835_board_reserve,
	.init_early = bcm2835_init_early,
	.dt_compat = bcm2835_compat
MACHINE_END
