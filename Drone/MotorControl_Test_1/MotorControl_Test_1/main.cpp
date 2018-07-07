/*
 * MotorControl_Test_1.cpp
 *
 * Created: 13-1-2018 00:21:05
 * Author : renzo
 */ 

#define F_CPU 16000000ul

#include <avr/io.h>																				// Allow: Standard I/O functions
#include <util/delay.h>																			// Allow: delays
#include <avr/interrupt.h>																		// Allow: interrupts
#include <stdint.h>																				// Allow: use of uint8_t

#include "USARTinit.h"

int main(void){
	char Chello;

	DDRB = 0x08;																				// Set register B 0000 1000
	DDRD = 0x68;																				// Set register D 0110 1000

	OCR2A = 0;																					// set PWM for D3
	OCR2B = 0;																					// set PWM for B3
	TCCR2A |= (1<<COM2A1);																		// set none-inverting mode OCR0A
	TCCR2A |= (1<<COM2B1);																		// set none-inverting mode OCR0B
	TCCR2A |= (1<<WGM22) | (1 << WGM20);														// set fast PWM Mode
	TCCR2B |= (1<<CS21);																		// set prescaler to 8 and starts PWM

	DDRD |= (1<<DDD6);																			// PD6 is an output
	DDRD |= (1<<DDD5);																			// PD5 is an output
	DDRB |= (1<<DDB5);																			// PB5 is an output
		
	DDRB &= ~(1<<DDB7);																			// PB7 is an input
		
	OCR0A = 0;																					// set PWM for D6
	OCR0B = 0;																					// set PWM for D5
	TCCR0A |= (1<<COM0A1);																		// set none-inverting mode OCR0A
	TCCR0A |= (1<<COM0B1);																		// set none-inverting mode OCR0B
	TCCR0A |= (1<<WGM02) | (1 << WGM00);														// set fast PWM Mode
	TCCR0B |= (1<<CS01);																		// set prescaler to 8 and starts PWM

	InitUART(MYUBRR);																			// Enable: UART communication	
    while (1) {
		Chello = ReceiveByte();
		while (ReceiveByte()!='\n');
		TransmitByte(Chello);
		if (Chello == 's'){
			OCR0A = 100;
			OCR0B = 100;
			OCR2A = 100;
			OCR2B = 100;
		} else if(Chello == 'd'){
			OCR0A = 200;
			OCR0B = 200;
			OCR2A = 200;
			OCR2B = 200;
		} else if(Chello == 'a'){
			OCR0A = 0;
			OCR0B = 0;
			OCR2A = 0;
			OCR2B = 0;
		}
    }
}
