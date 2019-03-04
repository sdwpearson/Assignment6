// GW_matcher.cc
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 6
//
// Description: This file attempts to match sample gravity wave power spectrums to a given gravity wave power spectrum.
// It will then output all of the correlation coefficients and then the top five candidates in the terminal.

#include <iostream>
#include <rarray>
#include <rarrayio>
#include <complex>
#include <string.h>
#include "NC_reader.h"
#include "power_spec.h"
#include "corr_coeff.h"
#include "output_top5.h"

// Number of canditate waves
#define NUM_WAVES 32

int  main() {
	rvector<std::complex<double>> f;			// Original wave to compare against
	rvector<double> F;							// Power spectrum of comparison wave
	rvector<std::complex<double>> g;			// Individual wave to compare against
	rvector<double> G;							// Power spectrum of the individual wave
	rvector<double> C(NUM_WAVES);				// Vector of all the correlation coefficients

	// File base for all of the waves
	std::string FILEBASE = "/scinet/course/phy1610/gwdata/";

	// Total filename for each netCDF file
	std::string filename;

	// Start by getting the power spectrum for the prediction wave 
	filename = FILEBASE + "GWprediction.nc";
	f = NC_reader(filename.c_str());
	F = power_spec(f);

	// Loop through all of the sample waves and compute their correlation coefficient.
	for(int i = 0; i<NUM_WAVES; i++){
		filename = "";

		// Get the correct netCDF filename
		if (i < 9)
			filename = FILEBASE + "detection0" + std::to_string(i+1) + ".nc";
		else
			filename = FILEBASE + "detection" + std::to_string(i+1) + ".nc";

		// Compute the power spectrum and then store the correlation coefficient in C
		g = NC_reader(filename.c_str());
		G = power_spec(g);
		C[i] = corr_coeff(F, G);

		// Output the correlation coefficient
		std::cout << "--------------- Wave Number " + std::to_string(i+1) + " ---------------" << std::endl;
 		std::cout << "correlation coefficient = " << C[i] << std::endl;

		// Clear the vectors we compare against
		g.clear();
		G.clear();
	}

	// Output the top 5 to the terminal
	output_top5(C);

	return 0;
}




