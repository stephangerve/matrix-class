#include <iostream>


int main(){
	int n = 3;
	double **arrayPtr = (double**)malloc(n*sizeof(double));
	for(int i = 0; i < n; i++){
		arrayPtr[i] = (double*)malloc(n*sizeof(double));
		for(int j = 0; j < n; j++){
			arrayPtr[i][j] = (i + 1)*(j + 1); 
		}
	} 
	std::cout << "Matrix created." << std::endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cout << "[" << arrayPtr[i][j] << "]";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	for(int i = 0; i < n; i++){
		free(arrayPtr[i]);
	}
	std::cout << "Memory block freed" << std::endl;
	

}	
