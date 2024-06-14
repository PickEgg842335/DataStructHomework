#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct DepositInf{
    int     *wName;
    float   fDepositBase;
    int     wDepositType;
    float   fInterestRate;
}strDepositInf;

typedef struct DepositData{
    const strDepositInf *strpersonInf;
    float   fTotalDeposit;
}strDepositData;

const strDepositInf    cstrMonenyDepositInf = {
    .wName = "錢精打",
    .fDepositBase = 100000,
    .wDepositType = 1,
    .fInterestRate = 0.1,
};

const strDepositInf    cstrHaoDepositInf = {
    .wName = "郝細算",
    .fDepositBase = 100000,
    .wDepositType = 2,
    .fInterestRate = 0.05,
};

strDepositData  strMonenyDeposit = {
    .strpersonInf = &cstrMonenyDepositInf,
    .fTotalDeposit = 0,
};

strDepositData  strHaoDeposit = {
    .strpersonInf = &cstrHaoDepositInf,
    .fTotalDeposit = 0,
};

float   sGetInterestValue(int wType, int wYear, float fRate);
int     sInterestChk(strDepositData *strPerson1, strDepositData *strPerson2);
void    sDisplayResult(int wYearTemp);


void main()
{
    int wYearValue;
    
    wYearValue = sInterestChk(&strMonenyDeposit, &strHaoDeposit);
    sDisplayResult(wYearValue);
    system("Pause");
}


float   sGetInterestValue(int wType, int wYear, float fRate)
{
    float   fResult = -1;

    switch(wType)
    {
        case 1:
            fResult = (1 + wYear * fRate);
            break;
        case 2:
            fResult = pow((1 + fRate), wYear);
            break;
        default:
            break;
    }
    
    return(fResult);
}


int     sInterestChk(strDepositData *strPerson1, strDepositData *strPerson2)
{
    int wYearValue = -1;
    int wYearTemp = 0;
    float fTotalDepositTemp1, fTotalDepositTemp2;
    strDepositInf *strPerson1Inf = strPerson1->strpersonInf;
    strDepositInf *strPerson2Inf = strPerson2->strpersonInf;


    while(wYearValue == -1)
    {
        float wResultTemp = 0;
        wYearTemp++;
        
        fTotalDepositTemp1 = strPerson1Inf->fDepositBase * sGetInterestValue(strPerson1Inf->wDepositType, wYearTemp, strPerson1Inf->fInterestRate);
        fTotalDepositTemp2 = strPerson2Inf->fDepositBase * sGetInterestValue(strPerson2Inf->wDepositType, wYearTemp, strPerson2Inf->fInterestRate);
        wResultTemp = fTotalDepositTemp1 - fTotalDepositTemp2;
        if(wResultTemp < 0)
        {
            strPerson1->fTotalDeposit = fTotalDepositTemp1;
            strPerson2->fTotalDeposit = fTotalDepositTemp2;
            wYearValue = wYearTemp;
        }
        else if(wYearTemp > 100)
        {
            wYearValue = 0;
        } 
    }
    return(wYearValue);
}


void    sDisplayResult(int wYearTemp)
{
    strDepositInf *strDisplayDepositInf[2] = {strMonenyDeposit.strpersonInf, strHaoDeposit.strpersonInf};
    
    printf("投資人資訊:\n");
    
    for(int i = 0; i < 2; i++)
    {
        printf("姓名: %s ", strDisplayDepositInf[i]->wName);
        printf("本金: %0.2f ", strDisplayDepositInf[i]->fDepositBase);
        switch(strDisplayDepositInf[i]->wDepositType)
        {
            case 1:
                printf("利率模式: 單利模式 ");
                break;
            case 2:
                printf("利率模式: 複利模式 ");
                break;
        }
        printf("利率%%值: %0.2f%%\n", strDisplayDepositInf[i]->fInterestRate * 100);
    }
    printf("\n第%d年後，%s的存款金額%0.2f超過%s的存款金額%0.2f\n", wYearTemp, strDisplayDepositInf[1]->wName, strHaoDeposit.fTotalDeposit,
        strDisplayDepositInf[0]->wName, strMonenyDeposit.fTotalDeposit);
}
