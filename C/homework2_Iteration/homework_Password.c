#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *cPassword = {
    "123456\0"
    }; 

int     sGetInputData(void);

void main()
{
    int wInputValue = 0;

    wInputValue = sGetInputData();
    system("Pause");
}


int sGetInputData(void)
{
    char    bInputPassword[20];
    size_t  wInputMatchChk = -1;
    int     wInputPasswordType = -1;
    int     wInputfailCnt = 0;
    
    while(wInputPasswordType != 1)
    {
        printf("請輸入密碼:");
        scanf("%s", bInputPassword);
        wInputMatchChk = strncmp(cPassword, bInputPassword, strlen(cPassword));
        if((wInputMatchChk == 0) && (strlen(cPassword) == strlen(bInputPassword)))
        {
            printf("密碼輸入正確，歡迎使用本系統！\n");
            wInputPasswordType = 1;
            wInputfailCnt = 0;
        }
        else
        {
            wInputPasswordType = 0;
            if(++wInputfailCnt >= 3)
            {
                printf("密碼輸入超過三次！結束\n");
                wInputfailCnt = 0; 
                break;
            }
        }
    }
    
    return(wInputPasswordType);
}

