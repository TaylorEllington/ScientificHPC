

#include "fcn.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double  newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates){

	double H;
	double X_K = x;	
	double X_K_1;

	for(int i = 0; i < maxit; i++){
		H = f(X_K) / df(X_K);
		X_K_1 = X_K - H;

		if(show_iterates)
		cout << "\t" << i << " - Current Guess: " << X_K <<
			" Solution update magniutde: " << fabs(H) << " Residual: " << f(X_K) << endl;

		if( fabs( X_K_1  - X_K ) < tol){
			if(show_iterates)
				cout << "\t Tolerance Reached" << endl;
			
			break;
		}

		if(  i == maxit-1 && show_iterates == true )
			cout << "\t Max iterations reached" << endl;

		X_K = X_K_1;

	}

	return X_K;

}