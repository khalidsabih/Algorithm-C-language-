#include <stdio.h>
long long FibNum (int n);
long RecFibNum (int j);
int main()
{
	int n;
	int j;
	printf("input n= ");
	scanf("%d" ,&n);
	printf("Fibonnaci number of %d =  %lld ",n ,FibNum(n));
}

long RecFibNum (int j)
{
	if (j<3) return 1;
	return RecFibNum(j-1)+RecFibNum(j-2);
}

long long FibNum (int n)
{
	if (n<3) return 1;
	long long f1, f2, f3; int k=2;
	f1=f2=1;
	do{
		f3=f1+f2; if( ++k==n ) return f3;
		f1=f2 ;
		f2=f3 ;
	}while(1);
}
