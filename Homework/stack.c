#include "stack.h"
#include <stdio.h>

void initializeStack(Stack* s)
{
	s->top = -1;
}


int isEmpty(Stack* s)
{
	return s->top == -1;
}

int isFull(Stack* s)
{
	return s->top == MAX_SIZE - 1;
}

void push(Stack* s, char item)
{
	// Stack�� item�� �ֱ� �� Stack�� �������ִ��� Ȯ��
	if (isFull(s))
	{
		printf("Stack is full!\n");
	}
	else
	{
		s->items[++s->top] = item;		// top+1�� item �ֱ�
	}
}

char pop(Stack* s)
{
	// Stack�� item�� ���� �� Stack�� ����ִ��� Ȯ��
	if (isEmpty(s))
	{
		printf("Stack is Empty!pop\n");
		return -1;
	}
	else
	{
		return s->items[s->top--];		// top��ġ�� �ִ� item�� ��ȯ �� top -1
	}
}

char peek(Stack* s)
{	
	if (isEmpty(s))
	{
		return -1;
	}
	return s->items[s->top];			// top��ġ�� �ִ� item�� ��ȯ
}
