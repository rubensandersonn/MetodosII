//
//  X_q5.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef X_R2_imp_hpp
#define X_R2_imp_hpp

#include "X_q5.hpp"
#include "N2.hpp"
#include "N3.hpp"
#include "N4.hpp"

#include <math.h>

class X_q5 : public Funcao_R2
{
public:
  X_q5 (){
  }

    double f(double s, double t)
    {
      N2 * n2 = new N2;
      N3 * n3 = new N3;
      N4 * n4 = new N4;

        return 2*n2->f(s,t) + 3*n3->f(s,t) + n4->f(s,t);

    }

};


#endif /* X_R2_imp_hpp */
