#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void sfInputRandArray(int wArrayLength, int wRang, int *pArrayTemp);
void sfInputArrayByBubbleChk(int wInputArrayLength, int *pInputArray);
void sfInputArrayBySelectionChk(int wInputArrayLength, int *pInputArray);
void sfInputArrayByInsertionChk(int wInputArrayLength, int *pInputArray);

void main()
{
    int wInputNum[10] = {0};
    int wRandRange = 11;     
    int wInputNumLength = sizeof(wInputNum) / sizeof(wInputNum[0]);

    sfInputRandArray(wInputNumLength, wRandRange, wInputNum);
    sfInputArrayByBubbleChk(wInputNumLength, wInputNum);
    sfInputArrayBySelectionChk(wInputNumLength, wInputNum);
    sfInputArrayByInsertionChk(wInputNumLength, wInputNum);
    system("Pause");
}


void sfInputRandArray(int wArrayLength, int wRang, int *pArrayTemp)
{
    srand(time(NULL));
    for(int i = 0; i < wArrayLength; i++)
    {
        *(pArrayTemp + i) = rand() % wRang;
        printf("%d ", *(pArrayTemp + i));
    }
    printf("\n��J���W�z%d�Ӷü�\n\n", wArrayLength);
}


void sfInputArrayByBubbleChk(int wInputArrayLength, int *pInputArray)
{
    int wOutputArray[wInputArrayLength];
    int *pwWorkNumber = wOutputArray;
    
    for(int i = 0; i < wInputArrayLength; i++)
    {
        wOutputArray[i] = *(pInputArray + i);
    }
    
    printf("(1)�ϥ�Bubble Sort��k�Ƨ�:\n");
    printf("��l�ƾ�:\n");
    for(int i = 0; i < wInputArrayLength; i++)
    {
        printf("%d ", *(pInputArray + i));
    }
    printf("\n");
    printf("�ԲӱƧǹL�{:\n");
    for(int i = 0; i < wInputArrayLength; i++)
    {
        pwWorkNumber = wOutputArray;
        for(int j = 1; j < (wInputArrayLength - i); j++)
        {
            int wChangeTemp;
            if(*pwWorkNumber > *(wOutputArray + j))
            {
                wChangeTemp = *pwWorkNumber;
                *pwWorkNumber =  *(wOutputArray + j);
                *(wOutputArray + j) = wChangeTemp;
                printf("%d %d:", i, j);
                for(int k = 0; k < wInputArrayLength; k++)
                {
                    printf("%d ", *(wOutputArray + k));
                }
                printf("\n");
            }
            pwWorkNumber = wOutputArray + j;
        }
    }
    printf("���G�p�U:\n");
    for(int i = 0; i < wInputArrayLength; i++)
    {
        printf("%d ", *(wOutputArray + i));
    }
    printf("\n\n");
}


void sfInputArrayBySelectionChk(int wInputArrayLength, int *pInputArray)
{
    int     wOutputArray[wInputArrayLength];
    bool    bignoreFlag[wInputArrayLength];
    int     wWorkNumber = *pInputArray;
    int     wSmallWorkNumber = 0;
    int     wSelectedIndex = 0;
    
    for(int i = 0; i < wInputArrayLength; i++)
    {
        wOutputArray[i] = 0;
        bignoreFlag[i] = false;
    }

    printf("(2)�ϥ�Selection Sort��k�Ƨ�:\n");
    printf("��l�ƾ�:\n");
    for(int i = 0; i < wInputArrayLength; i++)
    {
        printf("%d ", *(pInputArray + i));
    }
    printf("\n");
    printf("�ԲӱƧǹL�{:\n");

    for(int i = 0; i < wInputArrayLength; i++)
    {
        bool bFirstUpgrade = true;
        for(int j = 0; j < wInputArrayLength; j++)
        {
            if(((wWorkNumber >= *(pInputArray + j)) || (wWorkNumber < wSmallWorkNumber) || (bFirstUpgrade == true))
                && (bignoreFlag[j] == false))
            {
                wSelectedIndex = j;
                wWorkNumber = *(pInputArray + j);
                bFirstUpgrade = false;
            }
        }
        wOutputArray[i] = wWorkNumber;
        wSmallWorkNumber = wWorkNumber;
        bignoreFlag[wSelectedIndex] = true;
        printf("%d:", wSelectedIndex);
        for(int j = 0; j <= i; j++)
        {
            printf("%d ", *(wOutputArray + j));
        }
        printf("\n");
    }
    printf("���G�p�U:\n");
    for(int i = 0; i < wInputArrayLength; i++)
    {
        printf("%d ", *(wOutputArray + i));
    }
    printf("\n\n");
}


void sfInputArrayByInsertionChk(int wInputArrayLength, int *pInputArray)
{
    int wOutputArray[wInputArrayLength];
    
    for(int i = 0; i < wInputArrayLength; i++)
    {
        wOutputArray[i] = *(pInputArray + i);
    }
    
    printf("(3)�ϥ�Insertion Sort��k�Ƨ�:\n");
    printf("��l�ƾ�:\n");
    for(int i = 0; i < wInputArrayLength; i++)
    {
        printf("%d ", *(pInputArray + i));
    }
    printf("\n");
    printf("�ԲӱƧǹL�{:\n");
    
    for(int i = 0; i < wInputArrayLength; i++)
    {
        for(int j = i; j > 0; j--)
        {
            int wChangeTemp;
            if(wOutputArray[j - 1] > wOutputArray[j])
            {
                wChangeTemp = wOutputArray[j];
                wOutputArray[j] = wOutputArray[j - 1];
                wOutputArray[j - 1] = wChangeTemp;
                printf("%d %d:", i, j);
                for(int k = 0; k < wInputArrayLength; k++)
                {
                    printf("%d ", *(wOutputArray + k));
                }
                printf("\n");
            }
        }
    }
    
    printf("���G�p�U:\n");
    for(int i = 0; i < wInputArrayLength; i++)
    {
        printf("%d ", *(wOutputArray + i));
    }
    printf("\n\n");

}
