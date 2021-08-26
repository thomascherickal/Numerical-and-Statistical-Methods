#include <stdio.h>
#include <math.h>
#include <conio.h>

long double Equation(long double x)
{
	return (pow(x, 3) - 5 * x + 3) ; // equation
}

long double Diffren(long double x)
{
	return (3 * pow(x, 2) - 5) ; // equation
}


long double NewtonRaphson(long double x1, int n)
{
	long double fx1, fx2, x2, x0, precis = pow(10, -n);
	int i = 0;
	do {
		printf("\nIteration %d", ++i);
		fx1 = Equation(x1);
		printf("\nx0 = %.10Lf, f(x0) = %.10Lf", x1, fx1);
		x2 = (x1 - Equation(x1)/Diffren(x1));
      fx2 = Equation(x2);
		printf("\nx1 = %.10Lf, f(x1) = %.10Lf", x2, fx2);
		x0 = x1;
		x1 = x2;
		
		} while (fabs(fabs(x0) - fabs(x2)) > precis);

	return (fx1 < fx2) ? x1 : x2;
}

void main()
{
	long double x0;
	int n;
	printf("\n\t\t\tNewton Raphson Method");
	printf("\n\t\t\t*********************");
	printf("\n\nEnter initial value:");
	scanf("%lf",&x0);
	printf("\n\nEnter required precision:");
	scanf("%d",&n);
	printf("\n\n%.10Lf", NewtonRaphson(x0, n));
}

