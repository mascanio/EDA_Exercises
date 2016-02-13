#include <iostream>
using namespace std;

const int N = 5;

int buscar_cero(int a[N]);

int buscar_cero(int a[N]){

	int r = N-1;

	if (N > 0){
		for (int i = 0; i < N; i++)
		{
			if (a[i] == 0)
				r = i;
		}
	}

	return r;
}

int main(){

	int v[N] = {1,2,1,1,1};

	cout << buscar_cero(v);

	return 0;
}
