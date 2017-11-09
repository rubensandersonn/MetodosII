//  
//  estado.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
//  
#ifndef q2_2_hpp
#define q2_2_hpp

#include "Funcao_S.hpp"


class q2_2 : public Funcao_S {
public:
	q2_2(){

	}

	estado f(estado Si, double ti){

		// aqui o estado deve ser: (y , v, w)... f(si,ti) = v, w, 9*si - y(si)
		
		estado * R = new estado(Si.u2, Si.v1, 9*ti - Si.u1, 0);

		return *R;
	}

};

#endif /*q2_2_hpp*/