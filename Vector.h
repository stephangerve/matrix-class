#ifndef VECTOR_H_EXISTS
#define VECTOR_H_EXISTS

#include <iostream>

class Vector{
	private:
		int n;
		double *arrayPtr;

	public:
		Vector();
		Vector(std::string);
		~Vector();
		void operator=(const Vector*);
		Vector* operator+(const Vector*);
		Vector* operator-(const Vector*);
		double operator*(const Vector*);
		Vector* operator*(double);
		Vector* operator/(double);
		double operator[](int);
		inline int size();
		double norm();
		void insert(double);
		void printVector();
		void normalize();	
		void set(int,double);		




};






#endif
