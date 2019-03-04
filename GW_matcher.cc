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

#define NUM_WAVES 32

int  main() {
	rvector<std::complex<double>> f;	// Original wave to compare against
	rvector<double> F;					// Power spectrum of comparison wave
	rvector<std::complex<double>> g;	// Individual wave to compare against
	rvector<double> G;					// Power spectrum of the individual wave
	rvector<double> C(NUM_WAVES);		// Vector of all the correlation coefficients

	// File base for all of the waves
	std::string FILEBASE = "/scinet/course/phy1610/gwdata/";
	std::string filename;


	filename = FILEBASE + "GWprediction.nc";
	f = NC_reader(filename.c_str());
	F = power_spec(f);

	for(int i = 0; i<NUM_WAVES; i++){
		filename = "";
		if (i < 10)
			filename = FILEBASE + "detection0" + std::to_string(i+1) + ".nc";
		else
			filename = FILEBASE + "detection" + std::to_string(i+1) + ".nc";

		g = NC_reader(filename.c_str());
		G = power_spec(g);
		C[i] = corr_coeff(F, G);

		std::cout << C << std::endl;

		// Clear the vectors we compare against
		g.clear();
		G.clear();
	}

	return 0;
}




