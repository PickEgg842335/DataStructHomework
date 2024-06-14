#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cVerifier1Length     4
#define cVerifier2Length     4
#define cVerifier3Length     6

typedef struct VerifierData {
    char    bVerifierArray1[cVerifier1Length + 1];
    char    bVerifierArray2[cVerifier2Length + 1];
    char    bVerifierArray3[cVerifier3Length + 1];
    int     wVerifierArray1Length;
    int     wVerifierArray2Length;
    int     wVerifierArray3Length;
}StrVerifierData;

void    sfGetRandArray(StrVerifierData *strVerTemp);
void    sfDisplay(StrVerifierData *strVerTemp);

void    main()
{
    StrVerifierData StrMyVerifierData;

    StrMyVerifierData.wVerifierArray1Length = (sizeof(StrMyVerifierData.bVerifierArray1) / sizeof(StrMyVerifierData.bVerifierArray1[0])) - 1;
    StrMyVerifierData.wVerifierArray2Length = (sizeof(StrMyVerifierData.bVerifierArray2) / sizeof(StrMyVerifierData.bVerifierArray2[0])) - 1;
    StrMyVerifierData.wVerifierArray3Length = (sizeof(StrMyVerifierData.bVerifierArray3) / sizeof(StrMyVerifierData.bVerifierArray3[0])) - 1;
    sfGetRandArray(&StrMyVerifierData);
    sfDisplay(&StrMyVerifierData);
    system("Pause");
}


void    sfGetRandArray(StrVerifierData *strVerTemp)
{
    char    bRandTemp[62];
    int     wTemp1;
    char    bTemp1;
    
    srand(time(NULL));
    for(int i = 0; i < strVerTemp->wVerifierArray1Length; i++)
    {
        strVerTemp->bVerifierArray1[i] = (char)(rand() % 10) + '0';
    }
    strVerTemp->bVerifierArray1[strVerTemp->wVerifierArray1Length] = '\0';

    for(int i = 0; i < 10; i++)
    {
        bRandTemp[i] = (char)i + '0';
    }
    
    for(int i = 0; i < strVerTemp->wVerifierArray2Length; i++)
    {
        int wTemp1;
        
        wTemp1 = rand() % (10 - i);
        strVerTemp->bVerifierArray2[i] = bRandTemp[wTemp1];
        bTemp1 = bRandTemp[wTemp1];
        bRandTemp[wTemp1] = bRandTemp[9 - i];
        bRandTemp[9 - i] = bTemp1;
    }
    strVerTemp->bVerifierArray2[strVerTemp->wVerifierArray2Length] = '\0';
    
    for(int i = 0; i < 62; i++)
    {
        if(i < 10)
        {
            bRandTemp[i] = (char)i + '0';
        }
        else if(i < 36)
        {
            bRandTemp[i] = (char)(i - 10) + 'a';
        }
        else
        {
            bRandTemp[i] = (char)(i - 36) + 'A';
        }
    }
    
    for(int i = 0; i < strVerTemp->wVerifierArray3Length; i++)
    {
        int wTemp1;
        
        wTemp1 = rand() % (62 - i);
        strVerTemp->bVerifierArray3[i] = bRandTemp[wTemp1];
        bTemp1 = bRandTemp[wTemp1];
        bRandTemp[wTemp1] = bRandTemp[61 - i];
        bRandTemp[61 - i] = bTemp1;
    }
    strVerTemp->bVerifierArray3[strVerTemp->wVerifierArray3Length] = '\0';
}


void    sfDisplay(StrVerifierData *strVerTemp)
{
    printf("(1)產生四個數字的驗證碼:\n");
    printf("%s\n", strVerTemp->bVerifierArray1);
    printf("(2)產生四個數字的驗證碼且不重覆:\n");
    printf("%s\n", strVerTemp->bVerifierArray2);
    printf("(3)產生六個包含英文字母和數字的驗證碼:\n");
    printf("%s\n", strVerTemp->bVerifierArray3);
}

