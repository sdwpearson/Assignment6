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
#include <string.h>
#include "NC_reader.h"
#include "power_spec.h"
#include "corr_coeff.h"


int  main() {
	rvector<std::complex<double>> f;
	rvector<double> F;
	std::string FILEBASE = "/scinet/course/phy1610/gwdata/";
	std::string filename;

	filename = FILEBASE + "GWprediction.nc";
	f = NC_reader(filename.c_str());

	std::cout << f.size() << std::endl;

	F = power_spec(f);

	std::cout << F.size() << std::endl;

	return 0;
}




