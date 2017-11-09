//
//  gLEGENDRE_02.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef gLEGENDRE_02_hpp
#define gLEGENDRE_02_hpp

#include "Integracao.hpp"

class gLEGENDRE_02 : public Integracao
{
public:
    gLEGENDRE_02(Funcao * f, double a, double b, int N, double epsilon);

    virtual double integrar();

private:
    double  gLEGENDRE_02_integracao(Funcao * f, double a, double b);

    Funcao *m_pIntegrando;
    double  m_lInf;
    double  m_lSup;
    double  m_precisao;
    int     m_particao;
};


#endif /* gLEGENDRE_02_hpp */
