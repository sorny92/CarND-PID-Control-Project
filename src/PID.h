#ifndef PID_H
#define PID_H

class PID {
public:

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Initialize PID.
  */
  void Init(double K_p, double K_i, double K_d);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError(double speed);
private:
    /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double previous_error;
};

#endif /* PID_H */
