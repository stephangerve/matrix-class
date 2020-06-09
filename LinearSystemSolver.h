#ifndef LINEARSYSTEMSOLVER_H_EXISTS
#define LINEARSYSTEMSOLVER_H_EXISTS

#include "Matrix.h"
#include "Vector.h"

class LinearSystemSolver{
	private:

	public:
		LinearSystemSolver();
		~LinearSystemSolver();
		Vector* naiveGaussian(Matrix*, Vector*);
		Matrix* lowerTriangular(Matrix*);
		Matrix* upperTriangular(Matrix*);
		Matrix* augment(Matrix*, Vector*);




};

#endif
