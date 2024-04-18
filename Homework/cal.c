#include "cal.h"

// ���� ǥ��� ������ �޾Ƽ� ����Ͽ� ����� ����ϴ� �Լ�
void calculatePostfix(char* postfix)
{
    Stack s;
    initializeStack(&s);
    int i = 0;
    char item;
    int operand1, operand2, result;

    while ((item = postfix[i++]) != '\0')
    {
        if (isdigit(item)) 
        {                    // item�� 0~9�� stack�� �߰� (int�� ����� ���� -'0')
            push(&s, item - '0');
        }
        else 
        {                                  // item�� �����ڸ� stack���� �ΰ��� ���� ��� �� ����� stack�� ����
            operand2 = pop(&s);
            operand1 = pop(&s);
            switch (item) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                printf("����.\n"); 
            }
            push(&s, result);               
        }
    }
    printf("��� ���: %d\n", pop(&s));
}




































/*
* 

int evaluatePostfix(char* postfix) {
    Stack s;
    initializeStack(&s);
    int i;
    char temp[MAX_SIZE];

    for (i = 0; postfix[i]; ++i)
    {
        if ('0' <= postfix[i] && postfix[i] <= '9')
        {
            sprintf(temp, "%c", postfix[i]);
            push(&s, temp);
        }
        else {
            char operand2 = pop(&s);
            char operand1 = pop(&s);
            int int_op1 = (int)operand1 - 48;
            int int_op2 = (int)operand2 - 48;

            switch (postfix[i]) {
            case '+':
                sprintf(temp, "%d", int_op1 + int_op2);
                push(&s, temp);
                break;
            case '-':
                sprintf(temp, "%d", int_op1 - int_op2);
                push(&s, temp);
                break;
            case '*':
                sprintf(temp, "%d", int_op1 * int_op2);
                push(&s, temp);
                break;
            case '/':
                sprintf(temp, "%d", int_op1 / int_op2);
                push(&s, temp);
                break;
            }
        }
    }
    return pop(&s);
}

*/