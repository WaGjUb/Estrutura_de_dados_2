#include <stdio.h>

int* InsertionSort(int* v, int tam)
{

	
	InsertionSort(v+1, tam-1);

return(v);
}

int main()
{
	int v[]={1,6,5,4,2};
	int tam = 5;

	InsertionSort(v, tam);
return(0);
}
