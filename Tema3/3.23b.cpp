#include <iostream>
using namespace std;

const int N = 5;

int segLongMax(int a[N]);

int segLongMax(int a[N]){

	int cont = 1, contAux = 1;

	if (N > 0){
		for(int i = 0; i < N-1; i++){

			if (a[i] == a[i+1])
				contAux++;
			else
				contAux = 1;
			
			if (contAux > cont)
				cont = contAux;
		}
	}

	return cont;
}

int main(){

	int v[N] = {0,1,0,1,0};

	cout << segLongMax(v);

	return 0;
}
