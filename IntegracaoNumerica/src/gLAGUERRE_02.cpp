//
//  gLAGUERRE.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include "../headers/gLAGUERRE_02.hpp"
#include <math.h>

gLAGUERRE_02::gLAGUERRE_02(Funcao * f)
{
    m_pIntegrando = f;
}

double gLAGUERRE_02::integrar()
{

   return gLAGUERRE_02_integracao();
}

double gLAGUERRE_02::gLAGUERRE_02_integracao()
{
    double x1 = 0.585786;
    double x2 = 3.414213;

    double w1 = 0.85355;
    double w2 = 0.1464466;

    return m_pIntegrando->f(x1)*w1 + m_pIntegrando->f(x2) * w2;

}
