//
//  gHERMITE_03.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef gHERMITE_03_hpp
#define gHERMITE_03_hpp

#include "Integracao.hpp"

class gHERMITE_03 : public Integracao
{
public:
    gHERMITE_03(Funcao * f);

    virtual double integrar();

private:
    double  gHERMITE_03_integracao();

    Funcao *m_pIntegrando;
};


#endif /* gHERMITE_03_hpp */
