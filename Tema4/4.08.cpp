#include <iostream>
using namespace std;

int bin(int n);

int bin(int n){
    int out = 0;

    if(n == 0){
        out = 0;
    }
    else{
        out += (bin(n/2) * 10);
        out += (n%2);
    }
    return out;
}

int main(){

    for (int i = 0; i < 20; i++)
    cout << bin(i) << endl ;

    return 0;
}
