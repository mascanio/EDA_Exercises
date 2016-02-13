#include <iostream>

const int N = 10;

void buscaBolas(int bolas[], int n, int& priemra, int& segunda);
void buscaBolas(int bolas[], int a, int b, int& primera, int& segunda);
int calculaPeso (int bolas[], int a, int b);

void buscaBolas(int bolas[], int n, int& priemra, int& segunda) {
	priemra = -1;
	buscaBolas(bolas, 0, n, priemra, segunda);
}

void buscaBolas(int bolas[], int a, int b, int& primera, int& segunda) {

	if (b-a == 1)	{
		if (primera == -1)
			primera = a;
		else
			segunda = a;
	}
	else {
		if ((b-a) % 2 == 0) { //par 
			int izq = calculaPeso(bolas, a, (a+b)/2),
				der = calculaPeso(bolas, (a+b)/2, b);

			if (izq > der)
				buscaBolas(bolas, a, (a+b)/2, primera, segunda);
			else if (izq < der)
				buscaBolas(bolas, (a+b)/2, b, primera, segunda);
			else {
				buscaBolas(bolas, a, (a+b)/2, primera, segunda);
				buscaBolas(bolas, (a+b)/2, b, primera, segunda);
			}
		}
		else { //impar, retiro una bola arbitrariamente (la pos a)
			//Miro si es solución comprobando con otras dos
			if (bolas[a] > bolas[a+1] || bolas[a] > bolas[a+2]) {
				if (primera == -1)
					segunda = a;
				else
					primera = a;
			}
			//heuristica?
			// if (bolas[a+1] == bolas[a+2] && bolas[a] < bolas[a+1]) { //son las soluciones
			//	segunda = a+2;
			//	primera = a+1;
			//}
			else {
				a++;
				int izq = calculaPeso(bolas, a, (a+b)/2),
					der = calculaPeso(bolas, (a+b)/2, b);

				if (izq > der)
					buscaBolas(bolas, a, (a+b)/2, primera, segunda);
				else if (izq < der)
					buscaBolas(bolas, (a+b)/2, b, primera, segunda);
				else {
					buscaBolas(bolas, a, (a+b)/2, primera, segunda);
					buscaBolas(bolas, (a+b)/2, b, primera, segunda);
				}
			}
		}
	}
}
int calculaPeso (int bolas[], int a, int b) {
	int r = 0;
	for (int i = a; i < b; i++)
		r += bolas[i];

	return r;
}

int main() {

	int bolas[N] = {1,1,2,1,1,1,1,1,1,2};

	int primera, segunda;

	buscaBolas(bolas, N, primera, segunda);

	return 0;
}