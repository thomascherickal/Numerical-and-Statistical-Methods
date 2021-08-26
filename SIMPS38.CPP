#include <stdio.h>
#include <math.h>

long double Equation(long double x)
{
	return 1/ (1 + pow(x, 2));
}
long double Simpsons38(long double a, long double b, int n)
{
	long double h = ( b - a ) / n, s1 = 0, s2 = 0, x = a, Simp;
	int i;
	printf("\n h =  %Lf", h);

	printf("\n\t\tx    \t\ts1    \t\ts2");
	for (i = 2; i <= n; i++) {
		x += h;
	printf("\n\t   %lf\t   %lf\t   %lf", x, s1, s2);    
		if (i % 3 == 1)
			s1 += Equation(x);
		else
			s2 += Equation(x);
	}

	Simp = ( 3 * h / 8 ) * (Equation(a) + Equation(b) + 3 * s2 + 2 * s1);
	return Simp;
}

void main()
{
	long double a, b;
	int n;
	printf("\n\n*****************Simpsons 3/8th Rule********************");
	printf("\n\n\n\nEnter the lower limit:");
	scanf("%lf",&a);
	printf("\nEnter the upper limit:");
	scanf("%lf",&b);
	printf("\nEnter the number of intervals");
	scanf("%d", &n);
	printf("\n%1.15Lf", Simpsons38(a, b, n));

}
