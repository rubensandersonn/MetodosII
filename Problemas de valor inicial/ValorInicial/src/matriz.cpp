/*
	AUTOR: RUBENS ANDERSON - COMPUTAÇÃO UFC 2017
	DESC: Definição de uma classe matriz
*/
#include "../headers/matriz.hpp"

matriz::matriz(int n){
	    // fluxo excessão start
	if(n < 0){
		cout << "espertinho! nao passe numero de termos negativo!\n " << n << endl;
		sizeColuna = 0;
		sizeLinha = 0;
	}
	    // fluxo excessão finish
	else{
		sizeColuna = n;
		sizeLinha = n;
		m = createIdentity(n);
	}
}

matriz::matriz()
{
	sizeColuna = 0;
	sizeLinha = 0;
}

void matriz::escreveMatriz()
{
	    // fluxo excessão start
	if(sizeLinha <= 0 || sizeColuna <= 0){
		cout << "Matriz vazia!\n (escreveMatriz)\n";
		return ;
	}
	    // fluxo excessão finish

	for(int i = 0; i < sizeLinha; i++){
		cout << "\n	| " ;
		for (int j = 0; j < sizeColuna; j++)
		{
			cout << " " <<  m[i][j] << " ";
		}
		cout << " |" ;
	}
	cout << "\n";
}

vector < vector <double> > matriz::createIdentity(int n)
{
	    // fluxo excessão start
	if(n < 0){
		cout << "espertinho! nao passe numero de termos negativo!\n (createIdentity)\n " << n << endl;
	}
	    // fluxo excessão finish

	vector < vector <double> > I;
	for(int i = 0; i < n ; i++){
		vector<double> v = gerarVectorZeros(n);
		v[i] = 1;
		I.push_back(v);
	}

	return I;
}


int matriz::getNumLinha()
{
	return sizeLinha;
}

int matriz::getNumColuna(){
	return sizeColuna;
}

double matriz::get(int i, int j)
{
		    // fluxo excessão start
	if(i < 0 || j < 0){
		cout << "espertinho! nao passe numero de termos negativo!\n (get)\n " << i << ", "  << j << endl;
		return 0;
	}
	if( (i >= sizeLinha) || (j >= sizeColuna)){
		cout << "espertinho! nao passe coordenadas maiores que a dimensao da matriz!\n (get)\n (i,j) = " << i << ", "  << j << " - m,n = " << sizeLinha << ", "  << sizeColuna << endl;
		escreveMatriz();
		return 0;
	}

		    // fluxo excessão finish

	return m[i][j];
}

void matriz::push(double c, int i, int j)
{
	    // fluxo excessão start
	if(i < 0 || j < 0){
		cout << "espertinho! nao passe coordenadas negativas!\n (push)\n (i,j) = " << i << ", "  << j << endl;
	}
	    // fluxo excessão finish
	if(i >= sizeLinha){

		//cout << "i >= " << sizeLinha << endl;

		for(int l = sizeLinha; l <= i; l++){
			m.push_back(gerarVectorZeros(sizeColuna));
		}
		sizeLinha = i+1;
	}
	if(j >= sizeColuna){

		//cout << "j >= " << sizeColuna << endl;

		for(int l = 0; l < sizeLinha; l++){
			for(int k = sizeColuna; k <= j; k++){
				m[l].push_back(0);
			}
		}
		sizeColuna = j+1;
	}
	m[i][j] = c;
}

vector <double> matriz::gerarVectorZeros(int n){
	    // fluxo excessão start
	if(n < 0){
		cout << "espertinho! nao passe numero de termos negativo!\n (gerarVectorZeros)\n";
	}
	    // fluxo excessão finish

	vector<double> v;
	for(int i = 0; i < n; i++){
		v.push_back(0);
	}
	return v;
}
