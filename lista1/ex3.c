#include <stdio.h>

unsigned int Divisao(unsigned int dividendo, unsigned int divisor)
{

	if (dividendo < divisor)
	{
		return(0);
	}

	unsigned int soma=0;
	
	dividendo -= divisor;
	soma++;
	soma += Divisao((dividendo), divisor);
	
	return(soma);
}

int main()
{
	unsigned int divisor, dividendo;

	printf("Digite o valor de dividendo e do divisor separando-os por espaço: ");
	scanf("%u %u", &dividendo, &divisor);

	printf("%u/%u = %u\n", dividendo, divisor, Divisao(dividendo, divisor));

	return(0);
}
