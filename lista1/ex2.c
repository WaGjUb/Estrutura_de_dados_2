#include <stdio.h>

int Ackerman(unsigned int m, unsigned int n) //recursivo!! 
{
	if ((m == 0) || (n == 0))
	{
	return	m == 0 ? n+1 : Ackerman(m-1, 1);
	}

	return(Ackerman(m-1, Ackerman(m, n-1)));
}


int main()
{
	unsigned int m, n;

	printf("Digite o valor de m e n no formato ""m,n"": ");
	scanf("%d,%d", &m, &n);
	
	printf("Valor de retorno: %u\n", Ackerman(m, n));
	return(0);
}
