#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define size 100
int main ()
{
	char str[size];
    float alp, digit, splch,total,punc;
    int i;
    alp = digit = splch  = punc = 0;
    i = 0;
    float percent;
	

       printf("Count the percent of Latin letters among all characters of this string. :\n");	
       printf("Input the string : ");
       fgets(str, sizeof str, stdin);	
		
     

    while(str[i]!='\0')
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        {
            alp++;
        }
        else if(str[i]>='0' && str[i]<='9')
        {
            digit++;
        }
        else if (ispunct(str[i]))
        {
        	punc++;
		}
        else
        {
            splch++;
        }
		
        i++;
        }
    total=alp+digit+(splch-1)+punc;
    percent=(punc/total)*100;
    
    printf("Number of Punctuation marks in the string is : %0.f\n", punc);
    printf("Number of Total characters in the string is : %0.f\n\n", total);
    printf("Number of Percent of Punctuation marks characters in the string is : %.2f%%", percent);
    return 0;
	
}
