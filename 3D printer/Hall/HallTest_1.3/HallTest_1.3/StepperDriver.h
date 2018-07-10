#ifndef STEPPERDRIVER_H 
#define STEPPERDRIVER_H 

#ifndef F_CPU
#define F_CPU 16000000ul
#endif

#define Driver1Left PORTB &= ~(1<<PORTB0)
#define Driver2Left PORTB &= ~(1<<PORTB1)
#define Driver3Left PORTB &= ~(1<<PORTB2)
#define Driver4Left PORTB &= ~(1<<PORTB3)

#define Driver1right PORTB |= (1<<PORTB0)
#define Driver2right PORTB |= (1<<PORTB1)
#define Driver3right PORTB |= (1<<PORTB2)
#define Driver4right PORTB |= (1<<PORTB3)

#define Driver1OFF PORTD &= ~(1<<PORTD7)

#define Driver1ON PORTD |= (1<<PORTD7)

#define Driver1MoveOFF PORTB &= ~(1<<PORTB4)
#define Driver2MoveOFF PORTB &= ~(1<<PORTB5)
#define Driver3MoveOFF PORTB &= ~(1<<PORTB6)
#define Driver4MoveOFF PORTB &= ~(1<<PORTB7)

#define Driver1MoveON PORTB |= (1<<PORTB4)
#define Driver2MoveON PORTB |= (1<<PORTB5)
#define Driver3MoveON PORTB |= (1<<PORTB6)
#define Driver4MoveON PORTB |=(1<<PORTB7)

class StepperDriver{
	StepperDriver(int MaxSteps, int Devision, int StepsDistance, int Pins);
	public:
	void SetSpeed(const int Speed);
	void Steps(int16_t Stepstotake);
	void PowerEnable(const bool TrueFalse);
	void Positioning();

	private:
	void setDirection(const int StepDirection);
	void MoveStep();

	int MaxNumberOfSteps;
	int StepDevision;
	int UsedPins;
	int StepsPermm;
	uint16_t StepInterval;
};

#endif // end STEPPERDRIVER_H 

