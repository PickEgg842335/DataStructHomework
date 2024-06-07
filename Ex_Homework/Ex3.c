#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char result[100];
char stack[100];
int  intstack[100];
int  CalResult = 0;

int prec(char); // 設定運算子的優先順序 
void infixToPostfix(char expr[]);
void PostfixCal(char Postpr[]);

void main()
{
//    char expr[] = "A-B*(C+D)/E";
    char expr[] = "6-3*(7+9)/4";
    infixToPostfix(expr);
    printf("%s\n", result); //6379+*4/-
    PostfixCal(result);
    printf("%d\n", CalResult); //-6

//    char expr1[] = "A+B-C*(D+E)/F";
    char expr1[] = "8+2-9*(4+5)/3"; // 82+945+*3/- 
    infixToPostfix(expr1);
    printf("%s\n", result); // 82+945+*3/- 
    PostfixCal(result);
    printf("%d\n", CalResult); //-17
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

void infixToPostfix(char expr[])
{
    int result_idx = 0;
    int stack_idx = -1;
    for (int i = 0; i < strlen(expr); i++) 
    {
        char c = expr[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result[result_idx++] = c;
        }
        else if (c == '(')
        {
            stack[++stack_idx] = c;
        }
        else if (c == ')') 
        {
            while (stack_idx >= 0 && stack[stack_idx] != '(') 
            {
                result[result_idx++] = stack[stack_idx--];
            }
            stack_idx--; // Pop '('
        }
        else 
        {
            while (stack_idx >= 0 && prec(c) <= prec(stack[stack_idx])) 
            {
                result[result_idx++] = stack[stack_idx--];
            }
            stack[++stack_idx] = c;
        }
    }
 
    while (stack_idx >= 0)
    {
        result[result_idx++] = stack[stack_idx--];
    }
 
    result[result_idx] = '\0';
}


void PostfixCal(char Postpr[])
{
    int Postpr_idx = 0;
    int stack_idx = -1;
    int intValue = 1;
    
    while(intValue != '\0')
    {
        int intValueTemp1 = 0;
        int intValueTemp2 = 0;
        
        intValue = Postpr[Postpr_idx];
        if(intValue >= '0' && intValue <= '9')
        {
            intstack[++stack_idx] = (int)(intValue - '0');
        }
        else if(stack_idx >= 1)
        {
            if (intValue == '+') 
            {
                intValueTemp2 = intstack[stack_idx--];
                intValueTemp1 = intstack[stack_idx--];
                intValueTemp1 = intValueTemp1 + intValueTemp2;
                intstack[++stack_idx] = intValueTemp1;
            }        
            else if (intValue == '-')
            {
                intValueTemp2 = intstack[stack_idx--];
                intValueTemp1 = intstack[stack_idx--];
                intValueTemp1 = intValueTemp1 - intValueTemp2;
                intstack[++stack_idx] = intValueTemp1;
            }
            else if (intValue == '*')
            {
                intValueTemp2 = intstack[stack_idx--];
                intValueTemp1 = intstack[stack_idx--];
                intValueTemp1 = intValueTemp1 * intValueTemp2;
                intstack[++stack_idx] = intValueTemp1;
            }
            else if (intValue == '/')
            {
                intValueTemp2 = intstack[stack_idx--];
                intValueTemp1 = intstack[stack_idx--];
                intValueTemp1 = intValueTemp1 / intValueTemp2;
                intstack[++stack_idx] = intValueTemp1;
            }
        }
        Postpr_idx++;
    }
    CalResult = intstack[stack_idx--];
}
 

