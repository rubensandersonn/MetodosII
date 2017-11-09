/*
	AUTOR: RUBENS ANDERSON - COMPUTAÇÃO UFC 2017
	DESC: classe com operações de autovalores
*/
#include "../headers/autov.hpp"

void autov::testarAutovetor(matriz A, matriz autovetor, double a)
{
	// fluxo excessão start
	if(true)
	{
		if(A.getNumLinha() <= 0 || A.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz vazia!\n (testarAutovetor)\n";
			return;
		}
		if(autovetor.getNumLinha() <= 0 || autovetor.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe autovetor vazio!\n (testarAutovetor)\n";
			return ;
		}
		if(A.getNumColuna() != autovetor.getNumLinha()){
			cout << "	Nao, cara! Matrizes incoerentes!\n (testarAutovetor)\n";
			return ;
		}
	}
	    // fluxo excessão finish

	matriz At = opeMatriz::multiply(A, autovetor);
	matriz lt = opeMatriz::multiplyByEscalar(autovetor, a);

	cout << "\n Desejamos que A*t = \n";
	At.escreveMatriz();

	cout << "\n Seja igual a l*t = \n";

	lt.escreveMatriz();

}

double autov::metodoPotencia(matriz A, matriz x, double epsilon, matriz * autovetor)
{
	// fluxo excessão start
	if(true)
	{
		if(A.getNumLinha() <= 0 || A.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz vazia!\n (metodoPotencia)\n";
			return 0;
		}
		if(x.getNumLinha() <= 0 || x.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe vetor chute vazio!\n (metodoPotencia)\n";
			return 0;
		}
		if(A.getNumColuna() != x.getNumLinha()){
			cout << "	Nao, cara! Matrizes incoerentes!\n (metodoPotencia)\n";
			return 0;
		}
		if(epsilon <= 0){
			cout << "	Nao pode! precisao deve se positiva!\n (metodoPotencia)\n";
			return 0;
		}
	}
	    // fluxo excessão finish
	matriz y = x;
	matriz u;
	double oldLambida = 10;
	double newLambida = 0;

	int i = 0;

	matriz holder;
	while(fabs(oldLambida - newLambida) / fabs(oldLambida) > epsilon){

		i++;

		oldLambida = newLambida;

		u = opeMatriz::normalizar(y);
		y = opeMatriz::multiply(A, u);

		holder = opeMatriz::multiply(opeMatriz::transpor(u), y);

		newLambida = holder.get(0,0);
	}
	for(int n = 0; n < y.getNumLinha(); n++){
		autovetor->push(u.get(n, 0), n, 0 );
	}
	return newLambida;
}


double autov::metodoPotenciaInversa(matriz A, matriz x, double epsilon, matriz * autovetor)
{
	// fluxo excessão start
	if(true)
	{
		if(A.getNumLinha() <= 0 || A.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz vazia!\n (metodoPotenciaInversa)\n";
			return 0;
		}
		if(x.getNumLinha() <= 0 || x.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe vetor chute vazio!\n (metodoPotenciaInversa)\n";
			return 0;
		}
		if(A.getNumColuna() != x.getNumLinha()){
			cout << "	Nao, cara! Matrizes incoerentes!\n (metodoPotenciaInversa)\n";
			return 0;
		}
		if(epsilon <= 0){
			cout << "	Nao pode! precisao deve se positiva!\n (metodoPotenciaInversa)\n";
			return 0;
		}
	}

	matriz u = opeMatriz::normalizar(x);

	vector <matriz> LU = opeMatriz::makeLU(A);

	matriz L = LU[0];
	matriz U = LU[1];

	matriz w = opeMatriz::resolverSistemaTriangularInf(L, u);
	matriz y = opeMatriz::resolverSistemaTriangularSup(U, w);

	matriz holder = opeMatriz::multiply( opeMatriz::transpor(u), y);

	double oldLambida = holder.get(0,0);
	double newLambida = 0;


	while(fabs(oldLambida - newLambida) / fabs(oldLambida) > epsilon){

		oldLambida = newLambida;
		newLambida = 0;

		u = opeMatriz::normalizar(y);

		w = opeMatriz::resolverSistemaTriangularInf(L, u);
		y = opeMatriz::resolverSistemaTriangularSup(U, w);

		holder = opeMatriz::multiply( opeMatriz::transpor(u), y);

		newLambida = holder.get(0,0);

	}
	for(int n = 0; n < y.getNumLinha(); n++){
		autovetor->push(u.get(n, 0), n, 0 );
	}
	return 1 / newLambida;
}

double autov::metodoPotenciaDesloc(matriz A, matriz x, double epsilon, matriz * autovetor, double mi)
{
	// fluxo excessão start
	if(true)
	{
		if(A.getNumLinha() <= 0 || A.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz vazia!\n (metodoPotenciaDesloc)\n";
			return 0;
		}
		if(x.getNumLinha() <= 0 || x.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe vetor chute vazio!\n (metodoPotenciaDesloc)\n";
			return 0;
		}
		if(A.getNumColuna() != x.getNumLinha()){
			cout << "	Nao, cara! Matrizes incoerentes!\n (metodoPotenciaDesloc)\n";
			return 0;
		}
		if(epsilon <= 0){
			cout << "	Nao pode! precisao deve se positiva!\n (metodoPotenciaDesloc)\n";
			return 0;
		}
		if(autovetor == NULL){
			cout << "	Nao pode! autovetor nulo!\n (metodoPotenciaDesloc)\n";
			return 0;
		}

	}
	// fluxo excessão finish

	matriz *I = new matriz(A.getNumColuna());
	matriz B = opeMatriz::menos(A, opeMatriz::multiplyByEscalar(*I, -mi));

	double va = autov::metodoPotenciaInversa(B, x, epsilon, autovetor);

	return va - mi;
}

matriz autov:: metodoJacobi(matriz A, double epsilon, matriz * autovetores)
{
	// fluxo excessão start
	matriz nulo = opeMatriz::gerarVetorColunaZeros(A.getNumColuna());
	if(true)
	{
		if(A.getNumLinha() <= 0 || A.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz vazia!\n (metodoJacobi)\n";
			return nulo;
		}
		if(epsilon <= 0){
			cout << "	Nao pode! precisao deve se positiva!\n (metodoJacobi)\n";
			return nulo;
		}
		if(autovetores == NULL){
			cout << "	Nao pode! autovetor nulo!\n (metodoJacobi)\n";
			return nulo;
		}
		if(!opeMatriz::isSimetrica(A)){
			cout << "	Passei pra avisar que a matriz nao eh simetrica! fikadika!\n (metodoJacobi)\n";
		}

	}
	// fluxo excessão finish

	matriz R;
	matriz Rt;
	matriz * T = new matriz(A.getNumColuna());

	while(!opeMatriz::ModuloAbaixoDiagonal(A, epsilon)){
		for(int j = 0; j < A.getNumColuna() - 1; j++){
			for(int i = j+1; i < A.getNumLinha(); i++ ){

				//cout << "passo (" << i << ", " << j << ")\n";

				R = opeMatriz::makeMatrizRotacao(A, i, j);
				Rt = opeMatriz::transpor(R);

				A = opeMatriz::multiply(R, A);

				/*
				cout << " R A = \n";
				A.escreveMatriz();

				cout << " A = \n";
				A.escreveMatriz();
				*/

				A = opeMatriz::multiply(A, Rt);

				(*T) = opeMatriz::multiply(R, *T);
			}
		}
	}

	// atribuindo os valores da matriz de autovalores

	for(int i = 0; i < A.getNumLinha(); i++){
		for(int j = 0; j < A.getNumColuna(); j++){
			autovetores->push( T->get(i,j) , i , j);
		}
	}

	return A;
}

matriz autov:: findR(matriz A)
{

	matriz * I = new matriz(A.getNumColuna());
	matriz Pt = *I;
	matriz R = A;
	matriz Qt = *I;

	double theta = 0;

	for (int j = 0; j < A.getNumLinha()-1; ++j)
	{
		for (int i = j+1; i < A.getNumLinha(); ++i){
			if(A.get(i,j) != 0  && A.get(j,j) != 0){

				theta = atan(A.get(i,j)/ A.get(j,j));


				Pt = findQ(A, i, j);

				(R) = opeMatriz:: multiply(Pt, R);
			}
		}
	}

	return R;
}

matriz autov:: findQ(matriz A, int i , int j)
{


	matriz * Q = new matriz(A.getNumLinha());

	// fluxo ...
	if(i < j){
		int aux = j;
		j = i;
		i = aux;
	}

	if(fabs(A.get(i,j)) != 0 && fabs(A.get(j,j)) != 0){
		//cout << "entrou\n";
		double theta = atan(A.get(i,j)/A.get(j,j));

		Q->push( cos(theta), i,i);
		Q->push( cos(theta), j,j);
		Q->push( -sin(theta), i,j);
		Q->push( sin(theta), j,i);
/*
		cout << "Q temp = \n" ;
		Q->escreveMatriz();

		cout << "theta = " << theta << endl;
*/
	}

	return *Q;
}

matriz autov:: metodoQR(matriz A, double epsilon, matriz * autovetores)
{
	matriz GAMBIARRA_POR_CAUSA_DO_CPP;
	matriz * Qac = new matriz(A.getNumColuna());

		int l = 0;
	while(!opeMatriz::ModuloAbaixoDiagonal(A, 0.0001) ){
		//cout << "\n l = " << l << endl;
		l++;
		for(int j = 0; j < A.getNumColuna() - 1; j++){
			for(int i = j + 1; i < A.getNumLinha(); i++){

				matriz R = findR(A);

				//cout << " i = " << i << ", j = " << j << endl;
				matriz Q = findQ(A, i, j);
				/*
				cout << " R = \n";
				R.escreveMatriz();

				cout << " Q = \n";
				Q.escreveMatriz();
				*/

				A = opeMatriz:: multiply(R, Q);

				GAMBIARRA_POR_CAUSA_DO_CPP = (opeMatriz:: multiply( (Q) , *Qac));

				Qac = &GAMBIARRA_POR_CAUSA_DO_CPP;
			}
		}
	}


	for(int z = 0; z < Qac->getNumLinha(); z++){
		for(int w = 0; w < Qac->getNumColuna(); w++){
			autovetores->push(Qac->get(z,w), z, w);
		}
	}
	/*
	cout << " A = \n";
	A.escreveMatriz();
	*/

	return A;
}
