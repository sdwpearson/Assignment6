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

double corr_coeff(const rvector<double>& F, const rvector<double>& G);

#endif