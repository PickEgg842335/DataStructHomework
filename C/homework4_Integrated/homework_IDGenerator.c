#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *cbGender[2] = {
    "�k",
    "�k",
};

const char *cbTaiwanCity[26] = {
    "�x�_��",       //A
    "�x����",       //B
    "�򶩥�",       //C
    "�x�n��",       //D
    "������",       //E
    "�s�_��",       //F
    "�y����",       //G
    "��饫",       //H
    "�Ÿq��",       //I
    "�s�˿�",       //J
    "�]�߿�",       //K
    "NULL"  ,       //L
    "�n�뿤",       //M
    "���ƿ�",       //N
    "�s�˥�",       //O
    "���L��",       //P
    "�Ÿq��",       //Q
    "NULL"  ,       //R
    "NULL"  ,       //S
    "�̪F��",       //T
    "�Ὤ��",       //U
    "�x�F��",       //V
    "������",       //W
    "���",       //X
    "NULL"  ,       //Y
    "�s����",       //Z
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

    printf("���{���Ȩѵ{���}�o�m�ߨϥΡA���ŨϥΩ��L�γ~\n");   
    printf("�����Ҧr�����;�:\n");
    
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
            printf("�п�J�ʧO(�k/�k):");
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
            printf("�п�J����(ex:�x�_���B�s�_��):");
            scanf("%s", bInputData);
            getchar();

            if(strlen(bInputData) == 6)
            {
                for(int i = 0; i < 26; i++)
                {
                    if(strncmp("�O", bInputData, strlen("�O")) == 0)
                    {
                        char *bCharTemp = "�x";
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
            printf("��J���T�A���;��}�l�ͦ���...\n");
            wInputIdDataType = 1;
            wInputfailCnt = 0;
        }
        else
        {
            if(++wInputfailCnt >= 3)
            {
                printf("��J���~�W�L�T���I����\n");
                wInputfailCnt = 0;
                break;
            }
            else
            {
                printf("��J���~�A�Э��s��J\n");
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
    printf("���ͪ��s�����Ҧr����%s\n", bInputChar);
}

