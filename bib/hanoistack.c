#include "hanoistack.h"

Stack* Create()
{
	Stack* s;
        s = malloc(sizeof(Stack));
        s->top = NULL;
        s->size = 0;
	return(s);
}

bool Add(Stack *s, int data)
{
	int val;

		if (NextDataRequest(s,&val))
		{
			if  (data > val)
			{
				return(false);
			}
		}
		Node* aux;
		aux = malloc(sizeof(Stack));

		aux->data = data;
		aux->prev = s->top;
		s->top = aux;
		s->size++;

		return(true);
	
	return(false);
}

bool Pop(Stack *s)
{
	int val;
	if (NextDataRequest(s, &val))
	{
		Node* aux;

		aux = s->top;
		s->top = s->top->prev;
		aux->prev = NULL;
		free(aux);
		s->size--;
		return(true);
	}
	return(false);
}

bool NextDataRequest(Stack *s, int* val)
{
	if (s->top == NULL)
	{	
		return(false);
	}
	else
	{
		*val = s->top->data;
		return(true);
	}
}

