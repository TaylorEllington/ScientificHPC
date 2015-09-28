#include "matrix.hpp"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;

double f(double a){
	return ( pow(a, -3) );
}

double fPrime(double a){
	return ( -3 * ( pow(a, -4 ) ) );
}

double fDoublePrime(double a){
	return (12 * ( pow(a, -5) ) );
}

int main(int argc, char* argv[] ) {

	//SETUP
	//Make row vector with increments 1...52, Delta = 1.0
	Matrix n = Linspace(1, 52, 1 , 52 );
	Matrix h( n.Size() );
	Matrix r( n.Size() );
	Matrix R( n.Size() );
	for(int i = 0; i < n.Size(); i++){
		h(i) = pow(2, (-1*n(i) ) );
	}

	double forwardFiniteDifference;
	double c1 = abs((fDoublePrime(3))/( 2* fPrime(3)));
	double c2 = abs(  (f(3) * pow(2, -52) ) / (fPrime(3) )   );
	for(int i = 0; i < n.Size(); i++){
		forwardFiniteDifference = (f(3 + h(i)) - f(3) )/ h(i);


		r(i) = abs(  (fPrime(3) - forwardFiniteDifference) / ( fPrime(3) ) );

		R(i) = (c1 * h(i) ) + (c2 / h(i) );

	}

	n.Write("n.txt");
	h.Write("h.txt");
	r.Write("r.txt");
	R.Write("R.txt");

}