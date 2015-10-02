#include <stdio.h>
#define TAM 7 

int Partition(int* v,int ini, int fim)
{
	int pivo = v[ini], aux, i; //posição inicial do pivo, primeiro elemento do v

	i = ini;
	
		while (ini < fim)
	{ 
		while((v[ini] < pivo) && (ini < fim))
		{
			ini++;
		}
		while((v[fim] > pivo) && (ini < fim))
		{
			fim--;
		}
	
		if (ini < fim)
		{
			aux = v[ini];
			v[ini] = v[fim];
			v[fim] = aux;
		}

		else
		{
			break;
		}
	}
//		aux = v[i];//tira o pivo do local inicial e joga no meio
//		v[i] = v[fim];
//		v[fim] = aux;	
return(ini); //meio do vetor
	
}

int QuickSort(int* v, int ini, int fim)
{
	if (ini >= fim) //condição de parada
	{
		return(0); 
	}
	
	int meio=ini;
	
	meio = Partition(v,ini, fim);
	QuickSort(v,meio+1, fim);
	QuickSort(v, ini, meio-1);
	

	return(1);
}

void ImprimeVetor(int* v, int tam)
{
	int i;
	
	for (i=0; i<tam; i++)
	{
		printf("%d\n", v[i]); 
	}
}

int main(){

int v[TAM] = {7, 13, 5, 8, 9, 2, 3};	

QuickSort(v, 0, TAM-1);
ImprimeVetor(v, TAM);
	
return(0);
}
