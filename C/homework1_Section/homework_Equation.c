#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

typedef struct Eqsolution
{
    int wSolutionType;
    float fSolutionlist[2];
}strEqsolution;

void sEquationCal(strEqsolution *strEqsolut);

void main()
{
    strEqsolution strMyEqsolution;

    sEquationCal(&strMyEqsolution);
    
    if(strMyEqsolution.wSolutionType == -1)
    {
        printf("輸入異常\n");
    }
    else if(strMyEqsolution.wSolutionType == 0)
    {
        printf("沒有實根\n");
    }
    else if(strMyEqsolution.wSolutionType == 1)
    {
        printf("有兩個相等的實根, 實根為%f\n", strMyEqsolution.fSolutionlist[0]);
    }
    else if(strMyEqsolution.wSolutionType == 2)
    {
        printf("有兩個相異的實根, 實根為%f %f\n", strMyEqsolution.fSolutionlist[0], strMyEqsolution.fSolutionlist[1]);
    }
    system("Pause");
}

void sEquationCal(strEqsolution *strEqsolut)
{
    float fInputValue[3];
    int winputKeyinChk = -1;
    float fEigenValue = -1;
    float fRootValueTemp = 0;

    printf("請輸入二元二次方程式ax^2+bx+c=0,a,b,c三個常數項:");
    winputKeyinChk = scanf("%f %f %f", &fInputValue[0], &fInputValue[1], &fInputValue[2]);
    
    if(winputKeyinChk != 3)
    {
        strEqsolut->wSolutionType = -1;
    }
    else
    {
        fEigenValue = (fInputValue[1] * fInputValue[1]) - (4 * fInputValue[0] * fInputValue[2]);
        if(fEigenValue < 0)
        {
            strEqsolut->wSolutionType = 0;
        }
        else if(fEigenValue == 0)
        {
            strEqsolut->wSolutionType = 1;
            fRootValueTemp = ((-1) * fInputValue[1]) / (2 * fInputValue[0]);
            strEqsolut->fSolutionlist[0] = fRootValueTemp;
            strEqsolut->fSolutionlist[1] = fRootValueTemp;
        }
        else
        {
            strEqsolut->wSolutionType = 2;
            fEigenValue = sqrt(fEigenValue);
            fRootValueTemp = (((-1) * fInputValue[1]) + fEigenValue) / (2 * fInputValue[0]);
            strEqsolut->fSolutionlist[0] = fRootValueTemp;
            fRootValueTemp = (((-1) * fInputValue[1]) - fEigenValue) / (2 * fInputValue[0]);
            strEqsolut->fSolutionlist[1] = fRootValueTemp;
        }
    }
}

