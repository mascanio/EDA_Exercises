#include <iostream>
using namespace std;
#include <cmath>

void calculaCercanos(int v[], int tam, int& a, int& b);

void calculaCercanos(int v[], int tam, int& a, int& b){
    if (tam == 2){
        a = v[0];
        b = v[1];
    }
    else{
        calculaCercanos(v, tam-1, a, b, cont);
        int diferencia = abs(a - b);

        for(int i = 0; i < tam-1; i++){
            if(abs(v[tam-1]-v[i]) < diferencia){
                a = v[i];
                b = v[tam-1];
                diferencia = abs(a - b);
            }
        }
    }
}

int main(){

	int ar[11] = {131,5,328,23,0,1110,33,55,99,15,44};
	int N = 11;
	int A = 0; // Se puede inicializar a 0
	int B = 0;
	int cont = 0;
	calculaCercanos(ar,N,A,B, cont);
   cout << A << " " << B  << " " << cont;


    return 0;
}
