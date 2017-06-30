#include<stdio.h>
#include<time.h>

static char *day[8] = {"sun","mon","tue","wed","thu","fri","sat"};
main()
{
/*
time_t t = time(NULL);
struct tm tm = *localtime(&t);

printf("now: %d-%d-%d %d:%d:%d  %s\n", tm.tm_mday,tm.tm_mon+1,tm.tm_year + 1900,  tm.tm_hour, tm.tm_min, tm.tm_sec, day[tm.tm_wday]);
*/

int d,m,y,j;

printf("d,m,y\n");
scanf("%d %d %d",&d,&m,&y);
j=dayofweek(d,m,y);
printf("%s\n",day[j]);




}

int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;


}
