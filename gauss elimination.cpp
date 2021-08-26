
//Program to solve a system of n simultaneous linear equations by Gauss Elimination
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
//Gauss elimination//
void g_elim(float matrix[10][11], int n)
{
	int i, j, k;
	float p, q;
	for (k = 0; k < n - 1; k++) {
		p = matrix[k][k];
			//pcondens(matrix, n, k);
		for (j = k; j <= n; j++) {
			//normalization of coefficients//
			matrix[k][j] /= p;
		}  
		 //elimination of coefficients; triangularization//
		for (i = k + 1; i < n; i++) {
			q = matrix[i][k];
			for (j = k; j <= n; j++) 
				matrix[i][j] -= q * matrix[k][j];
		}
		printf("\n\nIteration %d", k);	
		display(matrix, n);
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
