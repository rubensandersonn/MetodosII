//  
//  forward_euler.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
/*
  a implementar:
        estado.hpp (*)
        opeEstado.hpp (*)
        Funcao_S.hpp (*)
*/

#include "../headers/forward_euler.hpp"



forward_euler::forward_euler(Funcao_S * f, double a, double b, double epsilon)
{
    funcao_f = f;
    lInf        = min(a,b);
    lSup        = max(a,b);
    delta_t    = epsilon;
    n    = fabs(b-a) / epsilon;

}

vector<estado> forward_euler::start(estado s0)
{
    vector<estado> r;
    r.push_back(s0);

    int i = 0;

    double ti = lInf;
    do{

        r.push_back(forward_euler::find_next_si(r[i], ti));
        i++;
        ti = ti + delta_t;

    }while(ti < lSup);

    return r;
}

estado forward_euler::find_next_si(estado Si, double ti)
{
    // na fórmula, esta multiplicando o estado retornado pela função 
    estado fi = funcao_f->f(Si, ti);
    estado z = opeEstado::multiplyByEscalar(fi, delta_t);

    z = opeEstado::somaEstados(Si, z);


    return z;
}
