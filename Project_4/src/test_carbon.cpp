/*
*   Taylor Ellington
*   test_carbon.cpp
*   11/10/2015
*/

#include "matrix.hpp"


int main(int argc, char** argv){
	// Create an array of 400 evenly-spaced T values over the
	// interval[800,1200] K. Output this to disk as the file
	// Temp.txt
	Matrix T_values = Linspace(800, 1200, 400, 1);

	// Create an array of 600 evenly-spaced t values over the
	// interval[0,48] K. Output this to disk as the file
	// temp.txt

	// Create a 400 x 600 array that contains C(0.002,t,T).
	// Output this to disk as the file C2mm.txt

	// Create a 400 x 600 array that contains C(0.004,t,T).
	// Output this to disk as the file C4mm.txt

	// Create an array of length 600 containing C(0.002,t,800)
	// Output to disk as the file C2mm_800K.txt . Repeat this
	// to output the carbon concentrations for 2mm depth at
	// 900K (C2mm_900K.txt), 1000K (C2mm_1000K.txt),
	// 1100K (C2mm_24hour.txt), 1200K (C2mm_1200K.txt)

	// Create an array of length 600 containing C(0.004,t,800)
	// Output to disk as the file C4mm_800K.txt . Repeat this
	// to output the carbon concentrations for 2mm depth at
	// 900K (C4mm_900K.txt), 1000K (C4mm_1000K.txt),
	// 1100K (C4mm_24hour.txt), 1200K (C4mm_1200K.txt)




	return 0;
}