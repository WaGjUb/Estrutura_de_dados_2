#ifndef __hanoibib__
#define __hanoibib__
#include <stdio.h>
#include <stdlib.h>

typedef enum {false=0, true=1} bool;


typedef struct node{

	int data;
	struct node* prev;  	

}Node;


typedef struct stack{
	Node* top;
	int size;
} Stack;

Stack* Create();
bool Add(Stack *s, int data);
bool Pop(Stack *s);
bool NextDataRequest(Stack *s, int* val);

#endif
