#include <stdio.h>
#include <stdlib.h>

typedef struct RopeNum{
    int     wRopeNumlength;
    float   fRopeNumValue[100];
}strRopeNum;

void    sGetRopeNum(strRopeNum *strRopeTemp);
void    sDisplayResult(strRopeNum *strRopeTemp);


void main()
{
    strRopeNum strMyRopeNum;

    sGetRopeNum(&strMyRopeNum);
    sDisplayResult(&strMyRopeNum);
    system("Pause");
}


void    sGetRopeNum(strRopeNum *strRopeTemp)
{
    strRopeTemp->wRopeNumlength = 0;
    float fRopeValue = 3000;

    while(fRopeValue >= 5)
    {
        fRopeValue = fRopeValue / 2;

        strRopeTemp->fRopeNumValue[strRopeTemp->wRopeNumlength] = fRopeValue;
        strRopeTemp->wRopeNumlength++;
    }
}


void    sDisplayResult(strRopeNum *strRopeTemp)
{
    printf("每天繩子長度如下:\n");
    for(int i = 0; i < strRopeTemp->wRopeNumlength; i++)
    {
        printf("第%d天剩餘繩子長度%0.2f公尺\n",(i + 1) , strRopeTemp->fRopeNumValue[i]);
    }
    printf("共花費%d天剪短繩子到短於5公尺\n", strRopeTemp->wRopeNumlength);
}
