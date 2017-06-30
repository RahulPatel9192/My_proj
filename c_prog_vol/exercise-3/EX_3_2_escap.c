/*Copyright(c) <2016>, Volansys Technologies 
 * 
 * Description: 
 * @escap.c   
 * @In this we creat function called escap(),which is convert escap sequance
 *  into visible character.
 * Author       - Rahul Patel 
 * 
 ******************************************************************************* 
 * 
 * History 
 * 
 * Aug/05/2016, Rahul P (Added comments) 
 *                      
 * Aug/04/2016, Rahul P, Created  
 * 
 ******************************************************************************/ 

#include<stdio.h>
#include<stdint.h>

/*escsp() find the escap sequance from the string and print that string again with appropriate escap sequance's char  */

void escap(char* str, char* res)
{
    
    uint32_t i,j; /*using for element counting*/
	
   for(i=0,j=0; str[i]; i++) {
   	
	switch(str[i]) {
	case '\n': 
	    res[j++]='\\';
	    res[j++]='n';
	    break;

	case '\t': 
	    res[j++]='\\';
	    res[j++]='t';
	    break;

	case '\v': 
	    res[j++]='\\';
	    res[j++]='v';
	    break;

	case '\b': 
	    res[j++]='\\';
	    res[j++]='b';
	    break;

	default:
	    res[j++]=str[i];
	 }
    }
    res[j]= '\0';
}

int main(void)
{

    char escap_seq[100]={"hello \t goodmorning"};  /*here we can use '\n' '\t '\v' '\b'*/
    char vescap_seq[100]={0};

    escap(escap_seq,vescap_seq);
    printf("%s \n",escap_seq); 
    printf("%s \n",vescap_seq); 
	
    return 0;    
}
