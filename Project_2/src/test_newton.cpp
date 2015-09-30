#include "newton.cpp"
#include "Fcn.cpp"
#include <iostream>

using namespace std;

class F : public Fcn
{ 

	double operator() (double x){
	   return  x * ( x - 3) * (x + 1); 
	}

};

class FD : public Fcn
{ 

	double operator() (double x){
	   return  3*x*x - 4 * x - 3; 
	}

};



int main(int argc, char * argv[]){



	F f;
	FD fd;
	double x[] = {-2.0, 1.0, 2.0};
	double tol[] = {1e-1, 1e-5, 1e-9};
	int maxit =  15;
	bool show_iterates =  true;

	cout << "test" << endl;

	//run every permutation
	for(int i = 0; i < 3; i++){
		for( int j = 0; j < 3; j++){
			cout << "Experement with X: " << x[i] << ",  and tolerance: "<< tol[j] << endl;
			cout << "\tresult:" <<  newton(f, fd, x[i], maxit, tol[j], show_iterates) << endl;
		}
 	}

 		return 0;

}