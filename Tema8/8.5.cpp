#include <iostream>
using namespace std;

int diamantes(string s) {
	int cont = 0, apertura = 0;

	for (unsigned i = 0; i < s.length(); i++)
	{
		if(s.at(i) == '<')
			apertura++;
		else if(s.at(i) == '>' && apertura > 0) {
			apertura--;
			cont++;
		}
	}

	return cont;
}


int main() {
	
	cout << diamantes(">>>>>>>>>>>><..<..>.><..><");

	return 0;
}