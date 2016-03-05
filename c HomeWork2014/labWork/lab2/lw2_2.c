/*##############################################################*/
/*LW2_Part2                                						*/
/*________________________                              		*/
/*Written by Evren Cifci on February 24, 2014					*/
/*                                                      		*/
/*Description:                                          		*/
/*____________                                          		*/
/*Computes the profit of a dealer								*/
/*Obtains purchase and selling information from text files and 	*/
/* outputs the profit to a text file							*/
/*Inputs:                                   					*/
/*  purchase.txt: purchase information 							*/
/*	sellings.txt: selling information							*/
/*Outputs:														*/
/*	profit.txt: prifit information								*/
/*##############################################################*/

#include<stdio.h>
#include<math.h>

double get1Term(double x, int n);

int main(void){
	FILE* purchaseF;	/*file pointer for purchase file*/
	FILE* sellingsF;	/*file ptr for sellings file*/
	FILE* profitF;			/*file ptr for profits file*/
	char itemCode;		/*code of the current item*/
	char skip;	/*a character to avoid uninterested characters in input files*/
	int countBought;	/*count of the buys in the current item*/
	int countSold;		/*count of the sells in the current item*/
	double purchasePrice; 	/* purchase price of the current item*/
	double sellingPrice;	/* selling price of the current item*/
	double profit, totalProfit = 0;		/*profit for an item and for all items*/
	
	
	/*Open files*/
	purchaseF = fopen("purchase.txt", "r");	
	sellingsF = fopen("sellings.txt", "r");
	profitF = fopen("profit.txt", "w");
	
	/*Handle item 1*/
	/*Read purchase information of an item*/
	fscanf(purchaseF, "%c%d%lf%c", &itemCode, &countBought, &purchasePrice, &skip);
	/*Read selling information of an item*/
	fscanf(sellingsF, "%c%d%lf%c", &skip, &countSold, &sellingPrice, &skip);
	/*Calculate profit for item 1*/
	profit = countSold*sellingPrice - countBought*purchasePrice;
	totalProfit += profit;
	/*Output profit*/
	fprintf(profitF, "The profit for item %c is %5.2fTL\n", itemCode, profit);
	
	
	/*Handle item 2*/
	fscanf(purchaseF, "%c%d%lf%c", &itemCode, &countBought, &purchasePrice, &skip);
	fscanf(sellingsF, "%c%d%lf%c", &skip, &countSold, &sellingPrice, &skip);
	profit = countSold*sellingPrice - countBought*purchasePrice;
	totalProfit += profit;
	fprintf(profitF, "The profit for item %c is %5.2fTL\n", itemCode, profit);
	
	/*Handle item 3*/
	fscanf(purchaseF, "%c%d%lf%c", &itemCode, &countBought, &purchasePrice, &skip);
	fscanf(sellingsF, "%c%d%lf", &skip, &countSold, &sellingPrice);
	profit = countSold*sellingPrice - countBought*purchasePrice;
	totalProfit += profit;
	fprintf(profitF, "The profit for item %c is %5.2fTL\n", itemCode, profit);
	
	/*Output total profit*/
	fprintf(profitF, "Total profit is %5.2fTL", totalProfit);
	
	
	
	/*Close files*/
	fclose(purchaseF);
	fclose(sellingsF);
	fclose(profitF);
	
	return(0);
}


