#include <string.h>
#include "infixToPostfix.h"
#include "cal.h"


void main()
{
	// ���� ǥ����(input)�� ����ǥ����(output)�� ������ �迭
	char infix[MAX_SIZE], postfix[MAX_SIZE] = { 0 };

	printf("����ǥ���� �Է�: ");
	fgets(infix, MAX_SIZE, stdin);			// ����ڿ��� ���� ǥ���� �޾ƿ�
	infix[strcspn(infix, "\n")] = 0;		// ���ڿ� �������� '\n' ���� (����Ű�� �Է��ϴϱ�)

	infixToPostfix(infix, postfix);
	printf("��ȯ�� ����ǥ����: %s\n", postfix);
	calculatePostfix(postfix); 

 }