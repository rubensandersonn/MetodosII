//
//  32.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/gLEGENDRE_03.hpp"
#include <math.h>
#include <iostream>

using namespace std;

gLEGENDRE_03::gLEGENDRE_03(Funcao * f, double a, double b, int N, double epsilon)
{
    m_pIntegrando = f;
    m_lInf        = a;
    m_lSup        = b;
    m_precisao    = epsilon;
    m_particao    = N;

}

double gLEGENDRE_03::integrar()
{
    double integral = 0.0;

    if (m_particao >= 1) // se for por PARTIÇÃO
    {
        double step = (m_lSup - m_lInf)/m_particao;
        double linf, lsup;

        integral += gLEGENDRE_03_integracao(m_pIntegrando, m_lInf, m_lSup);/*

        for (int i = 0; i < m_particao; i++)
        {
            linf = m_lInf + i*step;
            lsup = linf   + step;


        }*/

        return integral;
    }
    else // SE FOR POR PRECISÃO
    {
        int    N           = 1;
        double oldintegral = 0.0;
        double step;
        double linf, lsup;

        integral = gLEGENDRE_03_integracao(m_pIntegrando, m_lInf, m_lSup);

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

                integral += gLEGENDRE_03_integracao(m_pIntegrando, linf, lsup);
            }


        } while (fabs(integral - oldintegral) > m_precisao);

        return integral;
    }

}

double gLEGENDRE_03::gLEGENDRE_03_integracao(Funcao * f, double a, double b)
{
    double x1 = -0.774597;
    double x2 = 0;
    double x3 = -x1;

    double s1 = ((b+a) / 2) + ((b-a)/2)*x1;
    double s2 = ((b+a) / 2) + ((b-a)/2)*x2;
    double s3 = ((b+a) / 2) + ((b-a)/2)*x3;

    double f1 = m_pIntegrando->f(s1);
    double f2 = m_pIntegrando->f(s2);
    double f3 = m_pIntegrando->f(s3);

    double w1 = (0.5555555); // inwegral de x²(s)

    double w2 = 0.888888888 ; // integral de x(s) ; 2 = intergal de ds

    double p1 = w1 * (f1 + f3);
    double p2 = w2 * f2;

    cout << "dados: raizes " << s1 << ", " << s2 << ", " <<  s3 << endl;
    cout << "fi's " << f1 << ", " << f2 << ", " <<  f3 << endl;

    cout << "wi's " << w1 << ", " << w2 << endl;
    cout << "Pi's " << p1 << ", " << p2 << ", " << endl;

            return ((b-a)/2)*( p1 + p2);
}
