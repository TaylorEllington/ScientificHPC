#include "matrix.hpp"
#include "Fcn.cpp"
#include "newton.cpp"
#include <math.h>
#include <stdio.h>
class F: public  Fcn{

	double t = 0; // supress warnings
	double e = 0;
public:
	double operator() (double x){
	   return  e *sin(x) - x - t;
	}
	void  setT(double t){
		this->t = t;
	}
	void solveE(double a, double b){
		e = sqrt(  1 - ( (b*b) / (a*a) )  );
	}

};

class FD: public Fcn{

	double t = 0; // supress warnings
	double e = 0;
public:
	double operator() (double x){
	   return  e * cos(x) - 1; 
	}
	void  setT(double t){
		this->t = t;
	}
	void solveE(double a, double b){
		e = sqrt(  1 - ( (b*b) / (a*a) )  );
	}

};

double radialPosition( double a, double b, double w){

	return (a * b) / sqrt ( (b*cos(w) )*(b*cos(w)) + ( a* sin(w))*(a* sin(w))  );
}

int main(int argc, char * argv[]){
	double time_min = 0;
	double time_max  = 10;

	F f;
	FD fd;

	f.solveE(2.0, 1.25);
	fd.solveE(2.0, 1.25);

	Matrix t = Linspace(time_min, time_max, 1, 10000);
	Matrix x(t.Size() );
	Matrix y(t.Size() );

	double w = 0;
	double rw = 0;
	
	for(int i = 0; i < t.Size() ; i++){

		f.setT( t(i) );
		fd.setT( t(i) );

		w = newton(f,fd, w, 6, 1e-5, false);
		rw = radialPosition(2.0, 1.25, w);
		x(i) = rw * cos(w);
		y(i) = rw * sin(w);

	}

	t.Write("t.txt");
	x.Write("x.txt");
	y.Write("y.txt");


	return 0;
}