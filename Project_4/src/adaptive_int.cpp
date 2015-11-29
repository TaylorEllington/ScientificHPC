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

	//cout << b << " " << a << endl;

	//set starting conditions
	starting_n = n = 10;
	K = 70;
	
	//perfrom initial calcuation
	R_approx = composite_int(f,  a,  b,  starting_n);
	Ntot = n;
 	//cout << "------------------" << endl;
	//check error
	I_approx = composite_int(f,  a,  b,  starting_n + K);
	Ntot  += (starting_n+ K);
	error = fabs(I_approx - R_approx);
	//cout << I_approx << "   " << R_approx << endl;
	bound = (rtol*fabs(I_approx)) + atol;
	
	

	//if within bounds, done
	if( (error) < (bound) ){
		R = R_approx;
		return 0;
	} else {
	//if not, calcualte "good" step size based on convergence rate
		double h, c, h_better, n_better;

		h = (b-a)/starting_n;
		//cout << b << " " << a << " " << error << endl;
		c = (pow(h, 8.0))/error;

		h_better = ( pow( (bound/c), (1.0/8.0) ) );

		n_better = n + (b-a)/h_better;

		//cout << c << endl;
		R_approx = composite_int(f, a, b, ceil(n_better));

		
		R = R_approx;
		n = ceil(n_better);
		Ntot += n;



	}
	return 0;
}


/*int adaptive_int(Fcn& f, const double a, const double b, const double rtol,
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

}*/