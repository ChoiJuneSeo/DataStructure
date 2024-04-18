#include "infixToPostfix.h"
#include <ctype.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

// ������ �켱 ���� ��ȯ �Լ�

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

// strcat���� ��� ������ �߻��Ͽ� �������� ���� () �߰��� �����߽��ϴ�. 

// ���� -> ���� ��ȯ �Լ�
void infixToPostfix(char* infix, char* postfix)
{
	// Stack �� �ʿ��� ������ ����
	Stack s;		
	initializeStack(&s);	
	int i =0 , j = 0; 
	char item, x;
	
	while ((item = infix[i++]) != '\0')		// input���� ���� ���� null�� ������
	{
		if (item == '(')					// item�� (�� Stack�� �߰�
		{
			push(&s, item);
		}
		else if (isdigit(item)) 	// item�� �ǿ������̸� postfix�迭�� �߰�
		{
			postfix[j++] = item;
		}
		else if (precedence(item) > 0 )		// item�� �������̸� 
		{
			while (precedence(peek(&s)) >= precedence(item)) // Stack�� �ִ� �ͺ��� �켱������ ���� �����ڰ� ������
			{
				postfix[j++] = pop(&s);			// Stack�� �ִ� �����ڸ� �迭�� �ű�
			}
			push(&s, item);					// �迭�� ������ �߰�
		}
		else if (item == ')')			// )�� ������
		{
			while ((x = pop(&s)) != '(')		// (�� ���� �� ���� Stack�� �ִ� �����ڸ� �迭�� �ű�
			{
				postfix[j++] = x;		
			}
		}
	}

	if (!isEmpty(&s))		// �յڿ� ��ȣ�� �ȳ־��־��� ������, ���ÿ� ���� ���������� ���� pop
	{
		while (!isEmpty(&s))
		{
			postfix[j++] = pop(&s); 
		}
	}

	postfix[j] = '\0';		// �迭�� �������� null���ڷ� �ٲ�. strcspn�� �ݴ�

}