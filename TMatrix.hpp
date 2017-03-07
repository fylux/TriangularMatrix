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

#endif