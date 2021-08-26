#include <stdio.h>
#include <math.h>

#define L 25

typedef struct data {
	long double xi;
} Data;

long double Gamma(long double m)
{
	long double g = 1, i;
	if (m == (int) m)
		for (i = m - 1; i >= 2; i--)
			g *= i;
	else {
		for (i = m - 1; i >= 0.5; i--)
			g = g * i;
		g *= sqrt(3.14159265);
	}
	return g;
}

long double Mean(Data Table[L], long double n)
{
	long double Sxi = 0;
	int i;
	for (i = 0; i < n; i++)
		Sxi += Table[i].xi;
	return Sxi / n;
}

long double Var(Data Table[L], long double n)
{
	long double Sxi = 0, mean = Mean(Table, n);
	int i;
	for ( i = 0; i < n; i++)
		Sxi += pow(Table[i].xi - mean, 2);
	return Sxi / n;
}

long double f(long double x, long double C, long double d1, long double d2)
{
	return C * pow(x, (d1 - 2) / 2) * pow(1 + (d1 / d2) * x, -(d1 + d2) / 2);
}

long double Simpson13(long double f0, int n, long double d1, long double d2)
{
	long double I, h = f0 / n, s = 0, x = 0, fx1, fx2, fx3;
	long double m = n / 2, C = (pow(d1/d2, d1/2) * Gamma((d1 + d2) / 2)) / (Gamma(d1 / 2) * Gamma(d2 / 2));
	int  i;
	fx1 = f(x, C, d1, d2);

	for (i = 1; i <= m; i++)
	{
		fx2 = f(x + h, C, d1, d2);
		fx3 = f(x + 2 * h, C, d1, d2);
		s += fx1 + 4 * fx2 + fx3;
		fx1 = fx3;
		x = x + 2 * h;
	}
	I = s * h/3;

	 return I;
}

void Input(Data Table[L], long double n)
{
	int i;
	for(i = 0; i < n; i++) {
		printf("\nEnter the value %d:", i);
		scanf("%lf", &Table[i].xi);
	}
}
void main()
{
	long double d1, d2, n1 = 8, n2 = 8, f0;
	long double m1,m2, v1, v2;
	Data Table1[L], Table2[L];
	printf("\n\t\t\tF Test");
	printf("\n\t\t\t******");
	printf("\n\nEnter n1");
	scanf("%Lf", &n1);
	printf("\n\nEnter n2");
	scanf("%Lf", &n2);
	printf("\nEnter the first range");
	Input(Table1, n1);
	printf("\nEnter the second range");
	Input(Table2, n2);

	v1 = Var(Table1, n1), v2 = Var(Table2, n2), 
	m1 = Mean(Table1, n1), m2 = Mean(Table2, n2);

	if ( v1 > v2) {
		f0 = v1 / v2;
		d1 = n1 - 1;
		d2 = n2 - 1;
	}
	else {
		f0 = v2 / v1;
		d1 = n2 - 1;
		d2 = n1 - 1;
	}
	printf("\nf0 = %Lf", f0);
	printf("\nComputed probability = %Lf",  1 - Simpson13(f0, 100, d1, d2));
}
