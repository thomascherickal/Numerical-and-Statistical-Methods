#include <stdio.h>
#include <conio.h>
#include <math.h>


float a[10][11];
float s[10];

void GS(int n, int d, float init)
{
	int i = 1, j, flag = 0, t = 1,m = 0;
	double pres = pow(10, -d), temp = (double)init + 1;
	for(i = 0; i < n; i++)
		s[i] = init;

	do
	{
		m++;
		temp = s[0];
		for(i = 0; i < n; i++) {
			s[i] = a[i][n];
			flag = 1;
			for(j = 0; j < n; j++) {
				if (i == j)
					continue;
				else
					s[i] -= a[i][j] * s[j];
			}
			s[i] /= a[i][i];
			
		}
	} while(m < 50 && fabs(fabs((double)s[0]) - fabs((double)temp)) > pres);
	if (m >= 50)
		printf("\nNo solution after 50 iterations");
	else
		for( i = 0; i < n; i++)
			printf("\n%f", s[i]);
}

void input(int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j <= n; j++) {
			printf("\nEnter coeff %d %d", i, j);
			scanf("%f", &a[i][j]);
		}
}

void display(int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j <= n; j++) 
			printf("%0.2f", a[i][j]);
	}
}

void main()
{
	int n, d;
	printf("\n\t\t\tGauss-Seidel Iteration Method");
	printf("\n\t\t\t*****************************");
	printf("\n\n\nEnter the degree of the equation:");
	scanf("%d",&n);
	printf("\nEnter the required precision:");
	scanf("%d",&d);
	input(n);
	display( n);
	GS(n, d, 1);
}

	
