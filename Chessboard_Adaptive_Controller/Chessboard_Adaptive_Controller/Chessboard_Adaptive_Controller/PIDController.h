#ifndef  _PIDController_
#define _PIDController

#include <avr/io.h>
#include <avr/interrupt.h>

#define FREQ 1000




void Controller(int ref);
void AdaptParameters(void);
void CalculateError(void);


#endif
