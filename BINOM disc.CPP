#include <stdio.h>
#include <conio.h>
#include <math.h>

long double Binomial(int n, int r)
{

	if( r == 1)
		return (long double) n;
	else if (r == 0)
		return (long double)1.00;
	else if (n == r)
		return (long double) 1.00;
	else
		return (long double)(n - r + 1) * Binomial(n , r - 1) / r;
}

void main()
{
	int i, j;
	int n;
	printf("\nEnter the value of n:");
	scanf("%d", &n);
	printf("\n\t\t\tBinomial Distribution\n");
	for(i = 1; i <= n; i++) {
		for (j = 0; j <= i; j++)
			printf(" %.0Lf", Binomial(i, j));
		printf("\n");
	}
	getch();
}
