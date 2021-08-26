//Calculate the Karl Pearson's coefficient of correlation
#include <stdio.h>
#include <math.h>

#define L 25
double x[L], y[L];

double KP(int n)
{
	int i;
	double Sxi = 0, Sx2i = 0, Sxi2;
	double Syi = 0, Sy2i = 0, Syi2, Sxiyi = 0;
	for (i = 0; i < n; i++) {
		Sxi += x[i];
		Sx2i += pow(x[i], 2);
		Syi += y[i];
		Sy2i += pow(y[i], 2);
		Sxiyi += x[i]*y[i];
	}
	Sxi2 = pow(Sxi, 2);
	Syi2 = pow(Syi, 2);

	return (n * Sxiyi - Sxi * Syi) /
	( sqrt( (n * Sx2i - Sxi2  ) * ( n * Sy2i - Syi2 ) ) );
}


void main()
{
	int i, n;
	printf("\n\t\t\tKarl Pearson's Corellation Coefficient");
	printf("\n\t\t\t**************************************");
	printf("\n\nEnter the number of elements");
	scanf("%d",&n);
	for(i = 0; i < n; i++) {
		printf("\nEnter x%d ",i + 1 );
		scanf("%lf", &x[i]);
		printf("\nEnter y%d ",i + 1 );
		scanf("%lf", &y[i]);
	}
	for (i = 0; i < n; i++)
		printf("\n\t%lf\t%lf", x[i], y[i]);
	printf("\nCorellation Coefficient = %lf", KP(n));
}


