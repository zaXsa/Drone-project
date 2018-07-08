﻿/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include "StepperDriver.h" 
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio



#define motor_steps 200  //定義步進馬達每圈的步數  
#define step_divisition 16
#define en_pin 5
#define cw_pin 6
#define clk_pin 7

StepperDriver ss(motor_steps, step_divisition, en_pin, cw_pin, clk_pin);  

int main(){
	Serial.begin(9600);
	Serial.print("Test Serial");

	ss.setSpeed(160);
	ss.powerEnable(true);
	ss.positioning();
	delay(1600);

	while (1){
		if (digitalRead(8)){

		}
		ss.setSpeed(160);
		ss.step(20);
		delay(100);
	}
}

