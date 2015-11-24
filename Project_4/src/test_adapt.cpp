/*
*   Taylor Ellington
*   test_adapt.cpp
*   11/10/2015
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "fcn.hpp"

using namespace std;



int adaptive_int(Fcn& f, const double a, const double b, const double rtol,
                     const double atol, double& R, int& n, int& Ntot);



   
class fcn : public Fcn {
public:
  double c, d;
  double operator()(double x) {   // function evaluation
    return (exp(c*x) + sin(d*x));
  }
  double antiderivative(double x) { // function evaluation
    return (exp(c*x)/c - cos(d*x)/d);
  }
};



int main(int argc, char** argv){

  // limits of integration
  double a = -3.0;
  double b = 5.0;
  

  // integrand
  fcn f;
  f.c = 0.5;
  f.d = 25.0;

  double Itrue = f.antiderivative(b) - f.antiderivative(a);
  printf("\n True Integral = %22.16e\n", Itrue);

  vector<double> r_tolerances = {1e-2, 1e-4, 1e-6,1e-8, 1e-10, 1e-12};
  vector<double> a_tolerances = {1e-2/1000, 1e-4/1000, 1e-6/1000,1e-8/1000, 1e-10/1000, 1e-12/1000};
  double R, relError, errorBound;
  int n, Ntot, success;

  cout << "\n Adaptive approximation:\n";
  cout << "     R(f)                 |I(f) - R(f)|    rtol|I(f)| + atol         n     Ntot\n";
  cout << "  ------------------------------------------------------------------------------\n";



  for (int i = 0 ; i < r_tolerances.size(); i++ ){
  	
    success = adaptive_int(f, a, b, r_tolerances[i], a_tolerances[i], R,  n, Ntot);
    relError = fabs(Itrue - R);
    errorBound = (r_tolerances[i]*Itrue) + a_tolerances[i];
     printf("  %22.16e  %7.1e          %7.1e               %6i  %6i\n", R, relError, errorBound, n, Ntot);
  }


  cout << "  ------------------------------------------------------------------------------\n";
	return 0;
}