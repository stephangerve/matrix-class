#include "Matrix.h"
#include "Vector.h"
#include "LinearSystemSolver.h"
#include <iostream>

int main(){
	Matrix* A = new Matrix();
	std::string vectorStr;
	A->printMatrix();
	std::cout << "b = ";
	getline(std::cin, vectorStr);
	Vector* b = new Vector(vectorStr);
	b->printVector();
	LinearSystemSolver* LSS = new LinearSystemSolver();
	Vector* x = LSS->naiveGaussian(A,b);
	std::cout << "x = ";
	x->printVector();

	//std::cout << "m1(" << m1->numRows() - 1 << "," << m1->numColumns() - 1 << ") = " << m1->operator()(m1->numRows()-1, m1->numColumns()-1) << std::endl;
	//std::cout << "m1 is square: " << m1->isSquare() << std::endl;
	//std::cout << "m1 transpose: " << std::endl;
	//m1->transpose();
	//m1->printMatrix();
	//std::cout << "m1 rref: " << std::endl;
	//m1->RREF();
	//m1->printMatrix();
	/*for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			std::cout << "m1(" << i + 1 << "," << j + 1 << ") = " << m1->operator()(i+1,j+1) << std::endl;
		}
	}*/
	delete A;
	delete b;
	delete x;


}
