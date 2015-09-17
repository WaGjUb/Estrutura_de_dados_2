#include <stdio.h>

int Fatorial (int num)
{
	if (num <= 1)
	{
		return(1);
	}
	
	num *= Fatorial(num-1);
	return(num);
}


int Comum(int n, int k)
{
		
	int C;
	
	C = Fatorial(n)/(Fatorial(k)*Fatorial(n-k)); //equação de combinação
	return(C);
}	

int main()
{
	int n, k;
	printf("Digite o valor de n e k, separando-os por espaço: ");
	scanf("%d %d", &n, &k);
	
	if(k < 1 )
	{
		printf("Valor de k inválido!\nk necessita ser >= 1\n");
		return(0);
	}
	
	printf("Comum: %d\n", Comum(n,k));
	printf("Identidade: %d\n", (Comum(n-1, k) + Comum(n-1, k-1)));	
		

return(0);
}
