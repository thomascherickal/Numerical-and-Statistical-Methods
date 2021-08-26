//Calculate continuous binomial distribution
#include <stdio.h>
#include <conio.h>
#include <math.h>

long double Binomial(int n, int x)
{

	if( x == 1)
		return (long double) n;
	else if (x == 0)
		return (long double)1.00;
	else if (n == x)
		return (long double) 1.00;
	else
		return (long double)(n - x + 1) * Binomial(n , x - 1) / x;
}

void main()
{
	int x;
	int n;
	double p, q;
	printf("\n\t\t\tBinomial Distribution");
	printf("\n\t\t\t*********************");
	printf("\n\nEnter n:");
	scanf("%d", &n);  ;
	printf("\nEnter p:");
	scanf("%lf", &p);
	q = 1 - p;
	for (x = 1; x <= n; x++)
		printf(" %Lf", pow(p, x) * pow(q, n - x) * Binomial(n, x));
	printf("\n");
	getch();
}
