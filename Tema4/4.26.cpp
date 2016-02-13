#include <iostream>

const int N = 6;

int inflexion(int v[], int n);
int inflexion(int v[], int a, int b);

int inflexion(int v[], int n){
	return inflexion(v, 0, n-1);
}

int inflexion(int v[], int a, int b){
	int r;

	if (a == (b+1))
		r = a;
	else if (v[a] >= 0 && v[b] < 0)
	{
		r = -1;
	}
	else {
		if (v[a] < 0)
			a++;
		if (v[b] >= 0)
			b--;
		
		r = inflexion(v, a, b);
	}

	return r;
}

int main(){
	int v[N] = {-1,-1,0,-1,3,3};

	std::cout << inflexion(v, N);

	return 0;
}