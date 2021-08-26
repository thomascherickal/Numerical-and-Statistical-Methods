////////////////////////////////////////////////////
//           Thomas 16/8/04                       //
// Newton Raphson Method of solving algebraic and //
// transcendental equations                       //
// equation has to be coded by the programmer     //
////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>

#define min(a, b) (fabs(a) < fabs(b)) ? a : b


long double equation(long double x)
{ 
	return ( pow(x , 2) + 4 * sin(x));
	/* This is the equation which is given in the question */
}

long double diffren(long double x0)
{
	long double h = 0.0000001;
	return ((1 / h) * ( equation(x0 + h) - equation(x0) ) ); // f`(x0) = Lim   1/h ( f(x + h) - f(x) )
															 //         h -> 0
}


long double newt_raph(long double x0)
{
	int n = 4, i = 0;/*This is the precision given in the question*/
	long double x1, fx0, fx1, precis = 1 / pow(10, n), x2;

	do {

		printf("\nIteration %d", ++i);

		fx0 = equation(x0);
		printf("\nx%d= %lf, f(x%d) = %lf", i - 1, x0, i - 1, fx0);
		
		x1 = x0 - equation(x0) / diffren(x0);
		fx1 = equation(x1);
		
		printf("\nx%d = %lf, f(x%d) = %lf", i, x1, i, fx1);
		getchar();
		
		x2 = x0;                  
		x0 = x1;
	
	} while(fabs(fabs(x1) - fabs(x2)) > precis);  //Not very complicated, as only one 
	                                              //value is being iterated and there is 
												  //is no chance of one value becoming stable

	return x1;
}

void main()
{
	printf("%lf", newt_raph(-1.57079));/*programmer has to find out a and b */ 
								       /*and determine whether |f(a)| > |f(b)|*/
}
   
	
