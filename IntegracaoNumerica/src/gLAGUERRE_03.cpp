//
//  gLAGUERRE_03.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/gLAGUERRE_03.hpp"
#include <math.h>

gLAGUERRE_03::gLAGUERRE_03(Funcao * f)
{
    m_pIntegrando = f;
}

double gLAGUERRE_03::integrar()
{

   return gLAGUERRE_03_integracao();
}

double gLAGUERRE_03::gLAGUERRE_03_integracao()
{
        double x1 = 0.41577;
    double x2 = 2.29428;
    double x3 = 6.28995;

    double w1 = 0.227385;
    double w2 = 0.278467;
    double w3 = 0.010388;

    return m_pIntegrando->f(x1) * w1 + m_pIntegrando->f(x2) * w2 + m_pIntegrando->f(x3) * w3;
}
