#ifndef H_NEWTON_INTERPOLANT
#define H_NEWTON_INTERPOLANT
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "matrix.hpp"

using namespace std;


Matrix Newton_coefficients(Matrix& x, Matrix& y);
double Newton_evaluate(Matrix& x, Matrix& c, double z);

#endif