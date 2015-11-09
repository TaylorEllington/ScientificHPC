#include "fd_newton.cpp"
#include "Fcn.cpp"
#include <iostream>

using namespace std;

class F : public Fcn
{ 

	double operator() (double x){
	   return  x * ( x - 3) * (x + 1); 
	}

};


int main(int argc, char * argv[]){



	F f;
	double x[] = {-2.0, 1.0, 2.0};
	double tol[] = {1e-1, 1e-5, 1e-9};
	double alpha[] = {pow(2, -4), pow(2, -26), pow(2, -50)};
	int maxit =  20;
	bool show_iterates =  true;

	cout << "test" << endl;

	//run every permutation
	for(int i = 0; i < 3; i++){
		for( int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				cout << "Experement with X: " << x[i] <<" Alpha: "<< alpha[k] << ",  and tolerance: "<< tol[j] << endl;
				cout << "\t==result:" <<  fd_newton(f, x[i], maxit, tol[j], alpha[k], show_iterates) << endl;
			}
		}
 	}

 		return 0;

}