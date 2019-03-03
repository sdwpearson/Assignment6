// NC_reader.h
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 6
//
// Description: This file reads in the NetCDF file containing the gravitational wave.


#ifndef NCREADER_H
#define NCREADER_H

#include <rarray>
#include <complex>

rvector<std::complex<double>> NC_reader(const char* filename);

#endif