//#define __BROKEN_KEYBOARD_2
#ifdef __BROKEN_KEYBOARD_2
#include <iostream>
#include "Lista.h"

using namespace std;


class Text {

	string _text;
	Lista<char> _lista;
	Lista<char>::IteradorMutable _it;

public:
	
	Text (string s) : _it(_lista.principioMutable()) {
		_text = s;
	}

	void muestraCorrecto() {

		unsigned i = 0;
		_it = _lista.principioMutable();
		char c;
		while (i < _text.length())
		{
			c = _text.at(i);
			if (c == '[') {
				_it = _lista.principioMutable();
			} else if (c == ']') {
				_it = _lista.finalMutable();
			} else if (c == '>') {
				if(_lista.finalMutable() != _it)
					_it.avanza();			
			} else {
				_lista.insertar(c, _it);
			}
			i++;
		}
		_it = _lista.principioMutable();
		for (_it; _it != _lista.finalMutable(); _it.avanza())
		{
			cout << _it.elem();
		}
		cout << endl;
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