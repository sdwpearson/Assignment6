// corr_coeff.cc
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 5
//
// Description: This file calculates the correlation coefficient for two different
// power spectrums and returns it

#include <rarray>
#include <cblas.h>
#include <math.h>
#include "corr_coeff.h"


double corr_coeff(const rvector<double>& F, const rvector<double>& G){ 
    double C, FG, FF, GG;
    int length = F.size();
    
    // Calculate the intermediate dot producets of the correlation coefficient
    FG = cblas_ddot(length, F.data(), 1, G.data(), 1);
    FF = cblas_ddot(length, F.data(), 1, F.data(), 1);
    GG = cblas_ddot(length, G.data(), 1, G.data(), 1);

    // Perform the final calculation to obtain the correlation coefficient
    C = FG / sqrt(FF*GG);

    return C;
}