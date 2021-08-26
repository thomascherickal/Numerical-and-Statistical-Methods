#include <stdio.h>
#include <math.h>

double Fact(double x)
{
	if ( x == 0 ) return 1;
	else return x * Fact(x - 1);
}

double Poisson(double lda, double x)
{
	 return exp(-lda)*pow(lda, x)/Fact(x);
}

double F(double lda, double x)
{
	double i, ans = 0;
	for (i = 0; i <= x; i++)
		ans += Poisson(lda, i);
	return ans;
}
void main()
{
	double lambda,n, x;
	printf("\n\t\t\tPoisson Distribution");
	printf("\n\t\t\t*********************");
	printf("\n\nEnter n:");
	scanf("%lf", &n);  ;
	printf("\nEnter lambda:");
	scanf("%lf", &lambda);
	printf("\n  P(x)      F(x)");
	for (x = 0; x < n; x++) 
		printf("\n %lf %lf", Poisson(lambda, x), F(lambda, x));
}