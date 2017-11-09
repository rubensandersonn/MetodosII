//
//  N4.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef N4_imp_hpp
#define N4_imp_hpp

#include "N4.hpp"
#include "IntegralDupla.hpp"
#include <math.h>

class N4 : public Funcao_R2
{
public:
  N4 (){
  }

    double f(double s, double t)
    {

        return (-0.25)*(s - 1)*(t+1);

    }
private:

};


#endif /* N4_imp_hpp */
