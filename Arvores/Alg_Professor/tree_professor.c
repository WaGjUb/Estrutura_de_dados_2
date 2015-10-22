#include <stdio.h>
#include <stdlib.h>

struct arvore {
    char info;
    struct arvore *esq;
    struct arvore *dir;
};

typedef struct arvore Arvore;

Arvore *cria_vazia() {
    return NULL;
}

Arvore *cria (char c, Arvore *sae, Arvore *sad) {
    Arvore *p = (Arvore*) malloc(sizeof(Arvore));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int eh_vazia (Arvore *a) {
    return a == NULL;
}

Arvore *libera (Arvore *a){
    if (!eh_vazia(a)){
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

int pertence (Arvore *a, char c){
    if (eh_vazia(a))
        return 0; /* arvore vazia: nao encontrou */
    else
        return a->info==c ||
        pertence(a->esq,c) ||
        pertence(a->dir,c);
}

void imprime (Arvore *a) {
    if (!eh_vazia(a)) {
        printf("%c ", a->info); /* mostra raiz */
        imprime(a->esq); /* mostra sae */
        imprime(a->dir); /* mostra sad */
    }
}

////////////////////////////////////

int Altura_arvore(Arvore *a)
{
	if (eh_vazia(a))
	{
		return(-1);
	}
	
	int esq, dir;

	esq = Altura_arvore(a->esq);
	dir = Altura_arvore(a->dir);
	
	if (esq > dir)
	{
		return(esq+1);
	} 
	return(dir+1);	
}

void main() {
    
    // subarvore d
    Arvore *a1= cria('d', cria_vazia(), cria_vazia());
    // subarvore b
    Arvore *a2= cria('b', cria_vazia(), a1);
    // subarvore e
    Arvore *a3= cria('e', cria_vazia(), cria_vazia());
    // subarvore f
    Arvore *a4= cria('f', cria_vazia(), cria_vazia());
    // subarvore c
    Arvore *a5= cria('c', a3, a4);
    // arvore a
    Arvore *a = cria('a', a2, cria_vazia());
    
    imprime(a); printf("\n");

	printf("Altura: %d\n", Altura_arvore(a));
    
}
