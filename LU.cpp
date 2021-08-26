
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

//accept the matrix from user//
void input(float matrix[10][11], int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= n; j++) {
			printf("Enter equation %d, coefficient x%d: ", i, j);
			scanf("%f", &matrix[i][j]);
		}
	}
}

void display(float matrix[10][11], int n)
{
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j <= n; j++) {
			printf("   %.6f", matrix[i][j]);
		}
	}
	getch();
}

//if first coefficient in the first equation is zero, reorder until non-zero// 
void reorder(float matrix[10][11], int n)
{
	int i, j, k;
	float t;

	for (i = 0; i < n; i++)
		for (j = n - 1; j >= 0; j--)
			if (matrix[i][i] == 0 && matrix[j][i] != 0)
				for (k = 0; k < n; k++)
					t = matrix[i][k], matrix[i][k] = matrix[k][j], matrix[k][j] = t;
}

float pcondens(float a[10][11], int n, int k)
{
	int i, j = -1;
	float temp, M = a[k][k];
	for (i = k + 1; i < n; i++)
		if (a[i][k] > M) {
			M = a[i][k];
			j = i;
		}
	if (j != -1) {
		for (i = 0; i <= n; i++) {
			temp = a[k][i];
			a[k][i] = a[j][i];
			a[j][i] = temp;
		}
		printf("\n\nAfter pivotal condensation about %d", j);
		display(a, n);
	}
	return M;
}		
//LU Decomposition
void LU(float a[10][11], int n)
{
	int i, imax, j, k;
	float vv[10], big, dum, sum, temp;
	for (i = 0; i < n; i++) {
		big = 0;
		for (j = 0; j < n; j++) 
			if ((temp = fabs(a[i][j]) > big)
				big = temp;
			if (big == 0) {
				printf("\nSingular Matrix, exiting");
				exit(1);
			}
			vv[i] = 1.0 / big;
	}
	for (j = 0; j < n; j++) {
		for( i = 0; i < j; i++) {
			sum = a[i][j];
			for( k = 0; k < i; k++)
				sum -= a[i][k] * a[k][j];
			a[i][j] = sum;
		}
		for (i = j; i < n; i++) {
			sum = a[i][j];
			for (k = 0; k < j; k++)
				sum -= a[i][k] * a[k][j];
			a[i][j] = sum;
			if ((dum = vv[i] * fabs(sum)) > big) {
				big = dum;
				imax = i;
			}
		}
		if ( j != imax) {
			for (k =0;k < n; k++) {
				dum = a[imax][k];
				a[imax][k] = a[j][k];
				a[j][k] = dum;
			}
			vv[imax] = vv[j];
			if( j != n - 1) {
				dum = 1.0 / a[j][j];
				for( i = j + 1; i < n; i++)
					a[i][j] *= dum;
			}
		}
	}
}

	printf("\n\nIteration %d", k);	
		display(a, n);
	}
}


//Back substitution//
void back_subst(float matrix[10][11], int n, float x[10])
{
	int i, j;
	float s;
	x[n - 1] = matrix[n - 1][n] / matrix[n - 1][n - 1];

	for (i = n - 2; i >= 0 ; i--) {
		s = 0;
		for (j = n - 1; j > i; j--)
			s += matrix[i][j] * x[j];
		if (matrix[i][i] == 0) {
			printf("Division by zero, exiting");
			exit(-1);
		}
		x[i] = (matrix[i][n] - s)/matrix[i][i];
	}
}

void main()
{
	float a[10][11], x[10];
	int n, i;
	printf("\n\t\t\tGauss Elimination");
	printf("\n\t\t\t*****************");
	printf("\n\nEnter the degree of the system");
	scanf("%d", &n);
	input(a, n);
	display(a, n);
	reorder(a, n);
	g_elim(a, n);
	back_subst(a, n, x);
	printf("\nThe solution set is:");
	for (i = 0; i < n; i++)
		printf("\n%.2f", x[i]);
	getch();
}