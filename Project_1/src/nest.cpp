
#include "nest.hpp"

	double nest ( const Matrix& a, double x ){
		int size = a.Size() -1 ;
		double p = a(size);

		for( int i = size -1;  i >= 0 ; i--){
			p = a(i) + ( x*p ) ;
		}

		return p;
	}
