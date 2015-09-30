#include "Fcn.cpp"
#include <iostream>
#include <cmath>

using namespace std;

double ffd(Fcn& f, double x, double alpha){

	return (f(x-alpha) - f(x) ) / alpha;
}


double  fd_newton(Fcn& f, double x, int maxit, double tol, double alpha,  bool show_iterates){

	double H;
	double X_K = x;	
	double X_K_1;

	for(int i = 0; i < maxit; i++){
		H = 0 - (f(X_K) / ffd(f, X_K, alpha));
		X_K_1 = X_K - H;

		if(show_iterates)
		cout << "\t" << i << " - Current Guess: " << X_K <<
			" Solution update msagniutde: " << fabs(H) << " Residual: " << f(X_K) << endl;

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