/*
	Taylor Ellington       
 	Lagrange2D.cpp      
 	11/2/2015              
*/


#ifndef LAGRANGE_2D
#define LAGRANGE_2D 	

#include "matrix.hpp"

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

#endif