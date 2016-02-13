#define _MULTA_MATIC
#ifdef  _MULTA_MATIC

#include <iostream>
using namespace std;
#include "Tabla.h"
#include "Lista.h"

#define COMPARADOR_TIEMPO <=

class MultaMatic {
public:

	~MultaMatic() {
		for (Tabla<int, Tramo*>::Iterador it = _tablaTramos.principio(); it != _tablaTramos.final(); it.avanza())
		{
			delete it.valor();
		}

		for (Tabla<string, int*>::Iterador it = _matriculaToMultas.principio(); it != _matriculaToMultas.final(); it.avanza())
		{
			delete it.valor();
		}
	}

	void insertaTramo(int tramo, int camIni, int camFin, int t) {
		_tablaTramos.inserta(tramo, new Tramo(camIni, camFin, t));
		_camaraFinToIni.inserta(camFin, camIni);
		_camaraToIdTramo.inserta(camIni, tramo);
	}

	void fotoEntrada(int camara, string matricula, int t) {
		//Pre: camara es valida, comportamiento indefinido si no
		int tramo = _camaraToIdTramo.consulta(camara);

		Tramo* tr = _tablaTramos.consulta(tramo); // copia: O(1)

		tr->_avistamientos.inserta(matricula, t);

		if(!_matriculaToMultas.esta(matricula)) {
			int* v = new int;		
			(*v) = 0; // ???????????????????????????????????????????????????????????????????
			_matriculaToMultas.inserta(matricula, v);
		}

		_tablaTramos.inserta(tramo, tr);
	}

	void fotoSalida(int camara, string matricula, int t) {
		//Pre: camara es valida, comportamiento indefinido si no
		//Pre: matricula es valida, comportamiento indefinido si no
		int camaraIni = _camaraFinToIni.consulta(camara);
		int tramo = _camaraToIdTramo.consulta(camaraIni);

		Tramo* tr = _tablaTramos.consulta(tramo); // copia: O(1)

		if (t - tr->_avistamientos.consulta(matricula) COMPARADOR_TIEMPO tr->_tiempo) {
			tr->_multas.ponDr(matricula);

			int* v = _matriculaToMultas.consulta(matricula); // copia: O(1)
			(*v)++; // ???????????????????????????????????????????????????????????????????
			_matriculaToMultas.inserta(matricula, v);

		}

		tr->_avistamientos.borra(matricula);

		_tablaTramos.inserta(tramo, tr);
	}

	int multasPorMatricula(string matricula) {
		return *_matriculaToMultas.consulta(matricula);
	}

	const Lista<string> multasPorTramo(int tramo) {
		return _tablaTramos.consulta(tramo)->_multas;
	}

	struct Tramo {
		int _camaraIni, _camaraFin, _tiempo;

		Lista<string> _multas;
		Tabla<string, int> _avistamientos;

		Tramo(int ini, int fin, int t) {
			_camaraIni = ini;
			_camaraFin = fin;
			_tiempo = t;
		}
	};
private:

	Tabla<int, Tramo*> _tablaTramos;
	Tabla<int, int> _camaraToIdTramo, _camaraFinToIni;
	Tabla<string, int*> _matriculaToMultas;
};

int main() {
	/*
	int* v = new int;

	cout << v << " " << *v << " " << &v << endl;

	*v = 1;
	cout << v << " " << *v << " " << &v << endl;

	(*v)++;
	cout << v << " " << *v << " " << &v << endl;

	*v++;
	cout << v << " " << *v << " " << &v << endl;

	v++;
	cout << v << " " << *v << " " << &v << endl;
	*/

	MultaMatic multa;

	multa.insertaTramo(0,0,1,20);

	multa.fotoEntrada(0, "abcd", 1);
	multa.fotoSalida(1, "abcd", 2);


	multa.fotoEntrada(0, "abcd", 1);
	multa.fotoSalida(1, "abcd", 2);

	multa.insertaTramo(1,2,3,20);

	multa.fotoEntrada(0, "abcd", 1);
	multa.fotoEntrada(2, "abcd", 1);

	multa.fotoSalida(3, "abcd", 2);
	multa.fotoSalida(1, "abcd", 200);

	return 0;
}

#endif /* _MULTTA_MATIC */