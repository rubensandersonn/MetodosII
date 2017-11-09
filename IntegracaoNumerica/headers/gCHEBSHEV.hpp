//
//  gCHEBSHEV.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef gCHEBSHEV_hpp
#define gCHEBSHEV_hpp

#include "Integracao.hpp"

class gCHEBSHEV : public Integracao
{
public:
    gCHEBSHEV(Funcao * f, double a, double b, int N);

    virtual double integrar();

private:

    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    int     m_particao;

};


#endif /* gCHEBSHEV_hpp */
