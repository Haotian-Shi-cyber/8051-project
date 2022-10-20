#include "temp_sensor.h"
#include "global.h"

void Delay_DS18B20(int num){
	while(num--);// if looking its asm code, it costs 8 cycles so each loop lasts 8us
}

// init temperature sensor
void Init_DS18B20(){
	// pls refer to DS18B20 manual
	unsigned char x = 0;
	DQ = 1;// rest DQ
	Delay_DS18B20(8); // some delay, prepare for init
	DQ = 0; // pull down DQ Line, start to send reset pulse
	Delay_DS18B20(80); // make sure delay is between 480us to 960us
	DQ = 1; // after sending reset pulse, pull up DQ
	Delay_DS18B20(20);// then between 60us to 240us, slave sends presence pulse to indicate it initialised
	x = DQ; // get presence pulse value, if it is x == 0 it means ds18b20 is successfully initialised
	Delay_DS18B20(20); // end delay
}

// read one byte
unsigned char ReadOneByte(){
	unsigned char i = 0;
	unsigned char dat = 0;
	for(i = 8; i > 0; i--){
		DQ = 0; // before read, master has to be active low
		dat >>= 1;
		DQ = 1; // stop driving it to low in order to read state from sensor
		if(DQ){
			dat |= 0x80;// from msbit 
		}
		Delay_DS18B20(4);
	}
	return dat;
}

// write one byte
void WriteOneByte(unsigned char dat){
	unsigned char i = 0;
	for(i = 8; i > 0; i--){
		DQ = 0;// before write, master has to be active low
		DQ = dat&0x01;// write from lsbit to msbit
		Delay_DS18B20(5);// sample windows is between 15-60 after active low
		DQ = 1;// return to active high
		dat >>= 1;// write next bit
	}
	
}

// read temperature
unsigned int ReadTemperature(){
	unsigned char a = 0;
	unsigned char b = 0;
	unsigned int t = 0;
	float tt;
	// follow flow chart of ds18b20
	Init_DS18B20();
	WriteOneByte(0xCC); // skip ROM function, jump to memory function
	WriteOneByte(0x44); // memory function, convert T, result will be stored in to scratchpad memory
	
	Init_DS18B20(); // ??? why does it need to be inited again, can we just issue read scratchpad memory command
	WriteOneByte(0xCC);
	WriteOneByte(0xBE); // read scrachpad mem
	a = ReadOneByte(); // read low byte(LSByte first) of temperature
	b = ReadOneByte(); // read high byte(MSByte second) of temperature
			   
	/* serial debug */
	//remeber to comment out these operation in final code
	//TMOD = 0x20; // using timer to generate baud rate
	//TH1 = 0xfd; // baud rate 9600 bps
	//SCON = 0x50; // mode 1 8 bit uart, variable baud rate set by user
	//TR1 = 1; // enable timer 1
	//SBUF = a; // or SBUF = b
	/* end of debug info */

	t = b;
	t <<= 8; //put it into high byte of 16 bit temperature
	t |= a; // get the final 16 bit temperature;
	tt = t * 0.0625; // default resolution is 12 bit thus 4 bit floating point
	t = tt * 10 + 0.5; // get the first num after point
	return t;
}

void check_temp(){
	unsigned int tens, digit, t;
	t = ReadTemperature(); //234
	tens = t/100; // get its tens num, 234 / 100 = 2
	digit = t/10 - tens * 10; // get its digit num, 234 / 10 - 2 * 10 = 3
	ap = t - tens * 100 - digit * 10; // get first num after point
	
	m = t / 10;// get its integer val
	
	// range of detected temperature is between 0.0c ~ 99.9c
	if(m < 0){
		// upper limit
		m = 0;
		ap = 0;
	}
	
	if(m > 99){
		// lower limit
		m = 99;
		ap = 9;
	}
}
