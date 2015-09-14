#include "hanoistack.h"

bool GameInitialize(int qtdeblocos, Stack* a)//empilha todas os blocos para iniciar o jogo
{
	if (qtdeblocos == 1) //caso de parada
	{
		Add(a, qtdeblocos);
		return(true);
	}		

	Add(a, qtdeblocos); //empilha 
	GameInitialize(qtdeblocos-1, a); //empilha o proximo 
	return(true);
}

bool Win(int qtdeblocos, Stack* c)
{
	if (qtdeblocos == c->size)
	{
		return(true);
	}
	return(false);
}

bool Move(Stack* orig, Stack* dest)
{
	bool verif, veriforig;
	int val=-1, valorig=-1; //inicializa a variável 

	verif = NextDataRequest(dest, &val); //val recebe o valor do topo da torre de destino ou verif se a torre esta vazia
	veriforig = NextDataRequest(orig, &valorig);

	if (((val > valorig) || (!verif)) && (veriforig)) //verifica se pode ser trocado
	{
		Pop(orig);
		Add(dest, valorig);
		return(true);
	}
	return(false);
}

void Print(Stack* a, Stack* b, Stack* c)
{
	int size, i;
	Node *ap, *bp, *cp;

	ap = a->top;
	bp = b->top;
	cp = c->top;
	
	if (a->size > b->size)
	{
		if (a->size > c->size)
		{
			size = a->size;
		}
		else
		{
			size = c->size;
		}
	}
	else
	{
		if (b->size > c->size)
		{
			size = b->size;
		}
		else
		{
			size = c->size;
		}
	}

	for (i=0; i<size; i++)
	{
		if ((size-i) > a->size)
		{
			printf("    ");
		}
		else
		{
			printf("%d   ", ap->data);
			ap = ap->prev;
		}
		
		if ((size-i) > b->size)
		{
			printf("    ");
		}
		else
		{
			printf("%d   ", bp->data);
			bp = bp->prev;
		}

		if ((size-i) > c->size)
		{
			printf("    ");
		}
		else
		{
			printf("%d   ", cp->data);
			cp = cp->prev;
		}
	printf("\n");
	}
	printf("A   B   C");
}

int main()
{
	Stack *a, *b, *c; //torres
	int qtdeblocos, control=0;	

	a = Create(); //inicializa a torre a
	b = Create(); // inicializa a torre b
	c = Create(); // inicializa a torre c

	printf("Digite o número de blocos: ");
	scanf("%d", &qtdeblocos);

	GameInitialize(qtdeblocos, a); //cria o cenario inicial do jogo

	while(control!=7)
	{
		printf("\n\n");
		Print(a,b,c);
		printf("\n\n");

		printf("--------HANOY--------\n"
			"Selecione uma opção:\n"
			"1. Mover de a para b\n"
			"2. Mover de a para c\n"
			"3. Mover de b para a\n"
			"4. Mover de b para c\n"
			"5. Mover de c para a\n"
			"6. Mover de c para b\n"
			"7. Sair\n");

			scanf("%d", &control);

			switch (control)
			{

				case 1:
				Move(a,b);
				break;
				
				case 2:
				Move(a,c);
				break;
				
				case 3:
				Move(b,a);
				break;
				
				case 4:
				Move(b,c);
				break;
				
				case 5:
				Move(c,a);
				break;

				case 6:
				Move(c,b);
				break;				
			
				case 7:
				break;

				default:
				printf("Opção inválida!\n");
				break;
			}

		if (Win(qtdeblocos, c))
		{
			control = 7;
			Print(a,b,c);
			printf("Você ganhou!\n");
		}


	}


return(0);
}
