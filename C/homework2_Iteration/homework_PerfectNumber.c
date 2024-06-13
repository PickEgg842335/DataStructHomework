#include <stdio.h>
#include <stdlib.h>

typedef struct PerfectNum{
    int wMaxPerfectNum;
    int wPerfectNumlength;
    int wPerfectNumValue[100];
}strPerfectNum;

int     sGetInputData(void);
void    sGetPerfectNum(strPerfectNum *strPerfecTemp, int winputValue);
void    sDisplayResult(strPerfectNum *strPerfecTemp);

void main()
{
    strPerfectNum strMyPerfectNum;
    int wInputValue = 0;

    wInputValue = sGetInputData();
    if(wInputValue != -1)
    {
        sGetPerfectNum(&strMyPerfectNum, wInputValue);
        sDisplayResult(&strMyPerfectNum);
    }
    system("Pause");
}


int sGetInputData(void)
{
    float   fInputValueTemp = 0;
    int     wValue = -1;

    printf("請輸入一個正整數，來尋找完美數:");
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


void    sGetPerfectNum(strPerfectNum *strPerfecTemp, int winputValue)
{
    strPerfecTemp->wMaxPerfectNum = winputValue;
    strPerfecTemp->wPerfectNumlength = 0;
    
    for(int i = 2; i <= winputValue; i++)
    {
        int wFactorSum = 0;
        for(int j = 1; j < i; j++)
        {
            if((i % j) == 0)
            {
                wFactorSum += j;
            }
        }
        if(wFactorSum == i)
        {
            strPerfecTemp->wPerfectNumValue[strPerfecTemp->wPerfectNumlength] = i;
            strPerfecTemp->wPerfectNumlength++;
        }
    }
}


void    sDisplayResult(strPerfectNum *strPerfecTemp)
{
    printf("您輸入數值為%d，小於該數值的完美數如下:\n", strPerfecTemp->wMaxPerfectNum);
    for(int i = 0; i < strPerfecTemp->wPerfectNumlength; i++)
    {
        printf("%d ", strPerfecTemp->wPerfectNumValue[i]);
    }
    printf("\n共%d個完美數\n", strPerfecTemp->wPerfectNumlength);
}
