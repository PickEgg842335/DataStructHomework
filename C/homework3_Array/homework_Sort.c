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
    printf("\n輸入為上述%d個亂數\n\n", wArrayLength);
}


void sfInputArrayByBubbleChk(int wInputArrayLength, int *pInputArray)
{
    int wOutputArray[wInputArrayLength];
    int *pwWorkNumber = wOutputArray;
    
    for(int i = 0; i < wInputArrayLength; i++)
    {
        wOutputArray[i] = *(pInputArray + i);
    }
    
    printf("(1)使用Bubble Sort方法排序:\n");
    printf("原始數據:\n");
    for(int i = 0; i < wInputArrayLength; i++)
    {
        printf("%d ", *(pInputArray + i));
    }
    printf("\n");
    printf("詳細排序過程:\n");
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
    printf("結果如下:\n");
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

    printf("(2)使用Selection Sort方法排序:\n");
    printf("原始數據:\n");
    for(int i = 0; i < wInputArrayLength; i++)
    {
        printf("%d ", *(pInputArray + i));
    }
    printf("\n");
    printf("詳細排序過程:\n");

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
    printf("結果如下:\n");
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
    
    printf("(3)使用Insertion Sort方法排序:\n");
    printf("原始數據:\n");
    for(int i = 0; i < wInputArrayLength; i++)
    {
        printf("%d ", *(pInputArray + i));
    }
    printf("\n");
    printf("詳細排序過程:\n");
    
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
    
    printf("結果如下:\n");
    for(int i = 0; i < wInputArrayLength; i++)
    {
        printf("%d ", *(wOutputArray + i));
    }
    printf("\n\n");

}
