#include <stdio.h>
#include <stdlib.h>

typedef struct XcompanySalary
{
    int     wHourlySalary;
    int     wOvertimeLevellength; 
    int     wOvertimeHourLv[3];
    float   fOvertimeRatio[3];
}StructSalary;

const StructSalary XcoSalary = {
    .wHourlySalary = 150,
    .wOvertimeLevellength = 3,
    .wOvertimeHourLv = {0, 60, 80},
    .fOvertimeRatio = {1, 1.25, 1.5},
};

void sfSalaryCal(void);

void main(void)
{
    sfSalaryCal();
    system("Pause");
}


void sfSalaryCal(void)
{
    float fInputWorkHour = 0;
    int wInputWorkHour = 0;
    float fOutputPersonSalary = 0;
    float flastOvertimeRatio = 0;
    
    printf("��J�K�Q�ө��uŪ�ͪ��u�@�ɼ�(�H��Ƭ����, ���i�H�W�L400):");
    scanf("%f", &fInputWorkHour);

    if((fInputWorkHour < 0) || ((fInputWorkHour - (int)fInputWorkHour) != 0)
        || (fInputWorkHour > 400))
    {
        printf("��J���~�A���i���t�ƩΤp��\n");
    }
    else
    {
        wInputWorkHour = (int)fInputWorkHour;
        
        for(int i = 0; i < XcoSalary.wOvertimeLevellength; i++)
        {
            if(wInputWorkHour > XcoSalary.wOvertimeHourLv[i])
            {
                fOutputPersonSalary += (float)(XcoSalary.wHourlySalary * (wInputWorkHour - XcoSalary.wOvertimeHourLv[i]))
                * (XcoSalary.fOvertimeRatio[i] - flastOvertimeRatio);
                flastOvertimeRatio = XcoSalary.fOvertimeRatio[i];
            }
            else
            {
                break;
            }
        }
        printf("�K�Q�ө��uŪ�ͪ��u�@�ɼƬ�%d�A�~�굲�⬰%1.1f��\n", wInputWorkHour, fOutputPersonSalary);
    }
}
