#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double K_p, double K_i, double K_d) {
	Kp = K_p;
	Ki = K_i;
	Kd = K_d;
	p_error = 0;
	i_error = 0;
	d_error = 0;
	previous_error = 0;
}

void PID::UpdateError(double cte) {
	//CTE is [-4,4] aproximately to be inside the road
	p_error = cte;
	d_error = cte - previous_error;
	i_error += cte;
	previous_error = cte;
}

double PID::TotalError(double speed) {
	if(speed < 1) speed = 1;
	double aux_Kp= Kp*40/speed;
	double aux_Kd= Kd*speed/30;
	double steering = (-aux_Kp*p_error - Ki*i_error - Kd*d_error);
	if (steering < -1)
		steering = -1;
	else if (steering > 1)
		steering = 1;
	return steering;
}