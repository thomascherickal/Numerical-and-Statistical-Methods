////////////////////////////////////////////////////
//           Thomas 16/8/04                       //
// Bisection Method of solving algebraic and      //
// transcendental equations                       //
// equation has to be coded by the programmer     //
////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>


long double equation(long double x)
{ 
	return (pow(x, 3) - 4 * x - 9);
	/* This is the equation which is given in the question */
}

int i = 0;

long double bisection(long double x1, long double x2)
{
	int n = 2;/*This is the precision given in the question*/
	long double x3 = ( x1 + x2 ) / 2, fx1, fx2, fx3, precis = 1 / pow(10, n);
	printf("\nIteration %d", ++i);
	fx1 = equation(x1);
	printf("\nx1 = %lf, f(x1) = %lf", x1, fx1);
	fx2 = equation(x2);
	printf("\nx2 = %lf, f(x2) = %lf", x2, fx2);
	fx3 = equation(x3);
	printf("\nx3 = %lf, f(x3) = %lf", x3, fx3);
	getchar();
	if ( fabs(x1 - x2) < precis) return x1;
	else {		
		if (fx1 > 0 && fx2 < 0) {
			if (fx3 > 0) return bisection(x3, x2);
			else if (fx3 < 0) return bisection(x1, x3);
			else return fx3;
		}
		else if ( fx1 < 0 && fx2 > 0) {
			if (fx3 < 0) return bisection(x2, x3);
			else if (fx3 > 0) return bisection(x3, x1);
			else return fx3;
		}
		else if (fx1 == 0) return x1;
		else if (fx2 == 0) return x2;
		else {
			printf("\nRoots do not lie between the entered values");
			return 0;
		}
	}
}

void main()
{
	long double a, b;
	printf("\n**************************************");
	printf("\n*         Bisection Method           *");
	printf("\n**************************************");
	printf("\nEnter a:");
	scanf("%lf", &a);
	printf("\nEnter b:");
	scanf("%d", &b);
	printf("\nAnswer = %lf", bisection(2, 3)); 
}
   
	
