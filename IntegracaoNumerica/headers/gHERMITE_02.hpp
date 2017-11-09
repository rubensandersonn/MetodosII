//
//  gHERMITE_02.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef gHERMITE_02_hpp
#define gHERMITE_02_hpp

#include "Integracao.hpp"

class gHERMITE_02 : public Integracao
{
public:
    gHERMITE_02(Funcao * f);

    virtual double integrar();

private:
    double  gHERMITE_02_integracao();

    Funcao *m_pIntegrando;
};


#endif /* gHERMITE_02_hpp */
