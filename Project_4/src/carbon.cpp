/*
*   Taylor Ellington
*   carbon.cpp
*   11/10/2015
*/

#include "Fcn.cpp"
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

	return 6.2e-7 * (exp(  -((8e4)/(8.31*T)) ));
}


double erf(const double y, const double rtol, const double atol){
	
	fcn5 f;
	double a, b, R;
	int n, Ntot;


	a = 0;
	b = y;
	//cout << y << endl;
	int success = adaptive_int( f, a, b, rtol, atol, R, n, Ntot);

	//cout <<  (2.0/sqrt(M_PI)) << endl;


	return (2.0/sqrt(M_PI)) * R;
}

double carbon(const double x, const double t, const double T,
	          const double rtol, const double atol){
	

	double d = D(T);
	//cout << d << endl;
	double y = x/ (sqrt(4.0*t*d));
	//cout << y << endl;
	double ERF = erf(y, rtol, atol); 
	//cout << ERF << endl;

	return 0.02 -(0.02-0.001)*ERF;
}