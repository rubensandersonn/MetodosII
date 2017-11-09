//  
//  pred_corr.cpp - Metodos Numericos II
//  Rubens Anderson de Sousa Silva - 362984 - Computação UFC 2017
//
/*
  a implementar:
        estado.hpp (*)
        opeEstado.hpp (*)
        Funcao_S.hpp (*)
*/

#include "../headers/pred_corr.hpp"



pred_corr::pred_corr(Funcao_S * f, double a, double b, double epsilon)
{
    funcao_f = f;
    lInf        = min(a,b);
    lSup        = max(a,b);
    delta_t    = epsilon;
    n    = fabs(b-a) / epsilon;

}

vector<estado> pred_corr::start(estado s0)
{
    
    vector<estado> r;
    r.push_back(s0);

    // verificando se ha 3 pontos no domínio...

    r_k_4 * rk;
    if(n > 3){

        rk = new r_k_4(funcao_f, lInf, lInf + 2*delta_t, delta_t);
        r = rk->start(s0);

    }else{

        rk = new r_k_4(funcao_f, lInf, lSup, delta_t);
        return rk->start(s0);
    }

    int i = 2;

    double ti = lInf;

    do{

        r.push_back(pred_corr::find_next_si(r, i));
        i++;
        ti = lInf + i*delta_t;

    }while(ti < lSup);

    return r;
}

estado pred_corr::find_next_si(vector<estado> v, int i)
{
    // criando o preditor

    estado si = v[i];
    estado sim1 = v[i-1];
    estado sim2 = v[i-2];

    estado fi = funcao_f->f(si, lInf + i*delta_t);
    estado fim1 = funcao_f->f(sim1, lInf + (i-1)*delta_t);
    estado fim2 = funcao_f->f(sim2, lInf + (i-2)*delta_t);

    estado R = opeEstado::somaEstados( opeEstado::multiplyByEscalar(fi, 23.0) , opeEstado::multiplyByEscalar(fim1, -16.0) );
    R = opeEstado::somaEstados(R, opeEstado::multiplyByEscalar(fim2, 5.0));

    estado S_pred = opeEstado::somaEstados( v[i] , opeEstado::multiplyByEscalar( R, delta_t/12) ); 

    
    // agora, o corretor

    R = opeEstado::somaEstados( opeEstado::multiplyByEscalar(fi, 8.0) , opeEstado::multiplyByEscalar(fim1, -1.0) );
    R = opeEstado::somaEstados(R, opeEstado::multiplyByEscalar(S_pred, 5.0));

    estado S_corr = opeEstado::somaEstados( v[i] , opeEstado::multiplyByEscalar( R, delta_t/12) ); 



    return S_corr;
}
