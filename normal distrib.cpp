#include <stdio.h>
#include <math.h>

#define L 100
#define PI 3.141592653589793
#define UPR_LT 100000
#define LWR_LT -UPR_LT

double var, mean;

double Equation(double x) {

	return (1 / ( var * sqrt(2 * PI)) ) * exp(-pow(x - mean, 2) / (2 * pow(var , 2)) );
}
double Simpsons38(double a, double b, double n)
{
	double h = ( b - a ) / n, s1 = 0, s2 = 0, x = a, Simp;
	int i;
	
	for (i = 2; i <= n; i++) {
		x += h;  
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

	double n , z;
	double i;
	printf("\n\t\t\tNormal Distribution");
	printf("\n\t\t\t*******************");

	printf("\n\nEnter n:");
	scanf("%lf",&n);

	printf("\nEnter u:");
	scanf("%lf", &mean);
	printf("\nEnter variance:");
	scanf("%lf", &var);
	printf("\nMean = %lf", mean);
	printf("\nVariance = %lf", var);

		printf("\n\nZ         N(x)         Phi(x)");     
	for ( i = -n; i <= n; i += 0.5) {
			z = (i - mean) / var;
		printf("\n %lf %lf %lf",
		z, Equation(z), Simpsons38(0, i, 100));
	}
		
}