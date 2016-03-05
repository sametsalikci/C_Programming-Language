/*##########################################################################*/
/* Sample Solution LW7		                           						*/
/* ________________________                             					*/
/* Written by Evren Cifci on March 29, 2014								*/
/*                                                      					*/
/*                                                      					*/
/* Description:                                         					*/
/* ____________                                         					*/
/*Finds the minimum element of an integer array according to:				*/
/*	-usual minimum															
 * 	-minimum of the negatives
 * 	-minimum of the squares
 * 
 * Realizes a simple implementation of purchase and selling operations on
 * dolar, euro and gold														*/
/*##########################################################################*/


#include<stdio.h>


#define CAPACITY 20

/*Unit Prices*/
#define GOLD_UP 90		
#define DOLAR_UP 2.2
#define EURO_UP 3

#define INCREASE 1
#define DECREASE -1

/*Error Codes*/
#define INVALID_OPERATION_ERROR -1
#define INVALID_INSTRUMENT_ERROR -2

typedef enum{GOLD, DOLAR, EURO}instrument_type;
typedef enum{BUY, SELL}operation_type; 


/*##########################################################################*/
/* Finds the minimum element and its index in an integer array				*/
/*																			*/
/*	arr: array to be searched for minimum                             	*/
/*	size:size of the array													*/
/*	min_index(output): index of the minimum element							*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Value of the minimum element											*/
/*##########################################################################*/
int get_minimum(int arr[], int size, int *min_index);

/*##########################################################################*/
/* Finds the minimum element and its index in an integer array with 		*/
/* respect to a given comperator function 									*/
/*																			*/
/*	arr: array to be searched for minimum                             	*/
/*	size:size of the array													*/
/*	is_lower: a comperator function that returns 							*/
/* 		non-zero if first argument is lower than the second one			*/ 
/* 		zero otherwise														*/
/*	min_index(output): index of the minimum element							*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Value of the minimum element											*/
/*##########################################################################*/
int get_defined_minimum(int arr[], int size, int is_lower(int u1, int u2),int* min_index);


/*##########################################################################*/
/* A function that compares the values of u1 and u2                   	*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* 1 if u1<u2 and 0 otherwise  											*/
/*																			*/
/*##########################################################################*/
int is_lower_usual(int u1, int u2);

/*##########################################################################*/
/* A function that compares the negative values of u1 and u2             	*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* 1 if -u1 < -u2 and 0 otherwise 											*/
/*																			*/
/*##########################################################################*/
int is_lower_negative(int u1, int u2);

/*##########################################################################*/
/* A function that compares the squared values of u1 and u2              	*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* 1 if u1*u1 < u2*u2 and 0 otherwise										*/
/*																			*/
/*##########################################################################*/
int is_lower_square(int u1, int u2);

/*##########################################################################*/
/* Gets initial amounts of gold, dolar, euro and TL in the portfolio     */
/*																			*/
/*	Output Arguments:         												*/
/*	   gold: amount of gold in the portfolio								*/
/*	   dolar: amount of dolar in the portfolio								*/
/*	   euro: amount of euro in the portfolio								*/
/*	   tl: amount of tl in the portfolio									*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Nothing																	*/
/*##########################################################################*/
void get_initials(int *gold, int *dolar, int *euro, int *tl);

/*########################################################################*/
/* Makes buying and selling operations on gold, dolar and euro.			*/ 
/*																			*/
/*	Input Parameters:														/*
/*		op: type of operation												*/
/*		inst: type of instrument											*/
/*  	amoOfOp: amount of operation										*/
/*  Input/Output Parameters:												*/
/*  	amoGold: Current amount of gold (to be updated)					*/
/*  	amoDolar: Current amount of dolar (to be updated)					*/
/*  	amoEuro: Current amount of euro (to be updated)					*/
/*  	amoTL: Current amount of TL (to be updated)						*/
/*																			*/
/*	Returns																	*/
/*	____________															*/
/*	0	normaly, a negative errorcode on error								*/	
/*																			*/
/*########################################################################*/
int make_operation(operation_type op, instrument_type inst, int amoOfOp, 
	int *amoGold, int *amoDolar, int *amoEuro , int *amoTL);

/*##########################################################################*/
/* Prints the content of the current portfolio								*/
/*																			*/
/*	gold: Amount of gold in the portfolio									*/
/*	dolar: Amount of dolar in the portfolio								*/
/*	euro: Amount of euro in the portfolio									*/
/*	tl: Amount of TL in the portfolio										*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Nothing																	*/
/*##########################################################################*/
void report(int gold, int dolar, int euro, int tl);


int main(){
	int i;
	int size;
	int arr[CAPACITY];
	int min;
	int min_index;
	int gold, dolar, euro, tl;
	
	/*get an array to test part 1-2*/
	printf("Enter the size of the array:");
	scanf("%d", &size);
	
	/*check that the size is not grater than the capacity*/
	if(size > CAPACITY){
		size = CAPACITY;
		printf("Size cannot be grater than %d!!! Size is %d.\n", CAPACITY, CAPACITY);
	}
	
	printf("Array: ");
	for(i=0; i<size; i++)
		scanf("%d", &arr[i]);
	
	/*Part 1*/
	printf("\nTesting Part 1:\n");
	min = get_minimum(arr, size, &min_index);
	printf("Minimum element is %d. It is at %dth place in the array.\n", min, min_index);
	
	/*PART 2*/
	printf("\nTesting Part 2:\n");
	/*with usual min*/
	min = get_defined_minimum(arr, size, is_lower_usual, &min_index);
	printf("With respect to the usual minimum, minimum element is %d. It is at %dth place in the array.\n", min, min_index);
	
	/*with negative min*/
	min = get_defined_minimum(arr, size, is_lower_negative, &min_index);
	printf("With respect to the negative minimum, minimum element is %d. It is at %dth place in the array.\n", min, min_index);
	
	/*with squred min*/
	min = get_defined_minimum(arr, size, is_lower_square, &min_index);
	printf("With respect to the squared minimum, minimum element is %d. It is at %dth place in the array.\n", min, min_index);
	
	/*Part 3*/
	printf("\nTesting Part 3:\n");
	get_initials(&gold, &dolar, &euro, &tl);
	make_operation(BUY, DOLAR, 100, &gold, &dolar, &euro, &tl);
	make_operation(SELL, GOLD, 20, &gold, &dolar, &euro, &tl);
	make_operation(SELL, EURO, 300, &gold, &dolar, &euro, &tl);
	report(gold, dolar, euro, tl);
	
	return 0;
}

int get_minimum(int arr[], int size, int *min_index){
	int i;
	int min_so_far;
	
	/*initialize min to the 1st element*/
	min_so_far = arr[0];
	*min_index = 0;
	
	/*check other elements*/
	for(i = 1; i < size; i++){
		if(arr[i] < min_so_far){
			/*a smaller element is found, update min_so_far*/
			min_so_far = arr[i];
			*min_index = i;
		}
	}
	
	return min_so_far;
}
		

int get_defined_minimum(int arr[], int size, int is_lower(int u1, int u2), int *min_index){
	int i;
	int min_so_far;
	
	/*initialize min to the 1st element*/
	min_so_far = arr[0];
	*min_index = 0;
	
	/*check other elements*/
	for(i = 1; i < size; i++){
		if(is_lower(arr[i], min_so_far)){
			/*a smaller element is found, update min_so_far*/
			min_so_far = arr[i];
			*min_index = i;
		}
	}
	
	return min_so_far;
}

int is_lower_usual(int u1, int u2){
	return (u1 < u2);
}

int is_lower_negative(int u1, int u2){
	return (-u1 < -u2);
}

int is_lower_square(int u1, int u2){
	return (u1*u1 < u2*u2);
}

void get_initials(int *gold, int *dolar, int *euro, int *tl){
	printf("Enter the initial amounts of gold, dolar, euro and tl:\n");
	scanf("%d%d%d%d", gold, dolar, euro, tl);
}

int make_operation(operation_type op, instrument_type inst, int amoOfOp, 
	int *amoGold, int *amoDolar, int *amoEuro , int *amoTL){
		
	int cost; /*cost of the operation with respect to TL*/
	int instrument_multiplier;
	int tl_multiplier;
	
	if(op == BUY){
		/*increase investment instrument, decrease TL*/
		instrument_multiplier = INCREASE;
		tl_multiplier = DECREASE;
	}
	else if(op == SELL){
		/*increase TL, decrease investment instrument*/
		instrument_multiplier = DECREASE;
		tl_multiplier = INCREASE;	
	}
	else
		return INVALID_OPERATION_ERROR;
		
		
	switch(inst){
		case GOLD:
			/*buy or sell gold*/
			cost = GOLD_UP * amoOfOp; /*cost of operation*/
			*amoTL += tl_multiplier * cost; /*change amount of TL*/
			*amoGold += instrument_multiplier * amoOfOp; /*change amount of gold*/
			break;
		case DOLAR:
			/*buy or sell dolar*/
			cost = DOLAR_UP * amoOfOp;
			*amoTL += tl_multiplier * cost;
			*amoDolar += instrument_multiplier * amoOfOp;
			break;
		case EURO:
			/*buy or sell euro*/
			cost = EURO_UP * amoOfOp;
			*amoTL += tl_multiplier * cost;
			*amoEuro += instrument_multiplier * amoOfOp;
			break;
	}
	
	return 0;
}

void report(int gold, int dolar, int euro, int tl){
	printf("\nContent of the portfolio:\n");
	printf("\tGold:\t%d\n", gold);
	printf("\tDolar:\t%d\n", dolar);
	printf("\tEuro:\t%d\n", euro);
	printf("\tTL:\t%d\n\n", tl);
}
