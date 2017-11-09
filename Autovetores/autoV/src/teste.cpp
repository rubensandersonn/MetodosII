// multiplique uma matriz nxn por um vetor, um vetor nx1 por um vetor nx1 ou qualquer coisa do tipo

#include <iostream>
#include <vector>

using namespace std;

class matriz{
public:
	void escreveMatriz()
	{
		for(int i = 0; i < sizeLinha; i++){
			cout << "	|" ;
			for (int j = 0; j < sizeColuna; j++)
			{
				cout << "	" <<  m[i][j] << " 	";
			}
			cout << "	|" ;
		}
	}

	vector < vector <double> > createIdentity(int n)
	{
		vector < vector <double> > I;
		for(int i = 0; i < n ; i++){
			vector<double> v = gerarVectorZeros(n);
			v[i] = 1;
			I[i].push_back(v);
		}

		return I;
	}

	matriz(int n){
		sizeColuna = n;
		sizeLinha = n;
		m = createIdentity(n);
	}

	matriz()
	{
		sizeColuna = 0;
		sizeLinha = 0;
	}

	double getNumLinha()
	{
		return sizeLinha;
	}

	double getNumColuna(){
		return sizeColuna;
	}

	double get(int i, int j)
	{
		if(i < sizeLinha && j < sizeColuna){
			return m[i][j];
		}
		return 0;
	}

	void push(double c, int i, int j){
		if(i >= sizeLinha){
			for(int l = sizeLinha; l <= i; l++){
				m.push_back(gerarVectorZeros(sizeColuna));
			}
			sizeLinha = i+1;
		}
		if(j >= sizeColuna){
			for(int l = 0; l < sizeLinha; l++){
				for(int k = sizeColuna; k <= j; k++){
					m[l].push_back(0);
				}
			}
			sizeColuna = j+1;
		}
		m[i][j] = c;
	}

	vector <double> gerarVectorZeros(int n){
		vector<double> v;
		for(int i = 0; i < n; i++){
			v.push_back(0);
		}
		return v;
	}
private:
	int sizeLinha;
	int sizeColuna;
	vector < vector <double> > m;
}

matriz multiply(matriz M, matriz N){
	matriz * R = new matriz();
	for(int i = 0; i < M.getNumLinha(); i++){
		for(int j = 0 ; j < N.getSsizeLinha(); j++){
			total = 0;
			for(int k = 0; k < M.getNumColuna(); k++){
				total += M.get(i, k) * N.get(k, j);
			}
			R.push(total, i, j);
		}
	}
	return (*R);
}

matriz gerarVetorColunaZeros(int n){
		matriz * N = new matriz();
		for(int i = 0; i < n ; i++){
			N->push(0, i, 0);
		}
		return (*N);
	}

matriz multiplyByEscalar(matriz M, double c){
	matriz * R = new matriz();

	for(int i = 0; i < M.getNumLinha(); i++){
		for(int j = 0; j < M.getNumColuna(); j++){
			R->push( c * M.get(j,i), i , j);
		}
	}
	return (*R);
}

double produtoEscalar(matriz x, matriz y){
	double ac = 0;
	for(int i = 0; i < x.getNumLinha(); i++){
		ac = x.get(i,0) * y.get(i,0) + ac;
	}
	return ac;
}

double Modulo(matriz v){
	return pow( produtoEscalar(v, v) , 0.5);
}

matriz normalizar(matriz x){
	return multiplyByEscalar(x, 1/ Modulo(x));
}
matriz transpor(matriz M){
	matriz * R = new matriz();

	for(int i = 0; i < M.getNumLinha(); i++){
		for(int j = 0; j < M.getNumColuna(); j++){
			R->push( M.get(j,i), i , j);
		}
	}
	return (*R);
}

matriz resolverSLComLU(vector<matriz> LU, matriz x){

	matriz z = gerarVetorColunaZeros();
	matriz y = gerarVetorColunaZeros();

	matriz L = LU[0];
	matriz U = LU[1];

	double ac = 0;

	// achando z

	for(int i = 0; i < L.getNumColuna(); i ++){
		ac = 0;
		for(int k = 0; k < i; k++){
			ac = L.get(i,k) * x.get(k,0) + ac;
		}
		z.push(x.get(i,0) -  ac, i , 0);
	}

	// achando y

	for(int i = U.getNumColuna() - 1; i >= 0; i = i - 1){
		ac = 0;
		for(int k = i + 1; k < U.getNumColuna(); k++){
			ac = ac + U.get(i,k) * x.get(k,0);
		}
		y.push( ( (1/ U.get(i,i)) * (z.get(i,0) - ac) ), i, 0 );
	}

	return y;
}

vector<matriz> makeLU(matriz A){
	double f = 1;

	matriz L = createIdentity(A.getNumColuna());

	matriz U = L;

	for(int j = 0 ;  j < U.getNumColuna(); j++){
		U.push( A.get(0,j), 0, j);
	}

	for(int j = 0 ;  j < A.getNumColuna() - 1; j++){
		for(int i = 0 ;  i < A.getNumColuna(); i++){

			f = A.get(i,j) / A.get(j, j);
			L.push(f, i, j );

			for(int k = j; k < A.getNumColuna(); k++){
				U.push( A.get(j,k) * f + A.get(i,k), i, k);
			}
		}
	}

	vector<matriz> v;
	v.push_back(L);
	v.push_back(U);
	return v;
}
matriz mais(matriz M, matriz N){
	matriz * R = new matriz();
	for(int i = 0; i < M.getNumColuna(); i++){
		for(int j = 0; j < N.getNumLinha(); j++){
			R->push( M.get(i,j) + N.get(i,j), i , j );
		}
	}

	return (*R);
}

matriz menos(matriz M, matriz N){
	return mais(M, multiplyByEscalar(N, -1));
}


double metodoPotencia(matriz A, matriz x, double epsilon){ // retorna o autovalor l1

	matriz u = normalizar(x);
	matriz y = multiply(A, u);

	matriz holder = multiply(transpor(u), y);

	double oldLambida = holder.get(0,0);
	double newLambida = 0;

	while(fabs(oldLambida - newLambida) / fabs(oldLambida) > epsilon){

		oldLambida = newLambida;
		newLambida = 0;

		u = normalizar(y);
		y = multiply(A, u);

		holder = multiply(transpor(u), y);
		newLambida = holder.get(0,0);
	}
	return newLambida;
}


double metodoPotenciaInversa(matriz A, matriz x, double epsilon){ // retorna o autovalor l1
	// tem que inverter A

	matriz u = normalizar(x);

	matriz y = resolverSLComLU(A, u);

	matriz holder = multiply( transpor(u), y);

	double oldLambida = holder.get(0,0);
	double newLambida = 0;


	while(fabs(oldLambida - newLambida) / fabs(oldLambida) > epsilon){

		oldLambida = newLambida;
		newLambida = 0;

		u = normalizar(y);
		y = resolverSLComLU(A, u);

		holder = multiply( transpor(u), y);

		newLambida = holder.get(0,0);

	}
	return 1 / newLambida;
}

matriz tripartir(matriz A){
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

		double cv = Modulo(v);

		// fazendo v2 = 0
		for(int i = 0; i < A.getNumColuna(); i++){
			v2->push(0, i, 0);
		}
		for(int i = j+1; i < A->getNumColuna(); i++){
			v2->push( cv , i, 0);
		}

		matriz N = menos(v, v2);

		matriz n = normalizar(N);

		matriz H = menos( I, multiplyByEscalar( multiply(n, transpor(n) ), 2) );

		A = multiply( multiply(H, A), H);
	}
	return A;
}
