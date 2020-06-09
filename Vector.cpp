#include <iostream>
#include <sstream>
#include <math.h>
#include "Vector.h"

Vector::Vector(){
	n = 0;	
}
Vector::Vector(std::string vectorStr){
	n = 0;
	std::stringstream parser, converter;
	std::string componentStr;
	double component;
	parser.clear();
	parser.str("");
	parser.str(vectorStr);
	while(getline(parser, componentStr, ',')){
		converter.clear();
		converter.str("");
		converter << componentStr;
		converter >> component;
		insert(component);		
	}
}
Vector::~Vector(){
	free(arrayPtr);
}

void Vector::operator=(const Vector* rhs){
	this->n = rhs->n;
	free(arrayPtr);
	this->arrayPtr = rhs->arrayPtr;
	return;
}

Vector* Vector::operator+(const Vector* addend){
	if(this->n != addend->n){
		std::cout << "Error. Vectors need to be the same size." << std::endl;
		return NULL;
	}
	else{
		Vector *sum = new Vector();
		for(int i = 0; i < addend->n; i++){
			sum->insert(this->arrayPtr[i] + addend->arrayPtr[i]);
		}
		return sum;
	}
}

Vector* Vector::operator-(const Vector* subtrahend){
	if(this->n != subtrahend->n){
                std::cout << "Error. Vectors need to be the same size." << std::endl;
                return NULL;
        }
        else{
                Vector *difference = new Vector();
                for(int i = 0; i < subtrahend->n; i++){
                        difference->insert(this->arrayPtr[i] - subtrahend->arrayPtr[i]);
                }
                return difference;
        }
}

double Vector::operator*(const Vector* multiplicand){
	if(this->n != multiplicand->n){
                std::cout << "Error. Vectors need to be the same size." << std::endl;
                return -1;
        }
        else{
                double sum = 0;
                for(int i = 0; i < multiplicand->n; i++){
                        sum += this->arrayPtr[i] * multiplicand->arrayPtr[i];
                }
                return sum;
        }


}

Vector* Vector::operator*(double scalar){
	Vector *scaled = new Vector();
	for(int i = 0; i < this->n; i++){
		scaled->insert(this->arrayPtr[i]*scalar);
	}
	return scaled;
}

Vector* Vector::operator/(double scalar){
	if(scalar == 0){
		std::cout << "Error: Vector cannot be divided by zero" << std::endl;
		return NULL;
	}
	else{
		Vector* scaled = new Vector();
		for(int i = 0; i < n; i++){
			scaled->insert(this->arrayPtr[i] / scalar);
		}
		return scaled;
	}
}

double Vector::operator[](int i){
	if(i >= n || i < 0){
		std::cout << "Error. Out of bounds." << std::endl;
		return -1;
	}
	else{
		return arrayPtr[i];
	}
}

inline int Vector::size(){
	return n;
}

void Vector::insert(double k){
	n++;
	arrayPtr = (double*)realloc(arrayPtr, n*sizeof(double));
	arrayPtr[n - 1] = k;
}

void Vector::printVector(){
	std::cout << "[";
	for(int i = 0; i < n; i++){
		std::cout << arrayPtr[i];
		if(i == n - 1){
			std::cout << "]";
		}
		else{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

double Vector::norm(){	
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += pow(arrayPtr[i], 2);
	}	
	return sqrt(sum);
}

void Vector::normalize(){
	
}

void Vector::set(int i, double k){
	if(i < 0){
		std::cout << "Error: Invalid index." << std::endl;
	}
	else{
		arrayPtr[i] = k;
	}
}
