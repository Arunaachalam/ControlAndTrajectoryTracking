/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   _Kp = Kpi;
   _Ki = Kii;
   _Kd = Kdi;

   _outputLimMax = output_lim_maxi;
   _outputLimMin = output_lim_mini;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  if (_previousCTE == 0) {
     _previousCTE = cte; 
  }

  _pError = cte;
  _iError += cte * _deltaTime;
  _dError = (cte - _previousCTE) / _deltaTime;
  _previousCTE = cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control = _Kp * _pError + _Ki * _iError + _Kd * _dError;

    if (control < _outputLimMin) {
      control = _outputLimMin;
    }

    if (control > _outputLimMax) {
      control = _outputLimMax;
    }

    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   _deltaTime = new_delta_time;
}