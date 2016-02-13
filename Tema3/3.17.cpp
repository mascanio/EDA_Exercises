#include <iostream>
using namespace std;

const int N = 5;

int heroicos(int x[N]){
    int fib[N+2] = {0,1};
    int cont = 0;

    for(int i = 0; i < N; i++){
        //indice heroico
        if(x[i] > fib[i])
            cont++;
        //calcular fib
        fib[i+2] = fib[i+1] + fib[i];
    }

    return cont;
}

int main(){
    int v[N] = {0,0,0,0,0};
    cout << heroicos(v);

    return 0;
}
