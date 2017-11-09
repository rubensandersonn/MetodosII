
#include "headers/forward_euler.hpp"
#include "headers/backward_euler.hpp"
#include "headers/modif_euler.hpp"
#include "headers/r_k_4.hpp"
#include "headers/pred_corr.hpp"
#include "headers/Funcao_carros.hpp"
#include "headers/Funcao.hpp"
#include "headers/Funcao_01.hpp"
#include "headers/Funcao_02.hpp"
#include "headers/Funcao_03.hpp"
#include "headers/Funcao_04.hpp"
#include "headers/constant.hpp"
#include "headers/q2_2.hpp"

#include "headers/matriz.hpp"
#include "headers/opeMatriz.hpp"
#include "headers/estado.hpp"
#include "headers/opeEstado.hpp"

#include <stdlib.h>

int main(int argc, char const *argv[])
{
    system("clear || cls");
    // cins
    cout << "   \n  --------------------------------------------------\n";
    cout << "   \n       ...Programa Problema de Valor Inicial... \n";
    cout << "   \n  --------------------------------------------------\n";

    int id_func = 0, metodo = 0;
    double k1 = 0, k2 = 0, m1 = 0, m2 = 0, a = 0, b = 0, dt = 0;

    Funcao_S * Fc;
    Funcao * F1;
    Funcao * F2;

    
    cout << "\n Entre o intervalo (a, b): \n";
        cout << " a = ";
        cin  >>  a;
        cout << "\n b = ";
        cin  >> b;

    while (dt <= 0)
    {
        cout << " Entre com o deslocamento delta t. \n";
        cin  >> dt;
    }

    // switch dos métodos

    while (metodo < 1 || metodo > 5)
    {
        cout << " Escolha o método de valor inicial. \n\n";
        cout << "1 - forward_euler. \n";
        cout << "2 - backward_euler. \n";
        cout << "3 - euler modificado. \n";
        cout << "4 - Runge-Kutta (4). \n";
        cout << "5 - preditor-corretor. \n";
        cin  >> metodo;
    }

    id_func = 0;

    int id = 0;

    while (id < 1 || id > 2)
    {
        cout << " Escolha a EDO a ser resolvida. \n\n";
        cout << "1 - sistema carros-molas. \n";
        cout << "2 - questao 2.2 prova 3 \n";
        cin  >> id;
    }

    double u2 = 0, u1 = 0, v1 = 0, v2 = 0;  
    cout << "   \n  --------------------------------------------------\n";
    cout << "\n       ...Inicalizando os problemas... \n";
    cout << "   \n  --------------------------------------------------\n";

    switch(id){
        case 1:
            // inicializando a função carros

            while (m1 <= 0)
            {
                cout << " Entre com a massa do primeiro bloco. \n";
                cin  >> m1;
            }

            while (m2 <= 0)
            {
                cout << " Entre com a massa do segundo bloco. \n";
                cin  >> m2;
            }

            while (k1 <= 0)
            {
                cout << " Entre com o coeficiente de dureza da primeira mola. \n";
                cin  >> k1;
            }

            while (k2 <= 0)
            { 
                cout << " Entre com o coeficiente de dureza da segunda mola. \n";
                cin  >> k2;
            }

            // F1

            while (id_func <= 0 || id_func > 5)
            {
                cout << " Escolha a função de força 1 (F1) a ser integrada: \n";
                cout << "\t1 - x^2 \n";
                cout << "\t2 - x^3 \n";
                cout << "\t3 - cos(x) \n";
                cout << "\t4 - sin(x) \n";
                cout << "\t5 - constante \n";
                cin  >> id_func;

            }

            switch (id_func)
            {
                case 1:
                    F1 = new Funcao_01;
                    break;
                case 2:
                    F1 = new Funcao_02;
                    break;
                case 3:
                    F1 = new Funcao_03;
                    break;
                case 4:
                    F1 = new Funcao_04;
                    break;
                case 5:
                    double c = 0;
                    cout << "\tEntre o valor da constante \n";
                    cin  >> c;
                
                    F1 = new constant(c);
                    break;
                
            }

            // agora F2

            id_func = 0;

            while (id_func <= 0 || id_func > 5)
            {
                cout << " Escolha a função de força 2 (F2) a ser integrada: \n";
                cout << "\t1 - x^2 \n";
                cout << "\t2 - x^3 \n";
                cout << "\t3 - cos(x) \n";
                cout << "\t4 - sin(x) \n";
                cout << "\t5 - constante \n";
                cin  >> id_func;

            }

            switch (id_func)
            {
                case 1:
                    F2 = new Funcao_01;
                    break;
                case 2:
                    F2 = new Funcao_02;
                    break;
                case 3:
                    F2 = new Funcao_03;
                    break;
                case 4:
                    F2 = new Funcao_04;
                    break;
                case 5:
                    double c = 0;
                    cout << "\tEntre o valor da constante \n";
                    cin  >> c;
                
                    F2 = new constant(c);
                    break;
            }

            // fim F2


            Fc = new Funcao_carros(k1, k2, m1, m2, F1, F2);


            cout << "Entre o valor inicial de: \n";
                cout << " u1(0) = ";
                cin  >>  u1;

                cout << " u2(0) = ";
                cin  >>  u2;

                cout << " v1(0) = ";
                cin  >>  v1;

                cout << " v2(0) = ";
                cin  >>  v2;
            break;

       

        case 2: 
            // questão 2.2
            Fc = new q2_2();

            cout << "Entre o valor inicial de: \n";
                cout << " y(0) = ";
                cin  >>  u1;

                cout << " y'(0) = ";
                cin  >>  u2;

                cout << " y''(0) = ";
                cin  >>  v1;
                
            break;
    }

    estado * S0 = new estado(u1,u2,v1,v2);
    vector<estado> v;
    forward_euler * FE;
    backward_euler * BE;
    modif_euler * ME;
    pred_corr * pc;
    r_k_4 * RK;

    switch (metodo){
        case 1:

            FE = new forward_euler(Fc, a, b, dt);

            v = FE->start(*S0);
            break;

        case 2: // aqui vai ficar feio...

            //

            BE = new backward_euler(Fc, a, b, dt, 0.01);

            v = BE->start(*S0);
            break;

        case 3: // aqui tambem...

            ME = new modif_euler(Fc, a, b, dt, 0.01);

            v = ME->start(*S0);
            break;
        case 4:

            RK = new r_k_4(Fc, a, b, dt);

            v = RK->start(*S0);
            break;
        case 5:
            pc = new pred_corr(Fc, a, b, dt);

            v = pc->start(*S0);
            break;
    }

    // fim switch metodos

    // escrevendo os pontos... ideal: mostrar um grafico maneiro. não estamos no ideal...

    cout << "   \n  --------------------------------------------------\n";
    cout << "\n         ...Escrevendo os pontos...\n";
    cout << "   \n  --------------------------------------------------\n\n";

    for (int i = 0; i < v.size(); i++)
    {
        cout << "       Em ti = " << a + i*dt << ", u1 = " << v[i].u1 << endl;
        cout << "       Em ti = " << a + i*dt << ", u2 = " << v[i].u2 << endl << endl;
    }
    cout << "   \n  --------------------------------------------------\n";

	return 0;
}