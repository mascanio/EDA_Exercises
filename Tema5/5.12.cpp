#include <iostream>

const int N = 3;

int posMin(int v[], int n);
int posMin(int v[], int a, int b);

int posMin(int v[], int n) {
	return posMin(v, 0, n);
}

int posMin(int v[], int a, int b) {
	int r;
	int mid = a + (b-a) / 2;

	if (b-a > 1) {
		if (v[mid-1] > v[mid]) {
			r = posMin(v, mid, b);
		}
		else if (v[mid-1] < v[mid]) {
			r = posMin(v, a, mid);
		}
	}
	else {
		r = mid;
	}

	return r;
}
int main() {

	int v[N] = {2,0,2};

	std::cout << posMin(v, N);

	return 0;
}