#include <iostream>
using namespace std;

void fib(int n, int& r, int& s);
void fib(int n, int& r, int& s){
    if (n == 0){
        s = 1;
        r = 0;
    }
    else if (n == 1){
        r = 1;
        s = 1;
    }
    else{
        int aux1, aux2;
        fib(n-1,aux1, s);
        fib(n-2,aux2, s);
        r = aux1 + aux2;
        s = r + aux1;
    }
}

int main(){
    int r,s;

    fib(7,r,s);

    cout << r << " " << s;
}
