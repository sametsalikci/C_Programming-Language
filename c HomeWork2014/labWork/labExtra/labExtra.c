/*Exrta Lab Sample Solution*/
/*Preapared By Evren Cifci*/

#define FILE_NAME "Names.txt"
#define MAX_NAME_LEN 40

#define FILE_NOT_FOUND -1

#include <stdio.h>
#include <string.h>

int isElement(const int set[], int size, int element);
int getIntersection(const int set1[], int size1, const int set2[], int size2, int intersection[]);
void printSet(const int set[], int size);
int getPeople(char names[][MAX_NAME_LEN], char locations[][MAX_NAME_LEN], int sizeNames, const char location[], char people[][MAX_NAME_LEN]);
int getMostLivedCity(char names[][MAX_NAME_LEN], char locations[][MAX_NAME_LEN], int sizeNames, char people[][MAX_NAME_LEN], char mostLivedLoc[]);
int getData(char fName[], char names[][MAX_NAME_LEN], char residences[][MAX_NAME_LEN]);
void printStrArray(char strArr[][MAX_NAME_LEN], int size);

int main(void){
	int setA[] = {2, 4, 6, 8, 10, 12, 14};
	int setB[] = {3, 6, 9, 12};
	int setIntersection[10];
	int sizeIntersection;
	int numOfNames, numOfPeopleInCity;
	char names[20][MAX_NAME_LEN];
	char locations[20][MAX_NAME_LEN];
	char peopleInCity[20][MAX_NAME_LEN];
	char mostLivedCity[MAX_NAME_LEN];
	
	/*Test Part 1*/
	printf("*********************** Testing Part 1 ***************************\n");
	printf("A = ");
	printSet(setA, 7);
	printf("Search 6 in set A: %d\n", isElement(setA, 7, 6));
	printf("Search 15 in set A: %d\n", isElement(setA, 7, 15));
	
	/*Test Part 2*/
	printf("\n*********************** Testing Part 2 ***************************\n");
	
	sizeIntersection = getIntersection(setA, 7, setB, 4, setIntersection);
	printf("A = ");
	printSet(setA, 7);
	printf("B = ");
	printSet(setB, 4);
	printf("Intersection(A, B) = ");
	printSet(setIntersection, sizeIntersection);
	
	/*Test Part 3*/
	printf("\n*********************** Testing Part 3 ***************************\n");
	numOfNames = getData(FILE_NAME, names, locations);
	if(numOfNames >= 0){
		numOfPeopleInCity = getPeople(names, locations, numOfNames, "Ankara", peopleInCity);
		printf("People living in Ankara:\n");
		printStrArray(peopleInCity, numOfPeopleInCity);
		
		/*Test Bonus Part*/
		printf("\n*********************** Testing Part 3 ***************************\n");
		
		numOfPeopleInCity = getMostLivedCity(names, locations, numOfNames, peopleInCity, mostLivedCity);
		printf("Most lived city is %s.\n", mostLivedCity);
		printf("People living in this city:\n");
		printStrArray(peopleInCity, numOfPeopleInCity);
	}
	else{
		printf("File not found!!!\n");
	}
	
	return 0;
}

int isElement(const int set[], int size, int element){
	/*Base Case: Not Found*/
	if(size == 0)
		return 0;
	
	/*if found, return 1*/
	if(set[0] == element)
		return 1;
	
	/*so far not found, search in the rest part of the set*/
	return isElement(&set[1], size-1, element);
}

void printSet(const int set[], int size){
	int i;
	
	printf("{");
	if(size > 0)
		printf("%d", set[0]);
	
	for(i=1; i<size; ++i)
		printf(", %d", set[i]);
	
	printf("}\n");
}

int getIntersection(const int set1[], int size1, const int set2[], int size2, int intersection[]){
	int sizeIntersection;
	
	/*Base Case*/
	if(size1 < 0)
		return 0;
	
	/*search each element of set1 in set2 recursively*/
	sizeIntersection = getIntersection(&set1[1], size1-1, set2, size2, intersection);
	
	/*if 1st element of set 1 found in set2, add it to the intersection*/
	if(isElement(set2, size2, set1[0])){
		intersection[sizeIntersection] = set1[0];
		++sizeIntersection;
	}
	
	return sizeIntersection;
}

int getPeople(char names[][MAX_NAME_LEN], char locations[][MAX_NAME_LEN], int sizeNames, const char location[], char people[][MAX_NAME_LEN]){
	int i;
	int j=0;
	
	for(i=0; i<sizeNames; ++i){
		if(!strcmp(locations[i], location)){
			strcpy(people[j], names[i]);
			++j;	
		}
	}
	
	return j;
}


int getData(char fName[], char names[][MAX_NAME_LEN], char residences[][MAX_NAME_LEN]){
	FILE* file;
	int status=2; /*status indicating if end of file reached*/
	int row=0;	/*row numner of the string arrays*/
	
	file = fopen(fName, "r");
	if(file == NULL)
		return FILE_NOT_FOUND;
	
	while(status == 2){
		status = fscanf(file, "%s%s", names[row], residences[row]);
		++row;
	}
	
	fclose(file);
	return row-1;	
}

void printStrArray(char strArr[][MAX_NAME_LEN], int size){
	int i;
	for(i=0; i<size; ++i)
		printf("%s\n", strArr[i]);
}

int getMostLivedCity(char names[][MAX_NAME_LEN], char locations[][MAX_NAME_LEN], int sizeNames, char people[][MAX_NAME_LEN], char mostLivedLoc[]){
	int mostLived;/*index of most lived city*/
	int peopleC=0; /*number of people living in the most lived city*/
	int peopleCTemp; /*temporary people count*/
	char peopleTemp[20][MAX_NAME_LEN];
	int i, j;
	
	
	for(i=0; i<sizeNames; ++i){
		peopleCTemp = getPeople(names, locations, sizeNames, locations[i], peopleTemp);
		if(peopleCTemp > peopleC){
			peopleC = peopleCTemp;
			mostLived = i;
			for(j=0; j<peopleCTemp; ++j)
				strcpy(people[j], peopleTemp[j]);
		}		
	}
	
	strcpy(mostLivedLoc, locations[mostLived]);
	return peopleC;
}
