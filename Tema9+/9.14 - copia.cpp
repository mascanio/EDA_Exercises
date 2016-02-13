#define _14_10
#ifdef _14_10

#define AUX /
#define DEBUG /AUX

#include <iostream>
using namespace std;
#include "Arbus.h"

const string ERROR_INCONSISTENTE = "Error: lista inconsistente." ;
const int TAM = 1000;

int main() {
	Arbus<string, bool> arbus;
	Arbus<string, bool>::Iterador* it = &arbus.principio();

	string telfs[TAM] ;

	int n = 0;
	while (!cin.eof())
	{
		cin >> telfs[n];
		if(!cin.eof())  {
			n++;
		}
	}

	//int min = telfs[0].length();

	try {
		//arbus.inserta(telfs[0].substr(0,1), false);
		//para cada numero en la lista
		for (int i = 0; i < n; i++)
		{
			//	if(telfs[i].length() < min)
			//	min = telfs[i].length();			

			//para cada parte del numero (9, 91, 911...)
			for (int j = 0; j < telfs[i].length()-1; j++) {
				DEBUG cout << "Probando numero " << telfs[i] << " usando prefijo " << telfs[i].substr(0, j+1) << endl ;
				//if (arbus.esta(telfs[i].substr(0, j+1)) && arbus.consulta(telfs[i].substr(0, j+1)))
				//	throw 0;
				//DEBUG cout << "Inserto : " << telfs[i].substr(0, j+1) << endl ;
				//arbus.inserta(telfs[i].substr(0, j+1), false);
				
				it = &arbus.principio();
				//Buscamos si el prefijo está y si es nújero completo
				while (*it != arbus.final() && it->clave() != telfs[i].substr(0, j+1)) {
					it->avanza();
				} if (*it == arbus.final()) { //Si no lo encuenrta se inserta
					DEBUG cout << "Inserto : " << telfs[i].substr(0, j+1) << endl ;
					Arbus<string, bool> aux;
					aux.inserta(telfs[i].substr(0, j+1), false);
					it = &aux.principio();
					//arbus.inserta(telfs[i].substr(0, j+1), false);
				} else if (it->valor()) { //Si el prefijo está y además es final se sale
					throw 0;
				}
				/*
				try {
					if (arbus.consulta(telfs[i].substr(0, j+1)))
					{
						throw 0;
					}
				} catch (EClaveErronea) {
					DEBUG cout << "Inserto : " << telfs[i].substr(0, j+1) << endl ;
					arbus.inserta(telfs[i].substr(0, j+1), false);
				}
				*/
			}
			DEBUG cout << "Inserto : " << telfs[i] << endl ;
			arbus.inserta(telfs[i], true);
		}
	} catch (int) {
		cout << ERROR_INCONSISTENTE << endl ;
	}

	return 0;
}

#endif