// NC_reader.cc
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 6
//
// Description: This file reads in the NetCDF file containing the gravitational wave and 
// returns an array of the complex data.

#include <rarray>
#include <netcdf>
#include <complex>
#include "NC_reader.h"

rvector<std::complex<double>> NC_reader(const char* filename){ 
    
    // Open the netCDF file to read
    netCDF::NcFile file(filename, netCDF::NcFile::read);
    
    // Get the size of the gravitational wave to initialize the variable
    rvector<std::complex<double>> f_nc(file.getDim("nt").getSize());
    
    // Extract the complex gravitational wave
    file.getVar("f").getVar(&f_nc[0]);

    return f_nc;

    // The file will be automatically closed when the NcFile object goes
    // out of scope. This frees up any internal netCDF resources
    // associated with the file, and flushes any buffers.
}