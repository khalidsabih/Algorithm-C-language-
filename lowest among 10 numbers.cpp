#include <stdio.h>
int main ()
{
	double arr[100];
	int i,position=0;
	printf("Enter 10 real numbers ");
	for (i=0;i<10;i++){
		scanf("%lf",&arr[i]);
	}
	
	for (i=0;i<10;i++){
		if(arr[i]<arr[position])
		position = i;
		
	}
	printf("smallest element arr[%d] = %0.2lf\n", position+1, arr[position]);
	
	return 0;
}
