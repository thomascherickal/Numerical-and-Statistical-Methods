#include <stdio.h>
#include <math.h>
#include <conio.h>

long double fdash(long double x, long double y)
{
	return (y - x);
}

long double RK2(long double x0, long double y0, long double h, long double target)
{
	long double k1, k2, Dy, xi, yi = y0;
	printf("\n\txi      \tk1      \tk2      \tyi");
	for (xi = x0; xi < target; xi += h) {
		k1 = h * fdash(xi, yi);
		k2 = h * fdash(xi + h / 2, yi + k1 / 2);
	printf("\n\t%lf\t%lf\t%lf\t%lf",xi, k1, k2, yi);
		Dy = k2;

		yi += Dy;
	}
	return yi;
}

void main()
{
	long double x0, y0, h, target;
	printf("\n**************Runge-Kutta 2nd order*****************");
	printf("\nEnter x0");
	scanf("%lf",&x0);
	printf("\nEnter y0");
	scanf("%lf",&y0);
	printf("\nEnter h");
	scanf("%lf",&h);
	printf("\nEnter target");
	scanf("%lf",&target);
	printf("\n%Lf", RK2(x0, y0, h, target));
}
