/*##############################################################*/
/*LW2_Part1                                						*/
/*________________________                              		*/
/*Written by Evren Cifci on February 24, 2014					*/
/*                                                      		*/
/*Description:                                          		*/
/*____________                                          		*/
/*Computes a Taplor Polynomial for ln(x-1) +1/2 with 4 terms	*/
/*Inputs:                                   					*/
/*  x:the variable	
/*Outputs:														*/
/*	Result														*/
/*##############################################################*/

#include<stdio.h>
#include<math.h>

int main(void){
	double x; 			/*the variable*/
	double result;		/*evaluation value of function*/
	
	/*obtain x*/
	printf("Enter x>");
	scanf("%lf", &x);
	
	/*calculate result*/
	result = -pow(x, 1)/1.0 - pow(x, 2)/2.0 - pow(x, 3)/3.0 - pow(x, 4)/4.0 + 1.0/2.0;
	
	/*output result*/
	printf("The result is: %f \n", result);
	return(0);
}

