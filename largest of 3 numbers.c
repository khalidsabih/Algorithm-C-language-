		#include <stdio.h>
int main()
{
	int a, b, c;
	printf("Enter the values of a= ");
	scanf_s("%d", &a);
	printf("Enter the values of b= ");
	scanf_s("%d", &b );
	printf("Enter the values of c= ");
	scanf_s("%d", &c );
	if (a > b)
	{
		if (a > c)
		{
			printf("a is the largest among of the three",a);
		}
		else
		{
			printf("c is the largest among of the three ",c);
		}
	}
	else if (b > c)
	{
		printf("b is the largest among of the three ",b);
	}

	else
	{
		printf("c is the largest among of the three ",c);
	}
	return 0;
}
     
