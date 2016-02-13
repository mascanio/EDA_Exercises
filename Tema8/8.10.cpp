#include <iostream>
using namespace std;

#include "Pila.h"

void vagones(int n, int salida[]) {
	
	int i = 0;
	bool correcto;

	if (i+1 == salida[i])
	{
		while (i < n  && i+1 == salida[i])
		{
			i++;
		}
	}
	else
	{
		Pila<int> pila;

		while (i < n)
		{
			pila.apila(salida[i]);
			i++;
		}
		i = 0;
		while (!pila.esVacia() && pila.cima() == i+1)
		{
			pila.desapila();
			i++;
		}
	}

	cout << (i == n ? "Correcto" : "Incorrecto") << endl ;
}

int main() {

	int v[] = {5,4,3,2,1};

	vagones(5, v);

	int x[] = {1,2,3,4,5};

	vagones(5, x);


	int y[] = {1,1,1,1,1};

	vagones(5, y);


	return 0;
}