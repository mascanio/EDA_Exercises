//#define _IndiceInverso
#ifdef  _IndiceInverso

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Tabla.h"

typedef unsigned long long int tValue;

const unsigned int TAM = sizeof(tValue) * 8;

tValue interseccion(Tabla<string, tValue>& tabla, const string busqueda[TAM], int a, int b) {
	// b pos valida
	if (b <= a) {
		try {
			return tabla.consulta(busqueda[a]);
		} catch (EClaveErronea) {
			return 0x0;
		}
	} else if (a == b-1) {
		try {
			return tabla.consulta(busqueda[a]) & tabla.consulta(busqueda[b]);
		} catch (EClaveErronea) {
			return 0x0;
		}
	} else {
		return interseccion(tabla, busqueda, a, (a+b)/2) & interseccion(tabla, busqueda, (a+b)/2, b);
	}
};

int cuentaUnos(tValue n) {
	//Contar unos de representacion binaria
	int r = 0x0;
	for (int i = 0; i < TAM; i++)
	{
		r = ((0x1 & (n>>i)) == 0x1 ? r+1 : r); 
	}

	return r;
}

int main() {

	int numLineas;
	string ficheros[TAM], buff;
	stringstream ss;
	Tabla<string, tValue> tabla;

	cin >> numLineas;
	cin.get();
	tValue pos = 0x1;
	for (int i = 0; i < numLineas; i++)
	{
		//Lectura linea a linea
		ss.clear();
		ss.sync();
		ss.flush();
		getline(cin, buff);
		ss << buff;

		ss >> buff;
		while (ss)
		{
			if (tabla.esta(buff))
			{
				tabla.inserta(buff, tabla.consulta(buff) | pos);
			}
			else
			{
				tabla.inserta(buff, pos);
			}
			ss >> buff;
		}

		pos <<= 1;
	}

	int numBusquedas;
	cin >> numBusquedas;
	
	assert(numBusquedas < TAM);

	for (int i = 0; i < numBusquedas; i++)
	{
		int palabras, j = 0;
		string busqueda[TAM];
		cin >> palabras;

		for (int j = 0; j < palabras; j++)
		{
			cin >> busqueda[j];
		}

		cout << cuentaUnos(interseccion(tabla, busqueda, 0, palabras-1)) << endl ;
	}

	return 0;
}

#endif /* _IndiceInverso */