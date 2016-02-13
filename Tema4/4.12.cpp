#include <iostream>
using namespace std;

bool palindroma(char c[], int n);
bool palindroma(char c[], int n, int paso);

bool palindroma(char c[], int n){

	return palindroma(c, n, 0);
}
bool palindroma(char c[], int n, int paso){
	bool r;

	if (paso == n/2)
	{
		r = c[paso] == c[n - paso - 1];
	}
	else if (c[paso] != c[n - paso - 1])
	{
		r = false;
	}
	else
	{
		r = palindroma(c, n, paso+1);
	}

	return r;
}

int main(){

	const int n = 4;

	char c[n] = {'a','b','b', 'a'};

	cout << palindroma(c,n);

	return 0;
}


//#include <iostream>
//using namespace std;
//
//bool palindroma(char c[], int n);
//bool palindroma(char c[], int n, int paso);
//
//bool palindroma(char c[], int n){
//
//	return palindroma(c, n, 0);
//}
//bool palindroma(char c[], int n, int paso){
//	bool r;
//
//	if (paso == n/2)
//	{
//		r = c[paso] == c[n - paso - 1];
//	}
//	else
//	{
//		r = (c[paso] == c[n - paso - 1]) && palindroma(c, n, paso+1);
//	}
//
//	return r;
//}
//
//int main(){
//
//	const int n = 4;
//
//	char c[n] = {'a','c','b', 'a'};
//
//	cout << palindroma(c,n);
//
//	return 0;
//}
