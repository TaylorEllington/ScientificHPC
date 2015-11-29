

#include "fcn.hpp"
#include <math.h>

double  fd_newton(Fcn& f, double x, int maxit, double tol, double alpha,  bool show_iterates);
double carbon(const double x, const double t, const double T, const double rtol, const double atol);
int adaptive_int(Fcn& f, const double a, const double b, const double rtol,  const double atol, double& R, int& n, int& Ntot);


class carbon_root_finding: public Fcn{
public:
	 double operator()(double x) {
   // function evaluation
    return (carbon(0.03, 129600, x, 1e-14, 1e-15) - 0.006);
  }

};

int main(int argc, char** argv){

	carbon_root_finding f;
	double starting_x = 1100;

	double restult = fd_newton(f, starting_x, 50, 1e-4, pow(2, -20), true);


return 0;
}