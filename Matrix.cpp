#include "Matrix.h"
#include <iostream>
#include <sstream>

Matrix::Matrix(){
	rows = 0;
	columns = 0;
	arrayPtr = NULL;
	int i = 0;
	std::string rowStr;
	std::cout << "Enter row " << i << ": ";
	while(getline(std::cin, rowStr)){
		if(rowStr == ""){
			break;
		}
		insertRow(rowStr);
		i++;
		std::cout << "Enter row " << i << ": ";
	}	
}

Matrix::Matrix(int rows, int columns){
	this->rows = rows;
	this->columns = columns;
	arrayPtr = NULL;
}

Matrix::~Matrix(){
	for(int i = 0; i < rows; i++){
		free(arrayPtr[i]);
	}
}

void Matrix::edit(){

}

void Matrix::operator=(const Matrix* rhs){
	this->rows = rhs->rows;
	this->columns = rhs->columns;
	free(arrayPtr);
	this->arrayPtr = rhs->arrayPtr;
	return;
}

Matrix* Matrix::operator+(const Matrix* addend){
	if(this->rows != addend->rows||this->columns != addend->columns){
		std::cout << "Error. Matrix dimensions need to be the same." << std::endl;
		return NULL;
	}
	else{
		Matrix* sum = new Matrix();
		for(int i = 0; i < addend->rows; i++){
			for(int j = 0; j < addend->columns; j++){
				//sum->insert
			}
		}
	}
}

Matrix* Matrix::operator-(const Matrix* subtrahend){

}

Matrix* Matrix::operator*(const Matrix* multiplicand){

}

Matrix* Matrix::operator*(double scalar){

}

Matrix* Matrix::operator/(double scalar){


}

void Matrix::insertRow(std::string rowStr){
	std::stringstream parser, converter;
	std::string entryStr;
	double entry;
	int n = 0;
	parser.clear();
	parser.str("");
	parser.str(rowStr);
	while(getline(parser, entryStr, ',')){
		n++;
	}	
	if(this->columns != n && rows > 0){
		std::cout << "Error: Row dimensions need to be size " << columns << "." << std::endl;
	}
	else{
		columns = n;
		rows++;
		if(arrayPtr == NULL){
			arrayPtr = (double**)malloc(sizeof(double));
		}	
		else if(arrayPtr != NULL){
			arrayPtr = (double**)realloc(arrayPtr, rows*sizeof(double));
		}
		arrayPtr[rows - 1] = (double*)malloc(columns*sizeof(double));
		int j = 0;
		parser.clear();
		parser.str("");
		parser.str(rowStr);
		while(getline(parser, entryStr, ',')){
			converter.clear();
			converter.str("");
			converter << entryStr;
			converter >> entry;
			arrayPtr[rows - 1][j] = entry;
			j++;
		}	
	}
}

Matrix* Matrix::inverse(){

}

bool Matrix::isSquare(){

}

double Matrix::determinant(){

}

double Matrix::trace(){

}

void Matrix::transpose(){

}

Matrix* Matrix::RREF(){

}

void Matrix::printMatrix(){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			std::cout << "[" << arrayPtr[i][j] << "]";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}



