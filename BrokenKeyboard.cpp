#include <iostream>
using namespace std;

#include "DCola.h"

class Text {
	string _text;
	DCola<string> _cola;
	bool _principio;

	string siguiente() {
		string r;
		int home = _text.find_first_of('[');
		int end = _text.find_first_of(']');
		_principio = true;

		if (home != -1 && home < end) {
			r = _text.substr(0, home);
			_text = _text.substr(home+1, _text.length());
		} 
		else if ((end != -1 && home == -1) || end < home) {
			_principio = false;
			r = _text.substr(0, end);
			_text = _text.substr(end+1, _text.length());
		}
		else {
			r = _text;
			_text = "";
		}

		return r;
	}

public:
	Text (string s) {
		_text = s;
		_principio = false;
	}

	void muestraCorrecto() {
		string s;
		while (!_text.empty())
		{
			s = siguiente();
			if(!_principio)
				_cola.ponDetras(s);
			else
				_cola.ponDelante(s);
		}

		while (!_cola.esVacia())
		{
			cout << _cola.ultimo();
			_cola.quitaUlt();
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