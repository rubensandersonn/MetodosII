//
//  NC_F_P2.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.

// REVISAR TUDO DEPOIS!
//

#include "../headers/gLEGENDRE_04.hpp"
#include <math.h>

gLEGENDRE_04::gLEGENDRE_04(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;

}

double gLEGENDRE_04::integrar()
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

            integral += gLEGENDRE_04_integracao(m_pIntegrando, linf, lsup);
        }

        return integral;
    }
    else // SE FOR POR PRECISÃO
    {
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;

        integral = gLEGENDRE_04_integracao(m_pIntegrando, m_lInf, m_lSup);

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

                integral += gLEGENDRE_04_integracao(m_pIntegrando, linf, lsup);
            }


        } while (fabs(integral - oldintegral) > m_precisao);

        return integral;
    }

}

double gLEGENDRE_04::gLEGENDRE_04_integracao(Funcao * f, double a, double b)
{
    double x1 = -0.86144;
    double x2 = -0.33998;

    double x3 = -x2;
    double x4 = -x1;

    double s1 = ((b+a) / 2) + ((b-a)/2)*x1;
    double s2 = ((b+a) / 2) + ((b-a)/2)*x2;
    double s3 = ((b+a) / 2) + ((b-a)/2)*x3;
    double s4 = ((b+a) / 2) + ((b-a)/2)*x4;

    double f1 = m_pIntegrando->f(s1);
    double f2 = m_pIntegrando->f(s2);
    double f3 = m_pIntegrando->f(s3);
    double f4 = m_pIntegrando->f(s4);

    double w1 = 0.347567;

    double w2 = 0.65243;

    return ((b-a)/2)*((f1 + f4)*w1 + (f2 + f3)*w2);
}