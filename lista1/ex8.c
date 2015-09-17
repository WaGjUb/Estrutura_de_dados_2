#include <stdio.h>

int BinomialCoef(int n, int k)
{
	if ((n==k) || (n==0)) // o slide está errado... k nunca será 0 na relação de Stifel e se k fosse 0 o valor retornado seria n
	{
		return(1);
	}
	
	if (k==0)
	{
		return(n);
	}

	int coeficiente;

	coeficiente = BinomialCoef(n-1, k-1) + BinomialCoef(n-1, k);
	
	return(coeficiente);
}

int main()
{
		
	int n, k;

	printf("Digite o valor de n e k, separando-os por espaço: ");
	scanf("%d %d", &n, &k);
	
	if ((n < (k-1)) || ((k-1) < 0)) //relação de stifel ou regra de pascal
	{
		printf("Os valores de n e k devem ser n >= k-1 >= 0\n");
		return(0);
	} 
	printf("Coeficiente: %d\n", BinomialCoef(n, k)); 			
	return(0);
}
