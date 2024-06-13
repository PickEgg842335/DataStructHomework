#include <stdio.h>
#include <stdlib.h>

int sGetNumSeqCal(void);

void main()
{
    int wNumSeqResult = 0;
    wNumSeqResult = sGetNumSeqCal();
    printf("%d\n", wNumSeqResult);
    system("Pause");
}


int sGetNumSeqCal(void)
{
    int     wResultTemp = 0;
    int     wTemp = 1;
    
    for(int i = 1; i <= 50; i++)
    {
        wResultTemp += wTemp * i * i;
        wTemp = (~wTemp + 1);
    }
    return(wResultTemp);
}
