/*
	Rubens Anderson, computação UFC 2017.1
	Programa de metodos de autovetores/valores 
*/

#include "headers/matriz.hpp"
#include "headers/opeMatriz.hpp"
#include "headers/autov.hpp"
#include <stdlib.h>

using namespace std;

matriz criarMatrizDefault(int simetria){
	matriz * A = new matriz(3);
	
	A->push(4, 0,0);
	A->push(-1, 1,1);
	A->push(2, 2,2);

	if(simetria == 1){
		// nao simetrica

		A->push(-3, 1,2);
		A->push(5, 2,1);

		A->push(2, 0,2);
		A->push(9, 2,0);
	}else{
		// simetrica

		A->push(-3, 1,2);
		A->push(-3, 2,1);

		A->push(2, 0,2);
		A->push(2, 2,0);
		
	}

	return *A;
}

matriz criarVetorDefault(){

	matriz b = opeMatriz::gerarVetorColunaZeros(3);
	
	b.push(1, 0,0);
	b.push(-1, 1,0);
	b.push(2, 2,0);

	return b;
}


// ---------------------------------------------------------------------------


int main(){

	system("clear || cls");

	int makeOwnMat = -1;
	int sim = -1;
	
	int encerrar = 0;
	int ci = 0;
	int cj = 0;

	double d = 0;
	double dim = 0;

	matriz A;
	matriz b;

	matriz y;


	while(makeOwnMat < 0 || makeOwnMat > 1){
		cout << " Deseja entrar sua propria matriz ou escolher uma default? (default 3x3)\n (0: default ; 1: entrar matriz)\n";
		cin >> makeOwnMat;
	}

	if(makeOwnMat == 1){

		cout << " Entre a dimensao da matriz:\n ";
		cin >> dim;

		if(dim > 10){
			cout << "\n Matriz muito grande...\n";
			return 0;
		}

		A = opeMatriz::gerarVetorColunaZeros(dim);
		b = opeMatriz::gerarVetorColunaZeros(dim);

		while(encerrar == 0){
			cout << " Digite as coordenadas de matriz que você deseja inserir\n i: ";
			cin >> ci;
			cout << " \n j: ";
			cin >> cj;

			if(ci >= dim || cj >= dim || ci < 0 || cj < 0){
				cout << "\n ERRO! Nao pode extrapolar a dimensao da matriz!\n";
			}else{
				
				cout << " Digite o valor a ser inserido nesta coordenada\n";
				cin >> d;

				A.push(d, ci, cj);

			}
			cout << " Deseja encerrar?\n (1: sim ; 0: nao) ";
			cin >> encerrar;
		}

		system("clear || cls");

		encerrar = 0;

		while(encerrar == 0){
			cout << "\n Digite a coordenada do vetor b que você deseja inserir\n i: ";
			cin >> ci;
			
			if(ci >= dim || ci < 0){
				cout << "\n ERRO! Nao pode extrapolar a dimensao da matriz!\n";
			}else{
				
				cout << " Digite o valor a ser inserido nesta coordenada\n";
				cin >> d;

				b.push(d, ci, 0);

			}
			cout << " Deseja encerrar?\n (1: sim ; 0: nao) ";
			cin >> encerrar;
		}

	}else{
		// default
		while(sim < 0 || sim > 1){
			cout << " Matriz simetrica ou nao?\n (0: simetrica ; 1: nao simetrica) ";
			cin >> sim;
		}
		
		 A = criarMatrizDefault(sim);
		 b = criarVetorDefault();
	}

	system("clear || cls");	

	// criada a matriz, vamos as contas

	int metodo = 0;

	while(metodo < 1 || metodo > 6){
		cout << "\n Entre o Metodo a ser testado: \n";
		cout << " (1) : Potencia \n";
		cout << " (2) : Potencia Inversa \n";
		cout << " (3) : Potencia c/ Deslocamento \n";
		cout << " (4) : Jacobi \n";
		cout << " (5) : QR \n";
		cout << " (6) : HouseHolder \n";
		
		cin >> metodo;
	}

	cout << " 		matriz original = \n";
	A.escreveMatriz();


	matriz autovetores = opeMatriz::gerarVetorColunaZeros(1);
	double autovalor = 0;
	matriz H;

	double mi = 0;

	switch(metodo){
		case 1:
			cout << "\n		--- Metodo da Potencia ---\n\n";

			autovalor = autov::metodoPotencia(A, b, 0.0000001, &autovetores);

			cout << " Autovalor encontrado: " << autovalor << endl;
			cout << " Autovetor correspondente: \n";
			autovetores.escreveMatriz();

			autov::testarAutovetor(A, autovetores, autovalor);

			break;

		case 2:
			cout << "\n		--- Metodo da Potencia Inversa ---\n\n";

			autovalor = autov::metodoPotenciaInversa(A, b, 0.0000001, &autovetores);


			cout << " Autovalor encontrado: " << autovalor << endl;
			cout << " Autovetor correspondente: \n";
			autovetores.escreveMatriz();

			autov::testarAutovetor(A, autovetores, autovalor);

			break;

		case 3:

			cout << "\n		--- Metodo da Potencia Deslocada ---\n\n";
			
			
			cout << " Entre com o valor do chute para a funcao: ";
			cin >> mi;

			autovalor = autov::metodoPotenciaDesloc(A, b, 0.0000001, &autovetores, mi);

			cout << " Autovalor encontrado: " << autovalor << endl;
			cout << " Autovetor correspondente: \n";
			autovetores.escreveMatriz();

			autov::testarAutovetor(A, autovetores, autovalor);
		
			break;

		case 4:
			cout << "\n		--- Metodo Jacobi ---\n\n";

			H = autov::metodoJacobi(A, 0.001, &autovetores);

			cout << "\n matriz modificada = \n";
			H.escreveMatriz();


			y = opeMatriz::gerarVetorColunaZeros(H.getNumLinha());

			for(int i = 0; i < H.getNumLinha(); i++){
				y.push(H.get(i,i), i,0);
			}


			cout << "\n autovetores (nas linhas) = \n";
			autovetores.escreveMatriz();

			cout << "\n autovalores de A = \n";
			y.escreveMatriz();

			cout << "\n --- Comeco testes com autovetores encontrados em Jacobi--\n";

			for(int i = 0; i < y.getNumLinha(); i++){
				cout << "\n	-- autovetor numero " << i << "-- " << endl;
				autov:: testarAutovetor(A, opeMatriz::transpor(opeMatriz::getLinha(autovetores, i)), y.get(i,0));
			}
			
			cout << "\n\n --- Fim dos testes com autovetores encontrados em Jacobi--\n\n";

			break;
		

		case 5:
			cout << "\n		---Metodo QR---\n\n";

			H = autov::metodoQR(A, 0.001, &autovetores);

			y = opeMatriz::gerarVetorColunaZeros(H.getNumLinha());

			for(int i = 0; i < H.getNumLinha(); i++){
				y.push(H.get(i,i), i,0);
			}

			cout << " Matriz modificada: \n";
			H.escreveMatriz();

			cout << "\n matriz Qt acumulada = \n";
			autovetores.escreveMatriz();

			cout << "\n autovalores de A = \n";
			y.escreveMatriz();

			break;

		case 6:
			cout << "\n		---Metodo HouseHolder---\n\n";

			H = opeMatriz:: tripartir(A);

			cout << "\n matriz modificada = \n";
			H.escreveMatriz();

			break;

	}


	return 0;


}