#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/vmalloc.h>
#include <linux/spi/spi.h>
#include <linux/delay.h>

#include "fbtft.h"

#define DRVNAME		"fb_hx8357hd"
#define WIDTH		480
#define HEIGHT		320
#define TXBUFLEN	(4 * PAGE_SIZE)
#define DEFAULT_GAMMA	"0 0 00 0 0 0 00 0 0 0 0 0 0 0 0\n" \
			"0 0 00 0 0 0 00 0 0 0 0 0 0 0 0 "

static int init_display(struct fbtft_par *par)
{
    fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);

    par->fbtftops.reset(par);

    /* Sleep out
       This command turns off sleep mode.
       In this mode the DC/DC converter is enabled, Internal oscillator
       is started, and panel scanning is started. */
    write_reg(par, 0x11);
    mdelay(150);



    write_reg(par, 0xB9, 0xFF, 0x83, 0x57);
    write_reg(par, 0xB1, 0x00, 0x12, 0x1C, 0x1C, 0xC3, 0x33);
    //write_reg(par,0xB3,0x03,0x00,0x06,0x06);
    write_reg(par, 0xB4, 0x02, 0x40, 0x00, 0x2A, 0x2A, 0x12, 0x4E);
    write_reg(par, 0xB6, 0x38);
    write_reg(par, 0xC0, 0x50, 0x50, 0x01, 0x3C, 0x1E, 0x08);
    write_reg(par, 0xC2, 0x00, 0x12, 0x04);
    write_reg(par, 0xCC, 0x09);
    write_reg(par, 0xE0, 0x0B, 0x11, 0x1E, 0x30, 0x3A, 0x4C, 0x56, 0x5D, 0x3E, 0x39, 0x34, 0x2D, 0x2B, 0x27, 0x25, 0x21, 0x0B, 0x11, 0x1E, 0x30, 0x3A, 0x4C, 0x56, 0x5D, 0x3E, 0x39, 0x34, 0x2D, 0x2B, 0x27, 0x25, 0x21, 0x00, 0x01);
    write_reg(par, 0xEA, 0x03);
    write_reg(par, 0x3A, 0x55);
    write_reg(par, 0x36, 0x61); //+MX
    write_reg(par, 0x29);
    mdelay(10);

    return 0;
}

void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
    fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
                  "%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);

    /* Column address set */
    write_reg(par, 0x2A,
              (xs >> 8) & 0xFF, xs & 0xFF, (xe >> 8) & 0xFF, xe & 0xFF);

    /* Row adress set */
    write_reg(par, 0x2B,
              (ys >> 8) & 0xFF, ys & 0xFF, (ye >> 8) & 0xFF, ye & 0xFF);

    /* Memory write */
    write_reg(par, 0x2C);

}

static int set_var(struct fbtft_par *par)
{
    fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);

    switch (par->info->var.rotate)
    {
    case 0:
        write_reg(par, 0x36, 0x61);//CHECK OK
        break;
    case 270:
        write_reg(par, 0x36,
                  0xc1); //CHECK OK
        break;
    case 180:
        write_reg(par, 0x36, 0xa1); //CHECK OK
        break;
    case 90:
        write_reg(par, 0x36, 0x01);//0X81 + x = c1
        break;
    }
    return 0;

}

/*
  Gamma Curve selection, GC (only GC0 can be customized):
    0 = 2.2, 1 = 1.8, 2 = 2.5, 3 = 1.0
  Gamma string format:
    OP0 OP1 CP0 CP1 CP2 CP3 CP4 MP0 MP1 MP2 MP3 MP4 MP5 CGM0 CGM1
    ON0 ON1 CN0 CN1 CN2 CN3 CN4 MN0 MN1 MN2 MN3 MN4 MN5 XXXX  GC
*/
#define CURVE(num, idx)  curves[num*par->gamma.num_values + idx]
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
    return 0;
}
#undef CURVE


static struct fbtft_display display =
{
    .regwidth = 8,
    .width = WIDTH,
    .height = HEIGHT,
    .txbuflen = TXBUFLEN,
    .gamma_num = 2,
    .gamma_len = 15,
    .gamma = DEFAULT_GAMMA,
    .fbtftops = {
        .init_display = init_display,
        .set_addr_win = set_addr_win,
        .set_var = set_var,
        .set_gamma = set_gamma,
    },
};
FBTFT_REGISTER_DRIVER(DRVNAME, "himax,hx8357hd", &display);

MODULE_ALIAS("spi:" DRVNAME);
MODULE_ALIAS("platform:" DRVNAME);
MODULE_ALIAS("spi:hx8357hd");
MODULE_ALIAS("platform:hx8357hd");

MODULE_DESCRIPTION("FB driver for the HX8357HD LCD Controller");
MODULE_AUTHOR("TaterLi");
MODULE_LICENSE("GPL");
