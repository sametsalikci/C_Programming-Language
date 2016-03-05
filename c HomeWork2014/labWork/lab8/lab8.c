#include<stdio.h>
#include<stdlib.h>

#define maxSize 100

void createArray(int[], int*);
void printArray(int[], int);
int searchAfter(int[], int, int, int);
void findSubsequence(int[], int, int, int*, int*);
void findScores(int[], int[], int, int, int[], int*);

int main()
{
	int array[maxSize], size, num1, num2, num3;
	/*TEST FOR PART 1*/
	createArray(array, &size);
	printArray(array, size);
	/*END OF TEST FOR PART 1*/

	/*TEST FOR PART 2*/
	num1=2;
	num2=4;
	printf("Searching %d after %d...\n", num1, num2);
	if((num3=searchAfter(array, size, num1, num2))==-1)
		printf("Not found!\n");
	else
		printf("The index is: %d \n",num3);
	/*END OF TEST FOR PART 2*/

	/*TEST FOR PART 3*/
	printf("Searching for max subsequence between %ds\n", num1);
	findSubsequence(array, size, num1, &num2, &num3);
	if(num2==-1)
		printf("There is no subsequence between %d\n",num1);
	else
		printf("Start and end indexes of the max subsequence are %d and %d\n", num2, num3);
	/*END OF TEST FOR PART 3*/

	/*TEST FOR PART 4*/
	int numbers[maxSize], scores[maxSize], results[maxSize];
	num2=50;
	printf("Enter student numbers:\n");
	createArray(numbers, &size);
	printf("Enter student scores:\n");
	createArray(scores, &num1);
	printf("Searching for students with the score %d...\n",num2);
	findScores(numbers, scores, size, num2, results, &num3);
	printf("Results are:\n");
	printArray(results, num3);
	/*END OF TEST FOR PART 4*/

	return 0;
}

void createArray(int arr[], int *size)
{
	int indx=-1;

	do
	{
		indx++;
		printf("Enter a number (enter 1- to end):\n");
		scanf("%d",&arr[indx]);
	}while(arr[indx]!=-1);
	(*size)=indx;
}

void printArray(int arr[], int size)
{
	int i;

	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int searchAfter(int arr[], int size, int toSearch, int after)
{
	int i;

	if(after>=size)
		return -1;

	for(i=after;i<size;i++)
	{
		if(arr[i]==toSearch)
			return i;
	}
	return -1;
}

void findSubsequence(int arr[], int size, int toSearch, int *start, int *end)
{
	int i, j, total, maxTotal=0;

	(*start)=-1;
	(*end)=-1;

	for(i=0;i<size-1;i++)
	{
		if(arr[i]==toSearch)
		{
			total=0;
			for(j=i+1;j<size;j++)
			{
				if(arr[j]!=toSearch)
					total+=arr[j];
				else
					if(total>maxTotal)
					{
						maxTotal=total;
						(*start)=i;
						(*end)=j;
					}
			}
		}
	}
}

void findScores(int numbers[], int scores[], int size, int toSearch, int searchResults[], int *resultSize)
{
	int i;
	(*resultSize)=0;

	for(i=0;i<size;i++)
	{
		if(scores[i]==toSearch)
		{
			searchResults[*resultSize]=numbers[i];
			(*resultSize)++;
		}
	}
}
