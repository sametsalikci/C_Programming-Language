#include<stdio.h>
#include<stdlib.h>

#define maxSize 100

void read1D(FILE*, int[], int*);
void read2D(FILE*, int[][maxSize], int*, int*);
int isUnit(int[][maxSize], int, int);
int isSorted1D(int[], int);
int isSorted2D(int[][maxSize], int, int);
void sort1D(int[], int);
void sort2D(int[][maxSize], int, int);
int searchSorted1D(int[], int, int);
int searchSorted2D(int[][maxSize], int, int, int, int*);

int main()
{
	FILE *f;
	int sizeR, sizeC, array1D[maxSize], array2D[maxSize][maxSize],i,j,num;

	/*TEST FOR PART 1*/
	f=fopen("integers.txt","r");
	read1D(f,array1D,&sizeC);
	printf("\n 1-D Array:\n");
	for(i=0;i<sizeC;i++)
		printf("%d ",array1D[i]);
	fclose(f);
	/*-------------------------------------------*/
	f=fopen("integers.txt","r");
	read2D(f, array2D, &sizeR, &sizeC);
	printf("\n\n 2-D Array:\n");
	for(i=0;i<sizeR;i++)
	{
		for(j=0;j<sizeC;j++)
			printf("%d ",array2D[i][j]);
		printf("\n");
	}
	fclose(f);
	/*END OF TEST FOR PART 1*/

	/*TEST FOR PART 2*/
	f=fopen("unit.txt","r"); /*(try with nonunit.txt)*/
	read2D(f, array2D, &sizeR, &sizeC);
	if(isUnit(array2D, sizeR, sizeC)==1)
		printf("\nthe file represents an unit matrix");
	else
		printf("\nthe file does not represent an unit matrix");
	fclose(f);
	/*-------------------------------------------*/
	f=fopen("sorted.txt","r"); /*(try with unsorted.txt)*/
	read1D(f, array1D, &sizeC);
	if(isSorted1D(array1D, sizeC)==1)
		printf("\nthe file represents a sorted array");
	else
		printf("\nthe file does not represent a sorted array");
	fclose(f);
	/*-------------------------------------------*/
	f=fopen("sorted2D.txt","r"); /*(try with unsorted2D.txt)*/
	read2D(f, array2D, &sizeR, &sizeC);
	if(isSorted2D(array2D, sizeR, sizeC)==1)
		printf("\nthe file represents a matrix with sorted rows");
	else
		printf("\nthe file represent a matrix with unsorted rows");
	fclose(f);
	/*END OF TEST FOR PART 2*/

	/*TEST FOR PART 3*/
	f=fopen("unsorted.txt","r");
	read1D(f, array1D, &sizeC);
	printf("\n\n 1-D Array before sorting:\n");
	for(i=0;i<sizeC;i++)
		printf("%d ",array1D[i]);
	sort1D(array1D, sizeC);
	printf("\n 1-D Array after sorting:\n");
	for(i=0;i<sizeC;i++)
		printf("%d ",array1D[i]);
	fclose(f);
	/*-------------------------------------------*/
	f=fopen("unsorted2D.txt","r");
	read2D(f, array2D, &sizeR, &sizeC);
	printf("\n\n 2-D Array before sorting:\n");
	for(i=0;i<sizeR;i++)
	{
		for(j=0;j<sizeC;j++)
			printf("%d ",array2D[i][j]);
		printf("\n");
	}
	sort2D(array2D, sizeR, sizeC);
	printf("\n 2-D Array after sorting:\n");
	for(i=0;i<sizeR;i++)
	{
		for(j=0;j<sizeC;j++)
			printf("%d ",array2D[i][j]);
		printf("\n");
	}
	fclose(f);
	/*END OF TEST FOR PART 3*/

	/*TEST FOR PART 4*/
	num=2;
	f=fopen("sorted.txt","r"); /*(try with unsorted.txt)*/
	read1D(f, array1D, &sizeC);
	printf("\nThe number to search is %d.\n",num);
	if((i=searchSorted1D(array1D, sizeC, num))==-1)
		printf("\ncannot find the number");
	else
		printf("\nthe number is found and the index is %d",i);
	fclose(f);
	/*-------------------------------------------*/
	f=fopen("sorted2D.txt","r"); /*(try with unsorted2D.txt)*/
	read2D(f, array2D, &sizeR, &sizeC);
	if((i=searchSorted2D(array2D, sizeR, sizeC, num, &j))==-1)
			printf("\ncannot find the number");
		else
			printf("\nthe number is found, the row is %d and the index is %d",j, i);
	fclose(f);
	/*END OF TEST FOR PART 4*/

	return 0;
}

void read1D(FILE *fptr, int arr[],int *size)
{
	*size=0;
	char check;
	int status;

	do
	{
		status=fscanf(fptr,"%d%c",&arr[*size],&check);
		(*size)++;
	}while(check!='\n' || status==EOF);
}

void read2D(FILE *fptr, int arr[][maxSize], int *sizeRow, int *sizeCol)
{
	int colCount=0;
	char check;
	*sizeRow=0;
	*sizeCol=0;

	while(fscanf(fptr,"%d%c",&arr[*sizeRow][*sizeCol],&check)!=EOF)
	{
		if(check=='\n')
		{
			(*sizeRow)++;
			colCount=*sizeCol;
			(*sizeCol)=0;
		}
		else
			(*sizeCol)++;
	}
	(*sizeCol)=colCount+1;
}

int isUnit(int arr[][maxSize], int sizeR, int sizeC)
{
	int i,j;

	if(sizeR!=sizeC)
		return 0;

	for(i=0;i<sizeR;i++)
	{
		for(j=0;j<sizeC;j++)
			if((i==j && arr[i][j]!=1) || (i!=j && arr[i][j]!=0))
				return 0;
	}
	return 1;
}

int isSorted1D(int arr[], int size)
{
	int i;

	for(i=0;i<size-1;i++)
	{
		if(arr[i+1]<arr[i])
			return 0;
	}
	return 1;
}

int isSorted2D(int arr[][maxSize], int sizeR, int sizeC)
{
	int i;

	for(i=0;i<sizeR;i++)
	{
		if(isSorted1D(arr[i], sizeC)==0)
			return 0;
	}
	return 1;
}

void sort1D(int arr[], int size)
{
	int i,j, temp;

	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void sort2D(int arr[][maxSize], int sizeR, int sizeC)
{
	int row, temp;

	for(row=0;row<sizeR;row++)
	{
		sort1D(arr[row],sizeC);
	}
}

int searchSorted1D(int arr[], int size, int numToSearch)
{
	int low=0, high=size, mid;

	while(low<=high)
	{
		mid = low+(high-low)/2;
		if(arr[mid]==numToSearch)
			return mid;
		else if(arr[mid]<numToSearch)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}

int searchSorted2D(int arr[][maxSize], int sizeR, int sizeC, int numToSearch, int *rowFound)
{
	int row, indx;

	for(row=0;row<sizeR;row++)
	{
		if((indx=searchSorted1D(arr[row], sizeC, numToSearch))!=-1)
		{
			(*rowFound)=row;
			return indx;
		}
	}

	return -1;
}
