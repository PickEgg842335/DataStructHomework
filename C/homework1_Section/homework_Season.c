#include <stdio.h>
#include <stdlib.h>

void sfInputMonthChk(void);

void main()
{
    sfInputMonthChk();
    system("Pause");
}


void sfInputMonthChk(void)
{
    float fInputMonthTemp = 0;
    int   wInputMonth = 0;
    
    printf("請輸入月份:");
    scanf("%f", &fInputMonthTemp);
    
    wInputMonth = fInputMonthTemp;
    if((fInputMonthTemp - wInputMonth) != 0)
    {
        printf("您輸入的不是整數\n");
    }
    else
    {
        switch(wInputMonth)
        {
            case 12:
            case 1:
            case 2:
                printf("您輸入%d月，為冬季\n", wInputMonth);
                break;
            case 3:
            case 4:
            case 5:
                printf("您輸入%d月，為春季\n", wInputMonth);
                break;
            case 6:
            case 7:
            case 8:
                printf("您輸入%d月，為夏季\n", wInputMonth);
                break;
            case 9:
            case 10:
            case 11:
                printf("您輸入%d月，為秋季\n", wInputMonth);
                break;
            default:
                printf("您輸入錯誤\n");
                break;
        }
    }
}
