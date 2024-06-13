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
    printf("�C��÷�l���צp�U:\n");
    for(int i = 0; i < strRopeTemp->wRopeNumlength; i++)
    {
        printf("��%d�ѳѾl÷�l����%0.2f����\n",(i + 1) , strRopeTemp->fRopeNumValue[i]);
    }
    printf("�@��O%d�Ѱŵu÷�l��u��5����\n", strRopeTemp->wRopeNumlength);
}
