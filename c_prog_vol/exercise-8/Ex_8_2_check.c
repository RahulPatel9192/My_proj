/*Copyright(c) <2016>, Volansys Technologies 
 * 
 *Description: 
 *@Ex_8_2_check.c   
 *@date conversion, from day of the month to day of the year and vice versa. 
 * 
 *
 *
 *Author       - Rahul Patel 
 *   
 ******************************************************************************* 
 *           
 *History 
 *             
 *Aug/17/2016, Rahul P  
 *                                    
 *Aug/17/2016, Rahul P, Created
 * 
 *******************************************************************************/ 

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */

int day_of_year(int year, int month, int day)
{
    int i, leap;

    if( (month >= 1 && month <= 12) && (day >= 1 && day <= 31)) {  /* changes here */

        /* checking leap year is present or not */
        leap = (year%4 == 0) && (year%100 != 0) || (year%400 == 0);  
        for (i = 1; i < month; i++)
            day += daytab[leap][i];
        return day;
    }
    else {
        printf("Error: Enter proper month or date\n");
        return 0;
    }
}

/* month_day: set month, day from day of year */

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    if( yearday < 366) {  /* changes here */
        leap = (year%4 == 0) && (year%100 != 0) || (year%400 == 0);
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    }
    else {
        printf("enter proper yearday\n");
        return 0;
    }
}

int main(void)
{
    int month;  /* store months */
    int day,days; /* store days */
    int year;   /* store year */
    char op;  /* store option */
    int flag = 1;

    printf("1) day_of_year \n2) month_day\n");
    scanf("%c",&op);

    switch(op) {
        case '1':
            printf("Enter year month day:\n");
            scanf("%d %d %d",&year,&month,&day);
            days= day_of_year(year,month,day);
            if (days != 0)
                printf("day of the year is %d\n",days);
            break;
        case '2':
            printf("Enter year days:\n");
            scanf("%d %d",&year,&days);
            flag = month_day(year,days,&month,&day);
            if(flag != 0)
                printf("%d %d\n",month,day);
            break;
        default:
            printf("Enter valid option\n");
            break;

    }

    return 0;

}


