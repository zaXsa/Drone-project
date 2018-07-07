/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include "StepperDriver.h" 
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio



#define motor_steps 200;  //定義步進馬達每圈的步數  
#define step_divisition 16;
#define en_pin 5;
#define cw_pin 6;
#define clk_pin 7;

StepperDriver ss(motor_steps, step_divisition, en_pin, cw_pin, clk_pin);  

void setup() { 
	ss.setSpeed(160);
	ss.powerEnable(true);
	ss.positioning();
	delay(1600);
}

void loop() {
	ss.setSpeed(160);
	ss.step(400);
	delay(100);
	ss.step(-400);
	delay(100);
	ss.step(1200, 144, 160);
	delay(100);
	ss.step(-1200, 144, 160);
	delay(100);
	ss.setSpeed(200);
	ss.step(400, 32, 40);
	delay(100);
	ss.step(-400, 32, 40);
	delay(200);
}