#include <iostream>
using namespace std;
#include <cmath>
int cambioBase(bool v[], int n);

int cambioBase(bool v[], int n){
	int num = 0;
		if (n == 1)
			num = v[0];
		else{
			num += cambioBase(v, n-1);
			num += v[n-1] * pow(2,n-1);
		}
    return num;
}

int main(){

bool v[2] = {1,0};
    cout << cambioBase(v, 2);

    return 0;
}
