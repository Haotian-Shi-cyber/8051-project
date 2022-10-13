led.hex : led.c
	sdcc led.c
	packihx led.ihx > led.hex
	hex2bin led.hex
clean:
	rm -rf *.asm *.lst *.mem *.rst *.lk *.rel *.sym *.ihx *.hex *.map
