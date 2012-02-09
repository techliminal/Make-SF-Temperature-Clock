/*
Simple Temperature Sensor by Malcolm Knapp
Adapted from the open-source LM35DZ Temperature Sensor project for Arduino by Daniel Spillere Andrade
http://www.danielandrade.net
http://creativecommons.org/license/cc-gpl

This program reads the output of an LM35 Temperature sensor and then transmites of a serial connection
*/
#include "WProgram.h"
void setup();
void loop();
int pin = 0; // analog pin
float tempc = 0,tempf=0; // temperature variables
float samples[8]; // variables to make a better precision
int i;

void setup()
{
Serial.begin(9600); // start serial communication
}

void loop()
{
for(i = 0;i<= 7;i++){ // gets 8 samples of temperature
// System Volatge is 5V
// Analog read max ouput is 1024 units
// Therefore 4.9mV/unit
// LM35 has a linear scale of 10mV/degC
samples[i] = (analogRead(pin)*(5.0/1024) * (1/.01)); 
tempc = tempc + samples[i]; 
delay(150);
}
tempc = tempc/8.0; // better precision

tempf = (tempc * 9)/ 5 + 32; // converts to fahrenheit

Serial.print("?");
Serial.print(tempc);
Serial.print("%");

tempc = 0.0; // reset temp varible 
delay(100); // delay before loop
}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

