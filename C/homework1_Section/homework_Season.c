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
    
    printf("�п�J���:");
    scanf("%f", &fInputMonthTemp);
    
    wInputMonth = fInputMonthTemp;
    if((fInputMonthTemp - wInputMonth) != 0)
    {
        printf("�z��J�����O���\n");
    }
    else
    {
        switch(wInputMonth)
        {
            case 12:
            case 1:
            case 2:
                printf("�z��J%d��A���V�u\n", wInputMonth);
                break;
            case 3:
            case 4:
            case 5:
                printf("�z��J%d��A���K�u\n", wInputMonth);
                break;
            case 6:
            case 7:
            case 8:
                printf("�z��J%d��A���L�u\n", wInputMonth);
                break;
            case 9:
            case 10:
            case 11:
                printf("�z��J%d��A����u\n", wInputMonth);
                break;
            default:
                printf("�z��J���~\n");
                break;
        }
    }
}
