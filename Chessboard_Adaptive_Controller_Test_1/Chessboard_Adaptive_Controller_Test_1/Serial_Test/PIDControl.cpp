#include <avr/io.h>
#include "PIDControl.h"

void Controller(int ref)
{
	//Initialize all the
	static double error = 0;
	static double pre_error = 0;
	static double dif_error = 0;
	static double int_error = 0;
	double measuredValue = 0;

	static double dt = 1/FREQ;

	int output = 0;
	float Kp = 0;
	float Ki = 0;
	float Kd = 0;

	////////////////////////////////////////////
	//Calculating Error's
	error = ref - measuredValue;
	dif_error = error - pre_error;
	int_error = error + pre_error;
	pre_error = error;

	output = (Kp * error) + (Ki * int_error * dt) + ((Kd * dif_error) / dt);
}

void AdaptParameters()
{
	static double ModelY = 0;			//Output of the model of the system
	static double PlantY = 0;			//Realtime output of the system

	static double Error = 0;		//Error between the model and the realtime system (ModelY-PlantY)
	static double PreError = 0;			//Previous error

	double IntError = 0;			//Intergration of the error
	double A = 0;



	static double kff = 0;

	const double SampleTime = 1/1000;
	const double gamma = 0.2;
	const double k = 10;
	const double negate = -1;

	Error = ModelY;

	IntError = Error + PreError;
}

