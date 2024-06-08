#include <stdio.h>
#include <stdlib.h>

typedef struct ElectriccityTable
{
    float   fEctTabNonbine[6][3];
    float   fEctTabbine[4][3];
    int     wEctTabNonbineLength;
    int     wEctTabbineLength;
}strEctTab;

const strEctTab TaipowerEctTab = {
    {
        {0, 1.63, 1.63},
        {120, 2.38, 2.1},
        {330, 3.52, 2.89},
        {500, 4.8, 3.94},
        {700, 5.66, 4.60},
        {1000, 6.41, 5.03},
    },
    {
        {0, 2.53, 2.12},
        {330, 3.55, 2.91},
        {700, 4.25, 3.44},
        {1500, 6.43, 5.05},
    },
    6,
    4,
};

float sfElectricityCal(void);

void main(void)
{
    float TaipowerbillPrice = 0; 
    
    TaipowerbillPrice = sfElectricityCal();
    printf("%f\n", TaipowerbillPrice);
    system("Pause");
}


float sfElectricityCal(void)
{
    float fInputUserChk = 0;
    int wInputUserType = 0;
    int wInputUserDegree = 0;
    int wInputUserMonth = 0;
    float *fCurrentTable = 0;
    int wCurrntMonthType = 0;
    int wCurrentTableLength = 0; 
    int wInputfailCnt = 0;
    float fTotalBillPriceTemp = 0;
    float lastprice = 0;
    float fTotalBillPrice = 0;

    while((wInputUserType != 1) && (wInputUserType != 2))
    {
        printf("請輸入用電種類，輸入1:非營業用電，輸入2:營業用電:");
        scanf("%f", &fInputUserChk);
        getchar();
    
        if((fInputUserChk < 1) || (fInputUserChk > 2)
            || ((fInputUserChk - (int)fInputUserChk) != 0))
        {
            if(++wInputfailCnt < 3)
            {
                printf("輸入錯誤，需輸入1或2，請重新輸入\n");
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
            wInputUserType = (int)fInputUserChk;
            wInputfailCnt = 0;
        }
    }

    while(((wInputUserType == 1) || (wInputUserType == 2)) && (wInputUserDegree == 0))
    {
        printf("請輸入用電度數:");
        scanf("%f", &fInputUserChk);
        getchar();
    
        if(fInputUserChk < 0 || ((fInputUserChk - (int)fInputUserChk) != 0))
        {
            if(++wInputfailCnt < 3)
            {
                printf("輸入不可為負數、小數或非數字，請重新輸入\n");
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
            wInputUserDegree = (int)fInputUserChk;
            wInputfailCnt = 0;
        }
    }
    
    while(((wInputUserType == 1) || (wInputUserType == 2)) && (wInputUserDegree != 0) 
        && ((wInputUserMonth < 1) || (wInputUserMonth > 12)))
    {
        printf("請輸入用電月份:");
        scanf("%f", &fInputUserChk);
        getchar();
    
        if((fInputUserChk < 1) || (fInputUserChk > 12)
            || ((fInputUserChk - (int)fInputUserChk) != 0))
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
            if((fInputUserChk < 6) || (fInputUserChk > 9))
            {
                wInputUserType += 8;
            }
            else
            {
                wInputUserType += 4;
            }
            wInputUserMonth = (int)fInputUserChk;
            wInputfailCnt = 0;
        }
    }   

    if(((wInputUserType & 0x0F) != 0x00) && (wInputUserDegree != 0)
        && ((wInputUserMonth >= 1) && (wInputUserMonth <= 12)))
    {
        switch(wInputUserType)
        {
            case 0x05:
                wCurrentTableLength = TaipowerEctTab.wEctTabNonbineLength;
                fCurrentTable = TaipowerEctTab.fEctTabNonbine;
                wCurrntMonthType = wInputUserType >> 2;
                break;
            case 0x06:
                wCurrentTableLength = TaipowerEctTab.wEctTabbineLength;
                fCurrentTable = TaipowerEctTab.fEctTabbine;
                wCurrntMonthType = wInputUserType >> 2;
                break;
            case 0x09:
                wCurrentTableLength = TaipowerEctTab.wEctTabNonbineLength;
                fCurrentTable = TaipowerEctTab.fEctTabNonbine;
                wCurrntMonthType = wInputUserType >> 2;
                break;
            case 0x0A:
                wCurrentTableLength = TaipowerEctTab.wEctTabbineLength;
                fCurrentTable = TaipowerEctTab.fEctTabbine;
                wCurrntMonthType = wInputUserType >> 2;
                break;
        }
        for(int i = 0; i < wCurrentTableLength; i++)
        {
            if((float)wInputUserDegree > *(fCurrentTable + (i * 3)))
            {
                fTotalBillPriceTemp += ((float)wInputUserDegree - *(fCurrentTable + (i * 3)))
                * (*(fCurrentTable + (i * 3) + wCurrntMonthType) - lastprice);
                lastprice = *(fCurrentTable + (i * 3) + wCurrntMonthType);
            }
            else
            {
                break;
            }
        }
        fTotalBillPrice = fTotalBillPriceTemp;
    }

    return(fTotalBillPrice);
}
