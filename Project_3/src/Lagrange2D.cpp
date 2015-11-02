/*
	Taylor Ellington       
 	Lagrange2D.cpp      
 	11/2/2015              
*/

#include "matrix.hpp"


/*
double Lagrange_basis(int i, int j, int a, int b){
	double result = 0.0;

	if(i == a && j == b)
		result = 1.0;

	return result;
}
*/

double Lagrange_basis(Matrix& x, int i, double z);



double Lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b){

	double result = 0.0;

	for(int i = 0; i < x.Size(); i++){
		for(int j = 0; j < y.Size(); j++){
			result += ( f(i,j) * (Lagrange_basis(x, i, a) * Lagrange_basis(y, j, b) ) );
		}
	}

	return result;
}