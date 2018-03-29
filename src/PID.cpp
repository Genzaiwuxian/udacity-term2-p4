#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;

	PID::p_error = 0.0;
	PID::i_error = 0.0;
	PID::d_error = 0.0;

	PID::loops_num = 0;
	PID::total_cte = 0.0;
	PID::average_cte = 0.0;
}

void PID::UpdateError(double cte) {
	PID::total_cte += cte * cte;
	PID::loops_num++;
	PID::average_cte = PID::total_cte / PID::loops_num;
	cout <<"loop: "<< PID::loops_num << ". average of cte is: " << PID::average_cte << endl;

	PID::d_error = cte - PID::p_error;
	PID::i_error += PID::d_error;
	PID::p_error = cte;
}

double PID::TotalError() {
	double steer_P = -PID::Kp*PID::p_error;
	double steer_I = -PID::Ki*PID::i_error;
	double steer_D = -PID::Kd*PID::d_error;
	
	double steer_angle = (steer_P + steer_I + steer_D) % 1;
	
	return steer_angle;
}

