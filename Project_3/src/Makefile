###################################################################
#  
###################################################################

# compiler & flags
CXX = g++
CXXFLAGS = -O -std=c++11
#CXXFLAGS = -O0 -g -std=c++11

# makefile targets
all : test_Newton.exe  
	

test_Newton.exe : test_Newton.cpp  matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@

compare.exe : compare.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@


Newton_interpolant.o : Newton_interpolant.cpp  matrix.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

matrix.o : matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@




clean :
	\rm -f *.o *.out *.txt



####### End of Makefile #######