#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

// Stack 구조체 정의
typedef struct {				
	char items[MAX_SIZE];
	int top;
}Stack;

// Stack 관련 함수들 정의
void initializeStack(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);
void push(Stack* s, char item);
char pop(Stack* s);
char peek(Stack* s);

#endif
