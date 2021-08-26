
#include <stdio.h>
#include <math.h>

long double f(long double x)
{
	return sin(x);

}

long double Trapez(long double a, long double b, long double h)
{
	long double I = 0, x = a, y1 = f(a), y2;
	int i,  n = (int)((b - a)/h);
	for ( i = 0; i < n; i++)
	{
		y2 = f(x + h);
		printf("\nx%d = %Lf, f(x%d) = %Lf, f(x%d + h) = %Lf",
									 i + 1, x, i + 1, y1, i + 1, y2);
		I += y1 + y2;
		x += h;
		y1 = y2;
	}

	I  *= (h/2);
	return I;
}

int main()
{
	long double a, b, h;
	printf("\n******************Trapezoidal Rule********************");
	printf("\n\nEnter the lower lt:");
	scanf("%lf", &a);
	printf("\nEnter the upper lt:");
	scanf("%lf", &b);
	printf("\nEnter the interval length:");
	scanf("%lf",&h);
	printf("\n%Lf", Trapez(a, b, h));
	return 0;
}
