matrix.exe: matrix.o main.o
	g++ -std=c++17 -o matrix.exe matrix.o main.o

matrix.o: matrix.cpp matrix.hpp
	g++ -std=c++17 -c matrix.cpp

main.o: main.cpp matrix.hpp
	g++ -std=c++17 -c main.cpp

clean:
	rm -f matrix.exe

