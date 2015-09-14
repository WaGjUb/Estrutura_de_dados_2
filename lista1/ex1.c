#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Preenche(int* v, int tam)
{
	if (tam <= 0)
	{
		if (tam < 0)
		{
			return(1);
		}
		v[tam] = rand()%20;
		return(0);
	}
		
	v[tam] = rand()%20; 
	Preenche(v, tam-1);
	return(0);
	
}

int Imprime(int* v, int tam)
{
	if (tam == 0)
	{
		printf("%d\n", v[tam]);
		return(0);
	}

	Imprime(v, tam-1);
	printf("%d\n", v[tam]);
	return(0);
}

int Maximo(int* v, int tam)
{
	if (tam == 0)
	{
		return(v[tam]);
	}

	int max = Maximo(v, tam-1);

	if (v[tam] > max)
	{
		return(v[tam]);
	}
	else
	{
		return(max);
	}
}

int Minimo(int* v, int tam)
{
	if (tam == 0)
	{
		return(v[tam]);
	}

	int min = Minimo(v, tam-1);

	if (v[tam] < min)
	{
		return(v[tam]);
	}
	else
	{
		return(min);
	}
}

int Soma(int* v, int tam) 
{
	if (tam == 0)
	{
		return(v[tam]);
	}	

	return(v[tam] + Soma(v,tam-1));
}

int Produto(int* v, int tam)
{
	if (tam == 0)
	{
		return(v[tam]);
	}	

	return(v[tam] * Produto(v,tam-1));
}

double Media(int* v, int tam)
{
	if (tam == 0)
	{
		return(v[tam]);
	}

	double med;

	med = (float) (v[tam] + (Media(v,tam-1)*tam))/(tam+1); //anula a media anterior e cria uma nova
	return(med);
}


int main()
{
	srand(time(NULL));

	int tam;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);

	int v[tam];
	
	tam--;
	Preenche(v, tam);	
	
	printf("Vetor original: \n");
	Imprime(v, tam);

	printf("Maior elemento: %d\n", Maximo(v, tam));
	printf("Menor elemento: %d\n", Minimo(v, tam));
	printf("Soma dos elementos: %d\n", Soma(v, tam));
	printf("Produto dos elementos: %d\n", Produto(v, tam));
	printf("Média dos elementos: %lf\n", Media(v, tam));
	return(0);
}

