/*
	AUTOR: RUBENS ANDERSON - COMPUTAÇÃO UFC 2017
	DESC: Operações sobre matrizes definidas na classe matriz
*/
#ifndef OPEMATRIZ_H
#define OPEMATRIZ_H

#include <iostream>
#include <vector>
#include <math.h>
#include "matriz.hpp"

using namespace std;

class opeMatriz{
public:

	opeMatriz();

	static void trocaLinhas(matriz * M, int linha1, int linha2);

	static void acheLinhaValida(matriz * M, int linha, int coluna);

	static matriz multiply(matriz M, matriz N);

	static matriz gerarVetorColunaZeros(int n);

	static matriz multiplyByEscalar(matriz M, double c);

	static double determinante(matriz A);

	static double produtoEscalar(matriz x, matriz y);

	static double Modulo(matriz v);

	static matriz normalizar(matriz x);

	static matriz transpor(matriz M);

	static matriz mais(matriz M, matriz N);

	static matriz menos(matriz M, matriz N);

	static vector<matriz> makeLU(matriz A);

	static matriz tripartir(matriz A);

	static matriz resolverSLComLU(vector<matriz> LU, matriz x);

	static matriz resolverSistemaTriangularSup(matriz U, matriz b);

	static matriz resolverSistemaTriangularInf(matriz L, matriz b);

	static matriz resolverNucleo(matriz M);

	static bool isSimetrica(matriz A);

	static matriz gerarMatrizHouseholoder(matriz A, int j);

	static matriz makeMatrizRotacao(matriz A, int i, int j);

	static bool ModuloForaDiagonal(matriz A, double epsilon);

	static bool ModuloAbaixoDiagonal(matriz A, double epsilon);

	static bool ModuloAbaixoTriDiagonal(matriz A, double epsilon);

	static matriz getLinha(matriz A, int i);

	static matriz getColuna(matriz A, int j);

	static matriz nucleoResenberg(matriz A);

	static bool resenberg(matriz A);

private:
	static void somaEntreLinhas(matriz * M, int linha1, int linha2, double c);

	static void multiplicaLinhaPorEscalar(matriz * M, double c, int linha);
};

#endif