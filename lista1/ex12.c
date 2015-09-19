#include <stdio.h>
#include <time.h>

long int MultRecursivo(long int n1, long int n2)
{
	if ((n2 <= 1) && (n2 >= -1))
	{
		if (n2 == 0)
		{
			return(0);
		}
		else
		{
			return(n1);		
		}
	}

	long int result;

	if (n2 > 1)
	{
		result = n1 + MultRecursivo(n1, n2-1); 
	} 
	else
	{
		result = n1 + MultRecursivo(n1, n2+1);
	}

	return(result);

}

long int MultIterativo(long int n1, long int n2)
{
	long int i, result=0;

	if (n2 > 0)
	{
		for (i=0; i<n2; i++)
		{
			result += n1;
		}
	}
	else
	{
		for (i=0; i>n2; i--)
		{	
			result += n1;
		}
	}

	return(result);
}

int main()
{
	long int num1, num2, result, aux;
	clock_t t;

	printf("Digite os dois valores que serão multiplicados: ");
	scanf("%ld %ld", &num1, &num2);
	
	if (num2 > num1)
	{
		aux = num1;
		num1 = num2;
		num2 = aux;
	}

	t = clock();
	result = MultRecursivo(num1, num2);
	t = clock() - t;
	printf("Função recursiva:\n"
			"Resultado: %ld\n"
			"Tempo: %lf milésimos de segundo\n\n", result, ((double)t*1000)/CLOCKS_PER_SEC);

	t = clock();
	result = MultIterativo(num1, num2);
	t = clock() - t;
	printf("Função iterativa:\n"
			"Resultado: %ld\n"
			"Tempo: %lf milésimos de segundo\n", result, ((double)t*1000)/CLOCKS_PER_SEC);

	return(0);
}
