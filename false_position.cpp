////////////////////////////////////////////////////
//           Thomas 16/8/04                       //
// False Position Method of solving algebraic and //
// transcendental equations,                      //
// equation has to be coded by the programmer     //
////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>

#define min(a, b) (fabs(a) < fabs(b)) ? a : b


long double equation(long double x)
{ 
	return (pow(x, 3) + x - 1);
	/* This is the equation which is given in the question */
}


long double false_position(long double x1, long double x2)
{
	int n = 2, i = 0;/*n is the precision given in the question*/
	long double x3, rv, fx1, fx2, fx3, fx4, precis = 1 / pow(10, n);

	do {
		printf("\nIteration %d", ++i);

		fx1 = equation(x1);
		printf("\nx1 = %lf, f(x1) = %lf", x1, fx1);
		fx2 = equation(x2);
		printf("\nx2 = %lf, f(x2) = %lf", x2, fx2);
		x3 = ( fx2 * x1 - fx1 * x2 ) / ( fx2 - fx1 ); /*Regula Falsi formula*/
		fx3 = equation(x3);
		printf("\nx3 = %lf, f(x3) = %lf", x3, fx3);
		if ( getchar() == 'x') break;  //it is the responsibility of the student
									   //to terminate the program 
									   //when required precision is reached
		                               //by pressing x 
											
		if (  fx1 < 0.00001 && fx1 > -0.00001 ) return x1;       //Checking for 0, as this algorithm
		else if (  fx2 < 0.00001 && fx2 > -0.00001 ) return x2;  // will oscillate if either iterated value
																 //	becomes 0
		if (fx1 > 0 && fx2 < 0) {								 			
			if (fx3 > 0) x1 = x3;          //this section is to find
			else if (fx3 < 0) x2 = x3;     // which of the two iterating
			else return fx3;               // values have opposite sign to
		}                                  // that of f(x3) and to assign 
		else if ( fx1 < 0 && fx2 > 0) {    // new values accordingly
			if (fx3 < 0) x1 = x3;
			else if (fx3 > 0) x2 = x3;
			else return fx3;
		}
		else {       //error checking
			printf("\nRoots do not lie between the entered values");
			return 0;
		}
	} while(fabs(fabs(x1) - fabs(x2)) > precis);

	fx4 = min(fx2, fx3);                 //the algorithm needs to return the
	rv = min(fx1, fx4);                  //least function value's x, ie the xi
	if (rv == fx1) return x1;            //which is closest to 0
	else if (rv == fx2) return x2;
	else return x3;
}

void main()
{ 
	printf("%lf", false_position(0.5, 1)); /*parameters are the starting values of the iteration*/
}
   
	
