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

		if (max == 0) // verifica se o v2 está ordenado quando não foi feita nenhuma alteração
		{
			for (int j=1; j<size; j++)
			{
				count++;
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

int* InsertionSort(int* v2, int size)
{
	int i, j, aux;
	int* v; 

	v = (int*) malloc(sizeof(int)*size);
	memmove(v, v2, sizeof(int)*size);

	count = 0;

	for (i = 1; i < size; i++) {
		aux = v[i];

		j = i;

		while ((aux < v[j - 1]) && (j > 0))
		{
			v[j] = v[j - 1];
			j--;
			count++;
		}

		v[j] = aux;
	}
	return(v);
}

int* ShellSort(int* v, int size)
{
	int k , i, j;

	int* v2; 
	int aux;

	count = 0;

	v2 = (int*) malloc(sizeof(int)*size);
	memmove(v2, v, sizeof(int)*size);

	for(k = 1; k < size; k = 3*k+1) /* só para calcular o k */
	{
		k = size/2;
	}


	while (k > 0) {

		for (i = k; i < size; i++) 
		{
			aux = v2[i];
			j = i;

			/* efetua comparações entre elementos com distância k: */

			while ((v2[j - k] > aux) && (j >= k))
			{
				count++;
				v2[j] = v2[j - k];
				j = j-k;
			}

			v2[j] = aux;
		}

		k = (k-1)/3; /* atualiza o valor de k. */

		k = k/2;

	}
return(v2);
}

int* QuickSort();

int* HeapSort();

int main()
{
	int v1[]={7,13,5,8,9,2,3};
	int size = 7;
	int* vOrd;
	clock_t t;

 	printf("Vetor a ser ordenado: \n");	
	for (int i=0; i<size; i++)
	{
		printf("%d ", v1[i]);
	}
	
	t = clock();
	vOrd = BubbleSort(v1, size);
	t = clock() - t;

	printf("\n\nTempo de execução: %lf milisegundos\n", ((double)t*1000)/CLOCKS_PER_SEC);
	printf("Bubble Sort\nVetor Ordenado:\n");	
	for (int i=0; i<size; i++)
	{
		printf("%d ", vOrd[i]);
	}
	printf("\nNúmero de iterações: %d\n\n", count);
	free(vOrd);

	t = clock();
	vOrd = SelectionSort(v1, size);
	t = clock() - t;
	printf("Tempo de execução: %lf milisegundos\n", ((double)t*1000)/CLOCKS_PER_SEC);
	printf("Selection Sort\nVetor Ordenado:\n");	
	for (int i=0; i<size; i++)
	{
		printf("%d ", vOrd[i]);
	}
	printf("\nNúmero de iterações: %d\n\n", count);
	free(vOrd);

	t = clock();
	vOrd = InsertionSort(v1, size);
	t = clock() - t;
	printf("Tempo de execução: %lf milisegundos\n", ((double)t*1000)/CLOCKS_PER_SEC);
	printf("Instertion Sort\nVetor Ordenado:\n");	
	for (int i=0; i<size; i++)
	{
		printf("%d ", vOrd[i]);
	}
	printf("\nNúmero de iterações: %d\n\n", count);
	free(vOrd);

	t = clock();
	vOrd = ShellSort(v1, size);
	t = clock() - t;
	printf("Tempo de execução: %lf milisegundos\n", ((double)t*1000)/CLOCKS_PER_SEC);
	printf("Shell Sort\nVetor Ordenado:\n");	
	for (int i=0; i<size; i++)
	{
		printf("%d ", vOrd[i]);
	}
	printf("\nNúmero de iterações: %d\n", count);
	free(vOrd);

	return(0);
}
