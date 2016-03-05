/*##########################################################*/
/*Sample Solution HW1  Part3                            	*/
/*________________________                              	*/
/*Written by Evren Cifci on March 11, 2014					*/
/*                                                      	*/
/*                                                      	*/
/*Description:                                          	*/
/*____________                                          	*/
/*Calculates unit price of some items given their cumulative*/
/*		total costs											*/
/*Inputs:                                   				*/
/*  Cumulative total costs from text file Buys.txt			*/
/*Outputs:													*/
/*	Unit prices (to console and to UnitPrices.txt)			*/
/*##########################################################*/

#include<stdio.h>

#define BUYS_FILE "Buys.txt"
#define U_PRICES_FILE "UnitPrices.txt"

int main(){
	/*START_OF_MAIN*/
	/*codes of items*/
	int itemCode1, itemCode2, itemCode3, itemCode4;
	
	/*unit prices*/
	double uP1, uP2, uP3, uP4;
	
	int amo; /*the buyying amount of the current item*/
	double total; /*total price of items considered so far*/
	double totalOld = 0; /*old value of total - last item not considered*/
	
	FILE* buyF = fopen(BUYS_FILE, "r"); /*input file holding buying info*/
	FILE* uPF = fopen(U_PRICES_FILE, "w");/*out file holding unit prices*/
	/*END_OF_VARIABLES*/
	
	/*Get total costs & amounts from file and calculate unit prices*/
	/*calculation for item1*/
	/*get total price and amount*/ 
	fscanf(buyF, "%d%d%lf", &itemCode1, &amo, &total); 
	uP1 = (total - totalOld)/amo; /*calculate unit price 1*/
	totalOld = total; /*update old total price*/
	
	/*calculation for item2*/
	fscanf(buyF, "%d%d%lf", &itemCode2, &amo, &total);
	uP2 = (total - totalOld)/amo;
	totalOld = total;
	
	/*calculation for item3*/
	fscanf(buyF, "%d%d%lf", &itemCode3, &amo, &total);
	uP3 = (total - totalOld)/amo;
	totalOld = total;
	
	/*calculation for item4*/
	fscanf(buyF, "%d%d%lf", &itemCode4, &amo, &total);
	uP4 = (total - totalOld)/amo;
	
	/*Output unit prices*/
	printf("The unit price of the item %d is %dTL and %d Kurus.\n", itemCode1, (int)uP1, (int)(uP1*100)%100);
	fprintf(uPF, "%d\t%.2f\n", itemCode1, uP1);
	printf("The unit price of the item %d is %dTL and %d Kurus.\n", itemCode2, (int)uP2, (int)(uP2*100)%100);
	fprintf(uPF, "%d\t%.2f\n", itemCode2, uP2);
	printf("The unit price of the item %d is %dTL and %d Kurus.\n", itemCode3, (int)uP3, (int)(uP3*100)%100);
	fprintf(uPF, "%d\t%.2f\n", itemCode3, uP3);
	printf("The unit price of the item %d is %dTL and %d Kurus.\n", itemCode4, (int)uP4, (int)(uP4*100)%100);
	fprintf(uPF, "%d\t%.2f\n", itemCode4, uP4);
	
	fclose(buyF);
	fclose(uPF);
	return 0;
	
	/*END_OF_MAIN*/
}
