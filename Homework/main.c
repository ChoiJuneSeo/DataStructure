#include <string.h>
#include "infixToPostfix.h"
#include "cal.h"


void main()
{
	// 중위 표현식(input)과 후위표현식(output)을 저장할 배열
	char infix[MAX_SIZE], postfix[MAX_SIZE] = { 0 };

	printf("중위표현식 입력: ");
	fgets(infix, MAX_SIZE, stdin);			// 사용자에게 중위 표현식 받아옴
	infix[strcspn(infix, "\n")] = 0;		// 문자열 마지막의 '\n' 제거 (엔터키로 입력하니까)

	infixToPostfix(infix, postfix);
	printf("변환된 후위표현식: %s\n", postfix);
	calculatePostfix(postfix); 

 }