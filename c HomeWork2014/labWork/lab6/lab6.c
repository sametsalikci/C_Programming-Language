
 /* Adds, subtracts, multiplies and divides common fractions, displaying 
 * results in reduced form.
 * Calculates the average of integers in a file
 */

#include <stdio.h>
#include <stdlib.h>   	/* provides function abs */
#include <math.h> 		/* provides function sqrt */

#define IN_FILE_NAME "integers.txt"

/* Function prototypes */


void scan_fraction(int *nump, int *denomp);

char get_operator(void); 
 
void add_fractions(int n1, int d1, int n2, int d2,
                   int *n_ansp, int *d_ansp);

void multiply_fractions(int n1, int d1, int n2, int d2,
                        int *n_ansp, int *d_ansp);

int find_gcd (int n1, int n2);

void reduce_fraction(int *nump, int *denomp);

void print_fraction(int num, int denom);

void make_arithmatic_operations();

double get_average(FILE* in_file);

double to_double(int num, int denom);

void to_friction(double number, int* nump, int* denomp);

void get_square_root(int* num, int* denom);

int
main(void)
{
    FILE* in_file;
	double average;
	int num1, denom1, num2, denom2;
	int number_gcd_1, number_gcd_2;
	int gcd;
	double number1, number2;
	
	/*Test get_average*/
	in_file = fopen(IN_FILE_NAME, "r");
	if(in_file == NULL)
		printf("\nFile not found!!!!\n");
	else{
		average = get_average(in_file);
		printf("Average value is %f.\n", average);
	}
	
	/*Test to_double*/
	scan_fraction(&num1, &denom1);
	number1 = to_double(num1, denom1);
	printf("Double representation is: %f\n", number1);
	
	/*Test multiply_frictions*/
	make_arithmatic_operations();
	
	/*Test to_friction*/
	printf("Enter a number to be converted to frictions >");
	scanf("%lf", &number2);
	to_friction(number2, &num2, &denom2);
	printf("This number is equal to:\n");
	print_fraction(num2, denom2);
	
	/*Test get_square_root*/
	get_square_root(&num2, &denom2);
	printf("\nSquare root of this is:\n");
	print_fraction(num2, denom2);
	
	/*Test gcd*/
	printf("\nEnter 2 integers to find their gcd: ");
	scanf("%d%d", &number_gcd_1, &number_gcd_2);
	gcd = find_gcd(number_gcd_1, number_gcd_2);
	printf("Gratest common division of %d and %d is %d.\n", number_gcd_1, number_gcd_2, gcd);
	
	return (0);
}

/*Returns the average of integers in a given file holding integers only*/
double get_average(FILE* in_file){
	
	int status; /*return value of fscanf to be cheched for EOF*/
	int number; /*read value from file*/
	int count = 0; /*number of values read*/
	int total = 0; /*sum of read values*/
	
	status =  fscanf(in_file, "%d", &number);
	while(status != EOF){
		total += number;
		count++; 
		status = fscanf(in_file, "%d", &number);
	}
	
	return (double)total/(double)count;
}

/*Takes a number in fractional representation and returns its 
 * equivalent in floating point representation as the return value*/

double to_double(int num, int denom){
	return ((double)num / ((double)denom));
}


/*Takes a number in floating point representation and returns 
 *its equivalent in fractional representation	as output arguments	*/

void to_friction(double number, int* nump, int* denomp){
	int num;
	int denom;
	
	/*obtain friction with a denominator of 100000*/
	*nump = number * 100000;
	*denomp = 100000;
	
	/*reduce the fraction*/
	reduce_fraction(nump, denomp);
}

void get_square_root(int* num, int* denom){
	double double_result;
	
	double_result = sqrt(to_double(*num, *denom));
	to_friction(double_result, num, denom);
}

void
make_arithmatic_operations(void)
{
	  int  n1, d1;       /* numerator, denominator of first fraction	*/
      int  n2, d2;       /* numerator, denominator of second fraction	*/
      char op;           /* arithmetic operator + - * or /	*/
      char again;        /* y or n depending on user's desire to continue	*/
      int  n_ans, d_ans; /* numerator, denominator of answer	*/

      /* While the user wants to continue, gets and solves arithmetic 
problems with common fractions	*/
      do {
          /* Gets a fraction problem 	*/
          scan_fraction(&n1, &d1);
          op = get_operator();
          scan_fraction(&n2, &d2);

          /* Computes the result  */
          switch (op) {
          case '+':  
                add_fractions(n1, d1, n2, d2, &n_ans, &d_ans);
                break;

          case '-':
                add_fractions(n1, d1, -n2, d2, &n_ans, &d_ans);
                break;

          case '*':
                multiply_fractions(n1, d1, n2, d2, &n_ans, &d_ans);
                break;

          case '/':
                multiply_fractions(n1, d1, d2, n2, &n_ans, &d_ans);
          }
          reduce_fraction(&n_ans, &d_ans);

          /* Displays problem and result	*/
          printf("\n");
          print_fraction(n1, d1);
          printf(" %c ", op);
          print_fraction(n2, d2);
          printf(" = ");
          print_fraction(n_ans, d_ans);

          /* Asks user about doing another problem	*/
          printf("\nDo another problem? (y/n)> ");
          scanf(" %c", &again);
      } while (again == 'y'  ||  again == 'Y');
}


/* Insert function scan_fraction from Fig. 6.9 here. */

/*
 * Gets and returns a valid arithmetic operator.  Skips over newline
 * characters and permits re-entry of operator in case of error.
 */
char
get_operator(void) 
{
      char op;

      printf("Enter an arithmetic operator (+,-,*, or /)\n> ");
      for  (scanf("%c", &op);
            op != '+'  &&  op != '-'  &&
            op != '*'  &&  op != '/';
            scanf("%c", &op)) {
          if (op != '\n')
              printf("%c invalid, reenter operator (+,-, *,/)\n> ", op);
      }
      return (op);
}

/*
 * Adds fractions represented by pairs of integers.
 * Pre:  n1, d1, n2, d2 are defined; 
 *       n_ansp and d_ansp are addresses of type int variables.
 * Post: sum of n1/d1 and n2/d2 is stored in variables pointed 
 *       to by n_ansp and d_ansp.  Result is not reduced.
 */
void
add_fractions(int      n1, int      d1, /* input - first fraction   */
              int      n2, int      d2, /* input - second fraction  */
              int *n_ansp, int *d_ansp) /* output - sum of 2 fractions*/
{
      int denom,     /* common denominator used for sum (may not be least)	*/
          numer,       /* numerator of sum                	*/
          sign_factor; /* -1 for a negative, 1 otherwise	*/

      /* Finds a common denominator	*/
      denom = d1 * d2;

      /* Computes numerator	*/
      numer = n1 * d2 + n2 * d1;

      /* Adjusts sign (at most, numerator should be negative)	*/
      if (numer * denom >= 0)
            sign_factor = 1;
      else
            sign_factor = -1;

      numer = sign_factor * abs(numer);
      denom = abs(denom);

      /* Returns result	*/
      *n_ansp = numer;
      *d_ansp = denom;
}

/* 
 * Reduces a fraction by dividing its numerator and denominator by their
 * greatest common divisor.
 */
void
reduce_fraction(int *nump,   /* input/output -	*/
                int *denomp) /* numerator and denominator of fraction	*/
{
      int gcd;   /* greatest common divisor of numerator & denominator	*/

      gcd = find_gcd(*nump, *denomp);
      *nump = *nump / gcd;
      *denomp = *denomp / gcd;
}


/* 
 * Displays pair of integers as a fraction.
 */
void
print_fraction(int num, int denom)  /* input - numerator & denominator	*/
{
      printf("%d/%d", num, denom);
}


void scan_fraction(int *nump, int *denomp){
	char slash;
	int status;
	int error;
	char discard;

	do{
		error = 0;
		
		printf("Enter a common division as 2 integers seperated ");
		printf("by a slash> ");

		status = scanf("%d %c%d", nump, &slash, denomp);
	
		/*Validate the fraction*/
		if(status < 3){
			error = 1;
			printf("Invalid!!! \n");	
		} else if(slash != '/'){
			error = 1;
			printf("Invalid-seperate numerator and denominator\n");
		} else if(*denomp <= 0){
			error = 1;
			printf("Invalid-denominator must be positive\n");
		}

		do {
			scanf("%c", &discard);
		}while(discard != '\n');
	} while(error);
}


/* Multiplies fractions represented by pairs of integers.
 * Pre:  n1, d1, n2, d2 are defined; 
 *       n_ansp and d_ansp are addresses of type int variables.
 * Post: product of n1/d1 and n2/d2 is stored in variables pointed 
 *       to by n_ansp and d_ansp.  Result is not reduced.
 */
void
multiply_fractions(int      n1, int   d1, /*  input - first fraction	*/
                   int      n2, int   d2, /*  input - second fraction	*/
                   int *n_ansp,           /*  output -	*/
		   int *d_ansp)           /*     product of 2 fractions	*/
{
	*n_ansp = n1*n2;
	*d_ansp = d1*d2;
}

/* Finds greatest common divisor of two integers
 */
int
find_gcd (int n1, int n2) /* input - two integers	*/
{
	int i;
	int min; /*min(n1, n2)*/
	
	/*find min of n1, n2*/
	if(n1 < n2)
		min = n1;
	else
		min = n2;
	
	/*starting from minimum of inputs decrease i until i is a common division*/
	for(i=min; (n1 % i != 0) || (n2 % i != 0) /*i is not a  common division*/; i--)
	{/*do nothing*/}
	
	return i;
}

