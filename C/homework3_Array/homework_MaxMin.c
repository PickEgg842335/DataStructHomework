#include <stdio.h>
#include <stdlib.h>

void sfInputMaxMinChk(void);

void main()
{
    sfInputMaxMinChk();
    system("Pause");
}


void sfInputMaxMinChk(void)
{
    int   wInputNum[10] = {0};
    int   wMaxNum = 0;
    int   wMinNum = 0;
    
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        wInputNum[i] = rand() % 1000;
        printf("%d ", wInputNum[i]);
    }
    printf("\n�H�W10�ӼƦr����X�̤j�ȻP�̤p��\n");
    
    wMaxNum = wInputNum[0];
    wMinNum = wInputNum[0];

    for(int i = 0; i < 10; i++)
    {
        if(wMaxNum < wInputNum[i])
        {
            wMaxNum = wInputNum[i];
        }
        
        if(wMinNum > wInputNum[i])
        {
            wMinNum = wInputNum[i];
        }
    }
    printf("\n�H�W10�ӼƦr�����̤j��%d�P�̤p��%d\n", wMaxNum, wMinNum);
}
