#include <iostream>

typedef enum tLado {Babor, Estribor};

void ferry(float coches[], int n, int k, tLado sol[], float babor, float estribor);
void muestraSol(tLado sol[], int n);

void ferry(float coches[], int n, int k, tLado sol[], float babor, float estribor) {
   if (k < n) {
      if (coches[k] <= babor) {
         sol[k] = Babor;
         ferry(coches, n, k+1, sol, babor-coches[k], estribor);
      }
      if (coches[k] <= estribor) {
         sol[k] = Estribor;
         ferry(coches, n, k+1, sol, babor, estribor-coches[k]);
      }
      else if (coches[k] > babor) //soluion
         muestraSol(sol, k);
   }
   else
      muestraSol(sol, k);
}
void muestraSol(tLado sol[], int n) {
   for(int i = 0; i < n; i++) {
      std::cout << ((sol[i] == Babor) ? "BABOR " : "ESTRIBOR ");
   }
   std::cout << std::endl;
}

const int N = 5;

int main() {
   float coches[N] = {1,2,3,4,5};
   tLado sol[N];

   ferry(coches, N, 0, sol, 5, 5);

   return 0;
}
