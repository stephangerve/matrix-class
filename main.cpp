#include "Matrix.h"
#include <iostream>

int main(){
	Matrix* m1 = new Matrix();
	m1->printMatrix();
	std::cout << "m1(" << m1->numRows() - 1 << "," << m1->numColumns() - 1 << ") = " << m1->operator()(m1->numRows()-1, m1->numColumns()-1) << std::endl;
	std::cout << "m1 is square: " << m1->isSquare() << std::endl;
	//std::cout << "m1 transpose: " << std::endl;
	//m1->transpose();
	//m1->printMatrix();
	std::cout << "m1 rref: " << std::endl;
	m1->RREF();
	m1->printMatrix();

	delete m1;


}
