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
#include <complex>

rarray<double,1> power_spec(const rarray<std::complex<double>,1>& f);

#endif