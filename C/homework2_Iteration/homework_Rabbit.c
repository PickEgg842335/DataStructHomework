#include <stdio.h>
#include <stdlib.h>

typedef struct RabbitNum{
    int     wRabbitNum;
}strRabbitNum;

void    sGetRabbitNum(strRabbitNum *strRabbitTemp);
void    sDisplayResult(strRabbitNum *strRabbitTemp);


void main()
{
    strRabbitNum strMyRabbitNum;

    sGetRabbitNum(&strMyRabbitNum);
    sDisplayResult(&strMyRabbitNum);
    system("Pause");
}


void    sGetRabbitNum(strRabbitNum *strRabbitTemp)
{
    strRabbitTemp->wRabbitNum = 0;
    int wRabbitValue = 0;

    while(strRabbitTemp->wRabbitNum == 0)
    {
        wRabbitValue++;
        if(((wRabbitValue % 3) == 1)
            && ((wRabbitValue % 5) == 3)
            && ((wRabbitValue % 7) == 2))
        {
            strRabbitTemp->wRabbitNum = wRabbitValue;
        }
    }
}


void    sDisplayResult(strRabbitNum *strRabbitTemp)
{
    printf("老王最少養了%d隻兔子\n", strRabbitTemp->wRabbitNum);
}
