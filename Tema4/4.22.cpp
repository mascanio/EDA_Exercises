#include <iostream>

const int N = 10;

void parImpar(int v[], int n);
void parImpar(int v[], int a, int b);

void parImpar(int v[], int n){
	parImpar(v, 0, N-1);
}
void parImpar(int v[], int a, int b){
	//base if (a == b) return;
	if (a != b){
		while (((v[a] % 2) == 0) && a < b)
			a++;
		while (((v[b] % 2) != 0) && b > a)
			b--;
		int aux = v[a];
		v[a] = v[b];
		v[b] = aux;
		parImpar(v, a, b);
	}	
}

int main(){

	int v[N] = {0,2,4,6,8,10,12,14,16,18};

	parImpar(v, N);

	for (int i = 0; i < N; i++)
		std::cout << v[i] << std::endl;

	return 0;
}