#include "infixToPostfix.h"
#include <ctype.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

// 연산자 우선 순위 반환 함수

int precedence(char ch)
{
	switch (ch)
	{
	case '+' :
	case '-' :
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}
}

// strcat에서 계속 문제가 발생하여 안전성을 위한 () 추가는 생략했습니다. 

// 중위 -> 후위 변환 함수
void infixToPostfix(char* infix, char* postfix)
{
	// Stack 및 필요한 변수들 생성
	Stack s;		
	initializeStack(&s);	
	int i =0 , j = 0; 
	char item, x;
	
	while ((item = infix[i++]) != '\0')		// input으로 받은 값이 null일 때까지
	{
		if (item == '(')					// item이 (면 Stack에 추가
		{
			push(&s, item);
		}
		else if (isdigit(item)) 	// item이 피연산자이면 postfix배열에 추가
		{
			postfix[j++] = item;
		}
		else if (precedence(item) > 0 )		// item이 연산자이면 
		{
			while (precedence(peek(&s)) >= precedence(item)) // Stack에 있는 것보다 우선순위가 낮은 연산자가 들어오면
			{
				postfix[j++] = pop(&s);			// Stack에 있는 연산자를 배열로 옮김
			}
			push(&s, item);					// 배열에 연산자 추가
		}
		else if (item == ')')			// )를 만나면
		{
			while ((x = pop(&s)) != '(')		// (가 나올 떄 까지 Stack에 있는 연산자를 배열로 옮김
			{
				postfix[j++] = x;		
			}
		}
	}

	if (!isEmpty(&s))		// 앞뒤에 괄호를 안넣어주었기 때문에, 스택에 뭔가 남아있으면 전부 pop
	{
		while (!isEmpty(&s))
		{
			postfix[j++] = pop(&s); 
		}
	}

	postfix[j] = '\0';		// 배열의 마지막을 null문자로 바꿈. strcspn의 반대

}