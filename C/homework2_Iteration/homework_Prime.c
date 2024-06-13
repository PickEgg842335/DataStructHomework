#include <stdio.h>
#include <stdlib.h>

typedef struct PrimeNum{
    int wMaxFindPrimeNum;
    int wPrimeNumlength;
    int wPrimeNumValue[100];
}strPrimeNum;

int     sGetInputData(void);
void    sGetPrimeNum(strPrimeNum *strPrimeTemp, int winputValue);
void    sDisplayResult(strPrimeNum *strPrimeTemp);

void main()
{
    strPrimeNum strMyPrimeNum;
    int wInputValue = 0;

    wInputValue = sGetInputData();
    if(wInputValue != -1)
    {
        sGetPrimeNum(&strMyPrimeNum, wInputValue);
        sDisplayResult(&strMyPrimeNum);
    }
    system("Pause");
}


int sGetInputData(void)
{
    float   fInputValueTemp = 0;
    int     wValue = -1;

    printf("�п�J�@�ӥ���ơA�ӴM��p��Ӽƪ����:");
    scanf("%f", &fInputValueTemp);
    getchar();

    if((fInputValueTemp < 0) || (fInputValueTemp - (int)fInputValueTemp) != 0)
    {
        printf("��J���~\n");
    }
    else
    {
        wValue = (int)fInputValueTemp;
    }
    return(wValue);
}


void    sGetPrimeNum(strPrimeNum *strPrimeTemp, int winputValue)
{
    strPrimeTemp->wMaxFindPrimeNum = winputValue;
    strPrimeTemp->wPrimeNumlength = 0;
    
    for(int i = 2; i <= winputValue; i++)
    {
        int wFactorQty = 0;
        for(int j = 1; j <= i; j++)
        {
            if((i % j) == 0)
            {
                wFactorQty++;
            }
        }
        if(wFactorQty == 2)
        {
            strPrimeTemp->wPrimeNumValue[strPrimeTemp->wPrimeNumlength] = i;
            strPrimeTemp->wPrimeNumlength++;
        }
    }
}


void    sDisplayResult(strPrimeNum *strPrimeTemp)
{
    printf("�z��J�ƭȬ�%d�A�p��ӼƭȪ���Ʀp�U:\n", strPrimeTemp->wMaxFindPrimeNum);
    for(int i = 0; i < strPrimeTemp->wPrimeNumlength; i++)
    {
        printf("%d ", strPrimeTemp->wPrimeNumValue[i]);
    }
    printf("\n�@%d�ӽ��\n", strPrimeTemp->wPrimeNumlength);
}
