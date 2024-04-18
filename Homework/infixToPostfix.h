#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include "stack.h"

void infixToPostfix(char* infix, char* postfix);
int precedence(char ch);

#endif
