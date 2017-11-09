//  
//  r_k_4.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
//  

#ifndef r_k_4_hpp
#define r_k_4_hpp

#include <iostream>
#include <math.h>
#include <vector>

#include "estado.hpp"
#include "matriz.hpp"
#include "opeEstado.hpp"
#include "opeMatriz.hpp"
#include "Funcao_S.hpp"
#include "forward_euler.hpp"

using namespace std;

class r_k_4
{
public:
    r_k_4(Funcao_S * f, double a, double b, double epsilon);
    
    virtual std::vector<estado> start(estado);
    
    estado find_next_si(estado Si, double ti);
private:
    
    Funcao_S * funcao_f;
    double  lInf;
    double  lSup;
    double  delta_t;
    int     n;
};


#endif /* r_k_4_hpp */
