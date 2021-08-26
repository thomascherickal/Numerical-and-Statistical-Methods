#include <stdio.h>
#include <math.h>
#include <conio.h>

long double fdash(long double x, long double y)
{
	return (pow(y,2) - pow(x,2))/(pow(x,2) + pow(y,2));
}

long double RK4(long double x0, long double y0, long double h,
long double target)
{
	long double k1, k2,k3, k4, Dy, xi, yi = y0;
	printf("\n\t xi      \t k1       \t k2      \t k3      \t k4      \t yi");
	for (xi = x0; xi < target; xi += h) {
		k1 = h * fdash(xi, yi);
		k2 = h * fdash(xi + h / 2, yi + k1 / 2);
		k3 = h * fdash(xi + h / 2, yi + k2 / 2);
		k4 = h * fdash(xi + h, yi + k3);
		printf("\n\t  %lf\t  %lf\t  %lf\t  %lf\t  %lf\t  %lf",xi, k1, k2, k3, k4, yi);
		Dy = ((long double)1 / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
		yi += Dy;
	}
	return yi;
}

void main()
{
	long double x0, y0, h, target;
	printf("\n**************Runge-Kutta 4th order*****************");
	printf("\nEnter x0");
	scanf("%lf",&x0);
	printf("\nEnter y0");
	scanf("%lf",&y0);
	printf("\nEnter h");
	scanf("%lf",&h);
	printf("\nEnter target");
	scanf("%lf",&target);
	printf("\n%Lf", RK4(x0, y0, h, target));
}
