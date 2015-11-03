/*
	Taylor Ellington       
 	Runge_uniform.cpp      
 	11/2/2015              
*/

#include "matrix.hpp"

#include <string>

using namespace std;


double Lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b);

int main(int argc, char ** argv){

	//n= m = 6 , 24
	int set[] = {6,24};
	string setName[] = {"p6_uni.txt", "p24_uni.txt"};

	for( int s = 0; s < 2 ; s++){
		
		//Create a set of (m + 1) evenly spaced nodes, x, over the interval [-4, 4]
		Matrix x = Linspace(-4, 4, set[s]+1, 1);

		//Create a set of (n+ 1) evenly spaced nodes, y, over the interval [-4, 4]
		Matrix y = Linspace(-4, 4, set[s]+1, 1);

		Matrix f(set[s]+1, set[s]+1 );
  		for (int j=0; j<set[s]; j++) 
    		for (int i=0; i<set[s]; i++) 
    			f(i,j) = (1) / ( (1) + ( x(i)*x(i) ) +  (y(i)*y(i)) ) ;

    	cout << y.Size() << endl;
    	cout << x.Size() << endl;
		cout << f.Size() << endl;
		//Create an array of 201 evenly spaced evaluation points, a, over the interval [-4, 4]
		Matrix a = Linspace(-4, 4, 201, 1);
		//Output this to disk as the file bvals.txt, only once
		if(s == 0)
			a.Write("avals.txt");

		//Create an array of 101 evenly spaced evaluation points, b, over the interval [-4, 4]
		Matrix b = Linspace(-4, 4, 201, 1);
		//Output this to disk as the file bvals.txt
		if(s == 0)
			b.Write("bvals.txt");

		//Use your Lagrange2D() to evaluate the polynomial interpolant p(a,b) at the 20301 evaluation points 
		Matrix p(set[s], set[s] );

		cout << set[s] << endl;
  		for (int j=0; j<set[s]; j++) 
    		for (int i=0; i<set[s]; i++){


    			p(i,j) = Lagrange2D(x, y, f, a(i), b(j));
    		}


      		

		//write to disk in a matrix p6_uni.txt or p24_uni.txt
		
		p.Write(setName[s].c_str() );
	}

	return 0;
}