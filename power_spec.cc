// power_spec.cc
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 6
//
// Description: This file calculates the FFT of the raw GW data and then calculates the 
// power spectrum of that wave and returns it

#include <rarray>
#include <complex>
#include <iostream>
#include <fftw3.h>
#include "power_spec.h"

rvector<double> power_spec(const rvector<std::complex<double>>& f){ 
    int n = f.size();
    rvector<std::complex<double>> f_hat(n);

    fftw_plan p = fftw_plan_dft_1d(n,(fftw_complex*)f.data(), (fftw_complex*)f_hat.data(), FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(p);
    fftw_destroy_plan(p);

    int n_hat = f_hat.size();

    std::cout << n_hat << std::endl;

    rvector<double> F(n_hat);
    
    for(int i=0; i<n_hat; i++)
    {
        F[i] = std::real(f_hat[i]*std::conj(f_hat[i]));
    }

    return F;
}