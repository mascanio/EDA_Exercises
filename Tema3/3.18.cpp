#include <iostream>
using namespace std;

const int N = 10;

int miradores(int x[N]);

int miradores(int x[N]){
    int cont = 1; //v[n-1] es mirador
    int max = x[N-1];

    for(int i = N-2; i >= 0; i--){
        if(x[i] > max){
            max = x[i];
            cont++;
        }
    }

    return cont;
}

int main(){

    int v[N] = {9,100,0,0,0,490,0,0};

    cout << miradores(v);

    return 0;
}
