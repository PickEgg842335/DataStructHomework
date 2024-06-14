#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int wFirstCharChkSum [26] = {
    1,  10, 19, 28, 37, 46, 55, 64, 39, 73, 
    82,  2, 11, 20, 48, 29, 38, 47, 56, 65,
    74, 83, 21,  3, 12, 30,
};

int     sGetInputData(char *bInputChar);

void main()
{
    char bInputIdNum[20];
    int wIdNumCheckResult;

    wIdNumCheckResult = sGetInputData(bInputIdNum);
    if(wIdNumCheckResult == 1)
    {
        printf("您輸入的身分證號為%s\n", bInputIdNum);
    }
    system("Pause");
}


int     sGetInputData(char *bInputChar)
{
    char    bInputIdNum[20];
    int     wInputIdNumType = -1;
    int     wIdNumberChkbit = 0;
    int     wInputfailCnt = 0;
    int     wLastCharChksum = 0;
    
    while(wInputIdNumType != 1)
    {
        printf("請輸入身份證字號:");
        scanf("%s", bInputIdNum);
        
        wIdNumberChkbit = 0;
        wIdNumberChkbit |= (strlen(bInputIdNum) == 10) << 0;
        
        if((wIdNumberChkbit & 0x01) == 0x01)
        {
            wIdNumberChkbit |= (((bInputIdNum[0] >= 'A') && (bInputIdNum[0] <= 'Z')) || ((bInputIdNum[0] >= 'a') && (bInputIdNum[0] <= 'z'))) << 1;
            wIdNumberChkbit |= ((bInputIdNum[1] >= '1') && (bInputIdNum[1] <= '2')) << 2;
            if((wIdNumberChkbit & 0x06) == 0x06)
            {
                for(int i = 2; i <= 8; i++)
                {
                    if((bInputIdNum[i] < '0') || (bInputIdNum[i] > '9'))
                    {
                        wIdNumberChkbit = wIdNumberChkbit & !0x08;
                        break;
                    }
                    wIdNumberChkbit |= 0x08;
                }

                if((wIdNumberChkbit & 0x08) == 0x08)
                {
                    if((bInputIdNum[0] >= 'A') && (bInputIdNum[0] <= 'Z'))
                    {
                        wLastCharChksum = wFirstCharChkSum[bInputIdNum[0] - 'A'];
                    }
                    else
                    {
                        wLastCharChksum = wFirstCharChkSum[bInputIdNum[0] - 'a'];
                    }
                    
                    for(int i = 0; i < 8; i++)
                    {
                        wLastCharChksum += (8 - i) * (int)(bInputIdNum[i + 1] - '0');
                    }
                    wLastCharChksum = ((10 - (wLastCharChksum % 10)) - (int)(bInputIdNum[9] - '0'));
                    if(wLastCharChksum == 0)
                    {
                        wIdNumberChkbit |= 0x10;
                    }
                }
            }
        }
        
        if((wIdNumberChkbit & 0x1F) == 0x1F)
        {
            printf("身份證字號輸入正確，歡迎使用本系統！\n");
            wInputIdNumType = 1;
            wInputfailCnt = 0;
        }
        else
        {
            wInputIdNumType = 0;
            if(++wInputfailCnt >= 3)
            {
                printf("身份證字號輸入錯誤超過三次！結束\n");
                wInputfailCnt = 0;
                break;
            }
        }
    }
    
    if(wInputIdNumType == 1)
    {
        for(int i = 0; i < 10; i++)
        {
            *(bInputChar + i) = bInputIdNum[i];
        }
        *(bInputChar + 10) = '\0';
    } 
    
    return(wInputIdNumType);
}

