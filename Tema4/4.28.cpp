#include <iostream>
#include <cmath>

const int N = 6;
bool escalera(int v[], int n);
bool escalera(int v[], int n, int i, int cont);

bool escalera(int v[], int n){

	return escalera(v,n-1,0,0);
}

bool escalera(int v[], int n, int i, int cont){
	bool r;
	
	if (i == n+1)
	{
		r = true;
	}
	else
	{
		int contActual = 0;

		while (v[i] == v[i+contActual])
			contActual++;

		if (contActual > cont)
			r = escalera(v, n, i+contActual, contActual);
		else 
			r = false;
	}

	return r;
}

int main(){

	int v[N] = {1,2,2,3,3,3};

	std::cout << escalera(v, N);

	return 0;
}