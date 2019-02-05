#include "PID.h"
#include <iostream>
using namespace std;
/**
 * PID class. 
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

}

void PID::UpdateError(double cte) {
  /**
   * Update PID errors based on cte.
   */
  i_error +=cte;
  d_error = cte-p_error;
  p_error = cte;
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */
  float total_err;
  total_err = -Kp*p_error - Ki*i_error - Kd*d_error;
  return total_err;  // TODO: Add your total error calc here!
}
