###############################################################################
# Project 1 Makefile
# 
# Taylor Ellington
# Scientific HPC
# Fall 2015
###############################################################################

# compiler & flags
CXX = g++
CXXFLAGS = -O -std=c++11
###################################

Project1.exe : proj1_a.cpp  nest.o matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@


matrix.o : matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

nest.o : nest.cpp nest.hpp matrix.o
	$(CXX) $(CXXFLAGS) -c $< -o $@




clean :
	 rm *.o

