#include <stdio.h>
#define N 50
int main ()
{
	double m[N];
	int n=0;
	printf("Input elements of your array (%d elements) press any symbol if you are finished\n",N);
	while ( n < N ){
		if (scanf("%lf",m+n)==0)
			break ;
		n++;
	}
	double MULT =2 ;
	printf("\n\nArray mult by %d:\n",MULT);
	double *pel=m,*pend=m+n;
	for(; pel<pend; pel++){
		*pel*=MULT;
		printf("%.2lf  ",*pel);
	}	
	return 0;
}
