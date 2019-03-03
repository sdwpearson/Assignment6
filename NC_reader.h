// NC_reader.h
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 6
//
// Description: This file reads in the NetCDF file containing the gravitational wave.


#ifndef NCREADER_H
#define NCREADER_H

#include <rarray>

void NC_reader(const rarray<double,1>& x,  const char* filename, int length, const double t, const double INITIAL_Z0);

#endif