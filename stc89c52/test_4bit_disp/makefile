test.hex : test.c
	sdcc test.c
	packihx test.ihx > test.hex
	hex2bin test.hex
clean:
	rm -rf *.asm *.lst *.mem *.rst *.lk *.rel *.sym *.ihx *.hex *.map
