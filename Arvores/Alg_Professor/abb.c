#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore {
  int info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

Arvore* cria_vazia (void)
{
   return NULL;
}

void imprime_abb_in_ordem (Arvore* a)
{
   if (a != NULL)
   {
      imprime_abb_in_ordem(a->esq);
      printf("%d\n",a->info);
      imprime_abb_in_ordem(a->dir);
   }
}

Arvore* cria(int info){
    Arvore *a = (Arvore *)malloc(sizeof(Arvore));
    a->info = info;
    a->esq = a->dir = NULL;    
    return a;
}

Arvore* insere(Arvore* a, int info)
{
    if (a==NULL) {
        a = cria(info);
    }
    else
        if (info < a->info){
            a->esq = insere(a->esq,info);
        }
        else {
            a->dir = insere(a->dir,info);
        }

    return a;
}

Arvore* remover (Arvore* a, int v)
{
    // Exercício para entregar até a quinta-feira (21/05)
}


Arvore* busca (Arvore* a, int v)
{
    // Exercício para entregar até a quinta-feira (21/05)
}


int main()
{
    Arvore* arvore, *nova;

    arvore = cria_vazia();
    arvore = insere(arvore,7);
    arvore = insere(arvore,12);
    arvore = insere(arvore,2);
    arvore = insere(arvore,11);
    arvore = insere(arvore,21);
    arvore = insere(arvore,4);

    printf("Percurso na árvore (in ordem)\n");
    imprime_abb_in_ordem(arvore);

   return 0;
}


