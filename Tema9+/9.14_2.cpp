//#define _9_14_2
#ifdef _9_14_2

#define AUX /
#define DEBUG //AUX

#include <iostream>
using namespace std;
#include "Arbus.h"

const int TAM = 10000;

int main() {
	Arbus<string, bool> arbus;
	Arbus<string, bool>::Iterador it = arbus.principio();

	string telfs[TAM] ;

	int casos;
	cin >> casos;

	for (int i = 0; i < casos; i++)
	{
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> telfs[i];

		try {
			Arbus<string, bool> arbus;
			Arbus<string, bool>::Iterador it = arbus.principio();

			//para cada numero en la lista
			for (int i = 0; i < n; i++)
			{
				//para cada parte del numero (9, 91, 911...)
				for (int j = 0; j < telfs[i].length(); j++) 
				{
					DEBUG cout << "Probando numero " << telfs[i] << " usando prefijo " << telfs[i].substr(0, j+1) << endl ;
					
					it = arbus.principio();
					//Buscamos si el prefijo está y si es nújero completo
					while (it != arbus.final() && it.clave() != telfs[i].substr(0, j+1)) {
						it.avanza();
					} 
					if (it == arbus.final()) { //Si no lo encuenrta se inserta
						DEBUG cout << "Inserto : " << telfs[i].substr(0, j+1) << endl ;
						arbus.inserta(telfs[i].substr(0, j+1),  j == telfs[i].length()-1); //Indicamos si es final o no
					} else if (it.valor() || j == telfs[i].length()-1) { 
						//Si el prefijo está y además es final se sale o este msimo lo completa
						throw 0;
					}
				}
			}
			cout << "YES" << endl ;
		} catch (int) {
			cout << "NO" << endl ;
		}
	}

	return 0;
}

#endif /* _9_14_2 */