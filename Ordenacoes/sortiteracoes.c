#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef enum boolean{false=0, true} Bool;

int count;

int* BubbleSort(int* v, int size)
{
	int* v2; 
	int aux;
	Bool validator = false;
	
	count = 0;
	v2 = (int*) malloc(sizeof(int)*size);
	memmove(v2, v, sizeof(int)*size);
	
		while (!validator)
		{
			validator = true;
		
			for (int i=1; i<size; i++)
			{
			count++;
				if (v2[i] < v2[i-1])
				{
					aux = v2[i];
					v2[i] = v2[i-1];
					v2[i-1] = aux; 
					validator = false;
				}
			}
		size--;
		} 
	return(v2);
}

int* SelectionSort(int* v, int size)
{
	int* v2; 
	int aux, max;
	Bool validator=false;
	
	count = 0;
	v2 = (int*) malloc(sizeof(int)*size);
	memmove(v2, v, sizeof(int)*size);
	
	while (!validator)
	{
		max = 0;
		for(int i=1; i<size; i++)
		{
			if (v2[i] > v2[max])
			{
				max = i;
			}	
		count++;
		} 
		aux = v2[size-1];
		v2[size-1] = v2[max];
		v2[max] = aux;
		size--;

		if (max == 0) // verifica se o vetor está ordenado quando não foi feita nenhuma alteração
		{
			for (int j=1; j<size; j++)
			{
				validator = true;
				if (v2[j] < v2[j-1])
				{
					validator = false;
				}
			}
		}
	}
return(v2);
}

int* InsertionSort();

int* QuickSort();

int* HeapSort();

int main()
{
	int v1[]={7,13,5,8,9,2,3};
	int size = 7;
	int* vOrd;
	
	vOrd = BubbleSort(v1, size);
	printf("Bubble Sort\nVetor Ordenado:\n");	
	for (int i=0; i<size; i++)
	{
		printf("%d ", vOrd[i]);
	}
	printf("\nNúmero de iterações: %d\n", count);
		free(vOrd);

	vOrd = SelectionSort(v1, size);
	printf("Selection Sort\nVetor Ordenado:\n");	
	for (int i=0; i<size; i++)
	{
		printf("%d ", vOrd[i]);
	}
	printf("\nNúmero de iterações: %d\n", count);

	return(0);
}
