/*
	AUTOR: RUBENS ANDERSON - COMPUTAÇÃO UFC 2017
	DESC: Operações sobre matrizes definidas na classe matriz
*/
#ifndef AUTOV_H
#define AUTOV_H

#include <iostream>
#include <vector>
#include <math.h>
//#include "matriz.hpp"
#include "opeMatriz.hpp"

using namespace std;

class autov{
public:

	autov();
	virtual ~autov();

	static void testarAutovetor(matriz A, matriz autovetor, double a);

	static double metodoPotencia(matriz A, matriz x, double epsilon, matriz * autovetor);

	static double metodoPotenciaInversa(matriz A, matriz x, double epsilon, matriz * autovetor);

	static double metodoPotenciaDesloc(matriz A, matriz x, double epsilon, matriz * autovetor, double mi);

	static matriz metodoJacobi(matriz A, double epsilon, matriz * autovetores);

	static matriz metodoQR(matriz A, double epsilon, matriz * autovetores);

	static matriz findQ(matriz A, int i , int j);

	static matriz findR(matriz A);

};

#endif