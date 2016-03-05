/*######################################################*/
/*Sample Solution HW1  Part1                            */
/*________________________                              */
/*Written by Evren Cifci on March 11, 2014				*/
/*                                                      */
/*                                                      */
/*Description:                                          */
/*____________                                          */
/*Evaluates a mathematical function 					*/
/*Inputs:                                   			*/
/*  Variables a,b from text file Variables.txt			*/
/*Defined Parameters by Macro							*/
/*	Parameters C and D									*/
/*Outputs:												*/
/*	Evaluation Value (to console and to Result.txt)		*/
/*######################################################*/

#include<stdio.h>
#include<math.h>

#define C 5.0
#define D 8.0

#define VAR_FILE "Variables.txt"
#define OUT_FILE "Result.txt"

int main(){
	/*START_OF_MAIN*/
	int a, b;		/*User defined variables*/
	
	double baseInFirstTerm;	/*base component of the 1st term*/
	double baseInSecondTerm;/*base component of the 2nd term*/
	double logTerm;			/*logaritmic part of the 2nd term*/
	double baseInThirdTerm;	/*base component of the 3rd term*/
	
	/*Terms of the function*/
	double firstTerm;
	double secondTerm;
	double thirdTerm;
	
	double result; 	/*Evaluation value*/
	
	FILE* varF = fopen(VAR_FILE, "r"); 	/*Variable file pointer*/
	FILE* outF = fopen(OUT_FILE, "w"); 	/*Output file pointer*/
	/*END_OF_VARIABLES*/
	
	/*Get the variables*/
	fscanf(varF, "%d%d", &a, &b);
	
	/*Evaluate the function*/
	/*Calculate 1st Term*/
	baseInFirstTerm = (double)(a + b) / (b + 1.0);
	firstTerm = pow(baseInFirstTerm, 3.8);
	
	/*Calculate 2nd Term*/
	logTerm = log(D) / log(3.0);
	baseInSecondTerm = logTerm + 13.0/7.0;
	secondTerm = sqrt(baseInSecondTerm);
	
	/*Calculate 3rd Term*/
	baseInThirdTerm = a + D/C;
	thirdTerm = pow(baseInThirdTerm, 1.0/3.0);
	
	result = firstTerm + secondTerm + thirdTerm;
	
	/*Output the evaluation value*/
	printf("The result is %5.3f.", result);
	fprintf(outF, "%f", result);

	fclose(varF);
	fclose(outF);
	return 0;
	
	/*END_OF_MAIN*/
}
