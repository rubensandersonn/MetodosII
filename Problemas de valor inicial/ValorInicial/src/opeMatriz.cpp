/*
	AUTOR: RUBENS ANDERSON - COMPUTAÇÃO UFC 2017
	DESC: Operações sobre matrizes definidas na classe matriz
*/
#include "../headers/opeMatriz.hpp"

opeMatriz::opeMatriz()
{

}

matriz opeMatriz::multiply(matriz M, matriz N)
{
	// fluxo excessão start
	if(true)
	{
		if(M.getNumLinha() <= 0 || M.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz 0 vazia!\n (multiply)\n";
			return M;
		}
		if(N.getNumLinha() <= 0 || N.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz 1 vazia!\n (multiply)\n";
			return N;
		}
		if(M.getNumColuna() != N.getNumLinha()){
			cout << "	Nao, cara! Matrizes incoerentes!\n (multiply)\n";
			matriz * erro = new matriz();
			return (*erro);
		}
	}
	    // fluxo excessão finish

	double total = 0;

	matriz * R = new matriz();

	for(int i = 0; i < M.getNumLinha(); i++){
		for(int j = 0 ; j < N.getNumColuna(); j++){
			total = 0;
			for(int k = 0; k < N.getNumLinha(); k++){
				total += M.get(i, k) * N.get(k, j);
			}
			R->push(total, i, j);
		}
	}
	return (*R);
}

matriz opeMatriz::gerarVetorColunaZeros(int n)
{
	    // fluxo excessão start
	if(true)
	{
		if(n <= 0){
			cout << "	Nao vale! nao passe numero de termos nao positivo! \n (gerarVetorColunaZeros)\n";
			return gerarVetorColunaZeros(1);
		}
	}
	    // fluxo excessão finish

	matriz * N = new matriz();
	for(int i = 0; i < n ; i++){
		N->push(0, i, 0);
	}
	return (*N);
	}

matriz opeMatriz::multiplyByEscalar(matriz M, double c)
{
	    // fluxo excessão start
	if(true)
	{
		if(M.getNumLinha() <= 0 || M.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz vazia!\n (multiplyByEscalar)\n";
			return M;
		}
	}
	    // fluxo excessão finish

	matriz * R = new matriz();

	for(int i = 0; i < M.getNumLinha(); i++){
		for(int j = 0; j < M.getNumColuna(); j++){
			R->push( c * M.get(i,j), i , j);
		}
	}
	return (*R);
}

double opeMatriz::produtoEscalar(matriz x, matriz y)
{
	    // fluxo excessão start
	if(true)
	{
		if(x.getNumLinha() <= 0 || x.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe vetor 0 vazia!\n (produtoEscalar)\n";
			return 0;
		}
		if(y.getNumLinha() <= 0 || y.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe vetor 1 vazia!\n (produtoEscalar)\n";
			return 0;
		}
		if(x.getNumColuna() > 1 || y.getNumColuna() > 1){
			cout << "	Nao, cara! Nao trabalhamos com matrizes, so com vetores!\n (produtoEscalar)\n";
			return 0;
		}
		if(x.getNumLinha() != y.getNumLinha()){
			cout << "	Nao, mano! Os vetores tem tamanhos diferentes!\n (produtoEscalar)\n";
			return 0;
		}
	}
	    // fluxo excessão finish


	double ac = 0;
	for(int i = 0; i < x.getNumLinha(); i++){
		ac = x.get(i,0) * y.get(i,0) + ac;
	}
	return ac;
}

double opeMatriz::Modulo(matriz v)
{
	 // fluxo excessão start
	if(true)
	{
		if(v.getNumLinha() <= 0){
			cout << "	Nao vale! nao passe vetor vazio!\n (Modulo)\n";
			return 0;
		}
	}
	    // fluxo excessão finish

	return pow( produtoEscalar(v, v) , 0.5);
}

matriz opeMatriz::normalizar(matriz x)
{
	 // fluxo excessão start
	if(true)
	{
		if(x.getNumLinha() <= 0){
			cout << "	Nao vale! nao passe vetor vazio!\n (normalizar)\n";
			return x;
		}
	}
	    // fluxo excessão finish
	return multiplyByEscalar(x, 1/ Modulo(x));
}
matriz opeMatriz::transpor(matriz M)
{
	    // fluxo excessão start
	if(true)
	{
		if(M.getNumLinha() <= 0 || M.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz vazia!\n (transpor)\n";
			return M;
		}
	}
	    // fluxo excessão finish

	matriz * R = new matriz();

	for(int i = 0; i < M.getNumLinha(); i++){
		for(int j = 0; j < M.getNumColuna(); j++){
			R->push( M.get(i,j), j , i);
		}
	}
	return (*R);
}

matriz opeMatriz::resolverSLComLU(vector<matriz> LU, matriz x)
{
	    // fluxo excessão start
	if(true)
	{
		if(LU[0].getNumLinha() <= 0 || LU[0].getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz L vazia!\n (resolverSLComLU)\n";
			return LU[0];
		}
		if(LU[1].getNumLinha() <= 0 || LU[1].getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz U vazia!\n (resolverSLComLU)\n";
			return LU[1];
		}
		if(x.getNumColuna() <= 0){
			cout << "	kkk eae men! o chute inicial (1) nao deve vazio, nao eh mesmo?\n (resolverSLComLU)\n";
			return x;
		}
		if(LU[0].getNumLinha() != LU[0].getNumColuna()){
			cout << "	Suavera?! So trabalhamos com matrizes L quadradas!\n (resolverSLComLU)\n";
			return x;
		}
		if(LU[1].getNumLinha() != LU[1].getNumColuna()){
			cout << "	Suavera?! So trabalhamos com matrizes U quadradas!\n (resolverSLComLU)\n";
			return x;
		}
		if(LU[1].getNumLinha() != LU[0].getNumColuna()){
			cout << "	Nao, mano! As dimensoes de L e U devem ser iguais!\n (resolverSLComLU)\n";
			return x;
		}
		if(x.getNumColuna() > 1){
			cout << "	kkk eae men! o chute inicial (1) deve ser um vetor!\n (resolverSLComLU)\n";
			return x;
		}
		if(x.getNumLinha() != LU[0].getNumColuna()){
			cout << "	O loco bixo! O numero de colunas de LU deve ser igual ao de linhas de (1)!\n (resolverSLComLU)\n";
			return x;
		}
	}
	    // fluxo excessão finish

	/*LU[0].escreveMatriz();
	LU[1].escreveMatriz();
	opeMatriz::multiply(LU[0], LU[1]).escreveMatriz();*/

	matriz z = resolverSistemaTriangularInf(LU[0], x);
	return resolverSistemaTriangularSup(LU[1], z);
}

matriz opeMatriz::resolverSistemaTriangularInf(matriz L, matriz b){
	    // fluxo excessão start
	if(true)
	{
		if(L.getNumLinha() <= 0 || L.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz L vazia!\n (resolverSistemaTriangularInf)\n";
			return b;
		}

		if(b.getNumColuna() <= 0){
			cout << "	kkk eae men! o chute inicial (1) nao deve vazio, nao eh mesmo?\n (resolverSistemaTriangularInf)\n";
			return b;
		}
		if(L.getNumLinha() != L.getNumColuna()){
			cout << "	Suavera?! So trabalhamos com matrizes L quadradas!\n (resolverSistemaTriangularInf)\n";
			return b;
		}

		if(b.getNumColuna() > 1){
			cout << "	kkk eae men! o chute inicial (1) deve ser um vetor!\n (resolverSistemaTriangularInf)\n";
			return b;
		}
		if(b.getNumLinha() != L.getNumColuna()){
			cout << "	O loco bixo! O numero de colunas de L deve ser igual ao de linhas de (1)!\n (resolverSistemaTriangularInf)\n";
			return b;
		}
	}
	    // fluxo excessão finish
	double ac = 0;
	matriz z = gerarVetorColunaZeros(L.getNumLinha());

	for(int i = 0; i < L.getNumColuna(); i ++){
		ac = 0;
		for(int k = 0; k < i; k++){
			ac = L.get(i,k) * z.get(k,0) + ac;
		}
		z.push( (1/ L.get(i,i) ) * (b.get(i,0) -  ac), i , 0);
	}
	return z;
}

matriz opeMatriz::resolverSistemaTriangularSup(matriz U, matriz b){
	    // fluxo excessão start
	if(true)
	{
		if(U.getNumLinha() <= 0 || U.getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz U vazia!\n (resolverSistemaTriangularSup)\n";
			return b;
		}

		if(b.getNumColuna() <= 0){
			cout << "	kkk eae men! o chute inicial (1) nao deve vazio, nao eh mesmo?\n (resolverSistemaTriangularSup)\n";
			return b;
		}
		if(U.getNumLinha() != U.getNumColuna()){
			cout << "	Suavera?! So trabalhamos com matrizes U quadradas!\n (resolverSistemaTriangularSup)\n";
			return b;
		}

		if(b.getNumColuna() > 1){
			cout << "	kkk eae men! o chute inicial (1) deve ser um vetor!\n (resolverSistemaTriangularSup)\n";
			return b;
		}
		if(b.getNumLinha() != U.getNumColuna()){
			cout << "	O loco bixo! O numero de colunas de U deve ser igual ao de linhas de (1)!\n (resolverSistemaTriangularSup)\n";
			return b;
		}
	}
	    // fluxo excessão finish
	double ac = 0;

	matriz y = gerarVetorColunaZeros(U.getNumLinha());

	for(int i = U.getNumColuna() - 1; i >= 0; i = i - 1){
		ac = 0;
		for(int k = i + 1; k < U.getNumColuna(); k++){
			ac = ac + U.get(i,k) * y.get(k,0);
		}
		y.push( ( (1/ U.get(i,i)) * (b.get(i,0) - ac) ), i, 0 );
	}

	return y;
}

void opeMatriz:: multiplicaLinhaPorEscalar(matriz * M, double c, int linha){
	    // fluxo excessão start
	if(true)
	{
		if(M->getNumLinha() <= linha){
			cout << "	Nao vale! A linha passada esta fora da matriz!\n (multiplicaLinhaPorEscalar)\n";
			return;
		}
		if(M->getNumLinha() <= 0 || M->getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz U vazia!\n (multiplicaLinhaPorEscalar)\n";
			return;
		}
	}
		// fluxo excessao finish

	for(int i = 0; i < M->getNumColuna(); i++){
		M->push(c * M->get(linha, i), linha, i);
	}
}

void opeMatriz:: somaEntreLinhas(matriz * M, int linha1, int linha2, double c){
	    // fluxo excessão start
	if(true)
	{
		if(M->getNumLinha() <= linha1 || M->getNumLinha() <= linha2 ){
			cout << "	Nao vale! A linha (1) ou (2) passada(s) esta(o) fora da matriz!\n (multiplicaLinhaPorEscalar)\n";
			return;
		}
		if(M->getNumLinha() <= linha1){
			cout << "	Nao vale! A linha (1) passada esta fora da matriz!\n (multiplicaLinhaPorEscalar)\n";
			return;
		}
		if(M->getNumLinha() <= linha2){
			cout << "	Nao vale! A linha (2) passada esta fora da matriz!\n (multiplicaLinhaPorEscalar)\n";
			return;
		}

		if(M->getNumLinha() <= 0 || M->getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz U vazia!\n (multiplicaLinhaPorEscalar)\n";
			return;
		}
	}
		// fluxo excessao finish

	for(int i = 0; i < M->getNumColuna(); i++){
		M->push( M->get(linha1, i) * c + M->get(linha2, i) , linha2, i);
	}
}

vector<matriz> opeMatriz::makeLU(matriz A)
{
		// fluxo excessao start
	vector<matriz> v;
	if(true)
	{
		if(A.getNumColuna() <= 0 || A.getNumLinha() <= 0){
			cout << "	kkk eae men! A matriz deve ser nao vazia!\n (makeLU)\n";
			return v;
		}
		if(A.getNumColuna() != A.getNumLinha()){
			cout << "	Oi sumido! A matriz deve quadrada!\n (makeLU)\n";
			return v;
		}
	}
		// fluxo excessao finish

	double f = 1;

	int n = A.getNumColuna();

	matriz * L = new matriz(n);

	matriz U = A;

	for(int j = 0 ;  j < n; j++){

		for(int i = j+1;  i < n; i++){

			f = U.get(i,j) / U.get(j, j);
			L->push(f, i, j );

			opeMatriz::somaEntreLinhas(&U, j, i , -f);
		}
	}


	v.push_back((*L));
	v.push_back((U));
	return v;
}

matriz opeMatriz::mais(matriz M, matriz N)
{
		// fluxo excessao start
	if(true)
	{
		if(M.getNumColuna() <= 0 || M.getNumLinha() <= 0){
			cout << "	kkk eae men! A matriz (0) deve ser nao vazia!\n (mais)\n";
			return M;
		}
		if(N.getNumColuna() <= 0 || N.getNumLinha() <= 0){
			cout << "	kkk eae men! A matriz (1) deve ser nao vazia!\n (mais)\n";
			return N;
		}
		if(M.getNumColuna() != N.getNumColuna() || M.getNumLinha() != N.getNumLinha()){
			cout << "	Turu bem?! As matrizes devem ter dimensoes compativeis!\n (mais)\n";
			matriz * k = new matriz();
			return (*k);
		}
	}
		// fluxo excessao finish
	matriz * R = new matriz();
	for(int i = 0; i < M.getNumLinha(); i++){
		for(int j = 0; j < N.getNumColuna(); j++){
			R->push( M.get(i,j) + N.get(i,j), i , j );
		}
	}

	return (*R);
}

matriz opeMatriz::menos(matriz M, matriz N)
{

	return mais(M, multiplyByEscalar(N, -1));
}

matriz opeMatriz:: tripartir(matriz A){
	matriz * v = new matriz();
	matriz * v2 = new matriz();

	for(int j = 0; j < A.getNumColuna()-3; j++){
		// fazendo v = 0
		for(int i = 0; i < A.getNumColuna(); i++){
			v->push(0, i, 0);
		}
		for(int i = j+1; i < A.getNumColuna(); i++){
			v->push( A.get(i, j) , i, 0);
		}

		double cv = Modulo(*v);

		// fazendo v2 = 0
		for(int i = 0; i < A.getNumColuna(); i++){
			v2->push(0, i, 0);
		}
		for(int i = j+1; i < A.getNumColuna(); i++){
			v2->push( cv , i, 0);
		}

		matriz N = menos(*v, *v2);

		matriz n = normalizar(N);

		matriz * I = new matriz(n.getNumLinha());

		matriz H = menos( *I, multiplyByEscalar( multiply(n, transpor(n) ), 2) );

		A = multiply( multiply(H, A), H);
	}
	return A;
}