#include <stdio.h>
#include <math.h>

#define L 100
#define PI 3.141592653589793
#define UPR_LT 100000
#define LWR_LT -UPR_LT

typedef struct data {
	int freq;
	double xi;
	double hxi;
	double lxi;
} Data;

Data Table[L] = 
{   3, 62.5, 65, 60,
   21, 67.5, 70, 65,
  150, 72.5, 75, 70,
  335, 77.5, 80, 75,
  326, 82.5, 85, 80,
  135, 87.5, 90, 85,
   26, 92.5, 95, 90,
    4, 97.5,100, 95,
};

double var, mean;

double Mean(double n, double N)
{
	int i;
	double Sxi = 0;
	for (i = 0; i < n; i++)
		Sxi += Table[i].xi * Table[i].freq;
	return Sxi/ N;
}

double Var(double n, double N)
{
	double mean = Mean(n, N), fxi = 0;
	int i;
	for (i = 0; i < n; i++)
		fxi += Table[i].freq * pow(Table[i].xi - mean, 2.00);

	return sqrt(fxi / N);
}


double Equation(double x, double N)
{
	return (1 /( var * sqrt( 2 * PI) ) ) * exp(-pow(x - mean, 2) / pow(var, 2));
}

int InputC(double n) {
	int i, N = 0;
	double c;
	printf("\nEnter values\n");
	for (i = 0; i < n; i++) {
		if (i == 0) {
			printf("\nEnter first lower lt%d:", i);
			scanf("%lf",&Table[i].lxi);
			printf("\nEnter first upper lt%d:", i);
			scanf("%lf",&Table[i].hxi);
			c = Table[i].hxi - Table[i].lxi;
		}
		else
		{
			Table[i].lxi = Table[i - 1].hxi;
			Table[i].hxi = Table[i].lxi + c;
		}
		
		Table[i].xi = (Table[i].lxi + Table[i].hxi) / 2;
		printf("\nEnter f%d:", i);
		scanf("%d",&Table[i].freq);
		N += Table[i].freq;
		fflush(stdin);
	}
	return N;
}

void DisplayC(double n) {
	int i;
	printf("\n   xi   lxi   hxi  fi");
	for (i = 0; i < n; i++)
		printf("\n %0.2lf  %0.2lf  %0.2lf  %d",Table[i].xi,Table[i].lxi,Table[i].hxi,Table[i].freq);
}

double Simpsons38(double a, double b, double n, double N)
{
	double h = ( b - a ) / n, s1 = 0, s2 = 0, x = a, Simp;
	int i;
	
	for (i = 2; i <= n; i++) {
		x += h;  
		if (i % 3 == 1)
			s1 += Equation(x, N);
		else
			s2 += Equation(x, N);
	}

	Simp = ( 3 * h / 8 ) * (Equation(a, N) + Equation(b, N) + 3 * s2 + 2 * s1);
	return Simp;
}

void main()
{

	double n = 8, N = 1000, z;
	int i;
	printf("\n\t\t\tNormal Distribution");
	printf("\n\t\t\t*******************");
	/*
	printf("\n\nEnter n");
	scanf("%lf",&n);

	*/
	mean = 0;
	var = 1;
	printf("\nMean = %lf", mean);
	printf("\nVariance = %lf", var);

		printf("\n\nZ         N(x)         Phi(x)");     
	for ( i = 0; i < n; i++) {
			z = (Table[i].lxi - mean) / var;
		printf("\n %lf %lf %lf",
		z, Equation(Table[i].xi, N), Simpsons38(LWR_LT, Table[i].xi, 100, N));
	}
		
}