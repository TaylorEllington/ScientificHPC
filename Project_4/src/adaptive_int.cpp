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
	


	int n_temp, Ntot_temp, problem_condition;

	double R_approx, I_approx, error, bound;

	bool working = true; 
	n_temp = 5;
	Ntot_temp = 0;

	while( working == true){

		R_approx = composite_int(f,  a,  b,  n_temp);
		I_approx = composite_int(f,  a,  b,  n_temp+100);


		error = fabs(I_approx - R_approx);
		bound = (rtol*fabs(I_approx)) + atol;

		
		Ntot_temp += n_temp;
		if(n_temp > 330){
			working = false;
			problem_condition = 1;

		} else if((error) < (bound)){
			working = false;
			problem_condition = 0;

		} else {
			n_temp += 5;
		}

	}

	n =  n_temp;
	Ntot = Ntot_temp;
   	R = R_approx;

	return problem_condition;

}