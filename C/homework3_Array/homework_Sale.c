#include <stdio.h>
#include <stdlib.h>

typedef struct SaleResult {
    int wPersonResult[3];
    int wMaxPersonResult;
    int wProductResult[5];
    int wMaxProductResult;
}SaleResult;

void sfSaleResultCal(int *wIntputArray, SaleResult *strOutput);

void main()
{
    const char  *name[3] = {"Jean", "Tom", "Tina"};
    const char  *Product[5] = {"ProductA", "ProductB", "ProductC", "ProductD", "ProductE"};
    const int   wSaleValue[3][5] = {
        {33, 32, 56, 45, 33},
        {77, 33, 68, 45, 23},
        {43, 55, 43, 67, 65},
    };
    SaleResult StrSaleResult;

    sfSaleResultCal(wSaleValue, &StrSaleResult);
    printf("a. 每一位銷售業績如下:\n");
    for(int i = 0; i < 3; i++)
    {
        printf("%s: %d\n", &name[i][0], StrSaleResult.wPersonResult[i]);
    }
    printf("\n");
    
    printf("b. 有最好業績（銷售總金額最多者）的銷售員:\n");
    printf("%s\n", &name[StrSaleResult.wMaxPersonResult][0]);
    printf("\n");

    printf("c. 每一項產品的銷售總金額:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%s: %d\n", &Product[i][0], StrSaleResult.wProductResult[i]);
    }
    printf("\n");

    printf("d. 銷售總金額最多的產品:\n");
    printf("%s\n", &Product[StrSaleResult.wMaxProductResult][0]);
    printf("\n");

    system("Pause");
}


void sfSaleResultCal(int *wIntputArray, SaleResult *strOutput)
{
    int wInputData[3][5];
    int wPersonBaseResult[5] = {1, 1, 1, 1, 1};
    int wProductBaseResult[3] = {1, 1, 1};
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            wInputData[i][j] = *(wIntputArray + ((i * 5) + j));
        }
    }
    
    for(int i = 0; i < 3; i++)
    {
        strOutput->wPersonResult[i] = 0;
    }
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            strOutput->wPersonResult[i] += wInputData[i][j] * wPersonBaseResult[j];
        }
    }
    
    strOutput->wMaxPersonResult = 0;
    for(int i = 0; i < 3; i++)
    {
        if(strOutput->wPersonResult[strOutput->wMaxPersonResult] < strOutput->wPersonResult[i])
        {
            strOutput->wMaxPersonResult = i;
        }
    }
    
    for(int i = 0; i < 5; i++)
    {
        strOutput->wProductResult[i] = 0;
    }
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            strOutput->wProductResult[i] += wProductBaseResult[j] * wInputData[j][i];
        }
    }
    
    strOutput->wMaxProductResult = 0;
    for(int i = 0; i < 5; i++)
    {
        if(strOutput->wProductResult[strOutput->wMaxProductResult] < strOutput->wProductResult[i])
        {
            strOutput->wMaxProductResult = i;
        }
    }
}
