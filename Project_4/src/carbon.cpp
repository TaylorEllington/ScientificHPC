/*
*   Taylor Ellington
*   carbon.cpp
*   11/10/2015
*/

#include "fcn.hpp"
#include <math.h>
#include <iostream>

using namespace std;

int adaptive_int(Fcn& f, const double a, const double b, const double rtol,
                     const double atol, double& R, int& n, int& Ntot);

class fcn5 : public Fcn {
public:
  double operator()(double x) {
   // function evaluation
    return exp(-pow((x), 2));
  }

};

double D(double T){
	//temprature dependant coefficent, seperated out for readablility
	return 6.2e-7 * (exp(  -((8e4)/(8.31*T)) ));
}


double erf(const double y, const double rtol, const double atol){
	//Error function, uses adaptive_int 

	fcn5 f;
	double a, b, R;
	int n, Ntot;

	//setup conditions
	a = 0;
	b = y;

	//solve, catch errors in adaptive int
	int success = adaptive_int( f, a, b, rtol, atol, R, n, Ntot);

	if(success == 1 ){
		cerr << "Error: adaptive_int call in carbon.erf failed with conditions a= " 
		<< a << " b= " << b << " rtol= " << rtol << "atol= " << atol << " n= " << n << endl;
	}

	return (2.0/sqrt(M_PI)) * R;
}

double carbon(const double x, const double t, const double T,
	          const double rtol, const double atol){
	

	double d = D(T);
	
	double y = x/ (sqrt(4.0*t*d));
	
	double ERF = erf(y, rtol, atol); 
	
	return 0.02 -(0.02-0.001)*ERF;
}