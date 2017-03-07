#include <iostream>
#include "TMatrix.hpp"

using namespace std;

int main(){
	//Creates a 3*3 integer matrix initialized to zero
	TMatrix<int> matrix(3,0);
	
	//[1][2]=5
	cout << "Let's set [1][2] = 5" << endl;
	matrix(1,2,5);	//matrix.set(1,2,5);

	//Because is symmetric [1][2] = [2][1]
	cout << "So what is the value of [2][1]? = " << matrix(2,1) /*matrix.get(2,1)*/ << endl;

	return 0;
}