#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

// Stack ����ü ����
typedef struct {				
	char items[MAX_SIZE];
	int top;
}Stack;

// Stack ���� �Լ��� ����
void initializeStack(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);
void push(Stack* s, char item);
char pop(Stack* s);
char peek(Stack* s);

#endif
