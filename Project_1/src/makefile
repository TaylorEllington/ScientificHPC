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

All : proj1_a.exe proj1_b.exe

proj1_a.exe : proj1_a.cpp  nest.o matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@

proj1_b.exe : proj1_b.cpp matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@


matrix.o : matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

nest.o : nest.cpp nest.hpp matrix.o
	$(CXX) $(CXXFLAGS) -c $< -o $@





clean :
	rm *.exe
	rm *.o
	rm *.txt


