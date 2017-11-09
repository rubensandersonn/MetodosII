/*
	AUTOR: RUBENS ANDERSON - COMPUTAÇÃO UFC 2017
	DESC: Operações sobre matrizes definidas na classe matriz
*/
#include "../headers/opeMatriz.hpp"

opeMatriz::opeMatriz()
{

}


void opeMatriz:: trocaLinhas(matriz * M, int linha1, int linha2)
{
	// fluxo excessão start
	if(true)
	{
		if(M->getNumLinha() <= 0 || M->getNumColuna() <= 0){
			cout << "	Nao vale! nao passe matriz U vazia!\n (multiplicaLinhaPorEscalar)\n";
			return;
		}
		if(M->getNumLinha() <= linha1 || M->getNumLinha() <= linha2 || linha1 < 0 || linha2 < 0){
			cout << "	Nao vale! A linha passada esta fora da matriz!\n (multiplicaLinhaPorEscalar)\n";
			return;
		}
	}
		// fluxo excessao finish

	for(int j = 0; j < M->getNumColuna();j++){
		double c = M->get(linha1, j);
		M->push(M->get(linha2, j), linha1, j);
		M->push(c, linha2, j);
	}
}

void opeMatriz:: acheLinhaValida(matriz * M, int linha, int coluna){

	if(M->get(linha, coluna) > 0.00001){
		return ;
	}

	int i = 0;
	while(M->get(i, coluna) == 0 && i < M->getNumLinha()){
		i++;
	}
	if(i >= M->getNumLinha()){
		return;
	}
	trocaLinhas(M, linha, i);
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

double opeMatriz::determinante(matriz A)
{
	// fluxo excessao start
	if(true)
	{
		if(A.getNumColuna() <= 0 || A.getNumLinha() <= 0){
			cout << "	kkk eae men! A matriz deve ser nao vazia!\n (determinante)\n";
			return 0;
		}
	}
	// fluxo excessao finish

	double multiplicacao = 1;
	double soma = 0;

  	double y = 0;
  	int x = 0;
  	int n = 0;

	for (n=0; n<A.getNumLinha(); n++) {// numero de loops

	    for (x=0; x<A.getNumLinha(); x++) {

	        y = (x + n) % (int) A.getNumLinha();
	        multiplicacao = multiplicacao * A.get(x,(int) y);

	        cout << " | (x,y) = " << x << ", "<< y;

	    }

	    cout << endl;
    		soma = soma + multiplicacao;
  	}

  	cout << "soma = " << soma << endl;
  	multiplicacao = 1;


    for (n=A.getNumLinha()-1; n>=0; n = n-1) {

	  	for (x=A.getNumLinha()-1; x>=0; x = x-1) {// numero de loops

	        y = (x + n) % (int) A.getNumLinha();
	        multiplicacao = multiplicacao * A.get(x, y);
	        cout << " | (x,y) = " << x << ", "<< y << " | [Axy] = "<< A.get(x,y);

	    }
    		soma = soma - multiplicacao;
	    cout << endl;
  	}

  	return soma;
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
		if(Modulo(x) < 0.0001){
			cout << "	Vetor NULO!!\n (normalizar)\n";
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
			if(U.get(j,j) == 0){
				opeMatriz:: acheLinhaValida(&U, j ,j);
			}
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

matriz opeMatriz:: gerarMatrizHouseholoder(matriz A, int j)
{
	// fluxo excessao start
	matriz * I = new matriz(A.getNumColuna());

	if(true)
	{
		if(A.getNumColuna() <= 0 || A.getNumLinha() <= 0){
			cout << "	kkk eae men! A matriz deve ser nao vazia!\n (gerarMatrizHouseholoder)\n";
			return *I;
		}
		if(A.getNumColuna() != A.getNumLinha()){
			cout << "	Oi sumido! A matriz deve quadrada!\n (gerarMatrizHouseholoder)\n";
			return *I;
		}

		if(A.getNumColuna() <= j){
			cout << "	kkk eae men! i ou j sao fora de A!\n (gerarMatrizHouseholoder)\n";
			return *I;
		}
		if(!isSimetrica(A)){
			cout << "	Oi sumido!passei pra avisar que a matriz deve ser simetrica! segue o jogo...\n (gerarMatrizHouseholoder)\n";
		}

	}
	// fluxo excessao finish
	//A.escreveMatriz();

	matriz v = gerarVetorColunaZeros(A.getNumLinha());
	matriz v2 = gerarVetorColunaZeros(A.getNumLinha());

	// fazendo v = 0

	for(int i = j+1; i < A.getNumColuna(); i++){
		v.push( A.get(i, j) , i, 0);
	}

	v2.push( -Modulo(v), j+1, 0);
	//v = normalizar(v);
/*
	cout << "v = \n";
	v.escreveMatriz();
	cout << "v' = \n";
	v2.escreveMatriz();

	cout << "N = \n";
	N.escreveMatriz();

	cout << "n = \n";
	n.escreveMatriz();

	cout << "nnT = \n";
	H.escreveMatriz();

	cout << "H = \n";
	H.escreveMatriz();
*/

	matriz N = menos(v, v2);

	matriz n = normalizar(N);

	//matriz * I = new matriz(n.getNumLinha());
	//transpor(n).escreveMatriz();


	matriz H = multiply(n, transpor(n) );

	H = menos( *I, multiplyByEscalar( H, 2) );

	return H;

}

matriz opeMatriz:: tripartir(matriz A){
	// fluxo excessao start
	matriz nulo = gerarVetorColunaZeros(A.getNumLinha());

	if(true)
	{
		if(A.getNumColuna() <= 0 || A.getNumLinha() <= 0){
			cout << "	kkk eae men! A matriz deve ser nao vazia!\n (tripartir)\n";
			return nulo;
		}
		if(A.getNumColuna() != A.getNumLinha()){
			cout << "	Oi sumido! A matriz deve quadrada!\n (tripartir)\n";
			return nulo;
		}
		if(!isSimetrica(A)){
			cout << "	Oi sumido!passei pra avisar que a matriz deve ser simetrica! segue o jogo...\n (tripartir)\n";
		}

	}
	// fluxo excessao finish


	matriz v = gerarVetorColunaZeros(A.getNumLinha());
	matriz v2 = gerarVetorColunaZeros(A.getNumLinha());
	matriz H;
//for(int i = 0; i < 3; i++){
	for(int j = 0; j < A.getNumColuna()-2; j++){
		//cout  << "passo (" << i << ", " << j << ")\n";

		H = gerarMatrizHouseholoder(A, j);

		A = multiply(H, A);
		A = multiply(A, H);

		//cout << "A = \n";
		//A.escreveMatriz();
	//}
}
	return A;
}

matriz opeMatriz:: resolverNucleo(matriz M){

	// fluxo excessao start
	matriz nulo = gerarVetorColunaZeros(M.getNumLinha());

	if(true)
	{
		if(M.getNumColuna() <= 0 || M.getNumLinha() <= 0){
			cout << "	kkk eae men! M matriz deve ser nao vazia!\n (resolverNucleo)\n";
			return nulo;
		}
		if(M.getNumColuna() != M.getNumLinha()){
			cout << "	Oi sumido! M matriz deve quadrada!\n (resolverNucleo)\n";
			return nulo;
		}
	}
	// fluxo excessao finish


	int i = 0;
	while(M.get(i,i) == 0 && i < M.getNumLinha()) {
		i++;
	}
	if(i >= M.getNumLinha()){
		cout << "matriz nao valida\n";
		return nulo;
	}

	for(int j = 0; j < M.getNumLinha() - 1; j++){

		nulo.push( -M.get(j,i), j, 0);
		M.push(0, j,i);
		if(i == j){
			M.push(1, j,i);
		}

	}
	//opeMatriz:: acheLinhaValida(&M, i,i);

	return resolverSLComLU( makeLU(M), nulo);
}

bool opeMatriz:: ModuloForaDiagonal(matriz A, double epsilon){
	// fluxo excessao start
	if(true)
	{
		if(A.getNumColuna() <= 0 || A.getNumLinha() <= 0){
			cout << "	kkk eae men! A matriz deve ser nao vazia!\n (ModuloForaDiagonal)\n";
			return false;
		}
		if(epsilon <= 0){
			cout << "	Oi sumido! A tolerancia deve ser maior que 0!\n (ModuloForaDiagonal)\n";
			return false;
		}
	}
	// fluxo excessao finish

	double soma = 0;
	for(int i = 0; i < A.getNumLinha(); i++){
		for(int j = 0; j < A.getNumColuna(); j++){
			if(i != j){
				soma = soma +  fabs(A.get(i,j));
			}
		}
	}
	cout << soma << endl;
	if(fabs(soma) > epsilon){
		return false;
	}

	return true;
}
bool opeMatriz:: ModuloAbaixoDiagonal(matriz A, double epsilon){
	// fluxo excessao start
	if(true)
	{
		if(A.getNumColuna() <= 0 || A.getNumLinha() <= 0){
			cout << "	kkk eae men! A matriz deve ser nao vazia!\n (ModuloForaDiagonal)\n";
			return false;
		}
		if(epsilon <= 0){
			cout << "	Oi sumido! A tolerancia deve ser maior que 0!\n (ModuloForaDiagonal)\n";
			return false;
		}
	}
	// fluxo excessao finish

	double soma = 0;
	for(int j = 0; j < A.getNumColuna()-1; j++){
		for(int i = j+1; i < A.getNumLinha(); i++){

			soma = soma + fabs(A.get(i,j));

		}
	}
	if(fabs(soma) > epsilon){
		return false;
	}
	//cout << soma << ", " << epsilon << endl;

	return true;
}
bool opeMatriz:: ModuloAbaixoTriDiagonal(matriz A, double epsilon){
	// fluxo excessao start
	if(true)
	{
		if(A.getNumColuna() <= 0 || A.getNumLinha() <= 0){
			cout << "	kkk eae men! A matriz deve ser nao vazia!\n (ModuloForaDiagonal)\n";
			return false;
		}
		if(epsilon <= 0){
			cout << "	Oi sumido! A tolerancia deve ser maior que 0!\n (ModuloForaDiagonal)\n";
			return false;
		}
	}
	// fluxo excessao finish

	double soma = 0;
	for(int j = 0; j < A.getNumColuna()-2; j++){
		for(int i = j+2; i < A.getNumLinha(); i++){

			soma = soma +  fabs(A.get(i,j));

		}
	}
	cout << soma << endl;
	cout << fabs(soma) << endl;
	//cout << epsilon << endl;
	if(fabs(soma) > epsilon){
		return false;
	}

	return true;
}

bool opeMatriz:: isSimetrica(matriz A)
{
	// fluxo excessao start
	if(true)
	{
		if(A.getNumColuna() <= 0 || A.getNumLinha() <= 0){
			cout << "	kkk eae men! A matriz deve ser nao vazia!\n (isSimetrica)\n";
			return false;
		}
	}
	// fluxo excessao finish

	for(int i = 0; i < A.getNumLinha(); i++){
		for(int j = 0; j < A.getNumColuna(); j++){
			if(fabs(A.get(i,j) - A.get(j,i)) > 0.00001){
				return false;
			}
		}
	}
	return true;
}

matriz opeMatriz:: makeMatrizRotacao(matriz A, int i, int j)
{
	// fluxo excessao start
	matriz * I = new matriz(A.getNumColuna());
	if(true)
	{
		if(A.getNumColuna() <= 0 || A.getNumLinha() <= 0){
			cout << "	kkk eae men! A matriz deve ser nao vazia!\n (makeMatrizRotacao)\n";
			return *I;
		}

		if(A.getNumColuna() <= j || A.getNumLinha() <= i){
			cout << "	kkk eae men! i ou j sao fora de A!\n (makeMatrizRotacao)\n";
			return *I;
		}
		if(A.getNumColuna() != A.getNumLinha()){
			cout << "	kkk eae men! A matriz deve ser quadrada!\n (makeMatrizRotacao)\n";
			return *I;
		}

		if(A.get(i,j) == 0){
			//cout << " Voce esta tentando me enganar ? A(i,j) = 0.\n (makeMatrizRotacao)\n";
			return *I;
		}
	}
	// fluxo excessao finish

	double theta = 0;

	if( A.get(j,j) == A.get(i,i)){
		theta = 3.1416 / 4;
	}else{
		double a = 2 * (A.get(i,j) / (A.get(j,j) - A.get(i,i))) ;
		theta = 0.5 * atan(a);
	}

	matriz * R = new matriz(A.getNumColuna());

	R->push(cos(theta), j,j);
	R->push(cos(theta), i,i);
	R->push(-sin(theta), i,j);
	R->push(sin(theta), j,i);

	return *R;
}

bool opeMatriz:: resenberg(matriz A){
	return ModuloAbaixoTriDiagonal(A, 0.01);
}

matriz opeMatriz:: nucleoResenberg(matriz A){
	int m = A.getNumLinha();
	matriz n = opeMatriz::gerarVetorColunaZeros(m);

	matriz y;

	if(!resenberg(A)){
		return n;
	}

	double ac = 0;

	matriz b = multiplyByEscalar( getColuna(A, m - 2), -1 );

	for(int i = 0; i < m ; i++){
		if(i != m - 2){
			A.push(0, i, m-2);
		}
	}

	for(int i = A.getNumColuna() - 1; i >= 0; i = i - 1){
		ac = 0;
		for(int k = i + 1; k < A.getNumColuna(); k++){
			ac = ac + A.get(i,k) * y.get(k,0);
		}
		y.push( ( (1/ A.get(i,i)) * (b.get(i,0) - ac) ), i, 0 );
	}

	return y;
}

matriz opeMatriz:: getLinha(matriz A, int i)
{
	matriz v = transpor(gerarVetorColunaZeros(A.getNumColuna()));

	for(int j = 0; j < A.getNumColuna(); j++){
		v.push(A.get(i,j), 0, j);
	}

	return v;
}
matriz opeMatriz:: getColuna(matriz A, int j)
{
	matriz v = gerarVetorColunaZeros(A.getNumLinha());

	for(int i = 0; i < A.getNumLinha(); i++){
		v.push(A.get(i,j), i, 0);
	}

	return v;
}