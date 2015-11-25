#include <stdio.h>


void insertion_sort (int *vector, int n){

	int key = 0;
	int i,j;

	for (j = 1; j < n; j++)
	{

		key = vector[j];
		i = j - 1;
		while (i >= 0 && vector[i] < key) {
			vector[i+1] = vector[i];
			i--;
		}
		vector[i+1] = key;
	}

printf("primeiro: %d\nultimo: %d\n", vector[0], vector[n-1]);
}

void ImprimeVetor(int* v, int tam)
{
	int i;
	
	for(i=0; i<tam; i++)
	{
		printf("%d\n", v[i]);
	}
}

int main()
{
	int v[]={40,50,2,4,1,1,3,4,5,6,7,70};
	int tam = 12;	

	printf("Vetor desordenado: \n");
	ImprimeVetor(v, tam);	
	insertion_sort(v, tam);

	printf("Vetor ordenado: \n");
	ImprimeVetor(v, tam);
	
return(0);
}
