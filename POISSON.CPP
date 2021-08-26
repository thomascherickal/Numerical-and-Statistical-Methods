#include <stdio.h>
#include <conio.h>
#include <math.h>


long double Poisson(long double u, long double x)
{

	if( x == 0)
		return  exp(-u);
	else if (x == 1)
		return u * exp( -u);
	else
		return  Poisson(u, x - 1) * u /  x;
}

long double F(long double u, long double x)
{
	if (x == 0)
		return exp(-u);
	else
		return F(u, x - 1) + Poisson(u, x);
}

void main()
{
	long double i;
	int n;
	long double u;

	scanf("%d", &n);
	scanf("%Lf", &u);

	printf("\n\t\t\tPoisson Distribution\n");
	for(i = 0; i <= n; i++) {
		printf(" %.10Lf  %.10Lf", Poisson(u, i), F(u, i));
		printf("\n");
	}
	getch();
}
