//
//  Y_q5.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Y_q5_hpp
#define Y_q5_hpp

#include "N2.hpp"
#include "N3.hpp"
#include "N4.hpp"
#include "Funcao_R2.hpp"

#include <math.h>

class Y_q5 : public Funcao_R2
{
public:
  Y_q5 (){
  }

    double f(double s, double t)
    {
      N2 * n2 = new N2;
      N3 * n3 = new N3;
      N4 * n4 = new N4;

      return 1*n2->f(s,t) + 3*n3->f(s,t) + 2*n4->f(s,t);

    }
};


#endif /* Y_q5_imp_hpp */
