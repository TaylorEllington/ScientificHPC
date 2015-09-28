###############################################################################
# Project 2 Makefile
# 
# Taylor Ellington
# Scientific HPC
# Fall 2015
###############################################################################

# compiler & flags
CXX = g++
CXXFLAGS = -O -std=c++11
###################################

All : test_newton.exe test_fd_newton.exe kepler.exe

test_newton.exe :test_newton.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_fd_newton.exe : test_fd_newton.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

kepler.exe : kepler.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

newton.o : newton.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fd_newton.o : fd_newton.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@





clean :
	rm *.exe
	rm *.o
	rm *.txt
