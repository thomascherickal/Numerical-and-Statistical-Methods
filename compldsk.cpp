/////////////////////////////////////////////////////////////////////////////////
//	Computation of Measures of Location, Dispersion, Skewness, Kurtosis        //
//        Thomas 19/10/04													   //
// Functions with a C suffix are for continuous data, with D suffix are for    //
// discrete data, and with no suffix are for both discrete and continuous data //
/////////////////////////////////////////////////////////////////////////////////

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

/* Input and Output*/

//Input continuous data
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

//display continuous data, ie, frequency table
void DisplayC(double n) {
	int i;
	printf("\n   xi   lxi   hxi  fi");
	for (i = 0; i < n; i++)
		printf("\n %0.2lf  %0.2lf  %0.2lf  %d",Table[i].xi,Table[i].lxi,Table[i].hxi,Table[i].freq);
}

//input discrete data
void InputD(double n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Value %d",i);
		scanf("%lf",&Table[i].xi);
		Table[i].freq = 1;
	}
}

//display discrete data
void DisplayD(double n) {
	int i;
	printf("\nData Values");
	for (i = 0; i < n; i++)
		printf("\n%1.0lf",Table[i].xi);
}

/*Measures of Location */

//Arithmetic Mean for both discrete and continuous data
double AM( double n, double N)
{
	int i;
	double Sxi = 0;
	for (i = 0; i < n; i++)
		Sxi += Table[i].xi * Table[i].freq;
	return Sxi/ N;
}

//Geometric Mean for both discrete and continuous data
double GM( double n, double N)
{
	int i;
	double Pxi = 1, p;
	for (i = 0; i < n; i++)
		Pxi *= pow(Table[i].xi, Table[i].freq);
	p = (double) 1 / N;
	return pow(Pxi, p);
}

//Harmonic Mean for both discrete and continuous data
double HM( double n, double N)
{  int i = 0;
	double Sxi = 0;
	for (i = 0; i < n; i++)
		Sxi += Table[i].freq / Table[i].xi;
	return N / Sxi;
}

//Sorting function 
void InsertionSort(double n) {
	int i, j;
	Data temp;
	for (i = 1; i < n; i++) {
		temp = Table[i];
		for(j = i - 1; j >= 0 && (temp.xi < Table[j].xi); j--)
			Table[j + 1] = Table[j];
		Table[j + 1] = temp;
	}
}

/*Call the Sort function before calling the functions below */

//Quartiles for discrete data
double QuartileD(double n, int Q)
{
	if (Q == 2) {
			if ((int)n % 2 == 1)
				return Table[(int)(n - 1)/2].xi;
			else
				return 0.5 * (Table[(int)n / 2 - 1].xi + Table[(int)n / 2].xi);
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

//Quartiles for a frequency table
double QuartileC(double n, int Q, double N)
{
	int c = (int) (Table[1].xi - Table[0].xi), i;
	double m = 0, temp;
	for (i = 0; i < n; i++) {
		temp = m;
		m += Table[i].freq;
		if ((m - Q * N / 4) >= 0)
			break;
	}
	m = temp;
	int f = Table[i].freq;
	double l = Table[i].lxi;
	return (l + ((Q * ((double)N / 4) - m) / (double) f) * (double) c );

}

//Mode for a discrete set of values
double ModeD(double n)
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

//Mode for continuous data
double ModeC(double n)
{
	int i, M = -1, t, j, c = (int) (Table[1].xi - Table[0].xi);
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
		l = Table[j].lxi;
		f0 = Table[j - 1].freq;
		f1 = Table[j].freq;
		f2 = Table[j + 1].freq;

		return l + ((f1 - f0) /(2 * f1 - (f0 + f2))) * c;
	}
}

/*Measures of Dispersion*/

//Range and Coefficient of Range
double RangeD(double n, double *coeff)
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

//Quartile Deviation for continuous data, Inter-Quartile Range, Coefficient of Quartile Deviation
double QuartileDevC(double n, double *iq_range, double *coeff, double N) 
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
double MeanDev(double n, double M, double *coeff)
{
	double S = 0;
	double N = 0;
	int i;

	for (i = 0; i < n; i++) {
		S += Table[i].freq * fabs(Table[i].xi - M);
		N += Table[i].freq;
	}

	*coeff = S / N * M;
	return S / N;
}


//Standard Deviation for discrete or continuous data
double SD(double n, double *CV, double N)
{
	double mean = AM(n, N), fxi = 0;
	int i;
	for (i = 0; i < n; i++)
		fxi += Table[i].freq * pow(Table[i].xi - mean, 2.00);

	*CV = sqrt(fxi / N) * 100 / mean;
	return sqrt(fxi / N);
}

/* Measures of Skewness and Kurtosis*/

//Bowleys coefficient of skewness for continuous data
double Bowley(double n, double N)
{
	double Q3 = QuartileC(n, 3, N), Q1 = QuartileC(n, 1, N), M = QuartileC(n, 2, N);
	return (Q3 + Q1 - 2*M) / (Q3 - Q1);
}

//Karl Pearson's coefficient of skewness for continuous data
double KP(double n, double N)
{
	double dummy;
	double mean = AM(n, N), median = QuartileC(n, 2, N), mode = ModeC(n), sd = SD(n, &dummy, N);
	if( mode == 0) // Mode is not well defined
		return 3 * (mean - median) / sd;
	else
		return (mean - mode) / sd;
}

// Moments about the actual mean for continuous or discrete data
double Moment(int r, double n, double N)
{
	int i;
	double mean = AM(n, N), sxi = 0;
	for (i = 0; i < n; i++) 
		sxi += pow(Table[i].xi - mean,(double) r) * Table[i].freq;
	return sxi / N;
}

void main()
{
	int i;
	double n, N, type;
	double c1, c2, c3;
	double u[4];
	printf("\t\n**************************************************************");
	printf("\t\n*  Measures of Location, Dispersion, Skewness and Kurtosis   *");
	printf("\t\n**************************************************************");
	printf("\t\n\nEnter n");
	scanf("%lf",&n);
	printf("\nEnter 0 for discrete, 1 for continuous");
	do {
		scanf("%lf", &type);
	} while( type != 0 && type != 1);
	if (type == DISCRETE) {
		N = n;
		InputD(n);
		InsertionSort(n);
		DisplayD(n);
		printf("\n\nMedian = %lf", c3 = QuartileD(n, 2));
		printf("\nMode = %lf", ModeD(n));
		printf("\n\nRange = %lf",RangeD(n, &c1));
		printf("\nCoefficient of Range = %lf", c1);
		printf("\nQ1 = %lf", QuartileD(n, 1));
		printf("\nQ3 = %lf", QuartileD(n, 3));
	}
	else if (type == CONTINUOUS) {
		N = InputC(n);
		InsertionSort(n);
		DisplayC(n);
		printf("\nMedian = %lf", c3 = QuartileC(n, 2, N));
		printf("\nMode = %lf", ModeC(n));
		printf("\nQ1 = %lf", QuartileC(n, 1, N));
		printf("\nQ3 = %lf", QuartileC(n, 3, N));
		printf("\n\nQuartile Deviation = %lf",QuartileDevC(n, &c1, &c2, N));
		printf("\nInter-Quartile Range = %lf", c1);
		printf("\nCoefficient of Quartile Deviation = %lf",c2);
		printf("\n\nBowley's coefficient of skewness = %lf",Bowley(n, N));
		printf("\nKarl Pearson's coefficient of skewness = %lf",KP(n, N));
	}
	printf("\n\nArithmetic Mean = %lf", (c1 = AM(n, N)));
	printf("\nGeometric Mean = %lf",GM(n, N));
	printf("\nHarmonic Mean = %lf",HM(n, N));
	printf("\n\nMean Deviation about Mean = %lf",MeanDev(n, c1, &c2));
	printf("\nCoefficient of Mean Deviation about Mean = %lf",c2);
	printf("\nMean Deviation about Median = %lf",MeanDev(n, c3, &c2));
	printf("\nCoefficient of Mean Deviation about Median = %lf",c2);
	printf("\nStandard Deviation = %lf",SD(n, &c3, N));
	printf("\nCoefficient of Variance = %lf",c3);
	for (i = 0; i < 4; i++)
		u[i] = Moment(i + 1, n, N);
	printf("\n\n\tMoments");
	for(i = 0; i < 4; i++)
		printf("\nu%d = %lf",i + 1, u[i]);
	printf("\nSkewness = %lf",(pow(u[2],2) / pow(u[1], 3)));
	printf("\nVariance = %lf",u[1]);
	printf("\nKurtosis = %lf",(u[3] / pow(u[1], 2)));
	getch();

}




