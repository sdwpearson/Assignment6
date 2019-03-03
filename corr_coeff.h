// corr_coeff.h
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 5
//
// Description: This file calculates the correlation coefficient for two different
// power spectrums and returns it


#ifndef CORR_COEFF_H
#define CORR_COEFF_H

#include <rarray>

void corr_coeff(const rarray<double,1>& x,  const char* filename, int length, const double t, const double INITIAL_Z0);

#endif