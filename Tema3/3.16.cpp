#include <iostream>
using namespace std;

const int N = 8;

int suma_picos(int x[N]);

int suma_picos(int x[N]){
   int sum = x[0]; //x[0] es pico
   int max = x[0];

   for(int i = 0; i < N; i++){
        if(x[i] > max){
            max = x[i];
            sum += max;
        }
   }

    return sum;
}

int main(){

    int v[N] = {6,5,7};

    cout << suma_picos(v);

    return 0;
}
