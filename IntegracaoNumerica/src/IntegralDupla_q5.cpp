//
//  NC_F_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/IntegralDupla_q5.hpp"
#include "../headers/N2.hpp"
#include "../headers/N3.hpp"
#include "../headers/N4.hpp"

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

double IntegralDupla_q5::valida(double s){
    if(s < 0.0001){
        return 0;
    }
    return s;
}

double IntegralDupla_q5::derivada_R2(Funcao_R2 * func, double alp, double bet, double delta, double lim_sup, double lim_inf, int emRelacaoA){
    /*
        deltax
        x1, x2, x3
    */
    double x0;
    double x1;
    double x2;

    int s;

    if(emRelacaoA == 1){
        // em relação a y
        if(bet - delta < lim_inf){
        // forward
            x0 = bet;
            x1 = bet + delta;
            x2 = bet + delta*2;

            s = 2;
        }else if(bet + delta > lim_sup){
        // backword
            x2 = bet;
            x1 = bet - delta;
            x0 = bet - delta*2;

            s = 0;
        }else{
            // central
            x0 = bet - delta;
            x1 = bet;
            x2 = bet + delta;

            s = 1;
        }

        double resultado = (1/delta)*(func->f(alp, x2) * 0.5*(2*s - 1) + func->f(alp, x1) * (2- 2*s) + func->f(alp, x0)*( -1+0.5*(2*s-1)) );
        //cout << "\n       dados da derivada: " << x0 << ", " << x1 << ", " << x2 << endl;
        //cout << " resultado = " << resultado << endl;
        return valida(resultado);
    }else{

        // em relação a x

        if(alp - delta < lim_inf){
        // forward
            x0 = alp;
            x1 = alp + delta;
            x2 = alp + delta*2;

            s = 2;
        }else if(alp + delta > lim_sup){
        // backword
            x2 = alp;
            x1 = alp - delta;
            x0 = alp - delta*2;

            s = 0;
        }else{
            // central
            x0 = alp - delta;
            x1 = alp;
            x2 = alp + delta;

            s = 1;
        }

    }

    double resultado =  (1/delta)*(func->f(x2, bet) * 0.5*(2*s - 1) + func->f(x1, bet) * (2- 2*s) + func->f(x0, bet)*( -1+0.5*(2*s-1)) );
     //cout << "\n       dados da derivada: " << x0 << ", " << x1 << ", " << x2 << endl;
    //cout << " resultado = " << resultado << endl;
    return valida(resultado);
}

double IntegralDupla_q5::derivada(Funcao * func, double alp, double delta){
    /*
        deltax
        x1, x2, x3
    */
    double x0;
    double x1;
    double x2;

    int s;

    if(alp - delta < a_func){
        // forward

        x0 = alp;
        x1 = alp + delta;
        x2 = alp + delta*2;


        s = 2;

    }else if(alp + delta > b_func){
        // backword

        x2 = alp;
        x1 = alp - delta;
        x0 = alp - delta*2;

        s = 0;
    }else{
        // central

        x0 = alp - delta;
        x1 = alp;
        x2 = alp + delta;

        s = 1;
    }

    double resultado =  (1/delta)*(func->f(x2) * 0.5*(2*s - 1) + func->f(x1) * (2- 2*s) + func->f(x0)*( -1+0.5*(2*s-1)) );
    //cout << "\n       dados da derivada: " << x0 << ", " << x1 << ", " << x2 << endl;
    //cout << " resultado = " << resultado << endl;
    return valida(resultado);
}

double IntegralDupla_q5::detJacob(double alpha, double betha){


    return 0.75;
}

IntegralDupla_q5::IntegralDupla_q5(Funcao_R2 * f, double a, double b, Funcao * c, Funcao * d, int na, int nb, Funcao_R2 * x, Funcao_R2 * y)
{
   F = f;

   X = x;
   Y = y;

   C = c;
   D = d;

   nAlpha = na;
   nBetha = nb;

    b_func = b; a_func = a;

    cout << "\nInicializando...\n";

}

double IntegralDupla_q5::integrar()
{
    cout << "\n entrando na integracao\n";
    return IntegralDupla_q5_integracao();

}

double IntegralDupla_q5::IntegralDupla_q5_integracao()
{

    std::vector <double> alpha;
    std::vector <double> w_alpha;
    std::vector <double> betha;
    std::vector <double> w_betha;

    double integral = 0;

    cout << "nalpha\n";

    switch(nAlpha){

            case 2:
                alpha.push_back(-0.57735);
                alpha.push_back(0.57735);

                w_alpha.push_back(1);
                w_alpha.push_back(1);
                break;

            case 3:
                alpha.push_back(-0.774597);
                alpha.push_back(0.0);
                alpha.push_back(0.774597);

                w_alpha.push_back(0.5555555);
                w_alpha.push_back(0.8888888);
                w_alpha.push_back(0.5555555);


                break;

            case 4:
                alpha.push_back(-0.86144);
                alpha.push_back(-0.33998);

                alpha.push_back(0.33998);
                alpha.push_back(0.86144);

                w_alpha.push_back(0.347567);
                w_alpha.push_back(0.65243);
                w_alpha.push_back(0.65243);
                w_alpha.push_back(0.347567);

                break;
        }

    // nBetha
    cout << "nbetha\n";

switch(nBetha){

            case 2:
                betha.push_back(-0.57735);
                betha.push_back(0.57735);

                w_betha.push_back(1);
                w_betha.push_back(1);
                break;

            case 3:
                betha.push_back(-0.774597);
                betha.push_back(0.0);
                betha.push_back(0.774597);

                w_betha.push_back(0.5555555);
                w_betha.push_back(0.8888888);
                w_betha.push_back(0.5555555);


                break;

            case 4:
                betha.push_back(-0.86144);
                betha.push_back(-0.33998);

                betha.push_back(0.33998);
                betha.push_back(0.86144);

                w_betha.push_back(0.347567);
                w_betha.push_back(0.65243);
                w_betha.push_back(0.65243);
                w_betha.push_back(0.347567);

                break;
    }

    double xab = 0;
    double yab = 0;
    double detJ = 0;


    for(int i = 0; i < nAlpha; i++){
        for(int j = 0; j < nBetha; j++){

            xab = X->f( alpha[i], betha[j] );
            yab = Y->f( alpha[i], betha[j] );

            detJ = detJacob( alpha[i], betha[j] );

            integral += w_alpha[i] * w_betha[j] * F->f( xab, yab ) * detJ;

        }
    }

    return integral;
}
