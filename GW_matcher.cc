// GW_matcher.cc
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 6
//
// Description: This file attempts to match sample gravity wave power spectrums to a given gravity wave power spectrum.

#include <iostream>
#include <rarray>
#include <complex>
#include "NC_reader.h"
#include "power_spec.h"
#include "corr_coeff.h"

#define FILEBASE "/scinet/course/phy1610/gwdata"

int  main() {
	rarray<std::complex<double>,1>* f;
	std::string filename;

	filname = FILEBASE + "GWprediction.nc"
	f = NC_reader(filename);

	std::cout << f[0] << std::endl;
	std::cout << f[1] << std::endl;
	std::cout << f[2] << std::endl;
	std::cout << f[3] << std::endl;

	return 0;
}




