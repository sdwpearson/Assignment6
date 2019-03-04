CXX=g++
CXXFLAGS=-std=c++11 -g -O0 -march=native
CXXTESTFLAGS=-std=c++11 -g 
CXXFLAGS=-std=c++11 -g -O0 -march=native -ftree-vectorize -Wall

LDFLAGS=-g
LDLIBS= -lnetcdf_c++4 -lfftw3 -lopenblas

all: GW_matcher

clean: 
	\rm -f NC_reader.o GW_matcher.o corr_coeff.o power_spec.o

power_spec.o: power_spec.cc power_spec.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

output_topfive.o: output_topfive.cc output_topfive.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

corr_coeff.o: corr_coeff.cc corr_coeff.h
	${CXX} ${CXXFLAGS} -I${BLAS_INC} -c -o $@ $<

NC_reader.o: NC_reader.cc NC_reader.h
	${CXX} ${CXXFLAGS} -I${NETCDF_INC} -c -o $@ $<

GW_matcher.o: GW_matcher.cc NC_reader.h corr_coeff.h power_spec.h output_topfive.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

GW_matcher: GW_matcher.o NC_reader.o corr_coeff.o power_spec.o output_topfive.o
	${CXX} ${LDFLAGS} -L${NETCDF_LIB} -L${BLAS_LIB} -o $@ $^ ${LDLIBS}

run: GW_matcher
	./GW_matcher

help:
	@echo Type:
	@echo " 'make all'                	to compile the GW_matcher application;"
	@echo " 'make clean'            	to remove output files;"
	@echo " 'make power_spec.o'         to compile the power_spec module;"
	@echo " 'make output_topfive.o'     to compile the output_topfive module;"
	@echo " 'make corr_coeff.o			to compile the corr_coeff module;"
	@echo " 'make NC_reader.o'          to compile the NC_reader module;"
	@echo " 'make GW_matcher.o'         to compile the GW_matcher linking files;"
	@echo " 'make GW_matcher'           to compile the GW_matcher application;"
	@echo " 'make run'	            	to run the GW_matcher application;"







