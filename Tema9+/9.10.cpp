///#define _9_10
#ifdef _9_10

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

bool suma(const Arbin<int> &a, int acu, int numBuscado) {
	if (a.esVacio()) {
		return false;
	} else if (esHoja(a)) {
		cout << "Leo " << a.raiz() << " y llevo acumulado " << acu << endl ;
		cout << "Entro en caso base" << endl ;
		return acu + a.raiz() == numBuscado;
	} else {
		cout << "Leo " << a.raiz() << " y llevo acumulado " << acu << endl ;
		cout << "Reursivo en el hijo de " << a.raiz() << " que son izq: " << (a.hijoIz().esVacio() ? -11111 : a.hijoIz().raiz()) << "; der: " << (a.hijoDr().esVacio() ? -11111 : a.hijoDr().raiz()) << endl ;
		return suma(a.hijoIz(), acu + a.raiz(), numBuscado) ||
			suma(a.hijoDr(), acu + a.raiz(), numBuscado);
	}
}

int main() {
	//Arbin<int> a = leeArbol();

	Arbin<int> a = Arbin<int>(Arbin<int>(), 1, Arbin<int>(Arbin<int>(), 2, Arbin<int>()));
	std::cout << suma(leeArbolConParentesis(), 0, 10) << std::endl;
	std::cout << suma(a, 0, 1) << std::endl;
	std::cout << suma(a, 0, 3) << std::endl;

	return 0;
}

#endif
