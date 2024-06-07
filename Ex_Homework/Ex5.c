#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char result[100];
char stack[100];
int  intstack[100];
int  CalResult = 0;
int  infixCheck = 0;

int prec(char); // 設定運算子的優先順序 
int  infixInputChk(char expr[]);
void infixToPostfix(char expr[]);
void PostfixCal(char Postpr[]);

void main()
{
//    char expr[] = "A-B*(C+D)/E";
    char expr[] = "6-3*(7+9)/4";
    infixCheck = infixInputChk(expr);
    if(infixCheck == (-1))
    {
        printf("輸入計算式語法錯誤\n");
    }
    else if(infixCheck == (1))
    {
        printf("輸入計算式語法正確\n");
        infixToPostfix(expr);
        printf("%s\n", result); //6379+*4/-
        PostfixCal(result);
        printf("%d\n", CalResult); //-6
    }

//    char expr1[] = "A+B-C*(D+E)/F";
    char expr1[] = "8+2-9*(4+5)/3"; // 82+945+*3/- 
    infixCheck = infixInputChk(expr1);
    if(infixCheck == (-1))
    {
        printf("輸入計算式語法錯誤\n");
    }
    else if(infixCheck == (1))
    {
        printf("輸入計算式語法正確\n");
        infixToPostfix(expr1);
        printf("%s\n", result); // 82+945+*3/- 
        PostfixCal(result);
        printf("%d\n", CalResult); //-17
    }
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

int infixInputChk(char expr[])
{
    int inputValue = 1;
    int inputCheckBit = 0x09;
    int chk_idx = 0;
    int bracketCnt = 0;
    
    while (inputValue != '\0')
    {
        inputValue = expr[chk_idx];
        printf("%c:%d ", inputValue, inputValue);

        if ((inputValue >= 'a' && inputValue <= 'z') || (inputValue >= 'A' && inputValue <= 'Z')
            || (inputValue >= '0' && inputValue <= '9'))
        {
            if((inputCheckBit & 0x02) == 0x02)
            {
                return(-1);
            }
            else
            {
                inputCheckBit &= !0x09;
                inputCheckBit |= 0x06;
            }
        }
        else if((inputValue == '+') || (inputValue == '-') || (inputValue == '*') || (inputValue == '/'))
        {
            if((inputCheckBit & 0x01) == 0x01)
            {
                return(-1);
            }
            else
            {
                inputCheckBit &= !0x06;
                inputCheckBit |= 0x09;
            }
        }
        else if(inputValue == '(') 
        {
            if((inputCheckBit & 0x04) == 0x04)
            {
                return(-1);
            }
            else
            {
                bracketCnt++;
                inputCheckBit &= !0x02;
                inputCheckBit |= 0x01;
            }        
        }
        else if((inputValue == ')') && (bracketCnt > 0)) 
        {
            if((inputCheckBit & 0x08) == 0x08)
            {
                return(-1);
            }
            else
            {
                bracketCnt--;
                inputCheckBit &= !0x01;
                inputCheckBit |= 0x02;
            }
        }
        else if((inputValue == '\0') && (bracketCnt == 0) && ((inputCheckBit & 0x02) == 0x02))
        {
            break;
        }
        else
        {
            return(-1);
        }
        chk_idx++;
    }

    return(1);
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
 

