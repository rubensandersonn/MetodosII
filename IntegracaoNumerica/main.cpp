//
//  main.cpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "headers/Funcao.hpp"
#include "headers/Funcao_01.hpp"
#include "headers/Funcao_02.hpp"
#include "headers/Funcao_03.hpp"
#include "headers/Funcao_04.hpp"
#include "headers/Funcao_sqrt.hpp"
#include "headers/X_q5.hpp"
#include "headers/Y_q5.hpp"
#include "headers/Funcao_R2_imp.hpp"
#include "headers/Funcao_R2.hpp"

#include "headers/Integracao.hpp"
#include "headers/NC_A_P0.hpp"
#include "headers/NC_A_P1.hpp"
#include "headers/NC_A_P2.hpp"
#include "headers/NC_A_P3.hpp"
#include "headers/NC_A_P4.hpp"
#include "headers/NC_F_P1.hpp"
#include "headers/NC_F_P2.hpp"
#include "headers/NC_F_P3.hpp"
#include "headers/NC_F_P4.hpp"

#include "headers/IntegralDupla.hpp"

#include "headers/gCHEBSHEV.hpp"

#include "headers/gLEGENDRE_02.hpp"
#include "headers/gLEGENDRE_03.hpp"
#include "headers/gLEGENDRE_04.hpp"

#include "headers/gHERMITE_02.hpp"
#include "headers/gHERMITE_03.hpp"
#include "headers/gHERMITE_04.hpp"

#include "headers/gLAGUERRE_02.hpp"
#include "headers/gLAGUERRE_03.hpp"
#include "headers/gLAGUERRE_04.hpp"

#include "headers/quad_exp_simples.hpp"
#include "headers/quad_exp_dupla.hpp"
#include "headers/IntegralDupla_q5.hpp"

#include "headers/xSobreTan.hpp"
#include "headers/Funcao_semiesfera.hpp"
#include "headers/constant.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    system("clear");

    double co = 0;

    int         tipoquadratura              =  0;
    int         nc_fechada_ou_aberta        =  0;
    int         grau_polinomio_substituicao = -1;
    int         gauss_tipo                  =  0;
    int         particao_ou_precisao        =  0;
    int         numero_de_particoes         =  0;
    int         id_integrando               =  1;
    Funcao     *integrando                  =  0;
    Integracao *pintegrObj;

    double a        = -1.0;
    double b        =  1.0;
    double precisao =  0.001;
    double integral;

    int simplesOuDupla = -1;

    cout << "Bem-vindo ao programa de Integração numérica! \n\n";


    cout << "Escolha a função a ser integrada: \n";
    cout << "\t1 - x^2 \n";
    cout << "\t2 - x^3 \n";
    cout << "\t3 - cos(x) \n";
    cout << "\t4 - sin(x) \n";
    cout << "\t5 - sqrt(1 + 1/x ) \n";
    cout << "\t6 - 1/tan(x) \n";
    cout << "\t7 - f(x,y) =  2 y sin(x) + cos²(y)\n";
    cout << "\t8 - f(x,y) =  sqrt( 100 - (x² + y²))\n";
    cin  >> id_integrando;

    switch (id_integrando)
    {
        case 1:
            integrando = new Funcao_01;
            break;
        case 2:
            integrando = new Funcao_02;
            break;
        case 3:
            integrando = new Funcao_03;
            break;
        case 4:
            integrando = new Funcao_04;
            break;
        case 5:
            integrando = new Funcao_sqrt;
            break;
        case 6:
            integrando = new xSobreTan;
            break;
        case 7:

            tipoquadratura = 4;
            break;
        case 8:

            tipoquadratura = 5;
            break;
    }


    while (tipoquadratura < 1 || tipoquadratura > 5)
    {
        cout << "Escolha o método de integração. \n\n";
        cout << "1 - Newton-Cotes. \n";
        cout << "2 - Quadratura de Gauss. \n";
        cout << "3 - Exponenciação. \n";
        cin  >> tipoquadratura;
    }

    if (tipoquadratura == 1){
        // Quadratura de Newton-Cotes

        cout << "\n\nVocê escolheu quadratura de Newton-cotes \n\n";

        while (nc_fechada_ou_aberta < 1 || nc_fechada_ou_aberta > 2)
        {
            cout << "Escolha a filosofia adequada. \n";
            cout << "1 - Fórmulas fechadas. \n";
            cout << "2 - Fórmulas abertas.  \n";
            cin  >> nc_fechada_ou_aberta;
        }

        if (nc_fechada_ou_aberta == 1)
        {
            // N-C Fechada
            cout << "\n\nVocê escolheu quadratura de Newton-cotes fechada\n\n";

            while (grau_polinomio_substituicao < 1 || grau_polinomio_substituicao > 4)
            {
                cout << "\n\nEntre o grau do polinômio de substituição (1-4)\n\n";
                cin  >> grau_polinomio_substituicao;
            }
        }
        else
        {
            // N-C Aberta
            cout << "\n\nVocê escolheu quadratura de Newton-cotes aberta\n\n";

            while (grau_polinomio_substituicao < 0 || grau_polinomio_substituicao > 4)
            {
                cout << "\n\nEntre o grau do polinômio de substituição (0-4)\n\n";
                cin  >> grau_polinomio_substituicao;
            }
        }

        cout << "Entre o intervalo de integração (a, b): \n";
        cout << "a = ";
        cin  >>  a;
        cout << "\nb = ";
        cin  >> b;

        while(particao_ou_precisao < 1 || particao_ou_precisao > 2)
        {
            cout << "Você deseja particionar o intervalo de integração (a, b) ou quer definir uma precisão? \n";
            cout << "1 - Particionar.                     \n";
            cout << "2 - Definir a precisão do resultado. \n";
            cin  >>  particao_ou_precisao;
        }

        if (particao_ou_precisao == 1)
        {
            cout << "\n\nEntre o número de partições do intervalo (a,b) - número >= 1. \n";
            cin  >> numero_de_particoes;
        }
        else
        {
            cout << "\n\nEntre o valor da tolerância epslon (exemplo: 0.00001)\n";
            cin  >> precisao;
        }



        if (nc_fechada_ou_aberta == 1)
        {
            // N-C Fechada

            switch (grau_polinomio_substituicao)
            {
                case 1:
                    pintegrObj = new NC_F_P1(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;

                case 2:
                    pintegrObj = new NC_F_P2(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;
                case 3:
                    pintegrObj = new NC_F_P3(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;
                case 4:
                    pintegrObj = new NC_F_P4(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;
            }
        }
        else
        {
            // N-C Aberta
            switch (grau_polinomio_substituicao)
            {
                case 0:
                    pintegrObj = new NC_A_P0(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;

                case 1:
                    pintegrObj = new NC_A_P1(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;

                case 2:
                    pintegrObj = new NC_A_P2(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;
                case 3:
                    pintegrObj = new NC_A_P3(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;
                case 4:
                    pintegrObj = new NC_A_P4(integrando, a, b, numero_de_particoes, precisao);
                    integral   = pintegrObj->integrar();
                    break;
            }
        }

    }
    else if (tipoquadratura == 2)
    {
        // Quadratura de Gauss
        cout << "\n\nVocê escolheu quadratura de Gauss \n\n";

        while (gauss_tipo < 1 || gauss_tipo > 4)
        {
            cout << "Escolha a quadratura de gauss adequada. \n";
            cout << "1 - Gauss-Legendre.  \n";
            cout << "2 - Gauss-Hermite.   \n";
            cout << "3 - Gauss-Laguerre.  \n";
            cout << "4 - Gauss-Chebyshev. \n";
            cin  >> gauss_tipo;
        }

        while (grau_polinomio_substituicao < 2 || grau_polinomio_substituicao > 4)
        {
            cout << "\n\nEntre o grau do polinômio de substituição (0-4)\n\n";
            cin  >> grau_polinomio_substituicao;
        }
         switch (gauss_tipo){

            case 1: // lEGENDRE
                cout << "\n\nVocê escolheu quadratura de Gauss-Legendre \n\n";

                cout << "Entre o intervalo de integração (a, b): \n";
                cout << "a = ";
                cin  >>  a;
                cout << "\nb = ";
                cin  >> b;

                switch(grau_polinomio_substituicao){
                    case 2:
                        pintegrObj = new gLEGENDRE_02(integrando, a, b, grau_polinomio_substituicao, precisao);
                        integral   = pintegrObj->integrar();
                    break;

                    case 3:
                        pintegrObj = new gLEGENDRE_03(integrando, a, b, grau_polinomio_substituicao, precisao);
                        integral   = pintegrObj->integrar();
                    break;

                    case 4:
                        pintegrObj = new gLEGENDRE_04(integrando, a, b, grau_polinomio_substituicao, precisao);
                        integral   = pintegrObj->integrar();
                    break;

                }
            break;

            case 2: // HERMITE
                cout << "\n\nVocê escolheu quadratura de Gauss-Hermite \n\n         esta formula nao pede definicao de intervalo de integracao\n\n";
                switch(grau_polinomio_substituicao){
                    case 2:

                        pintegrObj = new gHERMITE_02(integrando);
                        integral   = pintegrObj->integrar();
                    break;

                    case 3:
                        pintegrObj = new gHERMITE_03(integrando);
                        integral   = pintegrObj->integrar();
                    break;

                    case 4:
                        pintegrObj = new gHERMITE_04(integrando);
                        integral   = pintegrObj->integrar();
                    break;

                }
            break;

            case 3: // LAGUERRE
                cout << "\n\nVocê escolheu quadratura de Gauss-Laguerre \n\n         esta formula nao pede definicao de intervalo de integracao\n\n";
                switch(grau_polinomio_substituicao){
                    case 2:
                        pintegrObj = new gLAGUERRE_02(integrando);
                        integral   = pintegrObj->integrar();
                    break;

                    case 3:
                        pintegrObj = new gLAGUERRE_03(integrando);
                        integral   = pintegrObj->integrar();
                    break;

                    case 4:
                        pintegrObj = new gLAGUERRE_04(integrando);
                        integral   = pintegrObj->integrar();
                    break;

                }
            break;

            case 4: // CHEBYSHEV
                cout << "\n\nVocê escolheu quadratura de Gauss-Chebyshev \n\n";
                while (grau_polinomio_substituicao < 0)
                {
                    cout << "\n\nEntre o grau do polinômio de substituição (>0)\n\n";
                    cin  >> grau_polinomio_substituicao;
                }


                cout << "Entre o intervalo de integração (a, b): \n";
                cout << "a = ";
                cin  >>  a;
                cout << "\nb = ";
                cin  >> b;

                pintegrObj = new gCHEBSHEV(integrando, a,b, grau_polinomio_substituicao);
                integral   = pintegrObj->integrar();

            break;

         }
    }
    else if(tipoquadratura == 3)
    {
        // Exponenciação
        cout << "\n\nVocê escolheu quadratura de Exponenciação \n\n";

         while (simplesOuDupla < 1 || simplesOuDupla > 2)
        {
            cout << "Escolha a exponencial adequada. \n";
            cout << "1 - exponencial simples. \n";
            cout << "2 - exponencial dupla.  \n";
            cin  >> simplesOuDupla;
        }

         cout << "Entre o intervalo de integração (a, b): \n";
                cout << "a = ";
                cin  >>  a;
                cout << "\nb = ";
                cin  >> b;

        do{
            cout << "\n\nEntre o valor da tolerância epslon (exemplo: 0.00001)\n";
            cin  >> precisao;
        }while(precisao <= 0);

        if(simplesOuDupla == 1){
            // exp simples
            pintegrObj = new quad_exp_simples(integrando, a, b, precisao);

            integral = pintegrObj->integrar();
        }else{
             // exp dupla
            pintegrObj = new quad_exp_dupla(integrando, a, b, precisao);

            integral = pintegrObj->integrar();
        }

    }else
    {
        // integral dupla

        id_integrando = 0;

        Funcao * c = 0;
        Funcao * d = 0;

        int alpha = 0;
        int betha = 0;

        while(id_integrando < 1 || id_integrando > 5){
            cout << "Escolha a função c(x) limite inferior a ser integrada em y: \n";
            cout << "\t1 - x^2 \n";
            cout << "\t2 - x^3 \n";
            cout << "\t3 - cos(x) \n";
            cout << "\t4 - sin(x) \n";
            cout << "\t5 - funcao constante \n";

            cin  >> id_integrando;
        }

        // achando c(x)

        switch (id_integrando)
        {
            case 1:
                c = new Funcao_01;
                break;
            case 2:
                c = new Funcao_02;
                break;
            case 3:
                c = new Funcao_03;
                break;
            case 4:
                c = new Funcao_04;
                break;
            case 5:
                co = 0;
                cout << "entre com o valor da constante ";
                cin >> co;
                c = new constant(co);
                break;

        }

        // achando d(x)

        id_integrando = 0;

        while(id_integrando < 1 || id_integrando > 5){
            cout << "Escolha a função d(x) limite superior a ser integrada no eixo y: \n";
            cout << "\t1 - x^2 \n";
            cout << "\t2 - x^3 \n";
            cout << "\t3 - cos(x) \n";
            cout << "\t4 - sin(x) \n";
            cout << "\t5 - funcao constante \n";

            cin  >> id_integrando;
        }

        switch (id_integrando)
        {
            case 1:
                d = new Funcao_01;
                break;
            case 2:
                d = new Funcao_02;
                break;
            case 3:
                d = new Funcao_03;
                break;
            case 4:
                d = new Funcao_04;
                break;
            case 5:
                co = 0;
                cout << "entre com o valor da constante ";
                cin >> co;
                d = new constant(co);
                break;
        }

        // achando os limites de integração em x

        cout << "Entre o intervalo de integração (a, b) no eixo y: \n";
        cout << "a = ";
        cin  >>  a;
        cout << "\nb = ";
        cin  >> b;

        while (alpha < 2 || alpha > 4)
        {
            cout << "\n\nEntre o grau do polinômio de substituição (0-4) no eixo y\n\n";
            cin  >> alpha;
        }

        while (betha < 2 || betha > 4)
        {
            cout << "\n\nEntre o grau do polinômio de substituição (0-4) no eixo x\n\n";
            cin  >> betha;
        }
        if(tipoquadratura == 4){

            Funcao_R2_imp * integrando_R2 = new Funcao_R2_imp;
            pintegrObj = new IntegralDupla(integrando_R2, a, b, c, d, alpha, betha);

        }else {
            X_q5 * x = new X_q5;
            Y_q5 * y = new Y_q5;

            Funcao_semiesfera * integrando_R2 = new Funcao_semiesfera;

            cout << "passou no declare da main\n";
            pintegrObj = new IntegralDupla_q5(integrando_R2, a, b, c, d, alpha, betha, x, y);

        }

        integral = pintegrObj->integrar();
    }


    cout << "A integral da função escolhida é : ";
    cout << integral <<"\n\n";


     //system("rm *.o ");

    return 0;
}


