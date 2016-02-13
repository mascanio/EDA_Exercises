#include <iostream>
using namespace std;

double combi(int n, int m);

double combi(int n, int m){
	double r;

	if (n == m)
	{
		r = 1;
	}
	else if (m == 0)
	{
		r = 1;
	}
	else
	{
		r = combi(n-1, m-1) + combi(n-1, m);
	}
	return r;
}

int main(){

	cout << combi(40,8);

	return 0;
}
