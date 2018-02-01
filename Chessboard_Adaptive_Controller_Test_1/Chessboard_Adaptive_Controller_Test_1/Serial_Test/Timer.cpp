#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											INITIALIZE TIMER 0															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitTimer0()
{
	//Set the timer mode
	TCCR0A = 0;					//Reset the register
	TCCR0A |= (1 << WGM01);		//Set the mode to CTC
}

void SetTimer0Prescaler(int prescaler)
{
	TCCR0B = 0;
	switch (prescaler)
	{
		//Clock / 1
		case 1:
		TCCR0B |= (1 << CS00);
		break;
		
		//Clock / 8
		case 8:
		TCCR0B |= (1 << CS01);
		break;
		
		//Clock / 64
		case 64:
		TCCR0B |= (1 << CS00) | (1 << CS01);
		break;
		
		//Clock / 256
		case 256:
		TCCR0B |= (1 << CS02);
		break;
		
		//Clock / 1024
		case 1024:
		TCCR0B |= (1 << CS02) | (1 << CS00);
		break;
	}
}

void SetTimer0Counter(int count)
{
	OCR0A = count;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											INITIALIZE TIMER 1															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitTimer1()
{
	//Set the timer mode
	TCCR1A = 0;					//Reset the register
	
	TCCR1B = 0;					//Reset the register
	TCCR1B |= (1 << WGM12);		//Set the timer mode to CTC
	
	TIMSK1 = 0;
	TIMSK1 |= (1 << OCIE1A);
	//Set interrupt on compare match
}

void SetTimer1Prescaler(int prescaler)
{
	TCCR1B = 0;
	switch (prescaler)
	{
		//Clock / 1
		case 1:
		TCCR1B |= (1 << CS10);
		break;
		
		//Clock / 8
		case 8:
		TCCR1B |= (1 << CS11);
		break;
		
		//Clock / 64
		case 64:
		TCCR1B |= (1 << CS10);
		TCCR1B |= (1 << CS11);
		break;
		
		//Clock / 256
		case 256:
		TCCR1B |= (1 << CS12);
		break;
		
		//Clock / 1024
		case 1024:
		TCCR1B |= (1 << CS12);
		TCCR1B |= (1 << CS10);
		break;
	}
}

void SetTimer1Counter(int count)
{
	OCR1A = count;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											INITIALIZE TIMER 2															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitTimer2()
{
	//Set the timer mode
	TCCR2A = 0;					//Reset the register
	TCCR2A |= (1 << WGM21);		//Set the mode to CTC

}

void SetTimer2Prescaler(int prescaler)
{
	TCCR2B = 0;
	switch (prescaler)
	{
		//Clock / 1
		case 1:
		TCCR2B |= (1 << CS20);
		break;
		
		//Clock / 8
		case 8:
		TCCR2B |= (1 << CS21);
		break;
		
		//Clock / 64
		case 64:
		TCCR2B |= (1 << CS20) | (1 << CS21);
		break;
		
		//Clock / 256
		case 256:
		TCCR2B |= (1 << CS22);
		break;
		
		//Clock / 1024
		case 1024:
		TCCR2B |= (1 << CS22) | (1 << CS20);
		break;
	}
}

void SetTimer2Counter(int count)
{
	OCR0A = count;
}
