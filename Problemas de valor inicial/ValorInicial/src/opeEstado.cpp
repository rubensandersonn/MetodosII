//  
//  opeEstado.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Comsetação UFC 2017
//
//

#include "../headers/opeEstado.hpp"


void opeEstado::escreveEstado(estado s){

	cout << "	s.u1 = " << s.u1 << endl;
	cout << "	s.u2 = " << s.u2 << endl;
	cout << "	s.v1 = " << s.v1 << endl;
	cout << "	s.v2 = " << s.v2 << endl;
}

estado opeEstado::multiplyByEscalar( estado Si, double t){

	Si.u1 = opeEstado::valida(Si.u1 * t);
	Si.u2 = opeEstado::valida(Si.u2 * t);
	Si.v1 = opeEstado::valida(Si.v1 * t);
	Si.v2 = opeEstado::valida(Si.v2 * t);

	return Si;
}

estado opeEstado::somaEstados( estado S1, estado S2){

	estado * R = new estado( opeEstado::valida( S1.u1 + S2.u1), opeEstado::valida(S1.u2 + S2.u2), opeEstado::valida(S1.v1 + S2.v1), opeEstado::valida(S1.v2 + S2.v2) );

	return *R;
}

matriz opeEstado::transformaEstadoVetor(estado E){
	
	matriz * m = new matriz(1);

	m->push(E.u1, 0,0);
	m->push(E.u2, 1,0);
	m->push(E.v1, 2,0);
	m->push(E.v2, 3,0);

	return *m;
}

estado opeEstado::transformaVetorEstado(matriz m){
	estado * s = new estado(m.get(0,0), m.get(1,0), m.get(2,0), m.get(3,0));

	return *s;
}

double opeEstado::valida(double x){
        if(fabs(x) < 0.00001){
            return 0;
        }
        return x;
    }