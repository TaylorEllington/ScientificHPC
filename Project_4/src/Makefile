###################################################################
#  Makefile for project 4
#
#  Taylor Ellington
#  22 November 2015
###################################################################

# compiler & flags
CXX = g++
CXXFLAGS = -O2 -std=c++11

# makefile targets
all : test_int.exe test_adapt.exe test_carbon.exe application.exe

test_int.exe : test_int.cpp composite_int.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_adapt.exe : test_adapt.cpp adaptive_int.cpp composite_int.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_carbon.exe : test_carbon.cpp adaptive_int.cpp composite_int.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

application.exe : application.cpp carbon.cpp adaptive_int.cpp composite_int.cpp fd_newton.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######
