main.hex : main.c
	sdcc -c display.c
	sdcc -c alarm.c
	sdcc -c interrupt.c
	sdcc -c temp_sensor.c
	sdcc -c timer.c
	sdcc -c global.c
	sdcc main.c display.rel alarm.rel interrupt.rel temp_sensor.rel timer.rel global.rel
	packihx main.ihx > main.hex
	hex2bin main.hex
clean:
	rm -rf *.asm *.lst *.mem *.rst *.lk *.rel *.sym *.ihx *.hex *.map
