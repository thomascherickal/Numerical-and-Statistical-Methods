 //Program to perform the T Test
#include <stdio.h>
#include <math.h>

#define L 50

typedef struct data {
	double xi;
} Data;



void Input(Data Table[L],double n) {
	int i;
	printf("\nEnter the data\n");
	for (i = 0; i < n; i++) {
		printf("Value %d:",i);
		scanf("%lf",&Table[i].xi);
	}
}

double AM(Data Table[L], double n)
{
	int i;
	double Sxi = 0;
	for (i = 0; i < n; i++)
		Sxi += Table[i].xi;
	return Sxi/ n;
}

double Var(Data Table[L], double n)
{
	double mean = AM(Table, n), fxi = 0;
	int i;
	for (i = 0; i < n; i++)
		fxi +=  pow(Table[i].xi - mean, 2.00);

	return (fxi / n);
}


long double Gamma(long double m)
{
	long double g = 1, i;
	if (m == (int)m) {
		for(i = 2; i <= m - 1; i++)
			g *= i;
	}

	else {
		for (i = m - 1; i >= 0.5; i--)
			g *= i;
		g *= sqrt(3.14159265359);
	}

	return g;
}

long double T(long double t, long double C, long double d)
{
	return C * pow(1 + pow(t, 2)/ d, (-(d + 1) / 2));
}

long double Simpson13(long double t0, int n, long double d)
{
	long double I, h = fabs(t0) /(double) n, s = 0, t = 0, fx1, fx2, fx3, C;
	int i;
	C = Gamma((d + 1) / 2) / (sqrt(3.14159265359 * d) * Gamma(d / 2));
	fx1 = T(t, C, d);

	for (i = 1; i <=  n / 2; i++)
	{
		fx2 = T(t + h, C, d);
		fx3 = T(t + 2 * h, C, d);
		s += fx1 + 4 * fx2 + fx3;
		fx1 = fx3;
		t += 2 * h;
	}

	I = s * h/3;

	 return I;
}

void main()
{
	long double n1, n2;
	Data Table1[L], Table2[L];
	long double t0, d, b1, b2;
	printf("\n\t\t\tT Test");
	printf("\n\t\t\t******");
	printf("\n\nEnter n1:");
	scanf("%lf", &n1);
	printf("\n\nEnter n2:");
	scanf("%lf", &n2);
	Input(Table1, n1);
	Input(Table2, n2);
	
	b1 = (n1 * Var(Table1, n1) + n2 * Var(Table2, n2))/( d = n1 + n2 - 2);
	b2 = (n1 + n2) / (n1 * n2);
	t0 = (AM(Table1, n1) - AM(Table2, n2)) / sqrt(b1 * b2);
	
	printf("\nt0 = %Lf", t0);
	printf("\nd = %Lf", d);
	printf("\n\n[P]c for two tailed test = %Lf", 1 - 2 * Simpson13(t0, 100, d));
}

