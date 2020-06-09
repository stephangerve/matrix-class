#include "Matrix.h"
#include <iostream>
#include <sstream>
#include <string.h>

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
	/*insertRow("25,5,1");
	insertRow("64,8,1");
	insertRow("144,12,1");	*/
}

Matrix::Matrix(int rows, int columns){
	this->rows = rows;
	this->columns = columns;
	arrayPtr = (double**)malloc(rows*sizeof(double));
	for(int i = 0; i < rows; i++){
		arrayPtr[i] = (double*)malloc(columns*sizeof(double));
	}
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

double Matrix::operator()(int m, int n){
	if(m <= 0 || n <= 0){
		std::cout << "Error: Invalid index." << std::endl;
		return -1;
	}
	else{
		return arrayPtr[m - 1][n - 1];
	}
}

int Matrix::numRows(){
	return rows;
}

int Matrix::numColumns(){
	return columns;
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
	if(rows == columns){
		return true;
	}
	else{
		return false;
	}
}

bool Matrix::isEmpty(){
	if(rows == 0 || columns == 0){
		return true;
	}
	else{
		return false;
	}
}

double Matrix::determinant(){
	if(this->isSquare() == false){
		std::cout << "Error: Determinants doesn't exists for non-square matrices." << std::endl;
		return -1;
	}
	else{

	}
}

double Matrix::trace(){

}

void Matrix::transpose(){
	double temp = rows;
	rows = columns;
	columns = temp;
	double** arrayPtrT = (double**)malloc(rows*sizeof(double));
	for(int i = 0; i < this->rows; i++){
		arrayPtrT[i] = (double*)malloc(columns*sizeof(double));
		for(int j = 0; j < this->columns; j++){
			arrayPtrT[i][j] = this->arrayPtr[j][i];
		}
	}
	for(int i = 0; i < temp; i++){
		free(this->arrayPtr[i]);
	}	
	this->arrayPtr = arrayPtrT;
}

/*void Matrix::RREF(){
	int n = columns;
	double xmult = 0.0;
	for(int k = 1; k <= n - 1; k++){
		for(int i = k + 1; i <= n; i++){
			//std::cout << "k = " << k << std::endl;
			//std::cout << "i = " << i << std::endl;
			//xmult = arrayPtr[i][k]/arrayPtr[k][k];
			//arrayPtr[i][k] = xmult;
			//printMatrix();
			for(int j = k; j <= n; j++){
				//std::cout << "j = " << j << std::endl;
				double entry = operator()(i,j) - (operator()(i,k)/operator()(k,k)) * operator()(k,j);
				set(i,j,entry);
				//std::cout << std::endl;
			}
		}
	}
}
*/
void Matrix::set(int m, int n, double entry){
	if(m <= 0 || n <= 0){
		std::cout << "Error: Invalid index." << std::endl;
	}
	else{
		arrayPtr[m - 1][n - 1] = entry;
	}
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



