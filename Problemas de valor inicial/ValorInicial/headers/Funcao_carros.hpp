//  
//  estado.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
//  
#ifndef Funcao_carros_hpp
#define Funcao_carros_hpp

#include "Funcao_S.hpp"
#include "Funcao.hpp"

class Funcao_carros : public Funcao_S {
public:
	Funcao_carros(double c1, double c2, double M1, double M2, Funcao * f1, Funcao * f2){

		k1 = c1;
		k2 = c2;

		m1 = M1;
		m2 = M2;

		F1 = f1;
		F2 = f2;
	}

	estado f(estado Si, double ti){

		double f1 = (1/m1)*( F1->f(ti) + k2*(Si.u2 - Si.u1) - k1*Si.u1 ); 
		double f2 = (1/m2)*( F2->f(ti) - k2*(Si.u2 - Si.u1) ); 

		estado * R = new estado(Si.v1, Si.v2, f1, f2);

		return *R;
	}

	double k1;
	double k2;
	double m1;
	double m2;

	Funcao * F1;
	Funcao * F2;

};

#endif /*Funcao_carros_hpp*/