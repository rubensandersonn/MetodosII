//  
//  backward_euler.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
/*
  a implementar:
        estado.hpp
        opeEstado.hpp
        Funcao_S.hpp
*/

#include "../headers/backward_euler.hpp"


backward_euler::backward_euler(Funcao_S * f, double a, double b, double dt, double ep)
{
    funcao_f = f;
    lInf        = min(a,b);
    lSup        = max(a,b);
    delta_t    = dt;
    n    = fabs(b-a) / dt;
    epsilon = ep;
}

vector<estado> backward_euler::start(estado s0) // espero receber a matriz doida de be
{
    vector<estado> r;
    r.push_back(s0);
    int i = 0;

    double ti = lInf;
    do{

        r.push_back(backward_euler::find_next_si(r[i], ti));
        i++;
        ti = lInf + i*delta_t;

    }while(ti < lSup);

    return r;
}

estado backward_euler::find_next_si(estado Si, double ti)
{
    estado Sip1 = opeEstado::somaEstados( Si , opeEstado::multiplyByEscalar(funcao_f->f(Si, ti), delta_t));
    estado sip1 = Sip1;
    
    do{
        sip1 = Sip1;

        Sip1 = opeEstado::somaEstados( Si , opeEstado::multiplyByEscalar(funcao_f->f(sip1, ti + delta_t), delta_t));
        
        
    }while(fabs(Sip1.u1 - sip1.u1) < epsilon);

    return Sip1;
}
