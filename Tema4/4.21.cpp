#include <iostream>
using namespace std;

const int N = 6;

int iguales(int v[N], int n, int& izq, int& der);

int iguales(int v[N], int n, int& izq, int& der){
	int cont;
	if (n == 1)
	{
		izq = 0;
		cont = 0;
	}
	else
	{
		int aux = der + v[n-1];
		cont = iguales(v, n-1, izq, aux);
		izq += v[n-2];
		if (der == izq)
		{
			cont++;
		}
	}
	return cont;
}

int main(){

	int v[N] = {0};
	int centr, a = 0;
	cout << iguales(v, N, centr,a);


	return 0;
}

//#include <iostream>
//using namespace std;
//
//const int N = 5;
//
//int fun(int v[N], int n, int izq, int der, int& centr);
//
//int fun(int v[N], int n, int izq, int der, int& centr){
//	int cont = 0;
//
//	if (n < N/2)
//	{
//		cont = 0;
//		centr = 0;
//	}
//	else
//	{
//		cont = fun(v, n-1, izq + v[N-n], der + v[n-1], centr);
//		
//		if (izq == der + centr + v[n]) //izq
//		{
//			cont++;
//		}
//		if (izq + centr + v[n-1] == der) //der
//		{
//			cont++;
//		}
//		centr += v[n] + v[n-1];
//	}
//
//	//if (n == N/2 && N%2 == 1) //IMPAR
//	//{
//	//	if (der == izq)
//	//	{
//	//		cont = 1;
//	//	}
//	//	centr = v[n];
//	//}
//	//else if (n == N/2 && N%2 == 0) //PAR
//	//{
//	//	if (der - v[n] == izq)
//	//	{
//	//		cont = 1;
//	//	}
//	//	centr = v[n-1] + v[n];
//	//}
//	//else
//	//{
//	//	cont = fun(v, n-1, izq + v[N-n], der + v[n-1], centr);
//	//	if (izq - v[N-n] == der + centr + v[n])
//	//	{
//	//		cont++;
//	//	}
//	//	if (der - v[n-1] == izq + centr + v[N-n])
//	//	{
//	//		cont++;
//	//	}
//	//	centr += v[N-n] + v[n-1];
//	//}
//	return cont;
//}
//
//int main(){
//
//	int v[N] = {2,3,5,0,5};
//	int centr;
//	cout << fun(v, N, 0, 0, centr);
//
//
//	return 0;
//}
