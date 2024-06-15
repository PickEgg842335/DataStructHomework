#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *cbGender[2] = {
    "男",
    "女",
};

const char *cbTaiwanCity[26] = {
    "台北市",       //A
    "台中市",       //B
    "基隆市",       //C
    "台南市",       //D
    "高雄市",       //E
    "新北市",       //F
    "宜蘭縣",       //G
    "桃園市",       //H
    "嘉義市",       //I
    "新竹縣",       //J
    "苗栗縣",       //K
    "NULL"  ,       //L
    "南投縣",       //M
    "彰化縣",       //N
    "新竹市",       //O
    "雲林縣",       //P
    "嘉義縣",       //Q
    "NULL"  ,       //R
    "NULL"  ,       //S
    "屏東縣",       //T
    "花蓮縣",       //U
    "台東縣",       //V
    "金門縣",       //W
    "澎湖縣",       //X
    "NULL"  ,       //Y
    "連江縣",       //Z
};

const int wFirstCharChkSum [26] = {
    1,  10, 19, 28, 37, 46, 55, 64, 39, 73, 
    82,  2, 11, 20, 48, 29, 38, 47, 56, 65,
    74, 83, 21,  3, 12, 30,
};

int     sGetInputData(char *bInputChar);
void    sGetNewIdNum(char *bInputChar);
void    sDisplayIdNum(char *bInputChar);

void main()
{
    char    bNewIdNum[11];
    int     wIdNumCheckResult;

    printf("本程式僅供程式開發練習使用，切勿使用於其他用途\n");   
    printf("身分證字號產生器:\n");
    
    wIdNumCheckResult = sGetInputData(bNewIdNum);
    if(wIdNumCheckResult == 1)
    {
        sGetNewIdNum(bNewIdNum);
        sDisplayIdNum(bNewIdNum);
    }
    system("Pause");
}


int     sGetInputData(char *bInputChar)
{
    char    bInputData[20];
    int     wInputIdDataType = -1;
    int     wInputChkbit = 0;
    int     wInputfailCnt = 0;

    while(wInputIdDataType != 1)
    {
        if((wInputChkbit & 0x01) != 0x01)
        {
            printf("請輸入性別(男/女):");
            scanf("%s", bInputData);
            getchar();

            if(strlen(bInputData) == 2)
            {
                for(int i = 0; i < 2; i++)
                {
                    if(strncmp(cbGender[i], bInputData, strlen(cbGender[i])) == 0)
                    {
                        wInputChkbit |= 1 << 0;
                        *(bInputChar + 1) = (char)(i + 1) + '0'; 
                        break;
                    }
                }
            }
        }

        if((wInputChkbit & 0x01) == 0x01)
        {
            printf("請輸入縣市(ex:台北市、新北市):");
            scanf("%s", bInputData);
            getchar();

            if(strlen(bInputData) == 6)
            {
                for(int i = 0; i < 26; i++)
                {
                    if(strncmp("臺", bInputData, strlen("臺")) == 0)
                    {
                        char *bCharTemp = "台";
                        for(int j = 0; j < 2; j++)
                        {
                            bInputData[j] = *(bCharTemp + j);
                        }
                    }
                    if(strncmp(cbTaiwanCity[i], bInputData, strlen(cbTaiwanCity[i])) == 0)
                    {
                        wInputChkbit |= 2 << 0;
                        *bInputChar = (char)(i) + 'A'; 
                        break;
                    }
                }
            }
        }

        if((wInputChkbit & 0x03) == 0x03)
        {
            printf("輸入正確，產生器開始生成中...\n");
            wInputIdDataType = 1;
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
            else
            {
                printf("輸入錯誤，請重新輸入\n");
            }
        }
    }

    return(wInputIdDataType);
}


void    sGetNewIdNum(char *bInputChar)
{
    int wLastCharChksum = 0;
    
    wLastCharChksum += wFirstCharChkSum[(int)(*bInputChar - 'A')] + ((int)(*(bInputChar + 1) - '0') * 8);

    srand(time(NULL));
    for(int i = 0; i < 7; i++)
    {
        int wRandTemp;
        wRandTemp = rand() % 10;
        *(bInputChar + 2 + i) = (char)wRandTemp + '0';
        wLastCharChksum += wRandTemp * (7 - i);
    }
    wLastCharChksum = 10 - (wLastCharChksum % 10);
    *(bInputChar + 9) = (char)wLastCharChksum + '0';
}


void    sDisplayIdNum(char *bInputChar)
{
    printf("產生的新身分證字號為%s\n", bInputChar);
}

