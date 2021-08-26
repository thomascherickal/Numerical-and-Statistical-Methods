//Program to perform the Chi Square Test
#include <stdio.h>
#include <math.h>

long double Gamma(long double d)
{
	long double g = 1, m = d / 2, i;
	if (m == (int)m) {
		for(i = 2; i <= m - 1; i++)
			g *= i;
	}

	else {
		for (i = m - 1; i >= 0.5; i--)
			g *= i;
		g *= sqrt(3.14159265358);
	}

	return g;
}

long double Chi2(long double X, long double C, long double d)
{
	return pow(C, -1) * pow(X, (d - 2) / 2) * exp(-X/2);
}

long double Simpson13(long double a, long double b, int n, long double d)
{
	long double I, h = (b - a) / n, s = 0, x = a, fx1, fx2, fx3, C;
	int m = n / 2, i;
	C = pow(2, d / 2) * Gamma(d);
	fx1 = Chi2(x, C, d);

	for (i = 1; i <= m; i++)
	{
		fx2 = Chi2(x + h, C, d);
		fx3 = Chi2(x + 2 * h, C, d);
		s += fx1 + 4 * fx2 + fx3;
		fx1 = fx3;
		x = x + 2 * h;
	}

	I = s * h/3;

	 return I;
}

void main()
{
	long double X2, d;
	printf("\n\t\t\tChi Square Test");
	printf("\n\t\t\t***************");
	printf("\n\nEnter computed chi square:");
	scanf("%Lf", &X2);
	printf("\nEnter the degrees of freedom:");
	scanf("%Lf", &d);
	printf("\nComputed Probability = %Lf", 1 - Simpson13(0, X2, 100, d));
}

