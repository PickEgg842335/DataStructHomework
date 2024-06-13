#include <stdio.h>
#include <stdlib.h>

typedef struct AmstrongNum{
    int wAmstrongNumlength;
    int wAmstrongNumValue[100];
}strAmstrongNum;

int     sIntpow(int base, int index);
void    sGetAmstrongNum(strAmstrongNum *strAmstrongTemp);
void    sDisplayResult(strAmstrongNum *strAmstrongTemp);

void main()
{
    strAmstrongNum strMyAmstrongNNum;

    sGetAmstrongNum(&strMyAmstrongNNum);
    sDisplayResult(&strMyAmstrongNNum);
    system("Pause");
}


int     sIntpow(int base, int index)
{
    int wCalTemp = 1;
    
    for(int i = 0; i < index; i++)
    {
        wCalTemp *= base;
    }
    
    return(wCalTemp);
}


void    sGetAmstrongNum(strAmstrongNum *strAmstrongTemp)
{
    strAmstrongTemp->wAmstrongNumlength = 0;
    
    for(int i = 100; i <= 999; i++)
    {
        int wAmstrongSum = 0;
        int wDigitNumTemp;
        
        for(int j = 0; j < 3; j++)
        {
            wDigitNumTemp = (i % sIntpow(10, 3 - j)) / sIntpow(10, 2 - j);
            wAmstrongSum += sIntpow(wDigitNumTemp, 3);
        }

        if(wAmstrongSum == i)
        {
            strAmstrongTemp->wAmstrongNumValue[strAmstrongTemp->wAmstrongNumlength] = i;
            strAmstrongTemp->wAmstrongNumlength++;
        }
    }
}


void    sDisplayResult(strAmstrongNum *strAmstrongTemp)
{
    printf("Amstrong數值如下:\n");
    for(int i = 0; i < strAmstrongTemp->wAmstrongNumlength; i++)
    {
        printf("%d ", strAmstrongTemp->wAmstrongNumValue[i]);
    }
    printf("\n共%d個Amstrong數值\n", strAmstrongTemp->wAmstrongNumlength);
}
