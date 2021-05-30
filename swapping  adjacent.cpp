#include <stdio.h>
int main ()
{
	double arr[50];
	double temp;
	int i,N;
	printf("Enter the size of your array 'must be even' \nsize = ");
	scanf("%d",&N);
	if(N%2!=0){
		printf("The number that you just entered is odd ");
		return 0 ;
	}
	else
	printf("Enter the element of the array \n");
	for(i=0;i<N;i++){
		scanf("%lf",&arr[i]);
	}
	double *p1=&arr[i], *p2=&arr[i+1];
	for(i=0;i<N;i+=2){
		
		temp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=temp;
	}
	 
    printf("\nelements after swapping adjacent \n");
    for(i=0;i < N;i++)
    {
        printf("%0.2lf\n",arr[i]);
    }
    
		
		return 0;
		
	
}
