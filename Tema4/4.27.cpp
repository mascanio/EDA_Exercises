#include <iostream>
#include <cmath>

const int N = 6;
bool forma(int v[], int n);
bool forma(int v[], int a, int b, int& unos);

bool forma(int v[], int n){
	bool r = false;

	//if (true){
		int unos = 0;
		r = forma(v, 0, n-1, unos);
	//}

	return r;
}
bool forma(int v[], int a, int b, int& unos){
	bool r;
	if (a > b)
		r = unos == 0;

	else if (v[a] != v[b] || (v[a] != 1 && v[a] != 0) || unos < 0)
		r = false;
	
	else {
		if (v[a] == 1)
			unos++;
		else
			unos--;
		r = forma(v,a+1,b-1,unos);
	}

	return r;
}
int main(){

	int v[N] = {1,1,0,0,1,1};

	std::cout << forma(v, N);

	return 0;
}