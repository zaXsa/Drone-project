/*Begining of Auto generated code by Atmel studio */


#include "Timers.h"
#include "PIDController.h"
#include "ExternalInterrupt.h"


#include <Arduino.h>
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



//C:\Users\Nout\Documents\Atmel Studio\7.0\Chessboard_Adaptive_Controller\Chessboard_Adaptive_Controller\Chessboard_Adaptive_Controller





void setup()
{
	//Initialize Timers
	//InitExInterruptRegister1();
	InitTimer0();
	



}

void loop()
{



}

//////////////////////////////////////////////////////////////////////////////////
//							TIMER INTERRUPTS									//
//////////////////////////////////////////////////////////////////////////////////


//TIMER 0 (8-bit timer)
ISR (TIMER0_COMPA_vect)
{
	
}

//TIMER 1 (12-bit timer)
ISR (TIMER1_COMPA_vect)
{
	
}


//TIMER 2 (8-bit timer)
ISR (TIMER2_COMPA_vect)
{
	
}


//////////////////////////////////////////////////////////////////////////////////
//							EXTERNAL INTERRUPTS									//
//////////////////////////////////////////////////////////////////////////////////

ISR (PCINT1_vect)
{
	*pChangedbits = PINB ^ *pPortChistory;
	*pPortChistory = PINB;

	
	//Check which pin caused a state change which triggered the event..
	if(*pChangedbits & (1 << PINC4))		// Pin PC4
	{
		if( (PINC & (1 << PINC4)) == 1 )	//Check if pin is high or low
		{
			/* LOW to HIGH pin change */
		}
		else
		{
			/* HIGH to LOW pin change */
		}
	}
	
	if(*pChangedbits & (1 << PINC5))	// Pin PC5
	{
		if( (PINC & (1 << PINC5)) == 1 )	//Check if pin is high or low
		{
			/* LOW to HIGH pin change */
		}
		else
		{
			/* HIGH to LOW pin change */
		}
	}
}
