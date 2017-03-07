a.exe: main.o TMatrix.o
	gcc -o a.exe main.o TMatrix.o -lstdc++ -std=c++11

main.o : main.cpp TMatrix.hpp
	gcc -c main.cpp -lstdc++ -std=c++11

TMatrix.o : TMatrix.cpp TMatrix.hpp
	gcc -c TMatrix.cpp -lstdc++ -std=c++11

run: a.exe
	a.exe