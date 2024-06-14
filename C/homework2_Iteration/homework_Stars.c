#include <stdio.h>
#include <stdlib.h>


int     sGetInputData(void);
void    sDisplayResult(int wLvTemp);


void main()
{
    int wInputValue = 0;

    wInputValue = sGetInputData();
    if(wInputValue != -1)
    {
        sDisplayResult(wInputValue);
    }
    system("Pause");
}


int     sGetInputData(void)
{
    float   fInputValueTemp = 0;
    int     wValue = -1;

    printf("請輸入星星層數:");
    scanf("%f", &fInputValueTemp);
    getchar();

    if((fInputValueTemp < 1) || ((fInputValueTemp - (int)fInputValueTemp) != 0))
    {
        printf("輸入錯誤\n");
    }
    else
    {
        wValue = (int)fInputValueTemp;
    }
    return(wValue);
}


void    sDisplayResult(int wLvTemp)
{
    printf("\n(1):\n\n");
    for(int i = 0; i < wLvTemp; i++)
    {
        for(int j = 0; j < wLvTemp; j++)
        {
            if(j <= i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n(2):\n\n");
    for(int i = 0; i < wLvTemp; i++)
    {
        for(int j = 0; j < wLvTemp; j++)
        {
            if(j >= i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("\n(3):\n\n");
    for(int i = 0; i < wLvTemp; i++)
    {
        for(int j = 0; j < (2 * wLvTemp + 1); j++)
        {
            if(j < wLvTemp)
            {
                if(j >= (wLvTemp - i))
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            else if(j == wLvTemp)
            {
                printf("*");
            }
            else
            {
                if((j - wLvTemp - 1) < i)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
