#include <iostream>

const int N = 3;

void mochila (double p[], double v[], int n, int& paso, double& peso, double& valor, double& parte);
void mochila (double p[], double v[], int n, int& paso, double& peso, double& valor, double& parte) {
	if (paso != n) {
		if (p[paso] < peso) {
			peso -= p[paso];
			valor += v[paso];
			paso++;
			mochila(p,v,n,paso,peso,valor,parte);
		}
		else {
			parte = peso / p[paso];
			valor += v[paso] * parte;
			peso = 0;
			paso++;
			//fin
		}
	}
	//else fin
}

int main() {

	double p[N] = {4, 3, 2};
	double v[N] = {30, 20, 10};
	double peso = 8;
	double valor = 0;
	double parte = 1;

	int paso = 0;

	mochila(p,v,N,paso,peso,valor,parte);

std:: cout << paso << " " << peso << " " << valor << " " << parte ;

	return 0;
}
