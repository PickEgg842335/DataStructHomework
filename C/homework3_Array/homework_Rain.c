#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *bInputCmdlist[4] = {
    "all\0",
    "year\0",
    "season\0",
    "month\0",
};

typedef struct RainData {
    float fAvgAllRainfull;
    float fAvgYearRainfull[5];
    float fAvgSeasonRainfull[4];
    float fTotalMonthRainfull[12];
    int wMaxProductResult;
}StrRainData;

typedef struct InputCmd {
    int  wYearNum;
    int  wInputType;
    int  wInputData;
}StrInputCmd;

void sfGetRandArray(int wArrayLength, int wRang, float *pArrayTemp);
void sfGetTotalRainfullInf(StrRainData *strRainResult, int wYearlength, int wSeasonlength, int wMonthlength, float *pArrayTemp);
void sfInputCmdChk(StrInputCmd *StrCmd);
void sfInfDisplay(StrInputCmd *StrCmd ,StrRainData *strRainResult);

void main()
{
    StrRainData StrLastFiveYearRainInf;
    StrInputCmd StrInputDisplayCmd;
    float fGetRainNum[5][4][3] = {0};
    int wRandRange = 2000;     
    int wRainNumLength = sizeof(fGetRainNum) / sizeof(fGetRainNum[0][0][0]);

    sfGetRandArray(wRainNumLength, wRandRange, fGetRainNum);
    sfGetTotalRainfullInf(&StrLastFiveYearRainInf, 5, 4, 3, fGetRainNum);
    StrInputDisplayCmd.wYearNum = 5;
    sfInputCmdChk(&StrInputDisplayCmd);
    
    if(StrInputDisplayCmd.wInputType != -1)
    {
        sfInfDisplay(&StrInputDisplayCmd ,&StrLastFiveYearRainInf);
    }

    system("Pause");
}


void sfGetRandArray(int wArrayLength, int wRang, float *pArrayTemp)
{
    srand(time(NULL));
    for(int i = 0; i < wArrayLength; i++)
    {
        *(pArrayTemp + i) = (float)rand() * (float)wRang / RAND_MAX;
    }
}


void sfGetTotalRainfullInf(StrRainData *strRainResult, int wYearlength, int wSeasonlength, int wMonthlength, float *pArrayTemp)
{
    float fAvgEveyYearSeasonRainfull[5][4];
    float fEveyYearSeaAvgArray[5][3];
    float fSeaAvgArray[5];
    float fYearAvgArray[4];
    float fAvgConst = (float)1 / 5;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            fEveyYearSeaAvgArray[i][j] = (float)1 / 3;
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
        fYearAvgArray[i] = (float)1 / 4;
    }
    
    for(int i = 0; i < 5; i++)
    {
        fSeaAvgArray[i] = (float)1 / 5;
    }
    
    
    for(int i = 0; i < wSeasonlength; i++)
    {
        for(int j = 0; j < wMonthlength; j++)
        {
            strRainResult->fTotalMonthRainfull[(i * wMonthlength) + j] = 0;
            for(int k = 0; k < wYearlength; k++)
            {
                strRainResult->fTotalMonthRainfull[(i * wMonthlength) + j] += *(pArrayTemp + (k * wSeasonlength * wMonthlength) + (i * wMonthlength) + j) * fSeaAvgArray[k];
            }
        }
    }
    
    for(int i = 0; i < wYearlength; i++)
    {
        for(int j = 0; j < wSeasonlength; j++)
        {
            fAvgEveyYearSeasonRainfull[i][j] = 0;
            for(int k = 0; k < wMonthlength; k++)
            {
                fAvgEveyYearSeasonRainfull[i][j] += *(pArrayTemp + ( i * wSeasonlength * wMonthlength) + (j * wMonthlength) + k) 
                    * fEveyYearSeaAvgArray[i][k];
            }
        }
    }
    
    for(int i = 0; i < wSeasonlength; i++)
    {
        strRainResult->fAvgSeasonRainfull[i] = 0;
        for(int j = 0; j < wYearlength; j++)
        {
            strRainResult->fAvgSeasonRainfull[i] += fAvgEveyYearSeasonRainfull[j][i] * fSeaAvgArray[j];
        }
    }
    
    for(int i = 0; i < wYearlength; i++)
    {
        strRainResult->fAvgYearRainfull[i] = 0;
        for(int j = 0; j < wSeasonlength; j++)
        {
            strRainResult->fAvgYearRainfull[i] += fAvgEveyYearSeasonRainfull[i][j] * fYearAvgArray[j];
        }
    }
    
    strRainResult->fAvgAllRainfull = 0;
    for(int i = 0; i < wYearlength; i++)
    {
        strRainResult->fAvgAllRainfull += strRainResult->fAvgYearRainfull[i] * fAvgConst;
    }
}


void sfInputCmdChk(StrInputCmd *StrCmd)
{
    char bInputCmd[40];
    float fInputValue;
    int  wInputMatchChk = 0;
    int  wInputTypeTemp = -1;
    int  wCmdlistLength = sizeof(bInputCmdlist) / sizeof(bInputCmdlist[0]);
    
    printf("���B�t�θ߰ݫ��O�p�U:\n");
    printf("all:�d�ݳ̪�5�~(60�Ӥ��`���B�q)\n");
    printf("year:�d�ݲ�N�~�`���B�q\n");
    printf("season:�d�ݲ�N�u�`���B�q\n");
    printf("month:�d�ݲ�N���`���B�q\n");
    printf("�п�J���O:");
    scanf("%s", bInputCmd);

    StrCmd->wInputType = wInputTypeTemp;
    for(int i = 0; i < wCmdlistLength; i++)
    {
        wInputMatchChk = strspn(bInputCmd, bInputCmdlist[i]);
        if(wInputMatchChk == strlen(bInputCmdlist[i]))
        {
            wInputTypeTemp = i;
            break;
        }
    }
    
    switch(wInputTypeTemp)
    {
        case 0:
            StrCmd->wInputType = wInputTypeTemp;
            break;
        case 1:
            printf("�п�J�~���A��J�d�򬰾��1~5:");
            scanf("%f", &fInputValue);
            if(((fInputValue - (int)fInputValue) == 0) && ((fInputValue >= 1) && (fInputValue <= StrCmd->wYearNum)))
            {
                StrCmd->wInputType = wInputTypeTemp;
                StrCmd->wInputData = (int)fInputValue - 1;
            }
            break;
        case 2:
            printf("�п�J�ĴX�u�A��J�d�򬰾��1~4:");
            scanf("%f", &fInputValue);
            if(((fInputValue - (int)fInputValue) == 0) && ((fInputValue >= 1) && (fInputValue <= 4)))
            {
                StrCmd->wInputType = wInputTypeTemp;
                StrCmd->wInputData = (int)fInputValue - 1;
            }
            break;
        case 3:
            printf("�п�J����A��J�d�򬰾��1~12:");
            scanf("%f", &fInputValue);
            if(((fInputValue - (int)fInputValue) == 0) && ((fInputValue >= 1) && (fInputValue <= 12)))
            {
                StrCmd->wInputType = wInputTypeTemp;
                StrCmd->wInputData = (int)fInputValue - 1;
            }
            break;
        default:
            break;
    }

    if(StrCmd->wInputType == -1)
    {
        printf("��J���~�A�����t��\n");
    }
}


void sfInfDisplay(StrInputCmd *StrCmd ,StrRainData *strRainResult)
{
    switch(StrCmd->wInputType)
    {
        case 0:
            printf("��5�~(60�Ӥ�)�����B�q��%0.2f\n", strRainResult->fAvgAllRainfull);
            break;
        case 1:
            printf("�e%d�~�����B�q��%0.2f\n", (StrCmd->wInputData + 1), strRainResult->fAvgYearRainfull[StrCmd->wInputData]);
            break;
        case 2:
            printf("��5�~��%d�u�����B�q��%0.2f\n", (StrCmd->wInputData + 1), strRainResult->fAvgSeasonRainfull[StrCmd->wInputData]);
            break;
        case 3:
            printf("��5�~%d�륭���B�q��%0.2f\n", (StrCmd->wInputData + 1), strRainResult->fTotalMonthRainfull[StrCmd->wInputData]);
            break;
    }
}

