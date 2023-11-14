#include "binaryTree.h"
typedef Tree ElementType;

typedef struct{
	ElementType *Element;
	int top;
	int capacity;
} Stack;

void makeNull(Stack *pS)
{
	pS->Element = (ElementType*)malloc(sizeof(ElementType));
	pS->capacity = 1;
	pS->top = -1;
}

void resize(Stack *pS, int newCapacity)
{
	ElementType *tmp = pS->Element;
	pS->capacity = newCapacity;
	pS->Element = (ElementType*)malloc(sizeof(ElementType)*newCapacity);
	int i;
	for(i = 0; i<=pS->top; i++)
	{
		pS->Element[i] = tmp[i];
	}
	free(tmp);
}


bool isEmpty_Stack(Stack S)
{
	return S.top == -1;
}
bool isFull(Stack S)
{

}

void push(ElementType X,Stack *pS)
{
	if(pS->top == pS->capacity-1) {
		resize(pS,pS->capacity*2);
	}
	pS->top++;
	pS->Element[pS->top] = X;
}

ElementType pop(Stack *pS)
{

		if(pS->capacity/4 == pS->top+1)
		{
			resize(pS,pS->capacity/2);
		}

		ElementType x = pS->Element[pS->top];
		pS->top--;
		return x;
}


void printStack(Stack S){
	int i;
	for(i = 0; i<=S.top; i++){
		printf("%d ",S.Element[S.top-i]);

	}
}
