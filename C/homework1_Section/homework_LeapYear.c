#include <stdio.h>
#include <stdlib.h>

int sfInputLeapYearChk(void);

void main()
{
    int LeapYearFlag = 0;
    
    LeapYearFlag = sfInputLeapYearChk();
    if(LeapYearFlag == 1)
    {
        printf("輸入年為閏年\n");
    }
    else if(LeapYearFlag == 0) 
    {
        printf("輸入年非閏年\n");
    }
    else
    {
        printf("輸入錯誤\n");
    }
    system("Pause");
}


int sfInputLeapYearChk(void)
{
    float fInputYearTemp = 0;
    int wInputYear = 0;
    int wInputfailCnt = 0;
    int wLeapYearFlag = -1;
    
    while(wInputYear == 0)
    {
        printf("請輸入西元年:");
        scanf("%f", &fInputYearTemp);
        getchar();
    
        if((fInputYearTemp < 0) || (fInputYearTemp - fInputYearTemp) != 0)
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
            wInputYear =  (int)fInputYearTemp;
            wInputfailCnt = 0;
        }
    }
    
    if(wInputYear != 0)
    {
        if((wInputYear % 4) == 0)
        {
            wLeapYearFlag = 1;
            if((wInputYear % 100) == 0)
            {
                wLeapYearFlag = 0;
                if((wInputYear % 400) == 0)
                {
                    wLeapYearFlag = 1;
                }
            }
        }
        else
        {
            wLeapYearFlag = 0;
        }
    }
    return(wLeapYearFlag);
}
