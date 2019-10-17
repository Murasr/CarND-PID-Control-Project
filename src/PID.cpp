#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  
  p_error = 0;
  i_error = 0;
  d_error = 0;

  last_cte = 0;
  last_cte_initialized = false;
  total_cte = 0;
  
  count = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
   if(!last_cte_initialized)
   {
     last_cte = cte;
     last_cte_initialized = true;
   }
  
  total_cte += cte;
  
  p_error = -Kp * cte;
  i_error = -Ki * total_cte;
  d_error = -Kd * (cte - last_cte);
  
  last_cte = cte;
  
  count++;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  
  double totalError = p_error + i_error + d_error;
  
  return totalError;  // TODO: Add your total error calc here!
}