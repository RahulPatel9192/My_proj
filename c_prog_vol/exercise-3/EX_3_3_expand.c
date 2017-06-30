/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @Expand.c   
 * @We creat one fun call expand(srange,range) which expand the srange and final  
 *  result save at range variable.
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P  (Added comments)
 *                      
 * Aug/04/2016, Rahul P, Created 
 * 
 ******************************************************************************/ 

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define srange_limit 20     /* shortrange limit */
#define range_limit 100     /* range array limit */

/* expand() fun expand the range which user write in short form like a-z or 0-9 etc... */

void expand(char* srange, char* range)
{
    
    int i = 0;  /*using counting purpose for range[] array */
    int j = 0;  /* using counting purpose for srange[] array */
    int flag;   /*using as a flag */
    char ch;    /*store character  */

    while (srange[j]) {
        for ( ;srange[j] == srange[j+1] ; j++);
    if ( srange[j] == '-') {
        range[i++] = '-';
        j++;
    }
	
    if(isalpha(srange[j]))
    flag=1;
    else 
    flag=0;

    if(flag == 1) {
      if(srange[j] >= 'a' && srange[j] <= 'z') { 
         for(ch = srange[j] ; ch <= srange[j+2]; ch++ ) 
            range[i++] = ch;
            range[i] = '\0';
      }

      if(srange[j] >= 'A' && srange[j] <= 'Z') { 
        for(ch = srange[j] ; ch <= srange[j+2]; ch++ ) 
           range[i++] = ch;
           range[i] = '\0';
      }
    
    }
    else {
     for( ch = srange[j] ; ch <= srange[j+2]; ch++ ) 
     range[i++] = ch;
     range[i] = '\0';
    }
    j = j+3;
    }
}

int main(void)
{
    char srange[srange_limit]={0}; /*store short range which user enter*/
    char range[range_limit]={0};  /*final result will store  */

    printf("Enter the range: \n");
    scanf("%s",srange);

    expand(srange,range);
    printf("Expand range is \n%s\n",range);


    return 0;
}
