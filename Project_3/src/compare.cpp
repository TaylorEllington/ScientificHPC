#include "Newton_interpolant.cpp"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "matrix.hpp"
#include "Lagrange.cpp"

#include <chrono>

using namespace std;
using namespace std::chrono;


int main(int argc, char* argv[]) {

	//define test sets
	int n[] = {10, 20, 40, 80};
	int m[] = {100, 1000, 10000, 10000};

	//test all permutations of sets
	for(int n_it = 0; n_it < 4; n_it++){
		for(int m_it = 0; m_it < 4; m_it++){

			cout << "Experiment with n = " << n[n_it] << ", m = " << m[m_it] << endl;

			//create a set of (n+1) evenly spaced nodes over [-2, 2]
			Matrix nodes = Linspace(-2, 2, (n[n_it] + 1) );

			//create the set of function data values y = cosh(x^2 / 3)
			Matrix y( nodes.Size() );
			for(int iterator = 0; iterator < y.Size() ; iterator++)
				y(iterator) = cosh (  (nodes(iterator) * nodes(iterator) ) / 3 );
			
			//create a set of (m_1) evenly spaced evaluation points over [-2,2]
			Matrix z = Linspace(-2, 2, (m[m_it]+1) );

			high_resolution_clock::time_point start_Lagrange, stop_Lagrange, start_Newton, stop_Newton;

			
			//measure and output the time it takes to evalute p(z) using Lagrange()
			start_Lagrange = high_resolution_clock::now();

			for(int iterator = 0; iterator < z.Size(); iterator++)
			 	Lagrange(nodes, y, z(iterator) );

			stop_Lagrange = high_resolution_clock::now();

			//measure and ouput the time it takes to construct coefficents c, and evalutate p(z) using newton methods
			start_Newton = high_resolution_clock::now();

			Matrix c = Newton_coefficients(nodes, y);

			for(int iterator = 0; iterator < z.Size(); iterator++)
				Newton_evaluate(nodes ,c , z(iterator) );

			stop_Newton = high_resolution_clock::now();

			auto duration_Lagrange = std::chrono::duration_cast<std::chrono::microseconds>(stop_Lagrange - start_Lagrange).count();
			auto duration_Newton = std::chrono::duration_cast<std::chrono::microseconds>(stop_Newton - start_Newton).count();

			cout  << "\tLagrange: " << duration_Lagrange << ", Newton: " << duration_Newton << endl;
		}
	}



return 0;
}