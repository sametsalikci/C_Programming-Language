/*
	LAB WORK 10

	author	 	:	Sinan NAR
	mail		:	sinan.nar@gmail.com
	test code modified by Evren Cifci

*/

# define MAX_COL 10

/*Includes*/
#include <stdio.h>
#include <string.h>

/*Prototypes*/
/* PART 1 */	
void printStr(char str[]);
int printReverseStr(char str[]);

/* PART 2 */	
int cmpStrRec(char str1[],char str2[]);

/* PART 3 */	
char* getElement(char strArr[][MAX_COL],char str[],int size);

/* BONUS PARTs */	
int findAndReplace(char strArr[][MAX_COL],char str[],char replace[],int size);

/*Auxilary Functions*/
void printStrArray(char strArr[][MAX_COL], int size);
int deleteElementPrintStatus(char strArr[][MAX_COL], int size, char deleteStr[]);

/*Main*/
int main(){

	char strArr[][MAX_COL]={"Computer","Pencil","Pencil","Pen","Book","Bag","Pencil","Mouse","Book","Pencil"};
	int numOfOpeations;
	
	printf("**************** Testing Part 1 *********************\n");
	printStr("Sinan");
	printf("\n");
	printReverseStr("Sinan");
	printf("\n");
	
	/*printf("\n*************** Testing Part 2 *****************");
	
	printf("\nAli - Ala: ");
	printf("\t%d", cmpStrRec("Ali", "Ala"));
	
	printf("\nAli - Ali: ");
	printf("\t%d", cmpStrRec("Ali", "Ali"));
	
	printf("\nAli - Alican ");
	printf("\t%d", cmpStrRec("Ali", "Alican"));
	printf("\n");
	
	
	printf("\n*************** Testing Part 3 ******************\n");
	printf("Initial String Array:\n");
	printStrArray(strArr, 10);
	
	printf("\nDeleting Pencil\n");
	deleteElementPrintStatus(strArr, 10, "Pencil");
	printf("\nString Array After Deletion\n"); 
	printStrArray(strArr, 10);
	
	printf("\nDeleting Train\n");
	deleteElementPrintStatus(strArr, 10, "Train");
	printf("\nString Array After Deletion\n"); 
	printStrArray(strArr, 10);

	printf("\n*****************Testing Bonus Part ********************");
	printf("\nReplacing all occurances of \"Pencil\" with \"***\"");
	numOfOpeations = findAndReplace(strArr,"Pencil","***",10);
	printf("\nString Array After Find & Replace Operatin\n"); 
	printStrArray(strArr, 10);
	printf("\n%d Operations Has Been Performed.\n", numOfOpeations);*/

	return 0;
}

/*Implementation Details*/
void printStr(char str[]){
	if(str[0]!='\0'){
		printf("%c",str[0]);
		printStr(&str[1]);
	}
}

int printReverseStr(char str[]){
	
	int size = 0;
	if(str[0]!='\0'){
		size = printReverseStr(&str[1]);
		printf("%c",str[0]);
		size++;
	}
	return size;
}

int cmpStrRec(char str1[],char str2[]){
	if(str1[0]=='\0' && str2[0]=='\0')
		return 0;
	else if(str1[0]==str2[0])
		return cmpStrRec(&str1[1],&str2[1]);
	else
		return 1;

}

char* getElement(char strArr[][MAX_COL],char str[],int size){
	if(size>0){
		if(cmpStrRec(strArr[0],str)==0)
			return strArr[0];
		else
		{
			return getElement(&strArr[1],str,size-1);
		}
	}
	else
		return NULL;
}

int findAndReplace(char strArr[][MAX_COL],char str[],char replace[],int size){
	char* cPtr = getElement(strArr,str,size);
	int i = 0;
	if(cPtr != NULL){
		strcpy(cPtr,replace);
		i = findAndReplace(strArr,str,replace,size);
		i++;
	}
	return i;
}


void printStrArray(char strArr[][MAX_COL], int size){
	int i;
	
	if(size == 0)
		return;
	
	printf("%s\n", strArr[0]);
	printStrArray(&strArr[1], size-1);

}

int deleteElementPrintStatus(char strArr[][MAX_COL], int size, char deleteStr[]){
	
	char *deletionRow = getElement(strArr, deleteStr, size);
	
	if(deletionRow == NULL){
		printf("Element does not exist!\n");
		return 0;
	}
	
	*deletionRow = '\0';
	printf("Element Deleted!!!!\n");
	return 1;
}
char*getlast(char str[],char ch)
{
	char *ans = NULL;

	if(str[0]==ch)
	{

		*ans = str[0];

		getlast(&str[1],ch);
	}
	else
	{

		getlast(&str[1],ch);
	}
	return ans;
}
