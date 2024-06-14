#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define cPokerTotalQty      52
#define cPokerPlayerQty     4
#define cPokerHandCardQty   13

typedef struct PokerData {
    int wCardstack[cPokerTotalQty];
    int wCardQty;
    int wPlayerCard[cPokerPlayerQty][cPokerHandCardQty];
    int wPlayerHandCardQty[cPokerPlayerQty];
}StrPokerData;

int     sGetPokerCmd(void);
void    sfCollectCards(StrPokerData *strPokerTemp);
void    sfShuffleCards(StrPokerData *strPokerTemp);
void    sfDealCards(StrPokerData *strPokerTemp);
void    sfPrintNumtoPokerWord(int wValue);
void    sfMainCardStackDisplay(StrPokerData *strPokerTemp);
void    sfDealCardDisplay(StrPokerData *strPokerTemp);

void    main()
{
    StrPokerData StrMyPokerPlay;
    int wInputCmd = -1;
    
    printf("�п�J���J�P�ʧ@�p�U:\n");
    printf("1. �~�P\n");
    printf("2. �o�P\n");
    printf("3. ���P\n");
    printf("4. �G�P��\n");
    printf("5. �G�Ҧ����a��P\n");
    printf("0. ����\n");
    
    sfCollectCards(&StrMyPokerPlay);
    
    while(1)
    {
        wInputCmd = sGetPokerCmd();
        switch(wInputCmd)
        {
            case 0:
                break;
            case 1:
                sfShuffleCards(&StrMyPokerPlay);
                break;
            case 2:
                sfDealCards(&StrMyPokerPlay);
                break;
            case 3:
                sfCollectCards(&StrMyPokerPlay);
                break;
            case 4:
                sfMainCardStackDisplay(&StrMyPokerPlay);
                break;
            case 5:
                sfDealCardDisplay(&StrMyPokerPlay);
                break;
                
            default:
                break;
        }
        if(wInputCmd == 0)
        {
            break;
        }
    }
    system("Pause");
}


int sGetPokerCmd(void)
{
    int     wInputCmd = -1;
    float   fInputCmdTemp = -1;
    
//    printf("�п�J���J�P�ʧ@�p�U:\n");
//    printf("1. �~�P\n");
//    printf("2. �o�P\n");
//    printf("3. ���P\n");
//    printf("4. �G�P��\n");
//    printf("5. �G�Ҧ����a��P\n");
//    printf("0. ����\n");
    printf("�п�J:");
    scanf("%f", &fInputCmdTemp);
    getchar();
    if(((fInputCmdTemp >= 0) && (fInputCmdTemp <= 5)) && ((fInputCmdTemp - (int)fInputCmdTemp) == 0))
    {
        wInputCmd = fInputCmdTemp;
    }
    else
    {
        printf("�Э��s��J");
    }
    
    return(wInputCmd);
}


void    sfCollectCards(StrPokerData *strPokerTemp)
{
    printf("���P..........\n");
    for(int i = 0; i < cPokerHandCardQty; i++)
    {
        for(int j = 0; j < cPokerPlayerQty; j++)
        {
            strPokerTemp->wPlayerCard[j][i] = -1;
            strPokerTemp->wCardstack[cPokerHandCardQty * j + i] = cPokerHandCardQty * j + i;
            strPokerTemp->wPlayerHandCardQty[j] = -1;
        }
    }
    strPokerTemp->wCardQty = cPokerTotalQty - 1;
}


void    sfShuffleCards(StrPokerData *strPokerTemp)
{
    if(strPokerTemp->wCardQty == -1)
    {
        printf("�P�襤�L�P\n");
        return;
    }
    
    printf("�~�P��");
    srand(time(NULL));
    for(int i = 0; i < cPokerTotalQty; i++)
    {
        int wTemp1, wTemp2;

        wTemp1 = rand() % (cPokerTotalQty - i);
        wTemp2 = strPokerTemp->wCardstack[cPokerTotalQty - 1 - i];
        strPokerTemp->wCardstack[cPokerTotalQty - 1 - i] = strPokerTemp->wCardstack[wTemp1];
        strPokerTemp->wCardstack[wTemp1] = wTemp2;
        printf(".");
    }
    printf("100%%\n");
}


void    sfDealCards(StrPokerData *strPokerTemp)
{
    int wPlayerTemp = 0;
    
    if(strPokerTemp->wCardQty == -1)
    {
        printf("�P�襤�L�P\n");
        return;
    }

    printf("�o�P��");
    while(strPokerTemp->wCardQty != -1)
    {
        int wDealCardTemp;
        
        wDealCardTemp = strPokerTemp->wCardstack[strPokerTemp->wCardQty];
        strPokerTemp->wPlayerCard[wPlayerTemp][++strPokerTemp->wPlayerHandCardQty[wPlayerTemp]] = wDealCardTemp;
        strPokerTemp->wCardstack[strPokerTemp->wCardQty--] = -1;
        wDealCardTemp = -1;
        if(++wPlayerTemp > 3)
        {
            wPlayerTemp = 0;
        }
        printf(".");
    }
    printf("100%%\n");
}


void    sfPrintNumtoPokerWord(int wValue)
{
    int wPokerType = wValue / 13;
    int wPokerValue = wValue % 13;
    
    if(wValue == -1)
    {
        printf("***");
        return;
    } 
    
    switch(wPokerType)
    {
        case 0:
            printf("�®�");
            break;
        case 1:
            printf("����");
            break;
        case 2:
            printf("����");
            break;
        case 3:
            printf("���");
            break;
    }
    
    switch(wPokerValue)
    {
        case 0:
            printf("A");
            break;
        case 1:
            printf("2");
            break;
        case 2:
            printf("3");
            break;
        case 3:
            printf("4");
            break;
        case 4:
            printf("5");
            break;
        case 5:
            printf("6");
            break;
        case 6:
            printf("7");
            break;
        case 7:
            printf("8");
            break;
        case 8:
            printf("9");
            break;
        case 9:
            printf("10");
            break;
        case 10:
            printf("J");
            break;
        case 11:
            printf("Q");
            break;
        case 12:
            printf("K");
            break;
    }
}


void    sfMainCardStackDisplay(StrPokerData *strPokerTemp)
{
    printf("�D�P��ѤW��U���|�ƦC�p�U:\n");
    for(int i = 0; i < cPokerTotalQty; i++)
    {
        sfPrintNumtoPokerWord(strPokerTemp->wCardstack[cPokerTotalQty - 1 - i]);
        printf(" ");
    }
    printf("\n\n");
}


void    sfDealCardDisplay(StrPokerData *strPokerTemp)
{
    printf("�o�P��A�Ҧ����a�p�U��P:\n");
    for(int i = 0; i < cPokerPlayerQty; i++)
    {
        printf("���a%d��o��P����:", i + 1);
        for(int j = 0; j < cPokerHandCardQty; j++)
        {
            sfPrintNumtoPokerWord(strPokerTemp->wPlayerCard[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n\n");
}

