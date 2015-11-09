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
	string xName[] = {"p6_uni_x.txt", "p24_uni_x.txt"};
	string yName[] = {"p6_uni_y.txt", "p24_uni_y.txt"};

	for( int s = 0; s < 2 ; s++){
		
		//Create a set of (m + 1) evenly spaced nodes, x, over the interval [-4, 4]
		Matrix x = Linspace(-4, 4, set[s]+1, 1);
		x.Write(xName[s].c_str() );

		//Create a set of (n+ 1) evenly spaced nodes, y, over the interval [-4, 4]
		Matrix y = Linspace(-4, 4, set[s]+1, 1);
		y.Write(yName[s].c_str() );

		Matrix f(set[s]+1, set[s]+1 );
  		for (int j=0; j<set[s]; j++) 
    		for (int i=0; i<set[s]; i++) 
    			f(i,j) = (1) / ( (1) + ( x(i)*x(i) ) +  (y(i)*y(i)) ) ;

		//Create an array of 201 evenly spaced evaluation points, a, over the interval [-4, 4]
		Matrix a = Linspace(-4, 4, 201, 1);
		//Output this to disk as the file bvals.txt, only once
		if(s == 0)
			a.Write("avals.txt");

		//Create an array of 101 evenly spaced evaluation points, b, over the interval [-4, 4]
		Matrix b = Linspace(-4, 4, 101, 1);
		//Output this to disk as the file bvals.txt
		if(s == 0)
			b.Write("bvals.txt");

		//Use your Lagrange2D() to evaluate the polynomial interpolant p(a,b) at the 20301 evaluation points 
		Matrix p(a.Size(), b.Size() );
		

  		for (int j=0; j<b.Size(); j++) 
    		for (int i=0; i<a.Size(); i++){
    			p(i,j) = Lagrange2D(x, y, f, a(i), b(j));
    		}

		//write to disk in a matrix p6_uni.txt or p24_uni.txt
		
		p.Write(setName[s].c_str() );
	}

	return 0;
}