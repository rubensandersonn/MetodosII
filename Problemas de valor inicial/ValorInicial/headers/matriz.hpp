/*
	AUTOR: RUBENS ANDERSON - COMPUTAÇÃO UFC 2017
	DESC: Definição de uma classe matriz
*/
#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class matriz{
public:
	void escreveMatriz();

	vector < vector <double> > createIdentity(int n);
	

	matriz(int n);

	matriz();

	int getNumLinha();

	int getNumColuna();

	double get(int i, int j);

	void push(double c, int i, int j);

private:
	

	vector <double> gerarVectorZeros(int n);
	int sizeLinha;
	int sizeColuna;
	vector < vector <double> > m;
};

#endif