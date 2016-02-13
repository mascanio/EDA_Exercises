#include <iostream>

const int N = 10;

bool mont(int v[], int n);
bool mont(int v[], int a, int b);

bool mont(int v[], int n){
	return mont(v, 0, N-1);
}
bool mont(int v[], int a, int b){
	bool r;
	if (a == b)
		r = true;

	else if (v[a] >= v[a+1] && v[b-1] <= v[b])
		r = false;

	else {
		if (v[a] < v[a+1])
			a++;
		if (v[b-1] > v[b])
			b--;

		r = mont(v, a, b);
	}
	return r;
}

int main(){

	int v[N] = {0,8,7,6,5,4,3,2,1,-12};

	std::cout << mont(v, N);

	return 0;
}