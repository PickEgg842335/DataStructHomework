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

    printf("�п�J�@�ӥ����:");
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
    printf("�z��J��%d�A��]�Ʀp�U:\n", strFactorTemp->wFactorSource);
    for(int i = 0; i < strFactorTemp->wFactorlength; i++)
    {
        printf("%d ", strFactorTemp->wFactorValue[i]);
    }
    printf("\n�@%d�Ӧ]��\n", strFactorTemp->wFactorlength);
}
