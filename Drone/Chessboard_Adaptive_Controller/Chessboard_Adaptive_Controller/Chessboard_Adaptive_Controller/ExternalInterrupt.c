
#include "ExternalInterrupt.h"


void InitExInterruptRegister1()
{


//Clear the PC4 and PC5 pin
DDRC &= ~(1 << DDC4);	//PC4 is now an input
DDRC &= ~(1 << DDC5);	//PC5 is now an input

//Turn on pull-up resistor for inputs
PORTC |= (1 << PORTC4);	//internal pull-up on PC4
PORTC |= (1 << PORTC5); //internal pull-up on PC5

//Set  PCIE1 to enable PCMSK1 scan
PCICR |= (1 << PCIE1);

//set PCINT12 and PCINT13 to trigger interrupt on state change
PCMSK1 |= (1 << PCINT12);
PCMSK1 |= (1 << PCINT13);
//Maybe only one needed IDK

}

