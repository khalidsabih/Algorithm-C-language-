#include <stdio.h>

int main ()
{
	unsigned int k;
	int arr[25];
	int i; 
	printf("Enter size of your array must be lower than 25\nsize ");
	scanf("%d",&k);
	if(k>25)
	{
		printf("size of array is more than 25");
		return 0;
	}
	printf("Enter your elements : ");
	for (i=0;i<k;i++){
		scanf("%d",&arr[i]);
	}
	int *p1=arr, *p2=arr+1;
	for(; p2<arr+k ; p1++,p2++) {
		 if(*p1>*p2) 
      	
        {
            printf("The given array is not in increasing order ");;
            return 0;
        }
    }
    printf("The given array is in increasing order ");
	
}
