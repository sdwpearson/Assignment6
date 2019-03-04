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
	rvector<std::complex<double>> g;
	rvector<double> G;
	double C;
	std::string FILEBASE = "/scinet/course/phy1610/gwdata/";
	std::string filename;

	filename = FILEBASE + "GWprediction.nc";
	f = NC_reader(filename.c_str());

	filename = "";
	filename = FILEBASE + "detection01.nc";
	g = NC_reader(filename.c_str());

	F = power_spec(f);
	G = power_spec(g);

	C = corr_coeff(F, G);

	std::cout << C << std::endl;

	return 0;
}




