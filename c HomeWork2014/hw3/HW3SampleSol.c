/*##########################################################################*/
/* Sample Solution HW3		                           						*/
/* ________________________                             					*/
/* Written by Evren Cifci on March 12, 2014									*/
/*                                                      					*/
/*                                                      					*/
/* Description:                                         					*/
/* ____________																*/
/* PART1:																	*/
/*		Calculates sinus of an angle using a Taylor Polynomial 				*/
/*	Inputs: (from console or file)                                  		*/					
/*		An angle (in degrees)												*/	
/*		Number of Terms of the Taylor Polynomial							*/
/*	Output:																	*/
/*		Sinus Value		(to console and file)								*/
/* PART2:																	*/
/*		Draws a tree using triangular and rectangular shapes				*/
/*	Inputs:																	*/
/*		Number of triangles in the tree										*/			
/*		Truck height of the tree											*/
/*		Truch width of the tree												*/
/*		Character to be used when drawing the tree							*/
/*##########################################################################*/


#include<stdio.h>

#define PI 3.14159265358979323846264338
#define ANGLE_FILE "Angle.txt"
#define SIN_FILE "Sinus.txt"

/*Error Codes*/
#define INVALID_SOURCE -1
#define INVALID_NUM_OF_TERMS -2
#define NEGATIVE_NUMBER_OF_TRIANGLES -3
#define NEGATIVE_TRUCK_HEIGHT -4
#define INVALID_TRUCK_WIDTH -5



/*##########################################################################*/
/* Translates and angle from radian to degree								*/
/*																			*/
/*	angleInRad: Value of the angle in radian								*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Value of the angle in Degrees											*/
/*##########################################################################*/
double rad2Deg(double angleInRad);

/*##########################################################################*/
/* Calculates the facctorial of the given integer							*/
/*																			*/
/*	n: number for which the fctorial will be calculated						*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* The factorial															*/
/*##########################################################################*/
int factorial(int n);

/*##########################################################################*/
/* Calculates the desired power of a number									*/
/*																			*/
/*	base : base of the power operation										*/
/*	exp  : exponent og-f the power operation 								*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Result of the power operation											*/
/*##########################################################################*/
double pow(double base, int exp);

/*##########################################################################*/
/* Calculates the sinus of an angle using a Taylor Polynomial				*/
/*																			*/
/*	angle : angle for which the sinus is calculated in radians				*/
/*	numOfTerms: number of terms used in the Taylor Polynomial				*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* The sinus value															*/
/*##########################################################################*/
double getSin(double angle, int numOfTerms);

/*##########################################################################*/
/* Provides a user interface for part1										*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* 0 normally																*/
/* a negative error code on error											*/
/*##########################################################################*/
int part1(void);

/*##########################################################################*/
/* Draws a line using the specified character								*/
/*																			*/
/*	length : length of the line												*/
/*	ch: character used for drawing											*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Number of characters drawn												*/
/*##########################################################################*/
int drawLine(int length, char ch);

/*##########################################################################*/
/* Draws a left-alligned triangle shifted a specific number of characters	*/
/*		right																*/
/*																			*/
/*	height : height of the shape											*/
/*	space : number of right shift characters								*/
/*	ch: character used for drawing											*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Number of characters drawn												*/
/*##########################################################################*/
int drawTriangleWithSpace(int height, int space, char ch);

/*##########################################################################*/
/* Draws a left-alligned rectangle shifted a specific number of characters	*/
/*		right																*/
/*																			*/
/*	height : height of the shape											*/
/*	width : width of the shape												*/
/*	space : number of right shift characters								*/
/*	ch: character used for drawing											*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Number of characters drawn												*/
/*##########################################################################*/
int drawRectangleWithSpace(int height, int width, int space, char ch);

/*##########################################################################*/
/* Draws a left-alligned tree using triangular and rectangular objects		*/
/*																			*/
/*	numberOfTriangles: number of triangular shapes used to draw the tree	*/
/*	truckHeight: height of the truck part in terms of characters			*/
/*	truckWidth: width of the truck part in terms of characters				*/
/*	ch: character used for drawing											*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Number of characters drawn												*/
/*##########################################################################*/
int drawTree(int numberOfTriangles, int truckHeight, int truckWidth, char ch);

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

	int chCount; /*number pf characters used*/
	int numOfTri;
	int truckH;
	int truckW;
	char ch;

	/*Test part 1*/
	chCount = part1();
	if(chCount < 0)
		printError(chCount);

	/*Test part 2*/
	printf("Draw triangle with space: 2, height: 5, ch = * \n");
	chCount = drawTriangleWithSpace(5, 2, '*');
	if(chCount < 0)
		printError(chCount);

	printf("Draw rectangle with height:3, width: 5, space: 4, ch: / \n");
	chCount = drawRectangleWithSpace(3, 5, 4, '/');
	if(chCount < 0)
		printError(chCount);

	printf("Draw tree with num of triangles: 2, truch height: 3, truck width: 2, ch = 0");
	chCount = drawTree(2, 3, 2, '0');
	if(chCount < 0)
		printError(chCount);
	
	printf("Enter number of triangles, truch height and truch width: ");
	scanf("%d%d%d", &numOfTri, &truckH, &truckW);
	printf("Enter the character you want to use: ");
	scanf(" %c", &ch);
	chCount = drawTree(numOfTri, truckH, truckW, ch);
	if(chCount < 0)
		printError(chCount);
	else
		printf("%d characters printed.", chCount);


	return 0;
}


double rad2Deg(double angleInRad){
	return angleInRad*PI/180.0;
}

int factorial(int n){
	int i;
	int fakt = 1;

	for(i=2; i<=n; i++)
		fakt *= i;
	return fakt;
}

double pow(double base, int exp){
	int i;
	double result = 1.0;

	for(i=0; i<exp; i++)
		result *= base;

	return result;
}

double getSin(double angle, int numOfTerms){
	int i;
	double totalSoFar = 0; /*sum of terms*/

	/*Calculate sinus*/
	for(i=0; i<numOfTerms; i++){
		/*sign change is implemented by pow(-1.0, i) multiplier*/
		totalSoFar += pow(-1.0, i) * pow(angle, 2*i+1) / factorial(2*i + 1);
	}

	return totalSoFar;
}

int part1(void){
	char source;	/*source of the input*/
	double angleInDeg; /*degree value of the angle, sinus of wwhich will be calculated */
	double angleInRad; /*radian value of the angle*/
	int numOfTerms; /*number of terms of the Taylor Poly*/
	double sinValue; /*calculated sinus value*/
	int fileOpened = 0; /*indicates if the input file has been opened*/ 
	FILE* angleFile; /*Input file holding angle and number of terms*/
	FILE* sinFile  = fopen(SIN_FILE, "w"); /*output file  sinus will be written to*/
	
	/*Get source of data*/
	printf("Please specify the source of future inputs (C or c for console, f or F for file): ");
	scanf("%c", &source);

	/*Get data*/
	switch(source){
	case 'c':
	case 'C':
		/*get data from console*/
		printf("Please enter angle in degrees: ");
		scanf("%lf", &angleInDeg);
		printf("Please enter number of terms: ");
		scanf("%d", &numOfTerms);
		break;
	
	case 'f':
	case 'F':
		/*get data from file*/
		angleFile = fopen(ANGLE_FILE, "r");
		fileOpened = 1;
		fscanf(angleFile, "%lf", &angleInDeg);
		fscanf(angleFile, "%d", &numOfTerms);
		break;

	default:
		return INVALID_SOURCE;
	}

	/*check the validity of number of term*/
	if(numOfTerms < 0)
		return INVALID_NUM_OF_TERMS;

	/*make calculations*/
	angleInRad = rad2Deg(angleInDeg);
	sinValue = getSin(angleInRad, numOfTerms);

	/*output result*/
	printf("The sinus of %f degree is %.3f\n", angleInDeg, sinValue);
	fprintf(sinFile, "%f", sinValue);

	fclose(sinFile);
	if(fileOpened)
		fclose(angleFile);

	return 0;
}

int drawLine(int length, char ch){
	int i;
	int chCount = 0; /*number of characters printed*/

	for(i=0; i<length; i++)
		chCount += printf("%c", ch); /*printf returns number of items it prints*/

	return chCount;
}

int drawTriangleWithSpace(int height, int space, char ch){
	int numOfSpace; /*number of space characters in the beginning of a line*/
	int lineLength; /*length of the line drawn using the specified character*/
	int chCount = 0; /*number of specified characters drawn*/
	int i;

	for(i=1; i <= height; i++){
		/*draw a line of the shape*/
		numOfSpace = space + height - i;
		drawLine(numOfSpace, ' '); /*draw the space on the left*/
		lineLength = 2*i - 1;
		chCount += drawLine(lineLength, ch);/*draw a line of the shape*/
		printf("\n"); /*approach a new line*/
	}

	return chCount;
}


int drawRectangleWithSpace(int height, int width, int space, char ch){
	int i;
	int chCount = 0; /*number of specified characters drawn*/

	for(i=0; i< height; i++){
		/*draw a line of the shape*/
		drawLine(space, ' '); /*draw the space on the left*/
		chCount += drawLine(width, ch);/*draw a line of the shape*/
		printf("\n"); /*approach a new line*/
	}
	return chCount;
}

int drawTree(int numberOfTriangles, int truckHeight, int truckWidth, char ch){
	int i;
	int chCount = 0; /*number of specified characters drawn*/
	int heightTri;	/*height of a triangle*/
	int spaceTri;	/*space on the left of a triangle*/
	int spaceRec;	/*space on the left of the rectangle*/

	/*Check input validity*/
	if(numberOfTriangles < 0)
		return NEGATIVE_NUMBER_OF_TRIANGLES;
	if(truckHeight < 0)
		return NEGATIVE_TRUCK_HEIGHT;
	if((truckWidth < 0) || (truckWidth % 2 == 0))
		return INVALID_TRUCK_WIDTH;

	/*Draw Triangles*/
	for(i = 1; i <= numberOfTriangles; i++){
		heightTri = i + 1;
		spaceTri = numberOfTriangles - i;
		chCount += drawTriangleWithSpace(heightTri, spaceTri, ch);
	}
	
	/*Draw the truck*/
	spaceRec = numberOfTriangles - truckWidth/2;
	chCount += drawRectangleWithSpace(truckHeight, truckWidth, spaceRec, ch);
	
	printf("\n"); 
	
	return chCount;
}

void printError(int errorCode){

	switch(errorCode){
	case INVALID_SOURCE:
		printf("Error: Invalid input source !!!\n");
		break;

	case INVALID_NUM_OF_TERMS:
		printf("Error: Invalid number of terms !!!\n");
		break;

	case NEGATIVE_NUMBER_OF_TRIANGLES:
		printf("Error: Negative number of triangles !!!\n");
		break;

	case NEGATIVE_TRUCK_HEIGHT:
		printf("Error: Negative truck height!!!\n");
		break;

	case INVALID_TRUCK_WIDTH:
		printf("Error: Invalid truck width!!!\n");
		break;

	default:
		printf("Unknown error code!!! Error code: %d\n", errorCode);
	}

}
