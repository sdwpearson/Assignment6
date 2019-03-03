// NC_reader.cc
// Author: Stewart Pearson
// Date: March 3, 2019
// PHY1610 Assignment 3
//
// Description: This file reads in the NetCDF file containing the gravitational wave.

#include <rarray>
#include <netcdf>
#include <complex>
#include "NC_reader.h"

rarray<std::complex<double>,1>* NC_reader(const char* filename){ 
    
    netCDF::NcFile file(filename, netCDF::NcFile::read);
    
    rarray<std::complex<double>,1> f_nc(file.getDim("nt").getSize());
    
    file.getVar("f").getVar(&f_nc[0]);

    return f_nc;

    // The file will be automatically closed when the NcFile object goes
    // out of scope. This frees up any internal netCDF resources
    // associated with the file, and flushes any buffers.
}