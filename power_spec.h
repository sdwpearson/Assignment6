// power_spec.h
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 6
//
// Description: This file calculates the FFT of the raw GW data and then calculates the 
// power spectrum of that wave and returns it


#ifndef POWER_SPEC_H
#define POWER_SPEC_H

#include <rarray>

void power_spec(const rarray<double,1>& x,  const char* filename, int length, const double t, const double INITIAL_Z0);

#endif