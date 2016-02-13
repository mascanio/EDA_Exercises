#include <iostream>
using namespace std;

const int N = 5;

int credito_seg_max(int a[N]);

int credito_seg_max(int a[N]){

	int cont = 0, contAux = 0;

	if (N > 0){
		for(int i = 0; i < N; i++){

			if (a[i] > 0)
				contAux++;
			else if (a[i] <= 0)
				contAux = 0;
			
			if (contAux > cont)
				cont = contAux;
		}
	}

	return cont;
}

int main(){

	int v[N] = {1,0,0,1,1};

	cout << credito_seg_max(v);

	return 0;
}
