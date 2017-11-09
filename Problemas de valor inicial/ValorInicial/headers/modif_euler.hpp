//  
//  modif_euler.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
//  

#ifndef modif_euler_hpp
#define modif_euler_hpp


#include "estado.hpp"
#include "matriz.hpp"
#include "opeEstado.hpp"
#include "opeMatriz.hpp"
#include "Funcao_S.hpp"
#include <math.h>


class modif_euler
{
public:
    modif_euler(Funcao_S * f, double a, double b, double dt, double ep);
    
    virtual std::vector<estado> start(estado);
    
    estado find_next_si(estado Si, double ti);
private:
    
    Funcao_S * funcao_f;
    double  lInf;
    double  lSup;
    double  delta_t;
    int     n;
    double epsilon;
};


#endif /* modif_euler_hpp */
