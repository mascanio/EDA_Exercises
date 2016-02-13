#include <iostream>
using namespace std;

const int N = 5;

int segLongMax(int a[N]);

int segLongMax(int a[N]){

	int cont = 0, contAux = 0;

	if (N > 0){
		for(int i = 0; i < N; i++){

			if (a[i] == 0)
				contAux++;
			else
				contAux = 0;
			
			if (contAux > cont)
				cont = contAux;
		}
	}

	return cont-1;
}

int main(){

	int v[N] = {0,0,0,1,0};

	cout << segLongMax(v);

	return 0;
}
