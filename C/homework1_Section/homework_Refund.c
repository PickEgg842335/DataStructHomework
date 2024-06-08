#include <stdio.h>
#include <stdlib.h>

const int wBanknoteItem[7] = {1000, 500, 100, 50, 10, 5, 1};

typedef struct ChangeItem
{
    int wChangeTotal;
    int wChangeItemlist[7];
}strChangeItem;

int sfInputPayable(void);
int sChangeCalforPay(int wPay, strChangeItem *strChangel);

void main()
{
    int wPayablePrice = 0;
    int wPaybillType = 0; 
    strChangeItem strMyChangelist;

    wPayablePrice = sfInputPayable();
    wPaybillType = sChangeCalforPay(wPayablePrice, &strMyChangelist);
    if(wPaybillType == -1)
    {
        printf("輸入錯誤，結束系統\n");
    }
    else if(wPaybillType == 0)
    {
        printf("輸入金額不足\n");
    }
    else if(wPaybillType == 1)
    {
        printf("不需要找零\n");
    }
    else if(wPaybillType == 2)
    {
        printf("找零總金額為%d內容如下:\n", strMyChangelist.wChangeTotal);
        for(int i = 0; i < 7; i++)
        {
            if(i <= 2)
            {
                printf("找零%d元鈔票為%d張\n", wBanknoteItem[i], strMyChangelist.wChangeItemlist[i]);
            }
            else
            {
                printf("找零%d元硬幣為%d枚\n", wBanknoteItem[i], strMyChangelist.wChangeItemlist[i]);
            }
        }
    }
    system("Pause");
}

int sfInputPayable(void)
{
    srand(time(NULL));
    return((rand() % 5000) + 1);
}

int sChangeCalforPay(int wPay, strChangeItem *strChangel)
{
    float fInputPayChk = -1;
    int wInputPayprice = -1;
    int wInputfailCnt = 0;
    int wResultType = -1;
    int wChangeTotal = 0;
    int wBankItemQtyTemp = 0;
    
    while(wInputPayprice == -1)
    {
        printf("您的付款金額為%d元，請輸入付款金額:", wPay);
        scanf("%f", &fInputPayChk);
        getchar();

        if((fInputPayChk < 0) || ((fInputPayChk - (int)fInputPayChk) != 0))
        {
            if(++wInputfailCnt < 3)
            {
                printf("輸入錯誤，請重新輸入\n");
            }
            else
            {
                printf("輸入錯誤達三次，結束\n");
                wInputfailCnt = 0; 
                break;
            }
        }
        else
        {
            wInputPayprice = (int)fInputPayChk;
            wInputfailCnt = 0;
        }
    }

    if(wInputPayprice != -1)
    {
        if(wInputPayprice < wPay)
        {
            wResultType = 0;
        }
        else if(wInputPayprice == wPay)
        {
            wResultType = 1;
        }
        else
        {
            wResultType = 2;
            wChangeTotal = wInputPayprice - wPay;
            strChangel->wChangeTotal = wChangeTotal;
            for(int i = 0; i < 7; i++)
            {
                if(wChangeTotal != 0)
                {
                    strChangel->wChangeItemlist[i] = wChangeTotal / wBanknoteItem[i];
                    wChangeTotal = wChangeTotal % wBanknoteItem[i];
                }
                else
                {
                    strChangel->wChangeItemlist[i] = 0;
                }
            }
        }
    }

    return(wResultType);
}

