#include <stdio.h>
#include <math.h>

long double f(long double x)
{
	return sin(x);
}

long double Simpson13(long double a, long double b, int n)
{
	long double I, h = (b - a) / n, s = 0, x = a, fx1, fx2, fx3;
	int m = n / 2, i;
	fx1 = f(x);

	printf("\n\t\tx\t\tf(x1)\t\tf(x2)\t\tf(x3)");
	for (i = 1; i <= m; i++)
	{
		fx2 = f(x + h);
		fx3 = f(x + 2 * h);
	printf("\n\t     %Lf\t     %Lf\t      %Lf\t     %Lf", x, fx1, fx2, fx3);
		s += fx1 + 4 * fx2 + fx3;
		fx1 = fx3;
		x = x + 2 * h;
	}

	I = s * h/3;

	 return I;
}

int main()
{
	long double a, b;
	int n;
	printf("\n\n*****************Simpsons 1/3rd Rule********************");
	printf("\n\n\n\nEnter the lower limit:");
	scanf("%lf",&a);
	printf("\nEnter the upper limit:");
	scanf("%lf",&b);
	printf("\nEnter the number of intervals");
	scanf("%d", &n);

	printf("\n%Lf", Simpson13(a, b, n));

	printf("\n\n********************************************************");

	return 0;
}