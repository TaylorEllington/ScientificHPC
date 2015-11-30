/*
*   Taylor Ellington
*   test_carbon.cpp
*   11/10/2015
*/

#include "matrix.hpp"
#include "carbon.cpp"


int main(int argc, char** argv){

	//Setup tolerances for experiments
	double rtol, atol;
	rtol = 1e-11;
	atol = 1e-15;


	// Create an array of 400 evenly-spaced T values over the
	// interval[800,1200] K. Output this to disk as the file
	// Temp.txt
	Matrix T_values = Linspace(800, 1200, 400, 1);
	T_values.Write("Temp.txt");

	// Create an array of 600 evenly-spaced t values over the
	// interval[1 sec,48 hours] K. Output this to disk as the file
	// temp.txt
	Matrix t_values = Linspace(1, 172800, 600, 1);
	t_values.Write("time.txt");

	// Create a 400 x 600 array that contains C(0.002,t,T).
	// Output this to disk as the file C2mm.txt

	//carbon(0.002, t_values(300), T_values(45), rtol, atol);

	Matrix C2MM(400, 600);
	for(int i  = 0 ; i < T_values.Size();  i++){
		for(int j = 0; j < t_values.Size(); j++){

			C2MM(i, j) =
			 carbon( 0.002, t_values(j), T_values(i), rtol, atol);
		}
	}
	C2MM.Write("C2mm.txt");

	// Create a 400 x 600 array that contains C(0.004,t,T).
	// Output this to disk as the file C4mm.txt

	Matrix C4MM(400, 600);
	for(int i  = 0 ; i < T_values.Size();  i++){
		for(int j = 0; j < t_values.Size(); j++){

			C4MM(i, j) =
			 carbon( 0.004, t_values(j), T_values(i), rtol, atol);
		}
	}
	C4MM.Write("C4mm.txt");

	// Create an array of length 600 containing C(0.002,t,800)
	// Output to disk as the file C2mm_800K.txt . Repeat this
	// to output the carbon concentrations for 2mm depth at
	// 900K (C2mm_900K.txt), 1000K (C2mm_1000K.txt),
	// 1100K (C2mm_24hour.txt), 1200K (C2mm_1200K.txt)
	Matrix C2mm_800K(600);
	Matrix C2mm_900K(600);
	Matrix C2mm_1000K(600);
	Matrix C2mm_1100K(600);
	Matrix C2mm_1200K(600);

	for(int i =0 ;  i < 600 ; i++){
		C2mm_800K(i) =  carbon(0.002, t_values(i), 800, rtol, atol);
		C2mm_900K(i) =  carbon(0.002, t_values(i), 900, rtol, atol);
		C2mm_1000K(i) =  carbon(0.002, t_values(i), 1000, rtol, atol);
		C2mm_1100K(i) =  carbon(0.002, t_values(i), 1100, rtol, atol);
		C2mm_1200K(i) =  carbon(0.002, t_values(i), 1200, rtol, atol);
	} 

	C2mm_800K.Write("C2mm_800K.txt");
	C2mm_900K.Write("C2mm_900K.txt");
	C2mm_1000K.Write("C2mm_1000K.txt");
	C2mm_1100K.Write("C2mm_24hour.txt");
	C2mm_1200K.Write("C2mm_1200K.txt");

	// Create an array of length 600 containing C(0.004,t,800)
	// Output to disk as the file C4mm_800K.txt . Repeat this
	// to output the carbon concentrations for 2mm depth at
	// 900K (C4mm_900K.txt), 1000K (C4mm_1000K.txt),
	// 1100K (C4mm_1100K.txt), 1200K (C4mm_1200K.txt)

	Matrix C4mm_800K(600);
	Matrix C4mm_900K(600);
	Matrix C4mm_1000K(600);
	Matrix C4mm_1100K(600);
	Matrix C4mm_1200K(600);

	for(int i =0 ;  i < 600 ; i++){
		C4mm_800K(i) =  carbon(0.004, t_values(i), 800, rtol, atol);
		C4mm_900K(i) =  carbon(0.004, t_values(i), 900, rtol, atol);
		C4mm_1000K(i) =  carbon(0.004, t_values(i), 1000, rtol, atol);
		C4mm_1100K(i) =  carbon(0.004, t_values(i), 1100, rtol, atol);
		C4mm_1200K(i) =  carbon(0.004, t_values(i), 1200, rtol, atol);
	}

	C4mm_800K.Write("C4mm_800K.txt");
	C4mm_900K.Write("C4mm_900K.txt");
	C4mm_1000K.Write("C4mm_1000K.txt");
	C4mm_1100K.Write("C4mm_1100K.txt");
	C4mm_1200K.Write("C4mm_1200K.txt");

	return 0;
}