/*##########################################################################*/
/* Sample Solution HW5 Part2		                  						*/
/* ________________________                             					*/
/* Written by Evren Cifci on May 5, 2014									*/
/*                                                      					*/
/*                                                      					*/
/* Description:                                         					*/
/* ____________																*/
/*																			*/
/*		Draws a shape with some horizamtally and vertically oriented 		*/
/*	triangles on the console												*/
/*	Inputs:																	*/
/*		Number of vertical recurrance(console)								*/			
/*		Number of horizantal recurrance (console)							*/
/*##########################################################################*/


#include<stdio.h>


/*Error Codes*/
#define INVALID_PARAMETER_VALUES -1

/*##########################################################################*/
/* Draws a line																*/
/*																			*/
/*	Input Parameters:														*/
/*	c: the character used for drawing										*/
/*	length: length of the line												*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Number of printed characters normally, a negative errorCode on error	*/
/*########################################################################*/
int drawLine(char c, int length);


/*##########################################################################*/
/* Gets Prices of the investment instruments from an input text file		*/
/*																			*/
/*	Input Parameters:														*/
/*	m: height of the pattern												*/
/*	n: the number of empty columns between each triangle					*/
/*	k: number of recurren													*/
/*	c: the character used for drawing										*/
/*  e: the number of empty columns before start of the pattern 			*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Number of printed characters normally, a negative errorCode on error	*/
/*##########################################################################*/
int drawReccurOf2Triangles(int m, int n, int k, char c, int e);

/*##########################################################################*/
/* Gets initial amount the investment instruments from an input text file	*/
/*																			*/
/*	Input Parameters:														*/
/*	rH: horizontal recurrence of the pattern								*/
/*	rV: vertical recurrence of the pattern 								*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Number of printed characters normally, a negative errorCode on error	*/
/*########################################################################*/
int drawReccurOf4Triangles(int rH, int rV);

/*##########################################################################*/
/* Prints an error Message													*/
/*																			*/
/*	errorCode: code of the error											*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Nothing																	*/
/*##########################################################################*/
void printError(int errorCode);


int main(void){
	/*START_OF_MAIN*/
	int charCount;
	
	/*END_OF_VARIABLES*/
	charCount = drawReccurOf2Triangles(7, 3, 3, '*', 1);
	if(charCount<0)
		printError(charCount);
	else
		printf("Number of characters: %d\n", charCount);
	printf("\n");

	charCount = drawReccurOf4Triangles(3, 4);
	if(charCount<0)
		printError(charCount);
	else
		printf("Number of characters: %d\n", charCount);

	/*END_OF_MAIN*/
}

int drawLine(char c, int length){
	int i;
	int count=0; /*number of characters used*/
	
	for(i=0; i<length; ++i){
		count += printf("%c", c);
	}
	
	return count;
}

int drawReccurOf2Triangles(int m, int n, int k, char c, int e){
	int i, j;
	int count=0; /*number of characters used*/	
	
	if((m<0) || (n<0) || (k<0) || (e<0))
		return INVALID_PARAMETER_VALUES;
	
	for(i=0; i<m; ++i){
		drawLine(' ', e+i); /*draw space before each line*/
		for(j=0; j<k; ++j){
			count += drawLine(c, 2*(m-i)-1); /**/
			drawLine(' ', n);
			count += drawLine(c, 2*i + 1);
			drawLine(' ', n);
		}
		printf("\n");
	}
	
	return count;
}

int drawReccurOf4Triangles(int rH, int rV){
	int i;
	int count=0; /*number of characters used*/	
	
	if((rH<0) || (rV<0))
		return INVALID_PARAMETER_VALUES;
	
	for(i=0; i<rV; ++i){
		count += drawReccurOf2Triangles(3, 2, rH, 'x', 0);
		count += drawReccurOf2Triangles(3, 2, rH, 'x', 3);
	}
	return count;	
}

void printError(int errorCode){
	switch(errorCode){
		case INVALID_PARAMETER_VALUES:
			printf("\nError: The value of a parameter is invalid.\n");
			break;
			
		default:
			printf("\nUnspecified Error!!!\n");
	}
}
