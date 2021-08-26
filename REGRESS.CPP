//Program to compute the regression coefficients by least squares method
#include <stdio.h>
#include <math.h>
#include <conio.h>

#define L 25
double x[L], y[L];

void LeastSquares(int n, double *a, double *b)
{
	int i;
	double Sxi = 0, Sx2i = 0, Sxi2;
	double Syi = 0, Sy2i = 0, Syi2, Sxiyi = 0, mean_x, mean_y;
	for (i = 0; i < n; i++) {
		Sxi += x[i];
		Sx2i += pow(x[i], 2);
		Syi += y[i];
		Sxiyi += x[i]*y[i];
	}
	mean_x = Sxi / n;
	mean_y = Syi / n;
	Sxi2 = pow(Sxi, 2);
	Syi2 = pow(Syi, 2);

	*b  = (n * Sxiyi - Sxi * Syi) /
     	   ( n * Sx2i  -  Sxi2 );
	*a = mean_y - (*b) * mean_x;
}

void main()
{
	int n, i;
	double a, b;
	printf("\n\t\t\tLinear Regression Coefficients");
	printf("\n\t\t\t******************************");
	printf("\n\n");
	printf("\nEnter the value of n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("\nEnter x%d ", i);
		scanf("%lf",&x[i]);
		printf("\nEnter y%d ", i);
		scanf("%lf",&y[i]);
	}
	printf("\n   xi   yi");
	for (i = 0; i < n; i++)
		printf("\n  %lf   %lf ",x[i], y[i]);
		
	LeastSquares(n, &a, &b);
	printf("\n Y - %.5lfX + %.5lf = 0 ", b , a);
}
