#include <iostream>
using namespace std;

void movimiento(int i, int j, int& cont);
void hanoi(int n, int ini, int fin, int aux, int& cont);

void movimiento(int i, int j, int& cont){
	cout << "Movimiento de la varilla " << i << " a la varilla " << j << endl ;
   cont++;
}

void hanoi(int n, int ini, int fin, int aux, int& cont){

	if (n == 1){
		movimiento(ini, fin, cont);
	}
	else{
		hanoi(n-1, ini, aux, fin, cont);
		movimiento(ini, fin, cont);
		hanoi(n-1, aux, fin, ini, cont);
		movimiento(aux, fin, cont);
	}
}

int main(){
   int cont = 0;
   for(int i = 3; i < 10; i++){
      hanoi(i, 1, 2, 3, cont);
      cout << cont << endl;
      cont = 0;
	}
   return 0;
}
