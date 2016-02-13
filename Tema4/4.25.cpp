#include <iostream>

const int N = 10;
int numIguales(int u[], int v[], int n, int m);
int numIgualesRec(int u[], int v[], int n, int m);

int numIguales(int u[], int v[], int n, int m){
	int r;

	if (n <= m)
	{
		r = numIgualesRec(u,v,n-1,m-1);
	}
	else
	{
		r = numIgualesRec(v,u,m-1,n-1);
	}
	return r;
}

int numIgualesRec(int u[], int v[], int n, int m){
	int r;

	if (n == -1 || m == -1)
		r = 0;
	else {
		if (u[n] > v[m])
			r = numIgualesRec(u,v,n-1,m);
		else
			r = numIgualesRec(u,v,n-1,m-1);

		if (u[n] == v[m])
			r++;
	}

	return r;
}


int main(){

	int u[N] = {0,1,2,3,4,5,6,7,8,9};
	int v[N] = {0,1,2,3,4,5,6,7,8,9};

	std::cout << numIguales(u, v, N, N);

	return 0;
}