// GW_matcher.cc
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 6
//
// Description: This file attempts to match sample gravity wave power spectrums to a given gravity wave power spectrum.

#include <iostream>
#include <rarray>
#include <rarrayio>
#include <complex>
#include "NC_reader.h"
#include "power_spec.h"
#include "corr_coeff.h"

#define FILEBASE "/scinet/course/phy1610/gwdata"

int  main() {
	rarray<std::complex<double>,1> f;
	std::string filename;

	filename = FILEBASE + "GWprediction.nc"
	f = NC_reader(filename);

	std::cout << f << std::endl;

	return 0;
}




