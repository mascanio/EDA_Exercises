#include <iostream>
using namespace std;

const int N = 8;

int suma_buenos(int x[N]);

int suma_buenos(int x[N]){
    int s = 0;
    int pot = 1;

    for(int i = 0; i < N; i++){

        if(x[i] == pot)
            s += x[i];

        pot *= 2;
    }

    return s;
}

int main(){

    int v[N] = {1,2,3,8};

    cout << suma_buenos(v);

    return 0;
}
