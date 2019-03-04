// output_topfive.cc
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 6
//
// Description: outputs the top five correlations to the terminal.

#include <rarray>
#include <iostream>
#include "output_topfive.h"

void output_topfive(rvector<double>& C){
	waves = C.size();
	rarray<double,2> C_sorted(2, waves);	// Sorted array of all the correlation coefficients and their indices	

	// Sort the Cs into C_sorted which also keeps track to the original wave index
	for(int i = 0; i<waves; i++){
		for(int j = 0; j<waves; j++){
			if(C[i] > C_sorted[0][j]){

				// Shuffle all of the current array values to the end of the array. Pop the last value
				for(int k = waves-1; k>=j; k--){
					C_sorted[0][k] = C_sorted[0][k-1];
					C_sorted[1][k] = C_sorted[1][k-1];
				}

				// Insert the current value
				C_sorted[0][j] = C[i];
				C_sorted[1][j] = i+1;

				// Move on the next C value
				break;
			}				
		}
	}

	// Output the five most significant candidates
	std::cout << std::endl << "The five most significant candidates are:" << std::endl;
	for(int i=0; i<5; i++){
		filename = "";
		if (C_sorted[1][i] < 9)
			filename = "detection0" + std::to_string((int)C_sorted[1][i]) + ".nc";
		else
			filename = "detection" + std::to_string((int)C_sorted[1][i]) + ".nc";

		std::cout << filename << " with correlation coefficient = " << C_sorted[0][i] << std::endl;
	}
}
