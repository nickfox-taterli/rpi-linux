<<<<<<< HEAD
# Overlays for the Raspberry Pi platform

dtbo-$(CONFIG_ARCH_BCM2835) += \
	adau1977-adc.dtbo \
	adau7002-simple.dtbo \
	ads1015.dtbo \
	ads1115.dtbo \
	ads7846.dtbo \
	akkordion-iqdacplus.dtbo \
	allo-boss-dac-pcm512x-audio.dtbo \
	allo-piano-dac-pcm512x-audio.dtbo \
	allo-piano-dac-plus-pcm512x-audio.dtbo \
	at86rf233.dtbo \
	audioinjector-addons.dtbo \
	audioinjector-wm8731-audio.dtbo \
	audremap.dtbo \
	bmp085_i2c-sensor.dtbo \
	dht11.dtbo \
	dionaudio-loco.dtbo \
	dionaudio-loco-v2.dtbo \
	dpi18.dtbo \
	dpi24.dtbo \
	dwc-otg.dtbo \
	dwc2.dtbo \
	enc28j60.dtbo \
	enc28j60-spi2.dtbo \
	fe-pi-audio.dtbo \
	googlevoicehat-soundcard.dtbo \
	gpio-ir.dtbo \
	gpio-poweroff.dtbo \
	hifiberry-amp.dtbo \
	hifiberry-dac.dtbo \
	hifiberry-dacplus.dtbo \
	hifiberry-digi.dtbo \
	hifiberry-digi-pro.dtbo \
	hy28a.dtbo \
	hy28b.dtbo \
	i2c-bcm2708.dtbo \
	i2c-gpio.dtbo \
	i2c-mux.dtbo \
	i2c-pwm-pca9685a.dtbo \
	i2c-rtc.dtbo \
	i2c-sensor.dtbo \
	i2c0-bcm2708.dtbo \
	i2c1-bcm2708.dtbo \
	i2s-gpio28-31.dtbo \
	iqaudio-dac.dtbo \
	iqaudio-dacplus.dtbo \
	iqaudio-digi-wm8804-audio.dtbo \
	justboom-dac.dtbo \
	justboom-digi.dtbo \
	lirc-rpi.dtbo \
	mcp23017.dtbo \
	mcp23s17.dtbo \
	mcp2515-can0.dtbo \
	mcp2515-can1.dtbo \
	mcp3008.dtbo \
	midi-uart0.dtbo \
	mmc.dtbo \
	mz61581.dtbo \
	pi3-act-led.dtbo \
	pi3-disable-bt.dtbo \
	pi3-disable-wifi.dtbo \
	pi3-miniuart-bt.dtbo \
	piscreen.dtbo \
	piscreen2r.dtbo \
	pisound.dtbo \
	pitft22.dtbo \
	pitft28-capacitive.dtbo \
	pitft28-resistive.dtbo \
	pitft35-resistive.dtbo \
	pps-gpio.dtbo \
	pwm.dtbo \
	pwm-2chan.dtbo \
	qca7000.dtbo \
	raspidac3.dtbo \
	rpi-backlight.dtbo \
	rpi-cirrus-wm5102.dtbo \
	rpi-dac.dtbo \
	rpi-display.dtbo \
	rpi-ft5406.dtbo \
	rpi-proto.dtbo \
	rpi-sense.dtbo \
	rpi-tv.dtbo \
	rra-digidac1-wm8741-audio.dtbo \
	sc16is750-i2c.dtbo \
	sc16is752-spi1.dtbo \
	sdhost.dtbo \
	sdio.dtbo \
	sdio-1bit.dtbo \
	sdtweak.dtbo \
	smi.dtbo \
	smi-dev.dtbo \
	smi-nand.dtbo \
	spi-gpio35-39.dtbo \
	spi-rtc.dtbo \
	spi0-cs.dtbo \
	spi0-hw-cs.dtbo \
	spi1-1cs.dtbo \
	spi1-2cs.dtbo \
	spi1-3cs.dtbo \
	spi2-1cs.dtbo \
	spi2-2cs.dtbo \
	spi2-3cs.dtbo \
	tinylcd35.dtbo \
	uart1.dtbo \
	vc4-fkms-v3d.dtbo \
	vc4-kms-v3d.dtbo \
	vga666.dtbo \
	w1-gpio.dtbo \
	w1-gpio-pullup.dtbo \
	wittypi.dtbo
=======
ifeq ($(CONFIG_OF),y)

# Overlays for the Raspberry Pi platform

ifeq ($(CONFIG_ARCH_BCM2708),y)
   RPI_DT_OVERLAYS=y
endif
ifeq ($(CONFIG_ARCH_BCM2709),y)
   RPI_DT_OVERLAYS=y
endif
ifeq ($(CONFIG_ARCH_BCM2835),y)
   RPI_DT_OVERLAYS=y
endif

dtbo-$(RPI_DT_OVERLAYS) += adau1977-adc.dtbo
dtbo-$(RPI_DT_OVERLAYS) += ads1015.dtbo
dtbo-$(RPI_DT_OVERLAYS) += ads7846.dtbo
dtbo-$(RPI_DT_OVERLAYS) += akkordion-iqdacplus.dtbo
dtbo-$(RPI_DT_OVERLAYS) += allo-piano-dac-pcm512x-audio.dtbo
dtbo-$(RPI_DT_OVERLAYS) += at86rf233.dtbo
dtbo-$(RPI_DT_OVERLAYS) += audioinjector-wm8731-audio.dtbo
dtbo-$(RPI_DT_OVERLAYS) += audremap.dtbo
dtbo-$(RPI_DT_OVERLAYS) += bmp085_i2c-sensor.dtbo
dtbo-$(RPI_DT_OVERLAYS) += dht11.dtbo
dtbo-$(RPI_DT_OVERLAYS) += dionaudio-loco.dtbo
dtbo-$(RPI_DT_OVERLAYS) += dpi18.dtbo
dtbo-$(RPI_DT_OVERLAYS) += dpi24.dtbo
dtbo-$(RPI_DT_OVERLAYS) += dwc-otg.dtbo
dtbo-$(RPI_DT_OVERLAYS) += dwc2.dtbo
dtbo-$(RPI_DT_OVERLAYS) += enc28j60.dtbo
dtbo-$(RPI_DT_OVERLAYS) += enc28j60-spi2.dtbo
dtbo-$(RPI_DT_OVERLAYS) += gpio-ir.dtbo
dtbo-$(RPI_DT_OVERLAYS) += gpio-poweroff.dtbo
dtbo-$(RPI_DT_OVERLAYS) += hifiberry-amp.dtbo
dtbo-$(RPI_DT_OVERLAYS) += hifiberry-dac.dtbo
dtbo-$(RPI_DT_OVERLAYS) += hifiberry-dacplus.dtbo
dtbo-$(RPI_DT_OVERLAYS) += hifiberry-digi.dtbo
dtbo-$(RPI_DT_OVERLAYS) += hifiberry-digi-pro.dtbo
dtbo-$(RPI_DT_OVERLAYS) += hy28a.dtbo
dtbo-$(RPI_DT_OVERLAYS) += hy28b.dtbo
dtbo-$(RPI_DT_OVERLAYS) += i2c-gpio.dtbo
dtbo-$(RPI_DT_OVERLAYS) += i2c-mux.dtbo
dtbo-$(RPI_DT_OVERLAYS) += i2c-pwm-pca9685a.dtbo
dtbo-$(RPI_DT_OVERLAYS) += i2c-rtc.dtbo
dtbo-$(RPI_DT_OVERLAYS) += i2c-sensor.dtbo
dtbo-$(RPI_DT_OVERLAYS) += i2c0-bcm2708.dtbo
dtbo-$(RPI_DT_OVERLAYS) += i2c1-bcm2708.dtbo
dtbo-$(RPI_DT_OVERLAYS) += i2s-gpio28-31.dtbo
dtbo-$(RPI_DT_OVERLAYS) += i2s-mmap.dtbo
dtbo-$(RPI_DT_OVERLAYS) += iqaudio-dac.dtbo
dtbo-$(RPI_DT_OVERLAYS) += iqaudio-dacplus.dtbo
dtbo-$(RPI_DT_OVERLAYS) += iqaudio-digi-wm8804-audio.dtbo
dtbo-$(RPI_DT_OVERLAYS) += justboom-dac.dtbo
dtbo-$(RPI_DT_OVERLAYS) += justboom-digi.dtbo
dtbo-$(RPI_DT_OVERLAYS) += lirc-rpi.dtbo
dtbo-$(RPI_DT_OVERLAYS) += mcp23017.dtbo
dtbo-$(RPI_DT_OVERLAYS) += mcp23s17.dtbo
dtbo-$(RPI_DT_OVERLAYS) += mcp2515-can0.dtbo
dtbo-$(RPI_DT_OVERLAYS) += mcp2515-can1.dtbo
dtbo-$(RPI_DT_OVERLAYS) += mcp3008.dtbo
dtbo-$(RPI_DT_OVERLAYS) += mmc.dtbo
dtbo-$(RPI_DT_OVERLAYS) += mz61581.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pi3-act-led.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pi3-disable-bt.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pi3-disable-wifi.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pi3-miniuart-bt.dtbo
dtbo-$(RPI_DT_OVERLAYS) += piscreen.dtbo
dtbo-$(RPI_DT_OVERLAYS) += piscreen2r.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pisound.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pitft22.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pitft28-capacitive.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pitft28-resistive.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pitft35-resistive.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pps-gpio.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pwm.dtbo
dtbo-$(RPI_DT_OVERLAYS) += pwm-2chan.dtbo
dtbo-$(RPI_DT_OVERLAYS) += qca7000.dtbo
dtbo-$(RPI_DT_OVERLAYS) += raspidac3.dtbo
dtbo-$(RPI_DT_OVERLAYS) += rpi-backlight.dtbo
dtbo-$(RPI_DT_OVERLAYS) += rpi-dac.dtbo
dtbo-$(RPI_DT_OVERLAYS) += rpi-display.dtbo
dtbo-$(RPI_DT_OVERLAYS) += rpi-ft5406.dtbo
dtbo-$(RPI_DT_OVERLAYS) += rpi-proto.dtbo
dtbo-$(RPI_DT_OVERLAYS) += rpi-sense.dtbo
dtbo-$(RPI_DT_OVERLAYS) += rra-digidac1-wm8741-audio.dtbo
dtbo-$(RPI_DT_OVERLAYS) += sc16is750-i2c.dtbo
dtbo-$(RPI_DT_OVERLAYS) += sc16is752-spi1.dtbo
dtbo-$(RPI_DT_OVERLAYS) += sdhost.dtbo
dtbo-$(RPI_DT_OVERLAYS) += sdio.dtbo
dtbo-$(RPI_DT_OVERLAYS) += sdio-1bit.dtbo
dtbo-$(RPI_DT_OVERLAYS) += sdtweak.dtbo
dtbo-$(RPI_DT_OVERLAYS) += smi.dtbo
dtbo-$(RPI_DT_OVERLAYS) += smi-dev.dtbo
dtbo-$(RPI_DT_OVERLAYS) += smi-nand.dtbo
dtbo-$(RPI_DT_OVERLAYS) += spi-gpio35-39.dtbo
dtbo-$(RPI_DT_OVERLAYS) += spi-rtc.dtbo
dtbo-$(RPI_DT_OVERLAYS) += spi0-cs.dtbo
dtbo-$(RPI_DT_OVERLAYS) += spi0-hw-cs.dtbo
dtbo-$(RPI_DT_OVERLAYS) += spi1-1cs.dtbo
dtbo-$(RPI_DT_OVERLAYS) += spi1-2cs.dtbo
dtbo-$(RPI_DT_OVERLAYS) += spi1-3cs.dtbo
dtbo-$(RPI_DT_OVERLAYS) += spi2-1cs.dtbo
dtbo-$(RPI_DT_OVERLAYS) += spi2-2cs.dtbo
dtbo-$(RPI_DT_OVERLAYS) += spi2-3cs.dtbo
dtbo-$(RPI_DT_OVERLAYS) += tinylcd35.dtbo
dtbo-$(RPI_DT_OVERLAYS) += uart1.dtbo
dtbo-$(RPI_DT_OVERLAYS) += vc4-fkms-v3d.dtbo
dtbo-$(RPI_DT_OVERLAYS) += vc4-kms-v3d.dtbo
dtbo-$(RPI_DT_OVERLAYS) += vga666.dtbo
dtbo-$(RPI_DT_OVERLAYS) += w1-gpio.dtbo
dtbo-$(RPI_DT_OVERLAYS) += w1-gpio-pullup.dtbo
dtbo-$(RPI_DT_OVERLAYS) += wittypi.dtbo
>>>>>>> upstream/rpi-4.4.y

targets += dtbs dtbs_install
targets += $(dtbo-y)

<<<<<<< HEAD
=======
endif

>>>>>>> upstream/rpi-4.4.y
always		:= $(dtbo-y)
clean-files	:= *.dtbo
