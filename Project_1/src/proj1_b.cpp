#include "matrix.hpp"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;

int main(int argc, char* argv[] ) {

	//SETUP
	//Make row vector with increments 1...52, Delta = 1.0
	Matrix n = Linspace(1, 52, 1 , 52 );
	Matrix h( n.Size() );
	for(int i = 0; i < n.Size(); i++){
		h(i) = pow(2, (-1*n(i) ) );
	}
	double u_1, u_2;
	u_1 = pow(2, -52) / 2 ;	
	cout << u_1 << endl;
}