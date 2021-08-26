////////////////////////////////////////////////////
//           Thomas 16/8/04                       //
// Bisection Method of solving algebraic and      //
// transcendental equations                       //
// equation has to be coded by the programmer     //
////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>
#define min(a, b) (fabs(a) < fabs(b)) ? a : b

long double equation(long double x)
{ 
	return (x - cos(x));
	/* This is the equation which is given in the question */
}


long double bisection(long double x1, long double x2)
{
	int n = 2, i = 0;/*This is the precision given in the question*/
	long double x3,fx1, rv, fx2, fx3, fx4, precis = 1 / pow(10, n);

	while( fabs(fabs(x1) - fabs(x2)) > precis) {

		x3 = ( x1 + x2 ) / 2;

		printf("\nIteration %d", ++i);

		fx1 = equation(x1);
		printf("\nx%d = %lf, f(x%d) = %lf", i - 1, x1, i + 1, fx1);
		fx2 = equation(x2);
		printf("\nx%d = %lf, f(x%d) = %lf", i , x2, i, fx2);
		fx3 = equation(x3);
		printf("\nx%d  = %lf, f(x%d) = %lf", i + 1, x3, i + 1, fx3);

		if ( getchar() == 'x') break;  //it is the responsibility of the student
									   //to terminate the program 
									   //when required precision is reached
		                               //by pressing x 

		if ( fx1 < 0.00001 && fx1 > -0.00001 ) return x1;
		else if ( fx2 < 0.00001 && fx2 > -0.00001 ) return x2;

		if (fx1 > 0 && fx2 < 0) {
			if (fx3 > 0) x1 = x3;		   //this section is to find
			else if (fx3 < 0) x2 = x3;     // which of the two iterating
			else return fx3;               // values have opposite sign to
		}                                  // that of f(x3) and to assign 
		else if ( fx1 < 0 && fx2 > 0) {    // new values accordingly
		if (fx3 < 0) x1 = x3;
			else if (fx3 > 0) x2 = x3;
			else return fx3;
		}
		else {              //error checking
			printf("\nRoots do not lie between the entered values");
			return 0;
		}
	}
	fx4 = min(fx2, fx3);
	rv = min(fx1, fx4);
	if (rv == fx1) return x1;
	else if (rv == fx2) return x2;
	else return x3;
}

void main()
{
	printf("%lf", bisection(0, 2)); /*parameters are the starting values of the iteration*/
}
   
	
