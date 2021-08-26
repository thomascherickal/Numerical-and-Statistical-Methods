#include <stdio.h>
#include <math.h>
#include <conio.h>

long double Equation(long double x)
{
	return (pow(x, 2) - 4 * x + 1) ; // equation
}

long double Secant(long double x1,long double x2, int n)
{
	long double fx1, fx2, temp, precis = pow(10, -n);
	int i = 0;
	do {
		printf("\nIteration %d", ++i);
		fx1 = Equation(x1);
		printf("\nx1 = %Lf, f(x1) = %Lf", x1, fx1);
		fx2 = Equation(x2);
		printf("\nx2 = %Lf, f(x2) = %Lf", x2, fx2);
		getch();
	
		if ( fx1 * fx2 > 0) {
			printf("\nNo root lies between x1 and x2, exiting");
			return 0;
		}
		
		temp = x2;
		x2 = (fx2 * x1 -  fx1 * x2) / (fx2 - fx1);
		fx2 = Equation(x2);
		
		if ((fx1 * fx2) < 0)
			;
		else if ((fx2 * Equation(temp) < 0))
			x1 = temp;
		else {
			if (fabs(fx1) < 0.0000001) return x1;
			if (fabs(fx2) < 0.0000001) return x2;
		}
	} while (fabs(fabs(x2) - fabs(temp)) > precis);
	return x2;
}

void main()
{
	long double a, b, check;
	int n;
	printf("\n\t\t\tSecant Method");
	printf("\n\t\t\t*************");
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
	printf("\n\n%lf", Secant(a, b, n));
}

