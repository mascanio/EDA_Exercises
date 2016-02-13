//#define _9_10
#ifdef _9_10

#define AUX /
#define DEBUG /AUX

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

bool esHoja(const Arbin<int> &a) {
	return a.hijoIz().esVacio() && a.hijoDr().esVacio();
}

bool suma(const Arbin<int> &a, int acu, int numBuscado, bool paridad) {
	if (a.esVacio()) {
		return acu == numBuscado;
	} else if (esHoja(a)) {
		DEBUG cout << "Leo " << a.raiz() << " y llevo acumulado " << acu << endl ;
		DEBUG cout << "Entro en caso base" << endl ;
		return (paridad ? acu - a.raiz() : acu + a.raiz()) == numBuscado;
	} else {
		DEBUG cout << "Leo " << a.raiz() << " y llevo acumulado " << acu << endl ;
		DEBUG cout << "Reursivo en el hijo de " << a.raiz() << " que son izq: " << (a.hijoIz().esVacio() ? -11111 : a.hijoIz().raiz()) << "; der: " << (a.hijoDr().esVacio() ? -11111 : a.hijoDr().raiz()) << endl ;
		return suma(a.hijoIz(), (paridad ? acu - a.raiz() : acu + a.raiz()), numBuscado, !paridad) ||
			suma(a.hijoDr(), (paridad ? acu - a.raiz() : acu + a.raiz()), numBuscado, !paridad);
	}
}

int main() {
	int a;
	while (!cin.eof())
	{
		cin >> a;
		if(!cin.eof())
		std::cout << (suma(leeArbolConParentesis(), 0, a, false) ? "yes" : "no") << std::endl;
	}

	return 0;
}

#endif
