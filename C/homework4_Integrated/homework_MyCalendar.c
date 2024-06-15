#include <stdio.h>
#include <stdlib.h>

const char *cbWeekDay[] = {
    "Sun",
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat",
};

typedef struct Calendar {
    int wYear;
    int wMonth;
    int wMaxMonthDay;
    int wWeekDayOnFirst;
}strCalenderInf;

int     sfInputData(strCalenderInf *strTempCdrInf);
int     swGetWeekday(int wInputYear, int wInputMonth, int wInputDay);
int     swGetMaxMonthday(int wInputYear, int wInputMonth);
void    sCreateCalender(strCalenderInf *strTempCdrInf);
void    sGetStringFromNum(char* bString, int wDigit, int wNum);
int     sIntpow(int base, int index);

void    main()
{
    int wInputType = -1;
    strCalenderInf strMyCdrInf;

    wInputType = sfInputData(&strMyCdrInf);
    if(wInputType == 1)
    {
        sCreateCalender(&strMyCdrInf);
    }
    system("Pause");
}


int     sfInputData(strCalenderInf *strTempCdrInf)
{
    float   fInputTemp = 0;
    int     wInputType = -1;
    int     wInputChkbit = 0;
    int     wInputfailCnt = 0;

    while(wInputType != 1)
    {
        if((wInputChkbit & 0x01) != 0x01)
        {
            printf("請輸入西元年:");
            scanf("%f", &fInputTemp);
            
            if((fInputTemp > 0) && ((fInputTemp - (int)fInputTemp) == 0))
            {
                strTempCdrInf->wYear = (int)fInputTemp;
                wInputChkbit |= 1 << 0;
                wInputfailCnt = 0;
            }
        }

        if((wInputChkbit & 0x01) == 0x01)
        {
            printf("請輸入月份:");
            scanf("%f", &fInputTemp);

            if(((fInputTemp >= 1) && (fInputTemp <= 12)) && ((fInputTemp - (int)fInputTemp) == 0))
            {
                strTempCdrInf->wMonth = (int)fInputTemp;
                wInputChkbit |= 1 << 1;
                wInputfailCnt = 0;
            }
        }

        if((wInputChkbit & 0x03) == 0x03)
        {
            strTempCdrInf->wWeekDayOnFirst = swGetWeekday(strTempCdrInf->wYear, strTempCdrInf->wMonth, 1);
            strTempCdrInf->wMaxMonthDay = swGetMaxMonthday(strTempCdrInf->wYear, strTempCdrInf->wMonth);
            wInputType = 1;
            wInputfailCnt = 0;
        }
        else
        {
            if(++wInputfailCnt >= 3)
            {
                printf("輸入錯誤超過三次！結束\n");
                wInputfailCnt = 0;
                break;
            }
        }
    }
    return (wInputType);
}


int     swGetWeekday(int wInputYear, int wInputMonth, int wInputDay)
{
    int wTemp = 0;
    int wTemp2 = 0;
    int wCurrentLeapYear = 0;
    
    wCurrentLeapYear = (((wInputYear % 4) == 0) && ((wInputYear % 100) != 0)) || ((wInputYear % 400) == 0);
    wTemp = ((wInputYear - 1) * 365) + ((wInputYear - 1) / 4) - ((wInputYear - 1) / 100) + ((wInputYear - 1) / 400);
    if(wInputMonth >= 3)
    {
        wTemp2 = wInputMonth - 3;
        wTemp += (((wTemp2 % 5) % 2) * 31) + (((wTemp2 % 5) / 2) * 61) + ((wTemp2 / 5) * 153) + (59 + wCurrentLeapYear);
    }
    else
    {
        wTemp += (wInputMonth - 1) * 31;
    }
    wTemp = (wTemp + wInputDay) % 7;
    return (wTemp);
}


int     swGetMaxMonthday(int wInputYear, int wInputMonth)
{
    int wTemp = 0;
    int wTemp2 = 0;
    int wCurrentLeapYear = 0;

    wCurrentLeapYear = (((wInputYear % 4) == 0) && ((wInputYear % 100) != 0)) || ((wInputYear % 400) == 0);
    switch(wInputMonth)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            wTemp = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            wTemp = 30;
            break;
        case 2:
            wTemp = 28 + wCurrentLeapYear;
            break;
    }
    return (wTemp);
}


void    sCreateCalender(strCalenderInf *strTempCdrInf)
{
    char    bYearString[5];
    char    bMonthString[3];
    char    bDayString[3];
    int     wYearStringLength = sizeof(bYearString) / sizeof(bYearString[0]);
    int     wMonthStringLength = sizeof(bMonthString) / sizeof(bMonthString[0]);
    int     wDayStringLength = sizeof(bDayString) / sizeof(bDayString[0]);
    int     wStartDisplayCdrDay = 0;
    int     wMaxDayDisplayCnt = 0;

    sGetStringFromNum(bYearString, 4, strTempCdrInf->wYear);
    bYearString[wYearStringLength - 1] = '\0';
    sGetStringFromNum(bMonthString, 2, strTempCdrInf->wMonth);
    bMonthString[wMonthStringLength - 1] = '\0';
    printf("\n--- %s / %s -----------------------------\n", bYearString, bMonthString);
    printf("|");
    for(int i = 0; i < 7; i++)
    {
        printf(" %s |", cbWeekDay[i]);
    }
    printf("\n-------------------------------------------\n");
    for(int i = 0; i < 6; i++)
    {
        printf("|");
        for(int i = 0; i < 7; i++)
        {
            if(((strTempCdrInf->wWeekDayOnFirst == i) || (wStartDisplayCdrDay == 1)) && (wMaxDayDisplayCnt < strTempCdrInf->wMaxMonthDay))
            {
                wStartDisplayCdrDay = 1;
                wMaxDayDisplayCnt++;
                sGetStringFromNum(bDayString, 2, wMaxDayDisplayCnt);
                bDayString[wDayStringLength - 1] = '\0';
                printf("  %s |", bDayString);
            }
            else
            {
                printf("     |", bDayString);
            }
        }
        printf("\n-------------------------------------------\n");
    }
    printf("\n");
}


void    sGetStringFromNum(char* bString, int wDigit, int wNum)
{
    int wTemp = 0;
    int wDisplayZeroFlag = 0;

    for(int i = 0; i < wDigit; i++)
    {
        wTemp = (wNum % sIntpow(10, wDigit - i)) / sIntpow(10, wDigit - 1 - i);
        if((wTemp == 0) && (wDisplayZeroFlag == 0))
        {
            *(bString + i) = ' ';
        }
        else
        {
            wDisplayZeroFlag = 1; 
            *(bString + i) = (char)wTemp + '0';
        }
    }
}


int     sIntpow(int base, int index)
{
    int wCalTemp = 1;
    
    for(int i = 0; i < index; i++)
    {
        wCalTemp *= base;
    }
    
    return(wCalTemp);
}
