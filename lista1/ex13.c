#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum boolean { false = 0, true = 1} Bool; 


Bool Concat(char* v)
{
	if (v[0] == '\0')
	{
		return(true);
	}
	
	if (isalpha(v[0]))
	{
		v[0] = tolower(v[0]);
		Concat(v+1);
	}
	else
	{
		memmove(v, v+1, strlen(v)*sizeof(char));
		Concat(v);
	}
	
	return(true);
}


Bool Inverte(char* v, char* v2, int tam) //recursão de cauda para inverter a palavra
{
	if (tam < 0 )
	{
		return(true);
	}

	v2[0] = v[tam]; 

	if (Inverte(v, v2+1, tam-1))
	{
		v2[tam+1] = '\0';
	}

	return(true);
}

Bool Palindromo(char* v, char* v2)
{
	if (v[0] == '\0')
	{
		return(true);
	}
	
	if (v[0] != v2[0])
	{
		return(false);
	}
	else
	{
		return(Palindromo(v+1, v2+1));
	}
}

int main()
{
	char v[100], v2[100];
	
	printf("Digite uma palavra ou frase: ");
	scanf("%[^\n]", v);
	Concat(v);
	Inverte(v, v2, strlen(v)-1);
	printf("%s , %s\n", v, v2);
	
	if (Palindromo(v,v2))
	{
		printf("É palindromo\n");
	}
	else
	{
		printf("Não é palindromo\n");
	}
	return(0);
}
