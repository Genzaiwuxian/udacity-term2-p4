#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  //throttle coefficients
  double Kp_throttle;
  double target_speed;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  //initialize PID_throttle
  void InitThrottle(double Kp_throttle, double target_speed);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  // update throttle value
  double UpdateThrottle(double speed);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  unsigned int loops_num;

  double total_cte;

  double average_cte;
};

#endif /* PID_H */
