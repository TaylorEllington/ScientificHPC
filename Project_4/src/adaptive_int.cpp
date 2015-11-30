/*
*   Taylor Ellington
*   adaptave_int.cpp
*   11/10/2015
*/
#include <math.h>
#include "fcn.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

double composite_int(Fcn& f, const double a, 
			const double b, const int n);



int adaptive_int(Fcn& f, const double a, const double b, const double rtol,
                     const double atol, double& R, int& n, int& Ntot){

	double I_approx, R_approx, error, bound;
	int approx_success_flag, starting_n, K;

	//set starting conditions
	starting_n = n = 10;
	K = 10;
	
	//perfrom initial calcuation
	R_approx = composite_int(f,  a,  b,  starting_n);
	Ntot = n;
 	
	//check error
	I_approx = composite_int(f,  a,  b,  starting_n + K);
	Ntot  += (starting_n+ K);
	error = fabs(I_approx - R_approx);
	
	bound = (rtol*fabs(I_approx)) + atol;
	
	

	//if within bounds, done
	if( (error) < (bound) ){
		R = R_approx;
		return 0;
	} else {
	//if not, calcualte "good" step size based on convergence rate
		double h, c, h_better, n_better;

		h = (b-a)/starting_n;
		
		c = (pow(h, 8.0))/error;

		h_better = ( pow( (bound/c), (1.0/8.0) ) );

		n_better = n + (b-a)/h_better;

		n = ceil(n_better);

		R = composite_int(f, a, b, n);

		Ntot += n;

		//check failure condition
		if( n > 10 ){
			return 0;
		}else {
			R = 0 ;
			return 1;
		}


	}
	return 0;
}


