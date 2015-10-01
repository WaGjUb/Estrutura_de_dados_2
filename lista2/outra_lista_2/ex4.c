#include <stdio.h>
#define TAM 7

int Partition(int* v,int ini, int fim)
{
	int pivo = vetor[ini], aux; //posição inicial do pivo, primeiro elemento do vetor

	ini++;
	while (ini < fim)
	{ 
		while((vetor[ini] <= pivo) && (ini < fim))
		{
			ini++;
		}
		while((vetor[fim] > pivo) && (ini < fim))
		{
			fim--;
		}
	
		if (ini < fim)
		{
			aux = vetor[ini];
			vetor[ini] = vetor[fim];
			vetor[fim] = aux;
		}

		else
		{
			break;
		}
	}
	
return(ini); //meio do vetor	
	
}

int QuickSort(int* v, int tamanho)
{
	if (tamanho == 0) //condição de parada
	{
		return(0); 
	}
	
	int meio;
	
	meio = Partition(v,0, tamanho);
	Quicksort(v+1, tamanho-1);


	return(1);
}

int main(){

int v[TAM] = {7, 13, 5, 8, 9, 2, 3};	

	
return(0);
}
