//
//  NC_A_P3.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/NC_A_P3.hpp"
#include <math.h>

NC_A_P3::NC_A_P3(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;

}

double NC_A_P3::integrar()
{
    double integral = 0.0;

    if (m_particao >= 1) // se for por PARTIÇÃO
    {
        double step = (m_lSup - m_lInf)/m_particao;
        double linf, lsup;

        for (int i = 0; i < m_particao; i++)
        {
            linf = m_lInf + i*step;
            lsup = linf   + step;

            integral += NC_A_P3_integracao(m_pIntegrando, linf, lsup);
        }

        return integral;
    }
    else // SE FOR POR PRECISÃO
    {
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;

        integral = NC_A_P3_integracao(m_pIntegrando, m_lInf, m_lSup);

        do
        {
            oldintegral = integral;
            integral    = 0.0;

            N = N*2;

            step = (m_lSup - m_lInf)/N;

            for (int i = 0; i < N; i++)
            {
                linf = m_lInf + i*step;
                lsup = linf   + step;

                integral += NC_A_P3_integracao(m_pIntegrando, linf, lsup);
            }


        } while (fabs(integral - oldintegral) > m_precisao);

        return integral;
    }

}

double NC_A_P3::NC_A_P3_integracao(Funcao * f, double a, double b)
{
    double h = (b-a)/5;
    double x1 = a+h;
    double x2 = a + 2*h;
    double x3 = a + 3*h;
    double x4 = a + 4*h;

    // calculando W1

    double c14 = 1;
    double c13 = -x2 -x3 -x4;
    double c12 = x2*x3 + x2*x4 + x3*x4;
    double c11 = - x2 * x3 * x4;

    double w1 = c14*( (pow(b, 4)/4) - (pow(a, 4)/4) ) 
                + c13*( (pow(b, 3)/3) - (pow(a, 3)/3) ) 
                + c12*( (pow(b, 2)/2) - (pow(a, 2)/2) ) 
                + c11*( (pow(b, 1)/1) - (pow(a, 1)/1) ) ;

    double d1 = (x1 - x2)*(x1 - x3)*(x1 - x4);

    w1 = w1/d1;

    // Calculando W2

    double c24 = 1;
    double c23 = -x1 -x3 -x4;
    double c22 = x1*x3 + x1*x4 + x3*x4;
    double c21 = - x1 * x3 * x4;

    double w2 = c24*( (pow(b, 4)/4) - (pow(a, 4)/4) ) 
                + c23*( (pow(b, 3)/3) - (pow(a, 3)/3) ) 
                + c22*( (pow(b, 2)/2) - (pow(a, 2)/2) ) 
                + c21*( (pow(b, 1)/1) - (pow(a, 1)/1) ) ;

    double d2 = (x2 - x1)*(x2 - x3)*(x2 - x4);

    w2 = w2/d2;

    // Calculando W3

    double c34 = 1;
    double c33 = -x1 -x2 -x4;
    double c32 = x1*x2 + x1*x4 + x2*x4;
    double c31 = - x1 * x2 * x4;

    double w3 = c34*( (pow(b, 4)/4) - (pow(a, 4)/4) ) 
                + c33*( (pow(b, 3)/3) - (pow(a, 3)/3) ) 
                + c32*( (pow(b, 2)/2) - (pow(a, 2)/2) ) 
                + c31*( (pow(b, 1)/1) - (pow(a, 1)/1) ) ;

    double d3 = (x3 - x1)*(x3 - x2)*(x3 - x4);

    w3 = w3/d3;

    // Calculando W4

    double c44 = 1;
    double c43 = -x1 -x3 -x2;
    double c42 = x1*x3 + x1*x2 + x3*x2;
    double c41 = - x1 * x3 * x2;

    double w4 = c44*( (pow(b, 4)/4) - (pow(a, 4)/4) ) 
                + c43*( (pow(b, 3)/3) - (pow(a, 3)/3) ) 
                + c42*( (pow(b, 2)/2) - (pow(a, 2)/2) ) 
                + c41*( (pow(b, 1)/1) - (pow(a, 1)/1) ) ;

    double d4 = (x4 - x1)*(x4 - x3)*(x4 - x2);

    w4 = w4/d4;

    return m_pIntegrando->f(x1) * w1 + m_pIntegrando->f(x2) * w2 + m_pIntegrando->f(x3) * w3 + m_pIntegrando->f(x4) * w4 ;
}
