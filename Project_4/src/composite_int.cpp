/*
*   Taylor Ellington
*   composite_int.cpp
*   11/10/2015
*/
// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "fcn.hpp"

using namespace std;

// This routine numerically approximates the integral
//    int_a^b fun(x) dx
// using the composite Gaussian quadrature rule with 2 points per 
// subinterval (i.e. O(h^4) accurate), over n subintervals.  We 
// require that fun have the calling syntax 
//    y = fun(x)
// where y is a double and x is a const double.
//
// Usage: F = composite_Gauss2(fun, a, b, n);
//
// inputs:   f       integrand (Fcn object)
//           a       lower limit of integration
//           b       upper limit of integration
//           n       number of subintervals
//
// outputs:  F       value of numerical integral
// 


double composite_int(Fcn& f, const double a, const double b, const int n){
	

  // check input arguments
  if (b < a) {
    cerr << "error: illegal interval, b < a\n";
    return 0.0;
  }
  if (n < 1) {
    cerr << "error: illegal number of subintervals, n < 1\n";
    return 0.0;
  }

  // set subinterval width
  double h = (b-a)/n;

  // set nodes/weights defining the quadrature method
  double x1 = -sqrt((1.0/7.0)*(3.0 - 4*sqrt(0.3))) ;
  double x2 = -sqrt((1.0/7.0)*(3.0 + 4*sqrt(0.3)));
  double x3 = sqrt((1.0/7.0)*(3.0 - 4*sqrt(0.3)));
  double x4 = sqrt((1.0/7.0)*(3.0 + 4*sqrt(0.3)));
  double w1 =  0.5 + (1.0/12.0)*sqrt(10.0/3.0);
  double w2 =  0.5 - (1.0/12.0)*sqrt(10.0/3.0);
  double w3 =  0.5 + (1.0/12.0)*sqrt(10.0/3.0);
  double w4 =  0.5 - (1.0/12.0)*sqrt(10.0/3.0);
  // initialize result
  double F = 0.0;

  // loop over subintervals, accumulating result
  double xmid, node1, node2, node3, node4;
  for (int i=0; i<n; i++) {
   
    // determine evaluation points within subinterval 
    xmid  = a + (i+0.5)*h;
    node1 = xmid + 0.5*h*x1;
    node2 = xmid + 0.5*h*x2;
    node3 = xmid + 0.5*h*x3;
    node4 = xmid + 0.5*h*x4;

    // add Gauss2 approximation on this subinterval to result
    F += w1*f(node1) + w2*f(node2) + w3*f(node3) + w4*f(node4);
    //cout << "++++" <<F << endl;
  } // end loop

  // return final result

  return (0.5*h*F);

} // end of function


