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
	// Stack에 item을 넣기 전 Stack이 가득차있는지 확인
	if (isFull(s))
	{
		printf("Stack is full!\n");
	}
	else
	{
		s->items[++s->top] = item;		// top+1에 item 넣기
	}
}

char pop(Stack* s)
{
	// Stack에 item을 빼기 전 Stack이 비어있는지 확인
	if (isEmpty(s))
	{
		printf("Stack is Empty!pop\n");
		return -1;
	}
	else
	{
		return s->items[s->top--];		// top위치에 있는 item을 반환 후 top -1
	}
}

char peek(Stack* s)
{	
	if (isEmpty(s))
	{
		return -1;
	}
	return s->items[s->top];			// top위치에 있는 item을 반환
}
