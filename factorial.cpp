#include <stdio.h>
long long Factor(int n);
long long FactorRev(int n);
double FactorDR(int n);
double FactorDI(int n);
int main()
{
	int n;
	printf("Enter an integerr: ");
	scanf("%d", &n);
	
	printf("factorial %d = %.2lf\n", n, FactorDR(n));
}

long long Factor(int n){
	long long fac=1;
	if(n<2) return fac;
	for(int k=2; k<=n; k++)
		fac*=k;
	return fac;
}
long long FactorRev(int n){
	if(n<2) return 1;
	return n*FactorRev(n-1);
}
double FactorDR(int n){
	if(n<2) return 1;
	return n*FactorDR(n-1);
}
double FactorDI(int n){
	double fac=1;
	if(n<2) return fac;
	for(int k=2; k<=n; k++)
		fac*=k;
	return fac;
}
