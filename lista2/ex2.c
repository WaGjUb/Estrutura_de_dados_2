#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum boolean{false=0, true} Bool;

int* BubbleSort(int* v, int size)
{
	int* v2; 
	int aux;
	Bool validator;
	
	v2 = (int*) malloc(sizeof(int)*size);
	memmove(v2, v, sizeof(int)*size);
	
		while (validator != true)
		{
			validator = true;
		
			for (int i=1; i<size; i++)
			{
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

int* InsertionSort();

int* QuickSort();

int* HeapSort();

int main()
{
	int v1[]={7,13,5,8,9,2,3};
	int size = 7;
	int* vOrd;
	
	vOrd = BubbleSort(v1, size);
	
	for (int i=0; i<size; i++)
	{
		printf("%d\n", vOrd[i]);
	}
	return(0);
}
