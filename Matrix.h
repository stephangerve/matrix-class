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
		double operator()(int, int);
		int numRows();
		int numColumns();
		void insertRow(std::string);
		Matrix* inverse();
		bool isSquare();
		bool isEmpty();
		double determinant();
		double trace();
		void transpose();
		void RREF();		
		void printMatrix();
		


};

#endif
