/*##########################################################################*/
/* Sample Solution LW4		                           						*/
/* ________________________                             					*/
/* Written by Evren Cifci on March 11, 2014									*/
/*                                                      					*/
/*                                                      					*/
/* Description:                                         					*/
/* ____________                                         					*/
/* Calculates number of days between 2 given dates							*/
/* Inputs:                                   								*/
/*  2 Dates (console)														*/
/* Outputs:																	*/
/*	Number of days between dates (console)									*/
/*																			*/
/* Notes																	*/
/* _____																	*/
/*	1. Applies leap year regulations of extending February 1 more day		*/
/*		 if and only if the (currentYear % 4 == 0) and neglects all other	*/
/*		 regulations														*/
/*##########################################################################*/


#include<stdio.h>

/*Error Codes*/
#define INVALID_DAY -1
#define INVALID_MONTH -2
#define WRONG_DATE_ORDER -3 


/*##########################################################################*/
/* Genertes number of days a given month has								*/
/*																			*/
/*	month: month of the given year for which the output is generated		*/
/*	year: year of the input month											*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Number of days	on success												*/
/* a negative error code on error											*/
/*##########################################################################*/
int numberOfDays(int month, int year);

/*##########################################################################*/
/* Calculates number of days remains in the current month after a specified */
/*		date																*/
/*																			*/
/*	day	: day of the given date												*/
/*	month: month of the given date 											*/
/*	year: year of the given date											*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Number of remaining days	on success										*/
/* a negative error code on error											*/
/*##########################################################################*/
int remainingDays(int day, int month, int year);

/*##########################################################################*/
/* Calculates number of days between 2 given dates in the same year			*/
/*																			*/
/*	day1: day of the 1st date												*/
/*	month1: month of the 1st date											*/
/*	day2: day of the 2nd date												*/
/*	month2: month of the 2nd date											*/
/*	year: year of the both dates											*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Number of days	on success												*/
/* a negative error code on error											*/
/*##########################################################################*/
int daysBtwDatesInAYear(int day1, int month1, int day2, int month2, int year);

/*##########################################################################*/
/* Calculates number of days between 2 given dates      					*/
/*																			*/
/*	day1: day of the 1st date												*/
/*	month1: month of the 1st date											*/
/*	year1: year of the 1st date												*/
/*	day2: day of the 2nd date												*/
/*	month2: month of the 2nd date											*/
/*	year2: year of the 2nd date												*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Number of days	on success												*/
/* a negative error code on error											*/
/*##########################################################################*/
int daysBtwDates(int day1, int month1, int year1, int day2, int month2, int year2);

/*########################################################################*/
/* Checks the validation of a date											*/
/*																			*/
/*	day: day of the date													*/
/*	month: month of the date												*/
/*  year: year of the date													*/
/*	Returns																	*/
/*	____________															*/
/*	0 normally																*/	
/*	A negative error code on error											*/
/*########################################################################*/
int checkDateValidation(int day, int month, int year);

/*##########################################################################*/
/* Prints errors															*/
/*																			*/
/*	errCode: Code of the error												*/
/*																			*/
/* Returns																	*/
/* _______																	*/
/* Nothing																	*/
/*##########################################################################*/
void printError(int errCode);


int main(){
	int days;
	
	days = numberOfDays(2, 2016);
	if(days < 0)
		printError(days);
	else
		printf("February 2016 has %d days.\n", days);
	
	days = remainingDays(5, 3, 2012);
	if(days < 0)
		printError(days);
	else
		printf("There are %d days until the end of the month at 5 March, 2012.\n", days);
	
	days = daysBtwDatesInAYear(2, 1, 3, 6, 2012);
	if(days < 0)
		printError(days);
	else
		printf("There are %d days between 2 January and 3 June in 2012.\n", days);
	
	days = daysBtwDates(2, 1, 2000, 5, 2, 2018);
	if(days < 0)
		printError(days);
	else
		printf("There are %d days between 2, January 2000 and 5 February 2018.\n", days);
	
	days = daysBtwDates(29, 2, 2011, 5, 3, 2015);
	if(days < 0)
		printError(days);
	else
		printf("%d days exists.\n", days);
	
	days = daysBtwDates(1, 2, 2005, 2, 1, 2005);
	if(days < 0)
		printError(days);
	else
		printf("%d days exists.\n", days);
	
	return 0;
}

int numberOfDays(int month, int year){
	
	switch(month){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		/*has 31 days*/
		return 31;	/*because function ends, break not required*/
	case 4:
	case 6:
	case 9:
	case 11:
		/*has 30 days*/
		return 30;
	case 2:
		/*month is february; has 28 or 29 days depending on the year*/
		if(year%4 == 0)
			return 29;
		else
			return 28;
	}
	
	return INVALID_MONTH;
}
			
int remainingDays(int day, int month, int year){
	int numOfDays = numberOfDays(month, year);
	if(numOfDays < 0)
		return numOfDays; /*return the same error code on error*/
	/*check validity of day*/	
	if((day <= 0) || (day > numOfDays))
		return INVALID_DAY;
	
	return numOfDays-day; /*no error*/
}


	
int daysBtwDatesInAYear(int day1, int month1, int day2, int month2, int year){
		
	int i;
	int totalDays = 0; 
	
	if(month1 == month2){ /*dates are in the same month*/
		if(day2 < day1)
			return WRONG_DATE_ORDER;
		return day2-day1;
	}
	else if(month2 > month1){ /*dates are in different months*/
		/*days in the months between*/
		for(i=month1+1; i<month2; i++)
			totalDays += numberOfDays(i, year);
	}
	else
		return WRONG_DATE_ORDER;
	
	/*add remaining days of the first date to the new month and the days in the 
	 month of the second date*/
	totalDays = totalDays + remainingDays(day1, month1, year) + day2;
	return totalDays;
}
	
	
int daysBtwDates(int day1, int month1, int year1, int day2, int month2, int year2){	
	int totalDays = 0;
	int i;
	int errCode;
	
	/*check date validations individually*/
	errCode = checkDateValidation(day1, month1, year1);
	if(errCode < 0)
		return errCode;
	
	errCode = checkDateValidation(day2, month2, year2);
	if(errCode < 0)
		return errCode;
	
	if(year2<year1)
		return WRONG_DATE_ORDER;
	else if(year2 == year1) 
		/*dates in the same year, daysBtwDatesInAYear handles the calculation*/
		return daysBtwDatesInAYear(day1, month1, day2, month2, year1);
	else{	/*years are different*/
		/*calculate the days in the years between*/
		for(i = year1+1; i<year2; ++i){
			if(i%4 == 0)
				totalDays += 366;
			else
				totalDays += 365;
		}
		/*add the days in the year of the first date*/
		totalDays += daysBtwDatesInAYear(day1, month1, 31, 12, year1);
		/*add the days in the year of the second date*/
		totalDays += daysBtwDatesInAYear(1, 1, day2, month2, year2);
		totalDays += 1; /*add the day btw 31 Dec - 1 Jan*/
		return totalDays;	
	}
}

int checkDateValidation(int day, int month, int year){
	
	/*check validity of month*/
	if((month > 12) || (month < 0))
		return INVALID_MONTH;
	
	/*check validity of day*/
	if((day > numberOfDays(month, year)) || (day<0))
		return INVALID_DAY;
	
	/*normally*/
	return 0;
}

void printError(int errCode){
	switch(errCode){
		
		case INVALID_DAY:
			printf("\nError: Day is invalid!!!\n");
			break;
			
		case INVALID_MONTH:
			printf("\nError: Month is Invalid!!!\n");
			break;
			
		case WRONG_DATE_ORDER:
			printf("\nDate order is wrong!!!\n");
			break;
			
		default:
			printf("\nAn Unhandled Error Happened!!!\n");
			break;
	}
}
		










