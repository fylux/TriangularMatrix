#ifndef __T_MATRIX__
#define __T_MATRIX__
#include <cstring>

template<class T>
class TMatrix {
	private:
		T * matrix;
		unsigned int N;
		unsigned int computeSize();
		unsigned int computePosition(unsigned int x, unsigned int y);
	public:
		TMatrix(unsigned int N);
		TMatrix(unsigned int N, T value); //Initialize all values
		~TMatrix();
		T get(unsigned int x, unsigned int y);
		void set(unsigned int x, unsigned int y, T value);

		//Overloading operators
		T operator()(unsigned int x, unsigned int y) { return get(x,y); }
		void operator()(unsigned int x, unsigned int y, T value) { set(x,y,value); }

		//It would be nice to overload '[][]' and '=' operators
};


//Code

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
	std::fill(matrix,matrix+size,value);
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



#endif