#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "LinearSystemSolver.h"

LinearSystemSolver::LinearSystemSolver(){

}

LinearSystemSolver::~LinearSystemSolver(){


}

Vector* LinearSystemSolver::naiveGaussian(Matrix* A, Vector* b){
	int n = A->numColumns();
    	//Matrix* Ab = augment(A,b);
	double entry = 0.0;	
	Vector* x = new Vector();
	x = b;
	for(int k = 1; k <= n - 1; k++){
		for(int i = k + 1; i <= n; i++){
			for(int j = k; j <= n; j++){
				//entry = Ab->operator()(i,j) - (Ab->operator()(i,k)/Ab->operator()(k,k)) * Ab->operator()(k,j);
				entry = A->operator()(i,j) - (A->operator()(i,k)/A->operator()(k,k)) * A->operator()(k,j);
				//Ab->set(i,j,entry);
				A->set(i,j,entry);
			}
			//entry = Ab->operator()(i,n+1) - (Ab->operator()(i,k)/Ab->operator()(k,k))*Ab->operator()(k,n+1);
			entry = x->operator[](i - 1) - (A->operator()(i,k)/A->operator()(k,k))*b->operator[](k - 1);
			//Ab->set(i,n+1,entry);
			x->set(i - 1, entry);
			A->printMatrix();
			x->printVector();
			std::cout << std::endl << std::endl;
		}
	}
	return x;

}

Matrix* LinearSystemSolver::lowerTriangular(Matrix* A){

	return NULL;
}

Matrix* LinearSystemSolver::upperTriangular(Matrix* A){
	return NULL;

}

Matrix* LinearSystemSolver::augment(Matrix* A, Vector* b){
	int m = A->numRows();
	int n = A->numColumns();
	Matrix* Ab = new Matrix(m,n + 1);
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			Ab->set(i,j,A->operator()(i,j));
		}
		Ab->set(i,n+1,b->operator[](i-1));
	}
	return Ab;

}
