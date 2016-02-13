#include <iostream>
using namespace std;

const int N = 6;

int iguales(int v[N], int n);

int iguales(int v[N], int n){
	int cont = 0;
	if (n == -1)
	{
		cont = 0;
	}
	else if (n > v[n])
	{
		cont = 0;
	}
	else
	{
		cont = iguales(v, n-1);
		if (v[n] == n)
		{
			cont++;
		}
	}
	return cont;
}

int main(){

	int v[N] = {-1,0,1,2,4,5};

	cout << iguales(v, N-1);


	return 0;
}
