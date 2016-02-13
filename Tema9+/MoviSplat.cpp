#include <iostream>
#include <sstream>
using namespace std;

#include "Tabla.h"
#include "Lista.h"
#include "Arbin.h"

template <class A, class B>
struct Pareja {

};

class MoviSplat {

public:
	void definePieza(string nombre, char letra, int peso) {
		tablaPiezas.inserta(letra, Pieza(nombre, peso));
	}		

	bool produce(string estructura, int unidades, string modelo) {
		
		stringstream ss;
		Arbin<Pieza> arbin;

		ss << estructura;

		//Leo a ur arbin con pesos

		//Si no equilibrado --> error

		//Desglose en piezas: Arbus

		//guardo listaPiezas y cantidad en un modelo, indexo por nombre

	}
	const Lista<Pareja<string, int> > & listaPiezas (string modelo) const;

	bool preparaOrden(const Lista<Pareja <string, int> > orden) const;

	void ejecutaOrden(const Lista<Pareja <string, int> > orden);

private:

	struct Pieza {
		string nombre;
		int peso;

		Pieza(string n, int p) {
			nombre = n;
			peso = p;
		}

		Pieza() {
			nombre = "";
			peso = 0;
		}
	};
	Tabla<char, Pieza > tablaPiezas;

	struct Modelo {
		Lista<Pareja<string, int> > piezasPorCantidad;
		int unidades;
	};
	Tabla<string, Modelo> nombreAModelo;

	Arbin<Pieza> leeArbol(stringstream& ss) {
		Arbin<Pieza> r;		
		if(ss.peek() == 'T') {
			ss.get();
			r = Arbin<Pieza>(leeArbol(ss), Pieza(), leeArbol(ss));
		} else {
			r = Arbin<Pieza>(Arbin<Pieza>(), tablaPiezas.consulta(ss.get()), Arbin<Pieza>());	
		}
	}
};