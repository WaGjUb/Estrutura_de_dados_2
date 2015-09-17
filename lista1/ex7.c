#include <stdio.h>

double Harmonica(unsigned int n)
{
	if (n == 1)
	{
		return(n);
	}

	double soma=0; 

	soma += ((double) 1/n) + (Harmonica(n-1));  
	return(soma);
}

int main()
{
	unsigned int n;
	
	printf("Digite o valor de n: ");
	scanf("%u", &n);

	if (n <= 0)
	{
		printf("Valor inválido!\nn deve ser >=1\n");
		return(0);
	}

	printf("Série harmônica: %lf\n", Harmonica(n)); 
	return(0);
}
