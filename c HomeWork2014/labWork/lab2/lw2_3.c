/*##############################################################*/
/*LW2_Part3                                						*/
/*________________________                              		*/
/*Written by Evren Cifci on February 24, 2014					*/
/*                                                      		*/
/*Description:                                          		*/
/*____________                                          		*/
/*Computes a Taplor Polynomial for ln(x-1) +1/2 with 4 terms	*/
/*Using a function to calculate each term						*/
/*Inputs:                                   					*/
/*  x:the variable												*/	
/*Outputs:														*/
/*	Result														*/
/*##############################################################*/

#include<stdio.h>
#include<math.h>

double get1Term(double x, int n);

int main(void){
	double x; 			/*the variable*/
	double result;		/*evaluation value of function*/
	
	/*obtain x*/
	printf("Enter x>");
	scanf("%lf", &x);
	
	/*calculate result*/
	result = -get1Term(x, 1) - get1Term(x, 2) - get1Term(x, 3) - get1Term(x, 4) + 1.0/2.0;
	
	/*output result*/
	printf("The result is: %f \n", result);
	return(0);
}

/*##############################################################*/
/*double get1Term(double x, int n)                              */
/*																*/
/*Inputs:                                   					*/
/*  x: the variable												*/
/*	n: term number												*/	
/*Outputs:														*/
/*	Evaluation value of the correponding term					*/
/*																*/															
/*Description:                                          		*/
/*____________                                          		*/
/*Computes a generic term of the function						*/
/*##############################################################*/
double get1Term(double x, int n){
	double result1Term;	/*calculated result of 1 term*/
	
	result1Term = pow(x, n)/(int)n;
	return result1Term;
}

