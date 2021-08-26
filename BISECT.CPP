#include <stdio.h>
#include <math.h>
#include <conio.h>

long double Equation(long double x)
{
	return (pow(x, 3) - 2 * x + 1) ; // equation
}

long double Bisection(long double x1,long double x2, int n)
{
	long double fx1, fx2, fx3, x3, precis = pow(10, -n);
	int i = 0;
	do {
		printf("\nIteration %d", ++i);
		fx1 = Equation(x1);
		printf("\nx1 = %Lf, f(x1) = %Lf", x1, fx1);
		fx2 = Equation(x2);
		printf("\nx2 = %Lf, f(x2) = %Lf", x2, fx2);
		if ( fx1 * fx2 > 0) {
			printf("\nNo root lies between x1 and x2, exiting");
			return 0;
		}
		x3 = (x1 + x2) / 2;
		fx3 = Equation(x3);
		printf("\nx3 = %Lf, f(x3) = %Lf", x3, fx3);
		getch();
		if ((fx1 * fx3) <= 0)
			x2 = x3;
		else if ((fx2 * fx3) <= 0)
			x1 = x3;
	
	} while (fabs(fabs(x1) - fabs(x2)) > precis);

	return (fx1 < fx2) ? x1 : x2;
}

void main()
{
	long double a, b, check;
	int n;
	printf("\n\t\t\tBisection Method");
	printf("\n\t\t\t****************");
	do {
		printf("\nEnter a:");
		scanf("%lf",&a);
		printf("\nEnter b:");
		scanf("%lf",&b);
		check = Equation(a) * Equation(b);
		if (check > 0)
			printf("\nValues not suitable for iteration, re-enter");
	} while (check > 0);
	printf("\nEnter required precision:");
	scanf("%d",&n);
	printf("\n\n%Lf", Bisection(a, b, n));
}

