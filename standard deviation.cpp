/////////////////////////////////////////////////////////
//           Thomas 15/8/04                            //
//           Compute Standard Deviation                // 
//           for discrete and continuous data          //
/////////////////////////////////////////////////////////
#include <stdio.h>
#include <math.h>


struct entry {
	int mid_x;
	int freq;
} freq_table[100]; /*Data Structure 4 frequency distribution*/

//int data[100]; /* DS 4 discrete data v*/

long double Mean(int N)
{
	long double sum = 0;
	int i = 0;
	for (i = 0; i < N; i++)
		sum += freq_table[i].mid_x * freq_table[i].freq;
	return (sum /(long double) N);
}

long double C_SD(int N)
{
	long double fxisum = 0;
	int i;
	long double mean = Mean(N);
	
	for (i = 0; i < N; i++)
		fxisum += freq_table[i].freq * 
			      ( freq_table[i].mid_x - mean ) *
				  ( freq_table[i].mid_x - mean );

	return sqrt(fxisum /(long double) N);
}

void main()
{
	int i, n, N = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("Observation %d\n", i);
		printf("Mid-x\n");
		scanf("%d", &freq_table[i].mid_x);
		printf("Freq\n");
		scanf("%d", &freq_table[i].freq);
		N += freq_table[i].freq;
	}
	printf("\nMean = %lf", Mean(N));
	printf("\nStandard Deviation = %lf", C_SD(N));
}

				  


											
		
			

	