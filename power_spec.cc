// power_spec.cc
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 6
//
// Description: This file calculates the FFT of the raw GW data and then calculates the 
// power spectrum of that wave and returns it

#include <rarray>
#include <complex>
#include <fftw3.h>
#include "power_spec.h"

rarray<double,1> power_spec(const rarray<std::complex<double>,1>& f){ 
    int n = f.size();
    rarray<std::complex<double>,1> f_hat;

    fftw_plan p = fftw_plan_dft_1d(n,(fftw_complex*)f.data(), (fftw_complex*)f_hat.data(),FFTW_FORWARD,FFTW_ESTIMATE);

    fftw_execute(p);
    fftw_destroy_plan(p);

    int n_hat = f_hat.size();
    rarray<double,1> F(n_hat);
    
    for(int i=0; i<n_hat; i++)
    {
        F[i] = real(f_hat[i]*std::conj(f_hat[i]));
    }

    return F;
}