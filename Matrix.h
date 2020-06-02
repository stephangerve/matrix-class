#ifndef MATRIX_H_EXISTS
#define MATRIX_H_EXISTS

#include <iostream>

class Matrix{
	private:
		int m, n;
		double *arrayPtr;
		
	public:
		Matrix();
		void edit();	
		void printMatrix();	
		~Matrix();


}
