//Program to compute the regression coefficients for y = ax^b
#include <stdio.h>
#include <math.h>
#include <conio.h>

#define L 25
double x[L], y[L];

void LeastSquares(int n, double *a, double *b)
{
	int i;
	double Sxi = 0, Sx2i = 0, Sxi2;
	double Syi = 0,  Sxiyi = 0;
	for (i = 0; i < n; i++) {
		Sxi += log10(x[i]);
		Sx2i += log10(x[i]) * log10(x[i]);
		Syi += log10(y[i]);
		Sxiyi += log10(x[i])*log10(y[i]);
	}

	Sxi2 = Sxi * Sxi;

	*b  = ( n * Sxiyi - Sxi * Syi) /
			( n * Sx2i  -  Sxi2 ) ;
	*a =  pow(10,((Syi - (*b) * Sxi) / n ));
}

void main()
{
	int n, i; 
	double a, b;
	printf("\n\t\t\tNon-Linear Regression Coefficients");
	printf("\n\t\t\t**********************************");
	printf("\n\n");
	printf("\nEnter the value of n:");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("\nEnter x%d: ", i);
		scanf("%lf",&x[i]);
		printf("\nEnter y%d: ", i);
		scanf("%lf",&y[i]);
	}
	printf("\n  xi     yi");
	printf("\n  ***    ***");
	for (i = 0; i < n; i++)
		printf("\n  %.2lf   %.2lf ",x[i], y[i]);

	LeastSquares(n, &a, &b);
	printf("\n Y -   %.3lfX^%.3lf  = 0", a , b);
}



