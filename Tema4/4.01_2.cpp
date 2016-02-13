

void CalculaLejanos(int* ar, int inicio, int fin, int& a, int &b)
{
	int c = ar[inicio];
	for(int i=inicio+1;i<fin;i++)
		if(abs(c-ar[i])>abs(a-b))
		{
			a=c;
			b=ar[i];
		}
	inicio++;
	if(inicio<fin)
		CalculaLejanos(ar,inicio,fin,a,b);
	return;
}

void CalculaCercanos(int* ar, int inicio, int fin, int& a, int &b)
{
	int c = ar[inicio];
	for(int i=inicio+1;i<fin;i++)
		if(abs(c-ar[i])<abs(a-b))
		{
			a=c;
			b=ar[i];
		}
	inicio++;
	if(inicio<fin)
		CalculaCercanos(ar,inicio,fin,a,b);
	return;
}

void Prueba()
{
	int ar[11] = {11,5,8,23,7,13,33,55,9,15,44};
	int Inicio = 0;
	int N = 11;
	int A = 0; // Se puede inicializar a 0
	int B = 0;
	CalculaLejanos(ar,Inicio,N,A,B);
	// Aquí A vale 5 y B 55

	A = 0; // uno de los dos se debe inicializar a un número muy grande
	B = MAXINT; // Se debe inicializar a un número muy grande
	CalculaCercanos(ar,Inicio,N,A,B);
	// Aquí A vale 8 y B 7
}
