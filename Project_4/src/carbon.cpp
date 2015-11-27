/*
*   Taylor Ellington
*   carbon.cpp
*   11/10/2015
*/
int adaptive_int(Fcn& f, const double a, const double b, const double rtol,
                     const double atol, double& R, int& n, int& Ntot);

class fcn5 : public Fcn {
public:
  double operator()(double x) {   // function evaluation
    return exp(pow(-x, 2));
  }

};

double D(double T){

	return 6.2e-7 * (exp(  (-8e4)/(8.31*T) ));
}


double erf(const double y, const double rtol, const double atol){
	
	fcn5 f;
	double a, b, R;
	int n, Ntot;


	a = 0;
	b = y;
	int success = adaptive_int( f, a, b, rotl, atol, R, n, Ntot);


	return (2/sqrt(PI)) * R;
}

double carbon(const double x, const double t, const double T,
	          const double rtol, const double atol){
	

	double d = D(T);

	double y = x/ (sqrt(4*t*d));

	double ERF = erf(y, rtol, atol);


	return 0.02 -(0.02-0.001)*ERF;
}