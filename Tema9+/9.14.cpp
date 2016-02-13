//#define _9_14
#ifdef _9_14

#define AUX /
#define DEBUG //AUX

#include <iostream>
using namespace std;
#include "Arbus.h"

const string ERROR_INCONSISTENTE = "Error: lista inconsistente." ;
const int TAM = 1000;

int main() {
	Arbus<string, bool> arbus;
	Arbus<string, bool>::Iterador it = arbus.principio();

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
			for (int j = 0; j < telfs[i].length(); j++) {
				DEBUG cout << "Probando numero " << telfs[i] << " usando prefijo " << telfs[i].substr(0, j+1) << endl ;
				//if (arbus.esta(telfs[i].substr(0, j+1)) && arbus.consulta(telfs[i].substr(0, j+1)))
				//	throw 0;
				//DEBUG cout << "Inserto : " << telfs[i].substr(0, j+1) << endl ;
				//arbus.inserta(telfs[i].substr(0, j+1), false);
				
				it = arbus.principio();
				//Buscamos si el prefijo est� y si es n�jero completo
				while (it != arbus.final() && it.clave() != telfs[i].substr(0, j+1)) {
					it.avanza();
				} if (it == arbus.final()) { //Si no lo encuenrta se inserta
					DEBUG cout << "Inserto : " << telfs[i].substr(0, j+1) << endl ;
					arbus.inserta(telfs[i].substr(0, j+1),  j == telfs[i].length()-1);
				} else if (it.valor() || j == telfs[i].length()-1) { 
					//Si el prefijo est� y adem�s es final se sale o este msimo lo completa
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
		}
	} catch (int) {
		cout << ERROR_INCONSISTENTE << endl ;
	}

	return 0;
}

#endif /* _9_14 */