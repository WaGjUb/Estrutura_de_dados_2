#include <stdio.h>
#define TAM 11

int comparacoes =0;
int troca=0;

int Partition(int* v,int ini, int fim)
{
	int pivo = v[(fim-ini)/2], aux, i; //posição inicial do pivo, MEIO do v

	i = ini;
	
		while (ini < fim)
	{ 
		while((v[ini] < pivo) && (ini < fim))
		{
			ini++;
			comparacoes++;
		}
		while((v[fim] > pivo) && (ini < fim))
		{
			fim--;
			comparacoes++;
		}
	
		if (ini < fim)
		{
			aux = v[ini];
			v[ini] = v[fim];
			v[fim] = aux;
			troca++;
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

int v[TAM] = {2, 5, 32, 21, 102, 1, 11, 24, 35, 44, 56};	

QuickSort(v, 0, TAM-1);
ImprimeVetor(v, TAM);
	printf("Comparações: %d\nTrocas: %d\n", comparacoes, troca);
	
return(0);
}
