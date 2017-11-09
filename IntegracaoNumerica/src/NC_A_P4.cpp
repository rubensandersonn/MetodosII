//
//  NC_A_P4.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/NC_A_P4.hpp"
#include <math.h>

NC_A_P4::NC_A_P4(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;

}

double NC_A_P4::integrar()
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

            integral += NC_A_P4_integracao(m_pIntegrando, linf, lsup);
        }

        return integral;
    }
    else // SE FOR POR PRECISÃO
    {
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;

        integral = NC_A_P4_integracao(m_pIntegrando, m_lInf, m_lSup);

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

                integral += NC_A_P4_integracao(m_pIntegrando, linf, lsup);
            }


        } while (fabs(integral - oldintegral) > m_precisao);

        return integral;
    }

}

double NC_A_P4::NC_A_P4_integracao(Funcao * f, double a, double b)
{
    double h = (b-a)/(6);
    double x1 = a + h;
    double x2 = a + 2*h;
    double x3 = a + 3*h;
    double x4 = a + 4*h;
    double x5 = a + 5*h;

    // calculando W1

    double c15 = 1;
    double c14 = -x2 -x3 -x4 -x5;
    double c13 = x2*x3 + x2*x4 + x2*x5 + x3*x4 + x3*x5 + x4*x5;
    double c12 = - x2 * x3 * x4 - x2*x3*x5 - x2*x4*x5 - x3*x4*x5;
    double c11 = x2 * x3 * x4 * x5;

    double w1 = c15*( (pow(b, 5)/5) - (pow(a, 5)/5) )
                + c14*( (pow(b, 4)/4) - (pow(a, 4)/4) )
                + c13*( (pow(b, 3)/3) - (pow(a, 3)/3) )
                + c12*( (pow(b, 2)/2) - (pow(a, 2)/2) )
                + c11*( (pow(b, 1)/1) - (pow(a, 1)/1) ) ;

    double d1 = (x1 - x2)*(x1 - x3)*(x1 - x4)*(x1 - x5);

    w1 = w1/d1;

// calculando W2

    double c25 = 1;
    double c24 = -x1 -x3 -x4 -x5;
    double c23 = x1*x3 + x1*x4 + x1*x5 + x3*x4 + x3*x5 + x4*x5;
    double c22 = - (x1 * x3 * x4) - (x1*x3*x5) - (x3*x4*x5) - x1*x4*x5;
    double c21 = x1 * x3 * x4 * x5;

    double w2 = c25*( (pow(b, 5)/5) - (pow(a, 5)/5) )
                + c24*( (pow(b, 4)/4) - (pow(a, 4)/4) )
                + c23*( (pow(b, 3)/3) - (pow(a, 3)/3) )
                + c22*( (pow(b, 2)/2) - (pow(a, 2)/2) )
                + c21*( (pow(b, 1)/1) - (pow(a, 1)/1) ) ;

    double d2 = (x2 - x1)*(x2 - x3)*(x2 - x4)*(x2 - x5);

    w2 = w2/d2;

// calculando W3

    double c35 = 1;
    double c34 = -x2 -x1 -x4 -x5;
    double c33 = x2*x1 + x2*x4 + x2*x5 + x1*x4 + x1*x5 + x4*x5;
    double c32 = - x2 * x1 * x4 - x2*x1*x5 - x1*x4*x5 - x2*x4*x5;
    double c31 = x2 * x1 * x4 * x5;

    double w3 = c35*( (pow(b, 5)/5) - (pow(a, 5)/5) )
                + c34*( (pow(b, 4)/4) - (pow(a, 4)/4) )
                + c33*( (pow(b, 3)/3) - (pow(a, 3)/3) )
                + c32*( (pow(b, 2)/2) - (pow(a, 2)/2) )
                + c31*( (pow(b, 1)/1) - (pow(a, 1)/1) ) ;

    double d3 = (x3 - x1)*(x3 - x2)*(x3 - x4)*(x3 - x5);

    w3 = w3/d3;

// calculando W4

    double c45 = 1;
    double c44 = -x2 -x3 -x1 -x5;
    double c43 = x2*x3 + x2*x1 + x2*x5 + x3*x1 + x3*x5 + x1*x5;
    double c42 = - x2 * x3 * x1 - x2*x3*x5 - x3*x1*x5 - x1*x2*x5;
    double c41 = x2 * x3 * x1 * x5;

    double w4 = c45*( (pow(b, 5)/5) - (pow(a, 5)/5) )
                + c44*( (pow(b, 4)/4) - (pow(a, 4)/4) )
                + c43*( (pow(b, 3)/3) - (pow(a, 3)/3) )
                + c42*( (pow(b, 2)/2) - (pow(a, 2)/2) )
                + c41*( (pow(b, 1)/1) - (pow(a, 1)/1) ) ;

    double d4 = (x4 - x1)*(x4 - x3)*(x4 - x2)*(x4 - x5);

    w4 = w4/d4;

// calculando W5

    double c55 = 1;
    double c54 = -x2 -x3 -x4 -x1;
    double c53 = x2*x3 + x2*x4 + x2*x1 + x3*x4 + x3*x1 + x4*x1;
    double c52 = - x2 * x3 * x4 - x2*x3*x1 - x3*x4*x1 - x1*x4*x2;
    double c51 = x2 * x3 * x4 * x1;

    double w5 = c55*( (pow(b, 5)/5) - (pow(a, 5)/5) )
                + c54*( (pow(b, 4)/4) - (pow(a, 4)/4) )
                + c53*( (pow(b, 3)/3) - (pow(a, 3)/3) )
                + c52*( (pow(b, 2)/2) - (pow(a, 2)/2) )
                + c51*( (pow(b, 1)/1) - (pow(a, 1)/1) ) ;

    double d5 = (x5 - x1)*(x5 - x3)*(x5 - x4)*(x5 - x2);

    w5 = w5/d5;

    return m_pIntegrando->f(x1) * w1 + m_pIntegrando->f(x2) * w2 + m_pIntegrando->f(x3) * w3 + m_pIntegrando->f(x4) * w4+ m_pIntegrando->f(x5) * w5 ;
}
