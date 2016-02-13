#include <iostream>
#include <cmath>

const int N = 6;

int ingresos(int v[], int n);
int ingresos(int v[], int n, int i);

int ingresos(int v[], int n){
	return ingresos(v, n-1, 0);
}

int ingresos(int v[], int n, int i) {
	int r;

	if (i > n/2)
	{
		r = 0;
	}
	else
	{
		r =  ingresos(v,n,i+1);
		r += pow(2,i) * (v[i] + v[n-i]);
	}

	return r;
}



int main(){

	int v[N] = {1,2,2,3,3,3};

	std::cout << ingresos(v, N);

	return 0;
}