// NC_reader.cc
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 3
//
// Description: This file reads in the NetCDF file containing the gravitational wave.

#include <rarray>
#include <netcdf>
#include <iostream>
#include <vector>
#include "NC_reader.h"

using namespace netCDF;
using namespace netCDF::exceptions;

void NC_reader(const rarray<double,1>& x, const char* filename, int length, const double t, const double INITIAL_Z0){ 
            
    // The file will be automatically closed when the NcFile object goes
    // out of scope. This frees up any internal netCDF resources
    // associated with the file, and flushes any buffers.
}