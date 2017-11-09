/*
	arquivo de testes
*/

#include <iostream>
#include <math.h>

using namespace std;

void mudaMatriz(double * m[2]){
	m[0][0] = 99;
}

int main(){
	system("clear");

	double matriz[2][2] = {
		{1,2}, {3, 8}
	};



	cout << " m[0][0] = " << matriz[0][0] << endl;
	mudaMatriz(&matriz);
	cout << " m[0][0] = " << matriz[0][0] << endl;

	system("rm *.o ");
	return 0;
}