/*
*   Taylor Ellington
*   application.cpp
*   11/10/2015
*/

#include "fcn.hpp"
#include <math.h>
#include <iostream>

using namespace std;

double  fd_newton(Fcn& f, double x, int maxit, double tol, double alpha,  bool show_iterates);
double carbon(const double x, const double t, const double T, const double rtol, const double atol);
int adaptive_int(Fcn& f, const double a, const double b, const double rtol,  const double atol, double& R, int& n, int& Ntot);


class carbon_root_finding: public Fcn{
public:
	 double operator()(double x) {
   // root finding funciton for carbon concentration 
    return (carbon(0.003, 129600, x, 1e-14, 1e-15) - 0.006);
  }

};

int main(int argc, char** argv){
	// setup
	carbon_root_finding f;

	//starting guess  from part 3 data
	double starting_x = 970;

	//output some feedback for console
	printf("\n--------------------Solve For T,  C(0.003, 129600, T) = 0.006---------------------\n");
	printf("  Calling fd_newton(f, %f ,50, 1e-4, pow(2, -20), false)                               \n", starting_x);
	printf("  where f = carbon(0.003, 129600, T, 1e-14, 1e-15) - 0.006                          \n");
	
	//run fd_newton on problem
	double result = fd_newton(f, starting_x, 50, 1e-4, pow(2, -20), false);

	//check that result gives desired carbon content
	double carbonConcentration = carbon(0.003, 129600, result, 1e-14, 1e-15);

	//output results to the terminal
	printf("------------------------------------------------------------------------------------\n");
	printf("\tRoot Solved Temprature for given conditions : %f K\n", result);
	printf("\tCarbon Concentration at Projected Temprature: %f \n", carbonConcentration);
	printf("------------------------------------------------------------------------------------\n");



return 0;
}