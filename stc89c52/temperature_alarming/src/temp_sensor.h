#ifndef _TEMP_SENSOR_H
#define _TEMP_SENSOR_H

// used for delay of sensor
void Delay_DS18B20(int num);

// init DS18B20
void Init_DS18B20();

// read one byte data from ds18b20
unsigned char ReadOneByte();

// write one byte to ds18b20
void WriteOneByte(unsigned char);

// read temperature procedure from ds18b20
unsigned int ReadTemperature();

// check if temperature is in the range
void check_temp();
#endif
