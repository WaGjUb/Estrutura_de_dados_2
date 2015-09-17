#include <stdio.h>

unsigned int Paridade(unsigned int verificado)
{

	if (verificado < 2)
	{
		return(verificado);
	}
	
	verificado -= 2;
	
	return(Paridade(verificado));
}

int main()
{
	unsigned int verificado;

	printf("Digite o valor a ser verificada a paridade: ");
	scanf("%u", &verificado);
	
	if (Paridade(verificado))
	{
		printf("Número: %d é ímpar\n", verificado);
	}
	else
	{
		printf("Número: %d é par\n", verificado);
	}
	return(0);
}
