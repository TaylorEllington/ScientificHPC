/*
   Taylor Ellington
   Newton_interpolant.cpp
   10/25/2015

*/

#include "Newton_interpolant.hpp"


Matrix Newton_coefficients(Matrix& x, Matrix& y){
	int n = x.Size();

	Matrix a( n );
    //calculates newton coefficents based on method in the book
	for(int i = 0; i < n; i++) {
		a(i) = y(i);
	}

	for(int j = 0; j < n; j++){
		for( int i = n-1 ; i > j; i--){
			a(i) = ( a(i) - a(i-1) )/( x(i) - x(i-1) );
		}
	}

	return a; 
}

double Newton_evaluate(Matrix& x, Matrix& c, double z){

	int n = x.Size();
	//evaluates newton interpolant
	double temp = c(n-1);

	for( int i = n - 1; i >= 0; i--){

		temp = (temp * ( z-x(i) ) );
		temp + c(i); 
 	}


	return temp;
}