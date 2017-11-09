all: main


main: main.o matriz.o opeMatriz.o autov.o
	g++ main.o matriz.o opeMatriz.o autov.o -o main



main.o: main.cpp headers/matriz.hpp headers/opeMatriz.hpp headers/autov.hpp
	g++ -c main.cpp

matriz.o: src/matriz.cpp headers/matriz.hpp
	g++ -c src/matriz.cpp

opeMatriz.o: src/opeMatriz.cpp headers/opeMatriz.hpp
	g++ -c src/opeMatriz.cpp

autov.o: src/autov.cpp headers/autov.hpp
	g++ -c src/autov.cpp
