#include "nest.hpp"
#include "matrix.hpp"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;

int main(int argc, char * argv[]){

  



	//create row vector z, from -3 to 3
    Matrix z =Linspace(-3, 3, 1, 600);

    //create vector of coeficents for taylor polynimial for cos x

    double coeff_temp[13] = {
    	1,
		0,
 		-0.5,
  		0,
   		0.04166666666666666666666666,
   		0,
   		-0.00138888888888888888888888,
    	0, 
		0.0000248015873015873015873015873015873015873015873015,
 		0,
  		-0.000000027557319223985890652,
   		0,
    	0.0000000020876756987868098979210090321201432312543423654534765645};

  
    //compute p4
    Matrix coeff4(1, 4, coeff_temp);
    Matrix  p4(z.Size());
    for(int i = 0; i < 600; i++){
    	p4(i) =  nest(coeff4, z(i));
    }
   
    //compute p8
    Matrix coeff8(1, 8, coeff_temp);
    Matrix  p8(z.Size());
    for(int i = 0; i < 600; i++){
    	p8(i) = nest(coeff8, z(i));
    }
  
    //compute p12
    Matrix coeff12(1, 12, coeff_temp);
    Matrix  p12(z.Size());
    for(int i = 0; i < 600; i++){
    	p12(i) =  nest(coeff12, z(i));
    }
    
    //compute f
    Matrix  f(z.Size());
    for(int i = 0; i < 600; i++){
    	f(i) = cos( z(i) );
    }

    //compute err4
    Matrix  err4(z.Size());
    for(int i = 0; i < 600; i++){
    	err4(i) = abs(f(i) - p4(i));
    }
    //compute err8
    Matrix  err8(z.Size());
    for(int i = 0; i < 600; i++){
    	err8(i) = abs(f(i) - p8(i));
    }
    //compute err12
    Matrix  err12(z.Size());
    for(int i = 0; i < 600; i++){
    	err12(i) = abs(f(i) - p12(i));
    }
    z.Write("z.txt");
    p4.Write("p4.txt");
    p8.Write("p8.txt");
    p12.Write("p12.txt");
    f.Write("f.txt");
    err4.Write("err4.txt");
    err8.Write("err8.txt");
    err12.Write("err12.txt");



 

	return 0;
}