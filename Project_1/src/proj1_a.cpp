#include "nest.hpp"
#include "matrix.hpp"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

    Matrix mat("1, 2 , 3 , 4");
    

	double derp = nest( mat , 4.0 );
	cout<< derp;

	return 0;
}