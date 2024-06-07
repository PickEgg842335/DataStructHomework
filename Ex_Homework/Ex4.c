#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char result[100];
char stack[100];

int prec(char); // 設定運算子的優先順序 
void infixToPrefix(char expr[]);

void main()
{
    char expr[] = "A-B*(C+D)/E";
    infixToPrefix(expr);
    printf("%s\n", result); //ABCD+*E/-  //-A/*B+CDE
    char expr1[] = "A+B-C*(D+E)/F";
    infixToPrefix(expr1);
    printf("%s\n", result); //ABCD+*E/-  //-+AB/*C+DEF
}

int prec(char c)
{
    if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
  
void infixToPrefix(char expr[])
{
    char reverseResult[100];
    int result_idx = 0;
    int stack_idx = -1;

    for (int i = strlen(expr); i >= 0; i--) 
    {
        char c = expr[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            reverseResult[result_idx++] = c;
        }
        else if (c == ')')
        {
            stack[++stack_idx] = c;
        }
        else if (c == '(') 
        {
            while (stack_idx >= 0 && stack[stack_idx] != ')') 
            {
                reverseResult[result_idx++] = stack[stack_idx--];
            }
            stack_idx--; // Pop ')'
        }
        else 
        {
            while (stack_idx >= 0 && prec(c) < prec(stack[stack_idx])) 
            {
                reverseResult[result_idx++] = stack[stack_idx--];
            }
            stack[++stack_idx] = c;
        }
    }
 
    while (stack_idx >= 0)
    {
        reverseResult[result_idx++] = stack[stack_idx--];
    }
    
    for(int i = 0; i < (result_idx - 1); i++)
    {
        result[result_idx - 2 - i] = reverseResult[i];
    }

    result[result_idx - 1] = '\0';
}
 

