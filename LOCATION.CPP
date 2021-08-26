#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define L 100
#define CONTINUOUS 1
#define DISCRETE 0

typedef struct data {
	int freq;
	double xi;
	double hxi;
	double lxi;
} Data;

Data Table[L];


double ModeC(int n)
{
	int i, M = -1, t, j, c = (int) (Table[1].freq - Table[0].freq);
	double l, f0, f1, f2;
	for (i = 0; i < n; i++)
		if (Table[i].freq >= M) {
			t = M;
			M = Table[i].freq;
			j = i;
		}
	if (t == M) {
		printf("\nMode is not well defined");
		return 0;
	}
	else {
		l = Table[j].lxi - c / 2;
		f0 = Table[j - 1].freq;
		f1 = Table[j].freq;
		f2 = Table[j + 1].freq;

		return l + (f1 - f0)/(2 * f1 - (f0 + f2));
	}
}


int InputC(int n) {
	int i, N = 0;
	printf("\nEnter values\n");
	for (i = 0; i < n; i++) {
		printf("\nEnter lower lt%d:", i);
		scanf("%lf",&Table[i].lxi);
		printf("\nEnter upper lt%d:", i);
		scanf("%lf",&Table[i].hxi);
		Table[i].xi = (Table[i].lxi + Table[i].hxi) / 2;
		printf("\nEnter f%d:", i);
		scanf("%d",&Table[i].freq);
		N += Table[i].freq;
		fflush(stdin);
	}
	return N;
}

void DisplayC(int n) {
	int i;
	printf("\n   xi   lxi   hxi   fi");
	for (i = 0; i < n; i++)
		printf("\n %0.2lf  %0.2lf  %0.2lf  %d",Table[i].xi,Table[i].lxi,Table[i].hxi,Table[i].freq);
}

void InputD(int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Value %d",i);
		scanf("%lf",&Table[i].xi);
		Table[i].freq = 1;
	}
}

void DisplayD(int n) {
	int i;
	printf("\nData Values");
	for (i = 0; i < n; i++)
		printf("\n%1.0lf",Table[i].xi);
}

double AM( int n, int N)
{
	int i;
	double Sxi = 0;
	for (i = 0; i < n; i++)
		Sxi += Table[i].xi * Table[i].freq;
	return Sxi/ N;
}

double GM( int n, int N)
{
	int i;
	double Pxi = 1, p;
	for (i = 0; i < n; i++)
		Pxi *= pow(Table[i].xi, Table[i].freq);
	p = (double) 1 / N;
	return pow(Pxi, p);
}

double HM( int n, int N)
{  int i = 0;
	double Sxi = 0;
	for (i = 0; i < n; i++)
		Sxi += Table[i].freq / Table[i].xi;
	return N / Sxi;
}

void InsertionSort(int n) {
	int i, j;
	Data temp;
	for (i = 1; i < n; i++) {
		temp = Table[i];
		for(j = i - 1; j >= 0 && (temp.freq > Table[j].freq); j--)
			Table[j + 1] = Table[j];
		Table[j + 1] = temp;
	}
}

//Call the Sort function before calling all the below functions

double QuartileD( int n, int Q)
{
	if (Q == 2) {
			if (n % 2 == 1)
				return Table[(n - 1)/2].xi;
			else
				return 0.5 * (Table[n / 2 - 1].xi + Table[n / 2].xi);
		}
	else if (Q == 1)
			return Table[(int)(n / 4)].xi;
	else if (Q == 3)
			return Table[(int)(3 * n / 4)].xi;
	else {
		printf("\nInvalid quartile");
		return 0;
	}
}

double QuartileC( int n, int Q, int N)
{
	int c = (int) (Table[1].xi - Table[0].xi), i;
	double m = 0;
	for (i = 0; i < n; i++) {
		m += Table[i].freq;
		if ((m - Q * N / 4) >= 0)
			break;
	}
	int f = Table[i].freq;
	double l = Table[i].lxi;
	return (l + (Q * N / 4 - m) / f * c );

}

double ModeD(int n)
{
	int i, count = 0, t = 0, place;
	for (i = 0; i < n; i++) {
		if (Table[i].freq == Table[i + 1].freq)
			count++;
		else {
			if ( t < count )
			t = count;
			count = 0;
			place = i;
		}
	}
	if ( t == count ) {
		printf("\nMode is not well defined");
		return 0;
	}

	else
		return Table[place].xi;
}

double RangeD(int n, double *coeff)
{
	double Sm = 99999, Lr = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (Table[i].xi > Lr)
			Lr = Table[i].xi;
		if (Table[i].xi < Sm)
			Sm = Table[i].xi;
	}
	*coeff = (Lr - Sm) / (Lr + Sm);
	return (Lr - Sm);
}

double QuartileDevC(int n, double *iq_range, double *coeff, int N) 
{
	double Q3, Q1;
	Q1 = QuartileC(n, 1, N);
	Q3 = QuartileC(n, 3, N);
	*iq_range = Q3 - Q1;
	*coeff = (Q3 - Q1) / (Q3 + Q1);
	return (Q3 - Q1) / 2;
}

//Can be used to find mean deviation abt Mean if M = Mean, abt Median if M = Median,
// for both discrete and continuous data
double MeanDev(int n, double M, double *coeff)
{
	double S = 0;
	int N = 0, i;

	for (i = 0; i < n; i++) {
		S += Table[i].freq * fabs(Table[i].xi - M);
		N += Table[i].freq;
	}

	*coeff = S / N * M;
	return S / N;
}



double SD(int n, double *CV, int N)
{
	double mean = AM(n, N), fxi = 0;
	int i;
	for (i = 0; i < n; i++)
		fxi += Table[i].freq * pow(Table[i].xi - mean, 2.00);

	*CV = sqrt(fxi / N) * 100 / mean;
	return sqrt(fxi / N);
}



void main()
{
	int n, N, type;
	double c1, c2, c3;
	printf("\t\n**************************************************************");
	printf("\t\n*  Measures of Location, Dispersion, Skewness and Kurtosis   *");
	printf("\t\n**************************************************************");
	printf("\t\n\nEnter n");
	scanf("%d",&n);
	printf("\nEnter 0 for discrete, 1 for continuous");
	do {
		scanf("%d", &type);
	} while( type != 0 && type != 1);
	InsertionSort(n);
	if (type == DISCRETE) {
		N = n;
		InputD(n);
		DisplayD(n);
		printf("\nMedian = %lf", c3 = QuartileD(n, 2));
		printf("\nMode = %lf", ModeD(n));
		printf("\nRange = %lf",RangeD(n, &c1));
		printf("\nCoefficient of Range = %lf", c1);
	}
	else if (type == CONTINUOUS) {
		N = InputC(n);
		DisplayC(n);
		printf("\nMedian = %lf", c3 = QuartileC(n, 2, N));
		printf("\nMode = %lf", ModeC(n));
		printf("\nQuartile Deviation = %lf",QuartileDevC(n, &c1, &c2, N));
		printf("\nInter-Quartile Range = %lf", c1);
		printf("\nCoefficient of Quartile Deviation = %lf",c2);
	}
	printf("\nArithmetic Mean = %lf", (c1 = AM(n, N)));
	printf("\nGeometric Mean = %lf",GM(n, N));
	printf("\nHarmonic Mean = %lf",HM(n, N));
	printf("\nMean Deviation about Mean = %lf",MeanDev(n, c1, &c2));
	printf("\nCoefficient of Mean Deviation about Mean = %lf",c2);
	printf("\nMean Deviation about Median = %lf",MeanDev(n, c3, &c2));
	printf("\nCoefficient of Mean Deviation about Median = %lf",c2);
	printf("\nStandard Deviation = %lf",SD(n, &c3, N));
	printf("\nVariance = %lf",c3);
	getch();

}




