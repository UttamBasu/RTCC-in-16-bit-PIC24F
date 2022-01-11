#include "mcc_generated_files/system.h"
#include "mcc_generated_files/rtcc.h"
#include "xc.h"
#include "time.h"
#include<stdint.h>

//For Year Calculation, declare both individual value.
int NowYear1 = 0;
int NowYear2 = 0;
int NowYear = 0; // NowYear1, NowYear2

int NowMonth1 = 0;
int NowMonth2 = 0;
int NowMonth = 0; // NowMonth1, NowMonth2

int NowDate1 = 0;
int NowDate2 = 0;
int NowDate = 0; // NowDate1, NowDate2

int NowHour1 = 0;
int NowHour2 = 0;
int NowHour = 0; //NowHour1, NowHour2

int NowMinute1 = 0;
int NowMinute2 = 0;
int NowMinute = 0; //NowHour1, NowHour2

int NowSecond1 = 0;
int NowSecond2 = 0;
int NowSecond = 0;

int main(void) 
{
    SYSTEM_Initialize();
    while (1) 
    {
        // For Year Calculation
        NowYear1 = ((DATEH & 0xF000) >> 12);
        NowYear2 = ((DATEH & 0x0F00) >> 8);
        NowYear = (2000 + (NowYear1 * 10) + NowYear2);

        // For Month Calculation
        NowMonth1 = ((DATEH & 0x00F0) >> 4);
        NowMonth2 = ((DATEH & 0x000F));
        NowMonth = ((NowMonth1 * 10) + NowMonth2);

        // For Date Calculation
        int NowDate1 = ((DATEL & 0xF000) >> 12);
        int NowDate2 = ((DATEL & 0x0F00) >> 8);
        int NowDate = ((NowDate1 * 10) + NowDate2);

        // For Hour Calculation
        NowHour1 = ((TIMEH & 0xF000) >> 12);
        NowHour2 = ((TIMEH & 0x0F00) >> 8);
        NowHour = ((NowHour1 * 10) + NowHour2);

        // For Minute Calculation
        NowMinute1 = ((TIMEH & 0x00F0) >> 4);
        NowMinute2 = ((TIMEH & 0x000F));
        NowMinute = ((NowMinute1 * 10) + NowMinute2);
        
        // For Second Calculation
        NowSecond1 = ((TIMEL & 0xF000) >> 12);
        NowSecond2 = ((TIMEL & 0x0F00) >> 8);
        NowSecond = ((NowSecond1 * 10) + NowSecond2);
    }
    return 1;
}


