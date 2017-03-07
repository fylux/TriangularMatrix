#include "TMatrix.hpp"

template<class T>
TMatrix<T>::TMatrix(unsigned int N) {
	this->N=N;
	matrix = new T[computeSize()];
}

template<class T>
TMatrix<T>::TMatrix(unsigned int N, T value) {
	this->N=N;
	unsigned int size = computeSize();
	matrix = new T[size];
	std::memset(matrix,value,size*sizeof(T));
}

template<class T>
TMatrix<T>::~TMatrix() {
	delete[] matrix;
}

template<class T>
unsigned int TMatrix<T>::computeSize() {
	return (N*N+N)/2;
}

template<class T>
unsigned int TMatrix<T>::computePosition(unsigned int x, unsigned int y) {
	if (y > x) {
		unsigned int aux = x;
		x=y;
		y=aux;
	}
	unsigned int position = (x*x+x)/2+y;
}


template<class T>
T TMatrix<T>::get(unsigned int x, unsigned int y) {
	return matrix[computePosition(x,y)];
}

template<class T>
void TMatrix<T>::set(unsigned int x, unsigned int y, T value) {
	matrix[computePosition(x,y)] = value;
}

//Add the types that you need
template class TMatrix<int>;