/*##########################################################################*/
/* Sample Solution HW5	Part1	                           						*/
/* ________________________                             					*/
/* Written by Evren Cifci on May 5, 2014									*/
/*                                                      					*/
/*                                                      					*/
/* Description:                                         					*/
/* ____________																*/
/* Investment Company Software												*/
/*Handles buying, selling, transaction, input, output and reporting 		*/
/*operations																*/
/*Inputs:																	*/
/*	Initials.txt: Initial amounts of investment instruments				*/
/*	Rates.txt: Prices of investment instruments							*/
/*  Operations (from console)												*/
/*Outputs:																	*/
/*	Report (both to console and text file Portfolio.txt)					*/
/*##########################################################################*/


#include<stdio.h>

#define INITIAL_FILE "Initials.txt"
#define RATE_FILE "Rates.txt"
#define REPORT_FILE "Portfolio.txt"
#define NUM_OF_INSTRUMENTS_WITH_LIRA 4
#define NUM_OF_INSTRUMENTS_WO_LIRA 3
#define TRUE 1
#define FALSE 0


/*Error Codes*/
#define INVALID_FILE_FORMAT -1
#define INVALID_PARAMETER_VALUES -2
#define INVALID_OPERATION -3
#define FILE_NOT_FOUND -4



/*##########################################################################*/
/* Gets Prices of the investment instruments from an input text file		*/
/*																			*/
/*	Input Parameters:														*/
/*	priceFile: file from which the prices are obtained						*/
/*																			*/
/*	Output Parameters:														*/
/*	dolarP: Price of 1$														*/
/*	goldP: Price of 1 unit gold 											*/
/*	foundP: Price of an investment found 									*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* 0 Normally, a negative errorCode on error								*/
/*##########################################################################*/
int getPrices(FILE* priceFile, double *dolarP, double *goldP, double *fundP);

/*##########################################################################*/
/* Gets initial amount the investment instruments from an input text file	*/
/*																			*/
/*	Input Parameters:														*/
/*	initFile: file from which the initial amounts are obtained				*/
/*																			*/
/*	Output Parameters:														*/
/*	dolarA: Amount of dolar													*/
/*	goldA: Amount of gold 													*/
/*	fundA: Amount of investment found 									*/
/*	liraA: Amount of Lira				 									*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* 0 Normally, a negative errorCode on error								*/
/*########################################################################*/
int getInitials(FILE* initFile, int *dolarA, int *goldA, int *fundA, int *liraA);

/*##########################################################################*/
/* Gets an operation from user												*/
/*																			*/
/*	Output Parameters:														*/
/*	opCode: operation code													*/
/*	operand1: first operand if available									*/
/*	operand2: second operand if available									*/
/*	operand3: third operand if available 									*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* 0 Normally, a negative errorCode on error								*/
/*########################################################################*/
int getOperation(char* opCode, char* operand1, char* operand2, int* operand3);

/*##########################################################################*/
/* Returns an amount pointer showing the given operand						*/
/*																			*/
/*	Input Parameters:														*/
/*	operand: char representation of the operand							*/
/*	*amoLira: Pointer showing the amount of Lira in the portfolio			*/
/*	*amoDolar: Pointer showing the amount of Dolar in the portfolio		*/
/*	*amoGold: Pointer showing the amount of gold in the portfolio			*/
/*	*amoFund: Pointer showing the amount of fund in the portfolio			*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Pointer showing the corresponding amount normally,						*/
/* A null pointer on error													*/
/*##########################################################################*/
int* getAmountPointer(char operand, int* amoLira, int* amoDolar, int* amoGold, int* amoFund);

/*##########################################################################*/
/* Returns the price of the given operand									*/
/*																			*/
/*	Input Parameters:														*/
/*	dolarP: The price of a dolar											*/
/*	goldP: the price of 1 unit gold										*/
/*	fundP: the price of an investment fund									*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Price of the item normally, a negative errorCode on error				*/	
/*##########################################################################*/
double getItemPrice(char operand, double dolarP, double goldP, double fundP);

/*########################################################################*/
/* Realizes a transaction operation										*/
/*																			*/
/*	Input Parameters:														*/
/*	rate: price of bought instrument / price of sold instrument			*/
/*																			*/
/*	Input/Output Parameters:												*/
/*	amoOSI: Amount of selling instrument - to be updated at each call		*/
/*	amoOBI: Amount of bought instrument - to be updated at each call 		*/									
/*	amount: Amount of operation performed - to be updated at each call 	*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/*amount of realized operation normally, a negative errorCode on error	*/
/*##########################################################################*/
int transaction(int *amoOSI, int *amoOBI, int *amount, double rate);

/*##########################################################################*/
/* Saves a report to a text file											*/
/*																			*/
/*	Input Parameters:														*/
/*	reportFile: file to which the report is saved							*/
/*	amoLira: Amount of Lira in the portfolio								*/
/*	amoDolar: Amount of Dolar in the portfolio								*/
/*	amoGold: Amount of gold in the portfolio								*/
/*	amoFund: Amount of fund in the portfolio								*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Nothing								*/
/*##########################################################################*/
void saveReport(FILE* reportFile, int amoLira, int amoDolar, int amoGold, int amoFund);

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
	
	/*amounts of instruments*/
	int amoLira,
		amoDolar,
		amoGold,
		amoFund;
		
	/*unit prices of instruments*/	
	double 	dolarP,
			goldP,
			fundP;
	
	double price; /*price of an item*/		
	
	int amount; /*amount of an operation*/
	
	char opCode; /*operation code*/
	char operand1; /*1st operand of the operation*/
	char operand2; /*2nd operand of the operation*/
	int operand3; /*3rd operand of the operation*/
			
	int continueOperations=TRUE; /* a flag to indicate the process of taking operation contnues*/
	int status; /*indicates error status of operations*/
	
	/*pointers showing the amount refered in operands */
	int *operand1Pointer, 
		*operand2Pointer;
	
	FILE* initAmoFile; /*a pointer showing the file having initial amount data*/
	FILE* ratesFile; /*a pointer showing the file having price data*/
	FILE* reportFile; /*a pointer showing the report file */

	/*END_OF_VARIABLES*/
	
	initAmoFile = fopen(INITIAL_FILE, "r");
	ratesFile = fopen(RATE_FILE, "r");
	
	/*check the existance of initial file and rates file*/
	if(!initAmoFile){
		printf("Initial amounts file does not exist!!!\n");
		return FILE_NOT_FOUND;
	}
	if(!ratesFile){
		printf("Rates file does not exist!!!\n");
		return FILE_NOT_FOUND;
	}
	
	/*Get initial amounts*/	
	status = getInitials(initAmoFile, &amoDolar, &amoGold, &amoFund, &amoLira);
	if(status){
		printError(status);
		return status;
	}
	
	/*Get prices of instruments*/
	status = getPrices(ratesFile, &dolarP, &goldP, &fundP);
	if(status){
		printError(status);
		return status;
	}
	
	while(continueOperations){
		/*Get an operation from user*/
		status = getOperation(&opCode, &operand1, &operand2, &operand3);
		if(status)
			printError(status);
		else{
			switch(opCode){
				case 'T':
				case 't':
					/*Transaction Operation*/
					
					/*get pointers showing the amounts of bought and sold items*/
					operand1Pointer = getAmountPointer(operand1, &amoLira, &amoDolar, &amoGold, &amoFund);
					operand2Pointer = getAmountPointer(operand2, &amoLira, &amoDolar, &amoGold, &amoFund);
					
					/*if 1st and 2nd operands are valid and different from each other, realize operation*/
					if((operand1Pointer) && (operand2Pointer) && (operand1Pointer != operand2Pointer))
						status = transaction(operand1Pointer, operand2Pointer, &operand3, getItemPrice(operand1, dolarP, goldP, fundP)/getItemPrice(operand2, dolarP, goldP, fundP));
					else
						status = INVALID_OPERATION;
					break;
					
				case 'B':
				case 'b':
					/*Buy Operation*/
					
					/*get pointer showing the amount of bought item*/
					operand1Pointer = getAmountPointer(operand1, &amoLira, &amoDolar, &amoGold, &amoFund);
					
					/*if the operand1 is valid realize the operation*/
					if(operand1Pointer && (operand1 != 'L') && (operand1 != 'l')){
						price = getItemPrice(operand1, dolarP, goldP, fundP);
						amount = operand3 * price; /*amount of transaction with respect to money*/
						status = transaction(&amoLira, operand1Pointer, &amount, 1/price);
					}
					else
						status = INVALID_OPERATION;
					break;
					
				case 'S':
				case 's':
					/*Sell Operation*/
					
					/*get pointer showing the amount of sold item*/
					operand1Pointer = getAmountPointer(operand1, &amoLira, &amoDolar, &amoGold, &amoFund);
					
					/*if the operand1 is valid realize the operation*/
					if(operand1Pointer && (operand1 != 'L') && (operand1 != 'l')){
						price = getItemPrice(operand1, dolarP, goldP, fundP);
						status = transaction(operand1Pointer, &amoLira, &operand3, price);
					}
					else
						status = INVALID_OPERATION;
					break;
					
				case 'I':
				case 'i':
					/*Input Operation*/
					
					/*get pointer showing the amount of input item*/
					operand1Pointer = getAmountPointer(operand1, &amoLira, &amoDolar, &amoGold, &amoFund);
					
					/*if the operand1 is valid, realize the operation*/
					if(!operand1Pointer)
						status = INVALID_OPERATION;
					else{
						*operand1Pointer += operand3;
						status = 0;
					}
					break;
					
				case 'O':
				case 'o':
					/*Output Operation*/
					
					/*get pointer showing the amount of output item*/
					operand1Pointer = getAmountPointer(operand1, &amoLira, &amoDolar, &amoGold, &amoFund);
					
					/*if the operand1is valid, realize the operation*/
					if(!operand1Pointer)
						status = INVALID_OPERATION;
					else{
						*operand1Pointer -= operand3;
						status = 0; /*operation succeeds*/
					}
						
					break;
					
				case 'F':
				case 'f':
					/*Save Operation*/
					reportFile = fopen(REPORT_FILE, "w");
					saveReport(reportFile, amoLira, amoDolar, amoGold, amoFund);
					fclose(reportFile);
					status = 0; /*operation succeeds*/
					break;
					
				case 'P':
				case 'p':
					/*Print Operation*/
					saveReport(stdout, amoLira, amoDolar, amoGold, amoFund);
					status = 0; /*operation succeeds*/
					break;
					
				case 'E':
				case 'e':
					/*Exit Operation*/
					continueOperations = FALSE;
					status = 0; /*operation succeeds*/
					break;
					
				default:
					status = INVALID_OPERATION;
			}
			
			/*if the operation fails, inform user*/
			if(status < 0)
				printError(INVALID_OPERATION);
			else
				printf("Operation is Succesful.\n");
			
		}
		
	}

	fclose(initAmoFile);
	fclose(ratesFile);
	return 0;

	/*END_OF_MAIN*/
}

int getPrices(FILE* priceFile, double *dolarP, double *goldP, double *fundP){
	char instrument;	/*instrument price of which is taken*/
	double price;			/*price of the instrument*/
	int numOfRead;		/*number of read items from file at one step*/
	/*flags indicating corresponding instruments are taken from file*/
	int dolarTaken=FALSE, goldTaken=FALSE, fundTaken=FALSE, liraTaken=FALSE;
	char skip;
	int i;
	
	for(i=0; i < NUM_OF_INSTRUMENTS_WO_LIRA; ++i){
		/*read price of an instrument*/
		numOfRead = fscanf(priceFile, " %c%c%lf", &instrument, &skip, &price);
		
		/*check if all required data exists in the file*/
		if(numOfRead < 3)
			return INVALID_FILE_FORMAT;
		
		/*update price of an instrument*/
		switch(instrument){
			case 'd':
			case 'D':
				*dolarP = price;
				dolarTaken = TRUE;
				break;
			
			case 'g':
			case 'G':
				*goldP= price;
				goldTaken = TRUE;
				break;
				
			case 'f':
			case 'F':
				*fundP = price;
				fundTaken = TRUE;	
				break;
				
			default:
				return INVALID_FILE_FORMAT;	
		}
		
	}
	
	/*check if all instruments have been read*/
	if((!dolarTaken) || (!goldTaken) || (!fundTaken))
		return INVALID_FILE_FORMAT;
	
	return 0;
}

int getInitials(FILE* initFile, int *dolarA, int *goldA, int *fundA, int *liraA){
	char instrument;	/*instrument amount of which is taken*/
	int amount;			/*amount of the instrument*/
	int numOfRead;		/*number of read items from file at one step*/
	/*flags indicating corresponding instruments are taken from file*/
	int dolarTaken=FALSE, goldTaken=FALSE, fundTaken=FALSE, liraTaken=FALSE;
	char skip;
	int i;
	
	for(i=0; i<NUM_OF_INSTRUMENTS_WITH_LIRA; ++i){
		/*read amount of an instrument*/
		numOfRead = fscanf(initFile, " %c%c%d", &instrument, &skip, &amount);
		
		/*check if all required data exists in the file*/
		if(numOfRead < 3)
			return INVALID_FILE_FORMAT;
		
		/*update amount of an instrument*/
		switch(instrument){
			case 'd':
			case 'D':
				*dolarA = amount;
				dolarTaken = TRUE;
				break;
			
			case 'g':
			case 'G':
				*goldA = amount;
				goldTaken = TRUE;
				break;
				
			case 'f':
			case 'F':
				*fundA = amount;
				fundTaken = TRUE;
				break;
				
			case 'l':
			case 'L':
				*liraA = amount;
				liraTaken = TRUE;
				break;
				
			default:
				return INVALID_FILE_FORMAT;	
		}
		
	}
	
	/*check if all instruments have been read*/
	if((!dolarTaken) || (!goldTaken) || (!fundTaken) || (!liraTaken))
		return INVALID_FILE_FORMAT;
	
	return 0;
}

int getOperation(char* opCode, char* operand1, char* operand2, int* operand3){
	/*flags that indicate the required operands*/
	int getOperand1=FALSE, getOperand2=FALSE, getOperand3=FALSE;
	
	/*Get the operation code*/
	printf("Please enter an operation code: ");
	scanf(" %c", opCode);
	
	/*Determine the required operands to be obtained from user*/
	switch(*opCode){
		case 't':
		case 'T':
			/*All 3 operands needed for transaction operation*/
			getOperand1 = TRUE;
			getOperand2 = TRUE;
			getOperand3 = TRUE;
			break;
		
		case 'b':
		case 's':
		case 'i':
		case 'o':
		case 'B':
		case 'S':
		case 'I':
		case 'O':
			/*1st and 3rd operands needed for these operations*/
			getOperand1 = TRUE;
			getOperand3 = TRUE;
			break;
			
		case 'F':
		case 'P':
		case 'E':
		case 'f':
		case 'p':
		case 'e':
			/*No operands needed, Do Nothing*/
			break;
			
		default:
			return INVALID_OPERATION;
	}
	
	/*Get operand 1 if required*/
	if(getOperand1){
		printf("Please enter the first operand: ");
		scanf(" %c", operand1);
	}
	
	/*Get operand 2 if required*/
	if(getOperand2){
		printf("Please enter the second operand: ");
		scanf(" %c", operand2);
	}
		
	/*Get operand 3 if required*/	
	if(getOperand3){
		printf("Please enter the amount of operation: ");
		scanf("%d", operand3);
		/*check the validity of amount*/
		if(*operand3 < 0)
			return INVALID_PARAMETER_VALUES;
	}
	
	/*No errors determined*/
	return 0;
}

int* getAmountPointer(char operand, int* amoLira, int* amoDolar, int* amoGold, int* amoFund){
	switch(operand){
		case 'L':
		case 'l':
			/*operand indicates TL*/
			return amoLira;
			
		case 'D':
		case 'd':
			/*operand indicates dolar*/
			return amoDolar;
			
		case 'G':
		case 'g':
			/*operand indicates gold*/
			return amoGold;
			
		case 'F':
		case 'f':
			/*operand indicates fund*/
			return amoFund;
	}

	return NULL; /*error in operand*/
 }
 
double getItemPrice(char operand, double dolarP, double goldP, double fundP){
	 switch(operand){
		case 'D':
		case 'd':
			/*operand indicates dolar*/
			return dolarP;
			
		case 'G':
		case 'g':
			/*operand indicates gold*/
			return goldP;
			
		case 'F':
		case 'f':
			/*operand indicates fund*/
			return fundP;
	}
	
	return INVALID_OPERATION;
}

int transaction(int *amoOSI, int *amoOBI, int *amount, double rate){
	
	/*check data validity*/
	if((*amoOSI < 0) || (*amoOBI < 0) || (*amount < 0) || (rate < 0))
		return INVALID_PARAMETER_VALUES;
	
	/*update operation amount if it exeeds the amount of selling item*/
	if(*amount > *amoOSI)
		*amount = *amoOSI;
	
	/*realize operation*/
	*amoOSI -= *amount;
	*amoOBI += (*amount) * rate;
	
	return *amount;
}

void saveReport(FILE* reportFile, int amoLira, int amoDolar, int amoGold, int amoFund){
	fprintf(reportFile, "L:%d\n", amoLira);
	fprintf(reportFile, "D:%d\n", amoDolar);
	fprintf(reportFile, "G:%d\n", amoGold);
	fprintf(reportFile, "F:%d\n", amoFund);
}

void printError(int errorCode){
	switch(errorCode){
		case INVALID_FILE_FORMAT:
			printf("\nError: File Format is Invalid!!!\n");
			break;
			
		case INVALID_PARAMETER_VALUES:
			printf("\nError in Operation Input: The value of a parameter is invalid.\n");
			break;
			
		case INVALID_OPERATION:
			printf("\nError in Operation Input: Operation is invalid!!! \n");
			break;
			
		default:
			printf("\nUnspecified Error!!!\n");
	}
}
