//
//  gLAGUERRE_04.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/gLAGUERRE_04.hpp"
#include <math.h>

gLAGUERRE_04::gLAGUERRE_04(Funcao * f)
{
    m_pIntegrando = f;
}

double gLAGUERRE_04::integrar()
{

   return gLAGUERRE_04_integracao();
}

double gLAGUERRE_04::gLAGUERRE_04_integracao()
{
    double x1 = 0.32255;
    double x2 = 1.74576;
    double x3 = 4.53662;
    double x4 = 9.39507;

    double w1 = 0.603156;
    double w2 = 0.357416;
    double w3 = 0.038894;
    double w4 = 0.0005398;

    return m_pIntegrando->f(x1) * w1 + m_pIntegrando->f(x2) * w2 + m_pIntegrando->f(x3) * w3 + m_pIntegrando->f(x4) * w4;
}
