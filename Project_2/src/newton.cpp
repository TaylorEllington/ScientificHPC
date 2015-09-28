double  newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates){

	double H;
	double X_K = x;	

	for(int i = 0; i < maxit; i++){
		H = f(X_K) / df(X_K)
		X_K_1 = X_K - H;

		if( fabs( X_K_1  - X_K ) < tol)
			break;

	}



}