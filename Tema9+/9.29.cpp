//#define _9_29
#ifdef _9_29

#include <iostream>
using namespace std;

#include "Arbus.h"

const int MAX = 1000;

int main() {

	Arbus<string, int> arbus;

	string listaBien[MAX] = {"a", "b", "z"};
	string listaMal[MAX] = {"c", "e", "j"};

	int numBien = 3, numMal = 3;

	for (int i = 0; i < numBien; i++)
	{
		//Buscarlo
		if (arbus.esta(listaBien[i])) 
		{
			//Si está, se le suma 1
			arbus.inserta(listaBien[i], arbus.consulta(listaBien[i])+1);
		} 
		else
		{
			//Si no, se inicia con 1
			arbus.inserta(listaBien[i], 1);
		}
	}
	for (int i = 0; i < numMal; i++)
	{
		//Buscarlo
		if (arbus.esta(listaMal[i])) 
		{
			//Si está, se le resta 1
			arbus.inserta(listaMal[i], arbus.consulta(listaMal[i])-1);
		} 
		else
		{
			//Si no, se inicia con -1
			arbus.inserta(listaMal[i], -1);
		}
	}

	Arbus<string, int>::Iterador it = arbus.principio();

	while (it != arbus.final())
	{
		if (it.valor() != 0 )
		{
			cout << it.clave() << " con un resultado de " << it.valor() << endl;
		}
		
		it.avanza();
	}

	return 0;
}

#endif /* _9_29 */