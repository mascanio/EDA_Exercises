//#define _9_31
#ifdef _9_31

#include <iostream>
using namespace std;

#include "Arbin.h"

/*
* ignora espacios en un 'stream' (por ejemplo, cin)
*/
void ignoraEspacios(istream &in) {
	int c;
	// in.peek() mira, *sin extraerlo*, el siguiente caracter de in
	while ((c = in.peek()) &&
		(c == ' ' || c == '\t' ||
		c == '\r'|| c == '\n')) {
			// es un espacio: extrae el caracter
			in.get();
	}
}

Arbin<int> leeArbolConParentesis() {
	// ejemplo de entrada:
	// (2 (1 () () ) (3 () (4 (5 () () ) (6 () () ) ) ) )

	// ignora parentesis de apertura y posibles espacios
	ignoraEspacios(cin);
	assert(cin.get() == '(');
	ignoraEspacios(cin);
	// fin o recursion
	if (cin.peek() == ')') {
		// ignora parentesis de cierre y devuelve vacio
		cin.get();
		return Arbin<int>();
	} else {
		// leemos valor y subarboles
		int valor;
		cin >> valor;
		const Arbin<int> &iz = leeArbolConParentesis();
		const Arbin<int> &dr = leeArbolConParentesis();
		// ignora espacios + cierre y devuelve leido
		ignoraEspacios(cin);
		assert(cin.get() == ')');
		return Arbin<int>(iz, valor, dr);
	}
}

bool esMonticulo(const Arbin<int> &a) {
	if (a.esVacio()) //BASE si es vacío SÍ es heap
	{
		return true;
	}
	else
	{
		if (a.hijoIz().talla() - a.hijoDr().talla() == 0 || a.hijoIz().talla() - a.hijoDr().talla() == 1)
		{
			if ((a.hijoIz().esVacio() || a.raiz() < a.hijoIz().raiz())
				&& (a.hijoDr().esVacio() || a.raiz() < a.hijoDr().raiz())) 
				// PASO RECURSIVO, es heap si los dos hijos lo son
			{
				return esMonticulo(a.hijoIz()) && esMonticulo(a.hijoDr());
			}
			else // BASE si una de las raíces de los hijos es mayor que la raíz padre NO es heap
			{
				return false;
			}
		}
		else // BASE si no está balanceado por la izquierda NO es heap
		{
			return false;
		}
	}
}

int main() {

	Arbin<int> a;

	while (!cin.eof())
	{
		if(!cin.eof()) {
			a = leeArbolConParentesis();
			cout << esMonticulo(a) << endl ;
		}
		cin.peek();
	}


	return 0;
}

#endif /* _9_31 */