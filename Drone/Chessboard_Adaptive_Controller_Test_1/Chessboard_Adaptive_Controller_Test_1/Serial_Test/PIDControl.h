#ifndef  PIDControl_H
#define PIDControl_H

#include <avr/io.h>
#include <avr/interrupt.h>

#define FREQ 1000

void Controller(int ref);
void AdaptParameters(void);
void CalculateError(void);

#endif
