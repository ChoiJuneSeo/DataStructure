#include <stdio.h>
#define MAX_SIZE 200

typedef struct
{
	int items[MAX_SIZE];
	int top;
}stack;

void createStack(stack* s) 
{
	s->top = -1;
};
int isFull(stack* s) 
{
	return s->top == MAX_SIZE-1;
};
int isEmpty(stack* s) 
{
	return s->top == -1;
};
void push(stack*s,int data) 
{
	if (isFull(s)) return;

	s->items[++s->top] = data;
};
int pop(stack* s) 
{
	if (isEmpty(s)) return;

	return s->items[s->top--];
};
int peek(stack* s) 
{
	if (isEmpty(s)) return;

	return s->items[s->top];
};












void maim()
{

}