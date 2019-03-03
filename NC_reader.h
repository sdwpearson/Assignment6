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

rarray<std::complex<double>,1> NC_reader(const std::string filename);

#endif