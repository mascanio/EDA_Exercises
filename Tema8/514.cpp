#include <string>
#include <iostream>
#include "Pila.h"
using namespace std;

bool bloque(int n) {
	Pila<int> objetivo, intermedia, inicial;
	int leido;

	for (int i=0; i<n; i++) {
		cin >> leido;
		if ( ! leido) {
			cout << "\n";
			return false;
		}
		
		intermedia.apila(leido);
		inicial.apila(n-i);
	}
	while ( ! intermedia.esVacia()) {
		objetivo.apila(intermedia.cima());
		intermedia.desapila();
	}

	/*
		Algoritmo: (repito mientras quede algo en 'objetivo')
			- mientras la cima de 'intermedia' no coincida con la de 
			  'objetivo', saco de 'inicial' y apilo en 'intermedia'
			- si no he conseguido que coincidan, fin: era imposible
			  si no conseguido, extraigo ambas cimas
	    Si consigo vaciar 'objetivo', he demostrado que es posible.
	*/
	while ( ! objetivo.esVacia()) {
		while ( ! inicial.esVacia() &&
				(intermedia.esVacia() ||
				(intermedia.cima() != objetivo.cima())) ) {
			intermedia.apila(inicial.cima());
			inicial.desapila();
		}
		if (intermedia.esVacia() || 
			(intermedia.cima() != objetivo.cima())) {
			cout << "No\n";
			return true;
		}
		if (intermedia.cima() == objetivo.cima()) {
			intermedia.desapila();
			objetivo.desapila();
		}
	}
	cout << "Yes\n";
	
	return true;
}

int main() {	
	int n;
	cin >> n;
	do {
		while (bloque(n)) /**/;
		cin >> n;
	} while (n);	
	return 0;
}
