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
        printf("�п�J�K�X:");
        scanf("%s", bInputPassword);
        wInputMatchChk = strncmp(cPassword, bInputPassword, strlen(cPassword));
        if((wInputMatchChk == 0) && (strlen(cPassword) == strlen(bInputPassword)))
        {
            printf("�K�X��J���T�A�w��ϥΥ��t�ΡI\n");
            wInputPasswordType = 1;
            wInputfailCnt = 0;
        }
        else
        {
            wInputPasswordType = 0;
            if(++wInputfailCnt >= 3)
            {
                printf("�K�X��J�W�L�T���I����\n");
                wInputfailCnt = 0; 
                break;
            }
        }
    }
    
    return(wInputPasswordType);
}

