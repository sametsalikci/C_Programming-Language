/*##########################################################*/
/*Sample Solution HW1  Part2                            	*/
/*________________________                              	*/
/*Written by Evren Cifci on March 11, 2014					*/
/*                                                      	*/
/*                                                      	*/
/*Description:                                          	*/
/*____________                                          	*/
/*Calculates average ages of 3 students						*/
/*Inputs:                                   				*/
/*  Birth years of 3 students from text file BirthYears.txt	*/
/*Outputs:													*/
/*	Average of ages (to console and to AverageAges.txt)		*/
/*##########################################################*/

#include<stdio.h>

#define IN_FILE "BirthYears.txt"
#define OUT_FILE "AverageAges.txt"
#define CURRENT_YEAR 2014

int main(){
	/*START_OF_MAIN*/
	
	/*Birth years and ages of students*/
	int birthYear1, birthYear2, birthYear3;
	int age1, age2, age3;
	
	int skip; /*a variable to skip student numbers in the input file*/
	
	double averageAge; /*Average ages of students*/
	
	FILE* inF = fopen(IN_FILE, "r"); 	/*Input file pointer*/
	FILE* outF = fopen(OUT_FILE, "w"); 	/*Output file pointer*/
	/*END_OF_VARIABLES*/
	
	/*Get the variables*/
	fscanf(inF, "%d%d", &skip, &birthYear1);
	fscanf(inF, "%d%d", &skip, &birthYear2);
	fscanf(inF, "%d%d", &skip, &birthYear3);
	
	/*Calculate ages and the average age*/
	age1 = CURRENT_YEAR - birthYear1;
	age2 = CURRENT_YEAR - birthYear2;
	age3 = CURRENT_YEAR - birthYear3;
	averageAge = (double)(age1 + age2 + age3) / 3.0;
	
	/*Output the evaluation value*/
	printf("The average age is %5.2f.", averageAge);
	fprintf(outF, "%f", averageAge);

	fclose(inF);
	fclose(outF);
	return 0;
	
	/*END_OF_MAIN*/
}
