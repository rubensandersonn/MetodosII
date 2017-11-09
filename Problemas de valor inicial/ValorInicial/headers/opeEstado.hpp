//  
//  opeEstado.hpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Comsetação UFC 2017
//
//  

#ifndef opeEstado_hpp
#define opeEstado_hpp

#include "estado.hpp"
#include "matriz.hpp"
#include <iostream>

using namespace std;

class opeEstado
{
public:
	static void escreveEstado(estado s);
	static estado multiplyByEscalar( estado Si, double t);
	static estado somaEstados( estado S1, estado S2);

	static matriz transformaEstadoVetor(estado E);
	static estado transformaVetorEstado(matriz m);
private:
	static double valida(double x);
};


#endif /* opeEstado_hpp */
