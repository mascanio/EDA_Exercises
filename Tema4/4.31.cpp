#include <iostream>

const int N = 6;

int complementario(int n);

int complementario(int n){
	int r;

	if (n == 0)
	{
		r = 0;
	}
	else
	{
		r = 10 * complementario(n/10) + ( 9 -(n % 10));
	}
	return r;
}

int main(){

	std::cout << complementario(146720);

	return 0;
}