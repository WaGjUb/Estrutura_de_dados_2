#ifndef __APS__
#define __APS__

#define M 4

typedef enum Boolean {false = 0, true = 1} bool;

typedef struct cadastro //arquivo que será lido/gravado
{	
	char nome[30];
	char fabricante[30];
	char pais[25]
	char estilo[25];
	char teor[4];
	char nota;
	char chave[5];
} Cadastro;

typedef struct dadoincide
{
	char chave[5];
	int RRN;
} DadoIndice;

typedef struct indice //arvoreB
{
	int qtdchaves;
	DadoIndice Chave[M-1];
	struct indice* filhos[M];
	bool folha;
} Indice;

#endif
