//#define __BROKEN_KEYBOARD
#ifdef __BROKEN_KEYBOARD
#include <iostream>
using namespace std;

#include "Lista.h"

class Text {

	string _text;
	Lista<string> _lista;
	bool _insertaPorDerecha;

	void inserta(string s) {
		if (_insertaPorDerecha) 
			_lista.Cons(s);
		else
			_lista.ponDr(s);
	}

public:
	Text (string s) {
		_text = s;
		_insertaPorDerecha = true;
	}

	void muestraCorrecto() {
		unsigned i = 0;
		string buffer = "";
		while (i < _text.length())
		{
			if (_text.at(i) == '[') {
				inserta(buffer);
				buffer.clear();
				_insertaPorDerecha = false;
			} else if (_text.at(i) == ']') {
				inserta(buffer);
				buffer.clear();
				_insertaPorDerecha = true;
			} else {
				buffer += _text.at(i);
			}
			i++;
		}
		inserta(buffer);
		buffer.erase();
		while (!_lista.esVacia())
		{
			buffer +=_lista.ultimo();
			_lista.inicio();
		}
		cout << buffer << endl;	
	}
};

int main() {
	string s;

	while (!cin.eof())
	{
		cin >> s;
		if(!cin.eof()) {
			Text text = Text(s);
			text.muestraCorrecto();
		}
	}

	return 0;
}
#endif