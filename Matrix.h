#ifndef MATRIX_H_EXISTS
#define MATRIX_H_EXISTS

#include <iostream>

class Matrix{
	private:
		int rows, columns;
		double **arrayPtr;
		
	public:
		Matrix();	
		Matrix(int, int);
		~Matrix();
		void edit();
		void operator=(const Matrix*);
		Matrix* operator+(const Matrix*);
		Matrix* operator-(const Matrix*);
		Matrix* operator*(const Matrix*);
		Matrix* operator*(double);
		Matrix* operator/(double);
		void insertRow(std::string);
		Matrix* inverse();
		bool isSquare();
		double determinant();
		double trace();
		void transpose();
		Matrix* RREF();		
		void printMatrix();
		


};

#endif
