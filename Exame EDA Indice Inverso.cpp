#include <iostream>
#include <string>
using namespace std;

#include "Tabla.h"

const unsigned int TAM = 1000;

Tabla<int, int> operator+ (Tabla<int, int> a, Tabla<int, int> b) {
	Tabla<int, int> r;

	Tabla<int, int>::Iterador it1 = a.principio(), it2 = b.principio();

	while (it1 != a.final())
	{
		it2 = b.principio();
		while (it2 != b.final())
		{
			if (it1.clave() == it2.clave())
			{
				r.inserta(it1.clave(), 0);
			}
			it2.avanza();
		}
		it1.avanza();
	}

	return r;
}

Tabla<int, int> interseccion(Tabla<string, Tabla<int, int> >& tabla, const string busqueda[TAM], int a, int b) {
	// b pos valida
	if (b <= a) {
		try {
			return tabla.consulta(busqueda[a]);
		} catch (EClaveErronea) {
			return Tabla<int, int>();
		}
	} else if (a == b-1) {
		try {
			return tabla.consulta(busqueda[a]) + tabla.consulta(busqueda[b]);
		} catch (EClaveErronea) {
			return Tabla<int, int>();
		}
	} else {
		return interseccion(tabla, busqueda, a, (a+b)/2) + interseccion(tabla, busqueda, (a+b)/2, b);
	}
};

int numElemns(Tabla<int, int> a) {
	Tabla<int, int>::Iterador it1 = a.principio();
	int r = 0;
	while (it1 != a.final())
	{
		r++;
		it1.avanza();
	}

	return r;
}

int main() {

	int numCasos;
	string buff;
	//Uso de tabla hash como set

	cin >> numCasos;
	for (int k = 0; k < numCasos; k++)
	{
		Tabla<string, Tabla<int, int> > tabla;
		int numFicheros = 0;
		cin >> numFicheros;
		for (int i = 0; i < numFicheros; i++)
		{
			cin >> buff;

			while (buff != ".")
			{
				if (tabla.esta(buff))
				{
					Tabla<int, int> aux = tabla.consulta(buff);
					aux.inserta(i, 0);
					tabla.inserta(buff, aux);
				}
				else
				{
					Tabla<int, int> aux;
					aux.inserta(i, 0);
					tabla.inserta(buff, aux);
				}
				cin >> buff;
			}

		}

		int numBusquedas;
		cin >> numBusquedas;

		for (int i = 0; i < numBusquedas; i++)
		{
			string busqueda[TAM];
			cin >> buff;

			int palabras = 0;
			while (buff != "?")
			{
				busqueda[palabras] = buff;
				cin >> buff;
				palabras++;
			}

			cout << numElemns(interseccion(tabla, busqueda, 0, palabras-1)) << endl ;
		}
	}

	return 0;
}
