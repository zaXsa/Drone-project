/******************************************************************************
 * Project        : 3D printer
 * File           : Sub program - Driver control
 * Copyright      : 12018 Better Progress
 ******************************************************************************
  Change History:

    Version 1.0 - July 12018		> Initial revision

******************************************************************************/
// ----------------------------------------------------------------------------
// Libraries 
// ----------------------------------------------------------------------------
#include <util/delay.h>

#include "StepperDriver.h"

// ----------------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Local function prototypes
// ----------------------------------------------------------------------------


/**
  * @brief  The constructor sets the maximum amount of steps the devision factor of the driver and what pins are going to be used
  * @param  Max steps the stepper can give, the devision factor of the driver and the used pin setup 
  * @retval none
  */
StepperDriver::StepperDriver(int MaxSteps, int Devision, int StepsDistance,int Pins){
	MaxNumberOfSteps = MaxSteps;
	StepDevision = Devision;
	UsedPins = Pins;
	StepsPermm = StepsDistance;

	StepInterval = 0;
}

/**
  * @brief  This function makes the stepper take one step
  * @param  none
  * @retval none
  */
void StepperDriver::MoveStep(){
	switch (UsedPins){
		case 1:Driver1MoveON;_delay_ms(StepInterval);Driver1MoveOFF;break;
		case 2:Driver2MoveON;_delay_ms(StepInterval);Driver2MoveOFF;break;
		case 3:Driver3MoveON;_delay_ms(StepInterval);Driver3MoveOFF;break;
		case 4:Driver4MoveON;_delay_ms(StepInterval);Driver4MoveOFF;break;
		default:break;
		}
	
}

/**
  * @brief  This function uses the wanted steps and the direction and makes sets the right configuration 
  * @param  The amount of steps to take and the direction
  * @retval none
  */
void StepperDriver::Steps(int16_t Stepstotake){
	Stepstotake *= StepDevision;
	setDirection(Stepstotake);

	for (int16_t i = abs(Stepstotake); i > 0; i--) {
		MoveStep();
	}
}

/**
  * @brief  This funtion makes sure the steppers are on the correct starting position before continuing   
  * @param  none
  * @retval none
  */
void StepperDriver::Positioning()
{
	uint16_t step_interval_0 = StepInterval;
	StepInterval *= 8;

	Steps(4);
	_delay_ms(200);
	Steps(-4);
	_delay_ms(200);

	StepInterval = step_interval_0;
}

/**
  * @brief  This function sets the wanted revolutions per minute by changing the time interval between steps based on the steps it takes for one mm
  * @param  Wanted revolutions per minute, the steps it takes per mm and the given step devision 
  * @retval The new step interval time in ms 
  */
void StepperDriver::setSpeed(float WantedSpeed){
  StepInterval = (WantedSpeed / (StepsPermm * StepDevision))*1000;

  // StepInterval = 60000/(WantedSpeed*MaxNumberOfSteps);
}
/**
  * @brief  This function enables or disables all driver 
  * @param  The enable or disable command
  * @retval none
  */
void StepperDriver::PowerEnable(const bool TrueFalse){
	if (TrueFalse){
		Driver1ON;
	} else{
		Driver1OFF;
	}					
}
/**
  * @brief  This function Checks the direction of the steps by checking if the given parameter is positive or negative 
  * @param  The wanted steps
  * @retval none
  */
void StepperDriver::setDirection(const int StepDirection){
	if (StepDirection < 0) {
		switch (UsedPins){
		case 1:Driver1Left;break;
		case 2:Driver2Left;break;
		case 3:Driver3Left;break;
		case 4:Driver4Left;break;
		default:break;
		}
	}
	else {
		switch (UsedPins){
		case 1:Driver1right;break;
		case 2:Driver2right;break;
		case 3:Driver3right;break;
		case 4:Driver4right;break;
		default:break;
		}
	}
}