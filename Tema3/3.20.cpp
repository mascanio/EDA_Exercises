#include <iostream>
using namespace std;

const int N = 8;

int max_resta(int a[N]);

int max_resta(int a[N]){

	int p = 0, q = 1;

	for(int i = 1; i < N; i++){
		if (a[i]-a[q] > a[p]-a[q])
			p = i;
		else if (a[p]-a[i] > a[p]-a[q])
			q = i;
	}

	return a[p]-a[q];
}

int main(){

	int v[N] = {-450,100,3,0,100,40,-10,1};

	cout << max_resta(v);

	return 0;
}
