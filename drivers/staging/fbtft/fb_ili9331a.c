#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/delay.h>

#include "fbtft.h"

#define DRVNAME		"fb_ili9331a"
#define WIDTH		240
#define HEIGHT		320
#define BPP		16
#define FPS		20
#define DEFAULT_GAMMA	"0F 00 7 2 0 0 6 5 4 1\n" \
			"04 16 2 7 6 3 2 1 7 7"


static unsigned bt = 6; /* VGL=Vci*4 , VGH=Vci*4 */
module_param(bt, uint, 0);
MODULE_PARM_DESC(bt, "Sets the factor used in the step-up circuits");

static unsigned vc = 0b011; /* Vci1=Vci*0.80 */
module_param(vc, uint, 0);
MODULE_PARM_DESC(vc,
                 "Sets the ratio factor of Vci to generate the reference voltages Vci1");

static unsigned vrh = 0b1101; /* VREG1OUT=Vci*1.85 */
module_param(vrh, uint, 0);
MODULE_PARM_DESC(vrh,
                 "Set the amplifying rate (1.6 ~ 1.9) of Vci applied to output the VREG1OUT");

static unsigned vdv = 0b10010; /* VCOMH amplitude=VREG1OUT*0.98 */
module_param(vdv, uint, 0);
MODULE_PARM_DESC(vdv,
                 "Select the factor of VREG1OUT to set the amplitude of Vcom");

static unsigned vcm = 0b001010; /* VCOMH=VREG1OUT*0.735 */
module_param(vcm, uint, 0);
MODULE_PARM_DESC(vcm, "Set the internal VcomH voltage");


/*
Verify that this configuration is within the Voltage limits

Display module configuration: Vcc = IOVcc = Vci = 3.3V

 Voltages
----------
Vci                                =   3.3
Vci1           =  Vci * 0.80       =   2.64
DDVDH          =  Vci1 * 2         =   5.28
VCL            = -Vci1             =  -2.64
VREG1OUT       =  Vci * 1.85       =   4.88
VCOMH          =  VREG1OUT * 0.735 =   3.59
VCOM amplitude =  VREG1OUT * 0.98  =   4.79
VGH            =  Vci * 4          =  13.2
VGL            = -Vci * 4          = -13.2

 Limits
--------
Power supplies
1.65 < IOVcc < 3.30   =>  1.65 < 3.3 < 3.30
2.40 < Vcc   < 3.30   =>  2.40 < 3.3 < 3.30
2.50 < Vci   < 3.30   =>  2.50 < 3.3 < 3.30

Source/VCOM power supply voltage
 4.50 < DDVDH < 6.0   =>  4.50 <  5.28 <  6.0
-3.0  < VCL   < -2.0  =>  -3.0 < -2.64 < -2.0
VCI - VCL < 6.0       =>  5.94 < 6.0

Gate driver output voltage
 10  < VGH   < 20     =>   10 <  13.2  < 20
-15  < VGL   < -5     =>  -15 < -13.2  < -5
VGH - VGL < 32        =>   26.4 < 32

VCOM driver output voltage
VCOMH - VCOML < 6.0   =>  4.79 < 6.0
*/

static int init_display(struct fbtft_par *par)
{
    fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);

    par->fbtftops.reset(par);

    if (par->gpio.cs != -1)
        gpio_set_value(par->gpio.cs, 0);  /* Activate chip */

    write_reg(par, 0x00EC, 0x108F); // internal timeing
    write_reg(par, 0x00EF, 0x1234); // ADD
    //write_reg(par,0x00e7,0x0010);
    //write_reg(par,0x0000,0x0001);//开启内部时钟
    write_reg(par, 0x0001, 0x0100);
    write_reg(par, 0x0002, 0x0700); //电源开启
    write_reg(par, 0x0003, 0x1038 ); 	//65K  RGB
    //DRIVE TABLE(寄存器 03H)
    //BIT3=AM BIT4:5=ID0:1
    //AM ID0 ID1   FUNCATION
    // 0  0   0	   R->L D->U
    // 1  0   0	   D->U	R->L
    // 0  1   0	   L->R D->U
    // 1  1   0    D->U	L->R
    // 0  0   1	   R->L U->D
    // 1  0   1    U->D	R->L
    // 0  1   1    L->R U->D 正常就用这个.
    // 1  1   1	   U->D	L->R
    //write_reg(par,0x0003,(1<<12)|(3<<4)|(1<<3));//65K
    write_reg(par, 0x0004, 0x0000);
    write_reg(par, 0x0008, 0x0202);
    write_reg(par, 0x0009, 0x0000);
    write_reg(par, 0x000a, 0x0000); //display setting
    write_reg(par, 0x000c, 0x0001); //display setting
    write_reg(par, 0x000d, 0x0000); //0f3c
    write_reg(par, 0x000f, 0x0000);
    //电源配置
    write_reg(par, 0x0010, 0x0000);
    write_reg(par, 0x0011, 0x0007);
    write_reg(par, 0x0012, 0x0000);
    write_reg(par, 0x0013, 0x0000);
    write_reg(par, 0x0007, 0x0001);
    //delay_ms(50);
    write_reg(par, 0x0010, 0x1490);
    write_reg(par, 0x0011, 0x0227);
    //delay_ms(50);
    write_reg(par, 0x0012, 0x008A);
    //delay_ms(50);
    write_reg(par, 0x0013, 0x1a00);
    write_reg(par, 0x0029, 0x0006);
    write_reg(par, 0x002b, 0x000d);
    //delay_ms(50);
    write_reg(par, 0x0020, 0x0000);
    write_reg(par, 0x0021, 0x0000);
    //delay_ms(50);
    //伽马校正
    write_reg(par, 0x0030, 0x0000);
    write_reg(par, 0x0031, 0x0604);
    write_reg(par, 0x0032, 0x0305);
    write_reg(par, 0x0035, 0x0000);
    write_reg(par, 0x0036, 0x0C09);
    write_reg(par, 0x0037, 0x0204);
    write_reg(par, 0x0038, 0x0301);
    write_reg(par, 0x0039, 0x0707);
    write_reg(par, 0x003c, 0x0000);
    write_reg(par, 0x003d, 0x0a0a);
    //delay_ms(50);
    write_reg(par, 0x0050, 0x0000); //水平GRAM起始位置
    write_reg(par, 0x0051, 0x00ef); //水平GRAM终止位置
    write_reg(par, 0x0052, 0x0000); //垂直GRAM起始位置
    write_reg(par, 0x0053, 0x013f); //垂直GRAM终止位置

    write_reg(par, 0x0060, 0xA700);
    write_reg(par, 0x0061, 0x0001);
    write_reg(par, 0x006a, 0x0000);
    write_reg(par, 0x0080, 0x0000);
    write_reg(par, 0x0081, 0x0000);
    write_reg(par, 0x0082, 0x0000);
    write_reg(par, 0x0083, 0x0000);
    write_reg(par, 0x0084, 0x0000);
    write_reg(par, 0x0085, 0x0000);

    write_reg(par, 0x0090, 0x0010);
    write_reg(par, 0x0092, 0x0600);
    //开启显示设置
    write_reg(par, 0x0007, 0x0133);

    return 0;
}

static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
    fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
                  "%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);

    write_reg(par, 0x0020, ys);
    write_reg(par, 0x0021, HEIGHT - xs);
    write_reg(par, 0x0022); /* Write Data to GRAM */

}

static int set_var(struct fbtft_par *par)
{
    fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);

    write_reg(par, 0x03, 0x1038 | (par->bgr << 12));
    return 0;
}

/*
  Gamma string format:
    VRP0 VRP1 RP0 RP1 KP0 KP1 KP2 KP3 KP4 KP5
    VRN0 VRN1 RN0 RN1 KN0 KN1 KN2 KN3 KN4 KN5
*/
#define CURVE(num, idx)  curves[num*par->gamma.num_values + idx]
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{

    return 0;
}
#undef CURVE


static struct fbtft_display display =
{
    .regwidth = 16,
    .width = WIDTH,
    .height = HEIGHT,
    .bpp = BPP,
    .fps = FPS,
    .gamma_num = 2,
    .gamma_len = 10,
    .gamma = DEFAULT_GAMMA,
    .fbtftops = {
        .init_display = init_display,
        .set_addr_win = set_addr_win,
        .set_var = set_var,
        .set_gamma = set_gamma,
    },
};
FBTFT_REGISTER_DRIVER(DRVNAME, "ilitek,ili9331a", &display);

MODULE_ALIAS("spi:" DRVNAME);
MODULE_ALIAS("platform:" DRVNAME);
MODULE_ALIAS("spi:ili9331a");
MODULE_ALIAS("platform:ili9331a");

MODULE_DESCRIPTION("FB driver for the ILI9331 LCD Controller");
MODULE_AUTHOR("TaterLi");
MODULE_LICENSE("GPL");
