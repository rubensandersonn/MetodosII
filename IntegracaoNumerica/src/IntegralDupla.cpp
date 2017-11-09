//
//  NC_F_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/IntegralDupla.hpp"
#include "../headers/X_R2.hpp"
#include "../headers/Y_R2.hpp"

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

double IntegralDupla::valida(double s){
    if(s < 0.0001){
        return 0;
    }
    return s;
}

double IntegralDupla::derivada_R2(Funcao_R2 * func, double alp, double bet, double delta, double lim_sup, double lim_inf, int emRelacaoA){
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

double IntegralDupla::derivada(Funcao * func, double alp, double delta){
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

double IntegralDupla::detJacob(double alpha, double betha){

    double xab = X(alpha, betha);

    X_R2 * x = new X_R2(a_func,b_func);
    //Y_R2 * y = new Y_R2(C, D, x);

    double ca = C->f(alpha);
    double da = D->f(alpha);

    double deltaAlpha = (b_func - a_func)/nAlpha;
    double deltaBetha = (da - ca)/nBetha;

    double dC = derivada(C, xab, deltaAlpha);
    double dD = derivada(D, xab, deltaAlpha);

    double Xalpha = derivada_R2(x, alpha, betha, deltaAlpha,  a_func, b_func,  0);
    double Xbetha = derivada_R2(x, alpha, betha, deltaBetha, ca , da , 1);

    double Yalpha = (0.5) * (dC * Xalpha + dD * Xalpha) + (betha / 2) * (-dC * Xalpha + dD * Xalpha);
    double Ybetha = (0.5) * (dC * Xbetha + dD * Xbetha) + (betha / 2) * (-dC * Xbetha + dD * Xbetha) + ((D->f(X(alpha, betha)) - C->f(X(alpha, betha)) )/2) ;

    //cout << "       dados dentro de detJacob: " << endl;
    //cout << "Xalpha = " << Xalpha << ", Xbetha = " << Xbetha << ", Yalpha = " << Yalpha << ", Ybetha = " << Ybetha << endl;
    //cout << "xa * yb = " << Xalpha * Ybetha << endl;
    //cout << "- ya * xb = " << -Yalpha * Xbetha << endl;
    return Xalpha * Ybetha - Xbetha * Yalpha;
}

double IntegralDupla::X(double s, double t){
    return ((b_func + a_func)/2) + ((b_func - a_func)/2) * s;
}

double IntegralDupla::Y(double s, double t){
    return (C->f(X(s,t)) + D->f(X(s,t)) )/2 + ((D->f(X(s,t)) - C->f(X(s,t)) )/2) * t;
}

IntegralDupla::IntegralDupla(Funcao_R2 * f, double a, double b, Funcao * c, Funcao * d, int na, int nb)
{
   F = f;

   C = c;
   D = d;

   nAlpha = na;
   nBetha = nb;

    b_func = b; a_func = a;

}

double IntegralDupla::integrar()
{

    return IntegralDupla_integracao();

}

double IntegralDupla::IntegralDupla_integracao()
{

    std::vector <double> alpha;
    std::vector <double> w_alpha;
    std::vector <double> betha;
    std::vector <double> w_betha;

    double integral = 0;

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

            xab = X( alpha[i], betha[j] );
            yab = Y( alpha[i], betha[j] );

            detJ = detJacob( alpha[i], betha[j] );

            integral += w_alpha[i] * w_betha[j] * F->f( xab, yab ) * detJ;
            //cout << " w_alpha[" << i << "] = " << w_alpha[i] << endl;
            //cout << " w_betha[" << j << "] = " << w_betha[j] << endl;

            //cout << " F(axb, yab) = " << F->f(xab, yab) << endl;

            //cout << " detJacob = " << detJ << endl;

            //cout << "\n             integral  = " << integral << " no ponto (" << i << ", " << j << ")\n" << endl;

            //cout << "-----------------------------------------------------------------------\n";
        }
    }

    return integral;
}
