#include <stdio.h>
#include <stdlib.h>

typedef struct factor{
    int wFactorSource;
    int wFactorlength;
    int wFactorValue[100];
}strFactor;

int     sGetInputData(void);
void    sGetFactorCal(strFactor *strFactorTemp, int winputValue);
void    sDisplayResult(strFactor *strFactorTemp);

void main()
{
    strFactor strInputFactor;
    int wInputValue = 0;

    wInputValue = sGetInputData();
    if(wInputValue != -1)
    {
        sGetFactorCal(&strInputFactor, wInputValue);
        sDisplayResult(&strInputFactor);
    }
    system("Pause");
}


int sGetInputData(void)
{
    float   fInputValueTemp = 0;
    int     wValue = -1;

    printf("請輸入一個正整數:");
    scanf("%f", &fInputValueTemp);
    getchar();

    if((fInputValueTemp < 0) || (fInputValueTemp - (int)fInputValueTemp) != 0)
    {
        printf("輸入錯誤\n");
    }
    else
    {
        wValue = (int)fInputValueTemp;
    }
    return(wValue);
}


void  sGetFactorCal(strFactor *strFactorTemp, int winputValue)
{   
    strFactorTemp->wFactorSource = winputValue;
    strFactorTemp->wFactorlength = 0;
    
    for(int i = 1; i <= winputValue; i++)
    {
        if((winputValue % i) == 0)
        {
            strFactorTemp->wFactorValue[strFactorTemp->wFactorlength] = i;
            strFactorTemp->wFactorlength++;
        }
    }
}


void  sDisplayResult(strFactor *strFactorTemp)
{
    printf("您輸入為%d，其因數如下:\n", strFactorTemp->wFactorSource);
    for(int i = 0; i < strFactorTemp->wFactorlength; i++)
    {
        printf("%d ", strFactorTemp->wFactorValue[i]);
    }
    printf("\n共%d個因數\n", strFactorTemp->wFactorlength);
}
