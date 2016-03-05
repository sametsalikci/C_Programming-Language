
#include <stdio.h>
/*function prototypes*/
	int conj(int x, int y);
        int disj(int x, int y);
	int not(int x);
	int mate(int x, int y);
	int excl(int x, int y);
	void testMonotone();
int main()
{
	
	int part;
	int t1,t2;

	printf("           MENU OF BOOLEAN ALGEBRA  \n");
	printf("1.Conjunction\n2.Disjunction\n3.Negation\n");
	printf("4.Material Implication\n5.Exclusive Or\n");
	printf("6.Test the calculator with Monotone Laws\n7.Exit\n");
	                     
	printf("Selection Time!\nEnter a part: ");
	scanf("%d",&part);	



	switch(part)
        {
        case 1:
	printf("CONJUNCTION\n");
	printf("\tYou can test true of conjunction law.\nLet's start test!!!");
	printf("Enter two value (1 or 0) for test: ");
	scanf("%d %d",&t1,&t2);
	printf("%d and %d = %d\n",t1,t2,conj(t1,t2));
	printf("                     <<<<<>>>>>\n                        ");
	break;

	case 2:

	printf("DISJUNCTION\n");
	printf("\tYou can test true of dijunction law.\nLet's start test!!!");
	printf("Enter two value (1 or 0) for test: ");
	scanf("%d %d",&t1,&t2);
	printf("%d or %d = %d\n",t1,t2,disj(t1,t2));
	printf("                     <<<<<<>>>>>\n                        ");
	break;

	case 3:

	printf("NEGATION\n");
	printf("\tYou can test true of negation law.\nLet's start test!!!");
	printf("Enter a value (1 or 0) for test: ");
	scanf("%d",&t1);
	printf("'(%d)  = %d\n",t1,not(t1,t2));
	printf("                     <<<<<<>>>>>>\n                        ");		
	break;

	case 4:

	printf("MATERİAL IMPLICATION\n");
	printf("\tYou can test true of material law.\nLet's start test!!!");
	printf("Enter two value (1 or 0) for test: ");
	scanf("%d %d",&t1,&t2);
	printf("%d mate %d = %d\n",t1,t2,mate(t1,t2));
	printf("                     <<<<<<>>>>>\n                        ");
	break;

	case 5:

	printf("5.EXCLUSIVE OR\n");
	printf("\tYou can test true of exclusive law.\nLet's start test!!!");
	printf("Enter two value (1 or 0) for test: ");
	scanf("%d %d",&t1,&t2);
	printf("%d excl %d = %d\n",t1,t2,excl(t1,t2)                       );
	printf("                     <<<<<<>>>>>\n                        ");          
	break;
	case 6:
	printf("Test the calculator with Monotone Laws\n");
	printf("Enter the 'results.txt' for Monotone Laws\n");
	testMonotone();
	break;
	case 7:

	printf("7.EXIT\n");
	printf("           <<<<<<THE END OF MENU>>>>>>\n                   ");	
	break;

	default:

	printf("NOT IN MENU\n");
	break;
	}

	return 0;	
}
int conj(int x, int y)
{
		if(x==y)
		{ 	if(x==1)
			return 1; 
		}
		else
		return 0;
}
int disj(int x, int y)
{	
		if(x==y)
		{ 	if(x==0)
			return 0; 
		}
		else
		return 1;
}
int not(int x)
{
		if(x==1)
		return 0;
		else
		return 1;
}
int mate(int x, int y)
{
		int arg1,arg2;
		arg1=not(x);
		arg2=y;
		return disj(arg1,arg2);
}
int excl(int x, int y)
{
	int arg1,arg2,arg3;

		arg1=disj(x,y);
		arg2=conj(x,y);
		arg3=not(arg2);
		return conj(arg1,arg3);
}


void testMonotone()
{
	FILE *out=fopen("results.txt","w");
	int x,y,z;
	char c1,c2,c3,c4;            
	char c5,c6,c7,c8; 

/*--------------------------------1.KURAL----------------------------*/
	
	fprintf(out,"**********Associativity of V**********\n");

	x=1; y=1; z=1;
	if(disj(x,disj(y,z))==disj(disj(x,y),z)) {
        fprintf(out,"x=1, y=1, z=1 için dogru\n");
	c1='t'; /* control1 */                   }
	else
	fprintf(out,"x=1, y=1, z=1 için yanlıs\n");

	x=1; y=1; z=0;
	if(disj(x,disj(y,z))==disj(disj(x,y),z)) {
        fprintf(out,"x=1, y=1, z=0 için dogru\n");
	c2='t'; /* control2 */                   }
	else
	fprintf(out,"x=1, y=1, z=0 için yanlıs\n");

	x=1; y=0; z=1;
	if(disj(x,disj(y,z))==disj(disj(x,y),z)) {
        fprintf(out,"x=1, y=0, z=1 için dogru\n");
	c3='t'; /* control3 */                   } 
	else
	fprintf(out,"x=1, y=0, z=1 için yanlıs\n");

	x=1; y=0; z=0;
	if(disj(x,disj(y,z))==disj(disj(x,y),z)) {
        fprintf(out,"x=1, y=0, z=0 için dogru\n");
	c4='t'; /* control4 */                   }
	else
	fprintf(out,"x=1, y=0, z=0 için yanlıs\n");

	x=0; y=1; z=1;
	if(disj(x,disj(y,z))==disj(disj(x,y),z)) {
        fprintf(out,"x=0, y=1, z=1 için dogru\n");
	c5='t'; /* control5 */                   }
	else
	fprintf(out,"x=0, y=1, z=1 için yanlıs\n");

	x=0; y=1; z=0;
	if(disj(x,disj(y,z))==disj(disj(x,y),z)) {
        fprintf(out,"x=0, y=1, z=0 için dogru\n");
	c6='t'; /* control6 */                   } 
	else
	fprintf(out,"x=0, y=1, z=0 için yanlıs\n");

	x=0; y=0; z=1;
	if(disj(x,disj(y,z))==disj(disj(x,y),z)) {
        fprintf(out,"x=0, y=0, z=1 için dogru\n");
	c7='t'; /* control7 */                   }
	else
	fprintf(out,"x=0, y=0, z=1 için yanlıs\n");

	x=0; y=0; z=0;
	if(disj(x,disj(y,z))==disj(disj(x,y),z)) {
        fprintf(out,"x=0, y=0, z=0 için dogru\n");
	c8='t'; /* control8 */                   }
	else
	fprintf(out,"x=0, y=0, z=0 için yanlıs\n");

		if(c1=='t' && c2=='t' && c3=='t' && c4=='t')
		{
			if(c5=='t' && c6=='t' && c7=='t' && c8=='t')
			fprintf(out,"\n1.Kural sağlandı!\n\n");
		}
/*--------------------------------2.KURAL----------------------------*/

	fprintf(out,"**********Associativity of Λ**********\n");

	x=1; y=1; z=1;
	if(conj(x,conj(y,z))==conj(conj(x,y),z)) {
        fprintf(out,"x=1, y=1, z=1 için dogru\n");
	c1='t'; /* control1 */                   }
	else
	fprintf(out,"x=1, y=1, z=1 için yanlıs\n");

	x=1; y=1; z=0;
	if(conj(x,conj(y,z))==conj(conj(x,y),z)) {
        fprintf(out,"x=1, y=1, z=0 için dogru\n");
	c2='t'; /* control2 */                   }
	else
	fprintf(out,"x=1, y=1, z=0 için yanlıs\n");

	x=1; y=0; z=1;
	if(conj(x,conj(y,z))==conj(conj(x,y),z)) {
        fprintf(out,"x=1, y=0, z=1 için dogru\n");
	c3='t'; /* control3 */                   }
	else
	fprintf(out,"x=1, y=0, z=1 için yanlıs\n");

	x=1; y=0; z=0;
	if(conj(x,conj(y,z))==conj(conj(x,y),z)) {
        fprintf(out,"x=1, y=0, z=0 için dogru\n");
	c4='t'; /* control4 */                  }
	else
	fprintf(out,"x=1, y=0, z=0 için yanlıs\n");

	x=0; y=1; z=1;
	if(conj(x,conj(y,z))==conj(conj(x,y),z)) {
        fprintf(out,"x=0, y=1, z=1 için dogru\n");
	c5='t'; /* control5 */                   }
	else
	fprintf(out,"x=0, y=1, z=1 için yanlıs\n");

	x=0; y=1; z=0;
	if(conj(x,conj(y,z))==conj(conj(x,y),z)) {
        fprintf(out,"x=0, y=1, z=0 için dogru\n");
	c6='t'; /* control6 */                   }
	else
	fprintf(out,"x=0, y=1, z=0 için yanlıs\n");

	x=0; y=0; z=1;
	if(conj(x,conj(y,z))==conj(conj(x,y),z)) {
        fprintf(out,"x=0, y=0, z=1 için dogru\n");
	c7='t'; /* control7 */                   }
	else
	fprintf(out,"x=0, y=0, z=1 için yanlıs\n");

	x=0; y=0; z=0;
	if(conj(x,conj(y,z))==conj(conj(x,y),z)) {
        fprintf(out,"x=0, y=0, z=0 için dogru\n");
	c8='t'; /* control8 */                   } 
	else
	fprintf(out,"x=0, y=0, z=0 için yanlıs\n");

	if(c1=='t' && c2=='t' && c3=='t' && c4=='t')
		{
			if(c5=='t' && c6=='t' && c7=='t' && c8=='t')
			fprintf(out,"\n2.Kural sağlandı!\n\n");
		}

/*--------------------------------3.KURAL----------------------------*/

	fprintf(out,"**********Commutativity of V**********\n");

	x=1; y=1; 
	if(disj(x,y)==disj(y,x))               {
        fprintf(out,"x=1, y=1 için dogru\n");
	c1='t'; /* control1 */                 }    
	else
	fprintf(out,"x=1, y=1 için yanlıs\n");

	x=1; y=0; 
	if(disj(x,y)==disj(y,x))               {
        fprintf(out,"x=1, y=0 için dogru\n");
	c2='t'; /* control2 */                 }   
	else
	fprintf(out,"x=1, y=0 için yanlıs\n");

	x=0; y=1; 
	if(disj(x,y)==disj(y,x))               {
        fprintf(out,"x=0, y=1 için dogru\n");
	c3='t'; /* control3 */                 }   
	else
	fprintf(out,"x=0, y=1 için yanlıs\n");

	x=0; y=0; 
	if(disj(x,y)==disj(y,x))               {
        fprintf(out,"x=0, y=0 için dogru\n");
	c4='t'; /* control4 */                 }   
	else
	fprintf(out,"x=0, y=0 için yanlıs\n");

	if(c1=='t' && c2=='t' && c3=='t' && c4=='t')	
	fprintf(out,"\n3.Kural sağlandı!\n\n");

/*--------------------------------4.KURAL----------------------------*/

	fprintf(out,"********** Commutativity of Λ**********\n");

	x=1; y=1; 
	if(conj(x,y)==conj(y,x))                {
        fprintf(out,"x=1, y=1 için dogru\n");
	c1='t'; /* control1 */                  }   
	else
	fprintf(out,"x=1, y=1 için yanlıs\n");

	x=1; y=0; 
	if(conj(x,y)==conj(y,x))               {
        fprintf(out,"x=1, y=0 için dogru\n");
	c2='t'; /* control2 */                 }   
	else
	fprintf(out,"x=1, y=0 için yanlıs\n");

	x=0; y=1; 
	if(conj(x,y)==conj(y,x))               {
        fprintf(out,"x=0, y=1 için dogru\n");
	c3='t'; /* control3 */                 }    
	else
	fprintf(out,"x=0, y=1 için yanlıs\n");

	x=0; y=0; 
	if(conj(x,y)==conj(y,x))               {
        fprintf(out,"x=0, y=0 için dogru\n");
	c4='t'; /* control4 */                 }    
	else
	fprintf(out,"x=0, y=0 için yanlıs\n");

	if(c1=='t' && c2=='t' && c3=='t' && c4=='t')	
	fprintf(out,"\n4.Kural sağlandı!\n\n");

/*--------------------------------5.KURAL----------------------------*/
	
	fprintf(out,"**********Distributivity of Λ over V**********\n");

	x=1; y=1; z=1;
	if(conj(x,disj(y,z))==disj(conj(x,y),conj(x,z))) {
        fprintf(out,"x=1, y=1, z=1 için dogru\n");
	c1='t'; /* control1 */                           }
	else
	fprintf(out,"x=1, y=1, z=1 için yanlıs\n");

	x=1; y=1; z=0;
	if(conj(x,disj(y,z))==disj(conj(x,y),conj(x,z))) {
        fprintf(out,"x=1, y=1, z=0 için dogru\n");
	c2='t';  /* control2 */                          } 
	else
	fprintf(out,"x=1, y=1, z=0 için yanlıs\n");

	x=1; y=0; z=1;
	if(conj(x,disj(y,z))==disj(conj(x,y),conj(x,z))) {
        fprintf(out,"x=1, y=0, z=1 için dogru\n");
	c3='t'; /* control3 */                           }
	else
	fprintf(out,"x=1, y=0, z=1 için yanlıs\n");

	x=1; y=0; z=0;
	if(conj(x,disj(y,z))==disj(conj(x,y),conj(x,z))) {
        fprintf(out,"x=1, y=0, z=0 için dogru\n");
	c4='t'; /* control4 */                           }   
	else
	fprintf(out,"x=1, y=0, z=0 için yanlıs\n");

	x=0; y=1; z=1;
	if(conj(x,disj(y,z))==disj(conj(x,y),conj(x,z))) {
        fprintf(out,"x=0, y=1, z=1 için dogru\n");
	c5='t'; /* control5 */                           }
	else
	fprintf(out,"x=0, y=1, z=1 için yanlıs\n");

	x=0; y=1; z=0;
	if(conj(x,disj(y,z))==disj(conj(x,y),conj(x,z))) {
        fprintf(out,"x=0, y=1, z=0 için dogru\n");
	c6='t'; /* control6 */                           }
	else
	fprintf(out,"x=0, y=1, z=0 için yanlıs\n");

	x=0; y=0; z=1;
	if(conj(x,disj(y,z))==disj(conj(x,y),conj(x,z))) {
        fprintf(out,"x=0, y=0, z=1 için dogru\n");
	c7='t'; /* control7 */                           }   
	else
	fprintf(out,"x=0, y=0, z=1 için yanlıs\n");

	x=0; y=0; z=0;
	if(conj(x,disj(y,z))==disj(conj(x,y),conj(x,z))) {
        fprintf(out,"x=0, y=0, z=0 için dogru\n");
	c8='t'; /* control8 */                           }
	else
	fprintf(out,"x=0, y=0, z=0 için yanlıs\n");
 
	if(c1=='t' && c2=='t' && c3=='t' && c4=='t')
		{
		  if(c5=='t' && c6=='t' && c7=='t' && c8=='t')
		  fprintf(out,"\n5.Kural sağlandı!\n\n");
		}

/*--------------------------------6.KURAL----------------------------*/

	fprintf(out,"**********Identity for V**********\n");

	x=1; 
	if(disj(x,0)==x)               {
        fprintf(out,"x=1 için dogru\n");
	c1='t'; /* control1 */         }
	else             
	fprintf(out,"x=1 için yanlıs\n");
	                 
	x=0; 
	if(disj(x,0)==x)                {
        fprintf(out,"x=0 için dogru\n");
	c2='t'; /* control2 */          }    
	else             
	fprintf(out,"x=0 için yanlıs\n");

	if(c1=='t' && c2=='t')
	fprintf(out,"\n6.Kural sağlandı!\n\n");

/*--------------------------------7.KURAL----------------------------*/

	fprintf(out,"**********Identity for Λ**********\n");

	x=1; 
	if(conj(x,1)==x)                 {
        fprintf(out,"x=1 için dogru\n");
	c1=='t'; /* control1 */          }
	else             
	fprintf(out,"x=1 için yanlıs\n");
			 								
	x=0; 
	if(conj(x,1)==x)                 {
        fprintf(out,"x=0 için dogru\n");
	c2=='t' ; /* control2 */         }
	else
	fprintf(out,"x=0 için yanlıs\n");

	if(c1=='t' && c2=='t')
	fprintf(out,"\n7.Kural sağlandı!\n\n");

/*--------------------------------8.KURAL----------------------------*/

	fprintf(out,"**********Annihilator for Λ**********\n");

	x=1; 
	if(conj(x,0)==0)                 {
        fprintf(out,"x=1 için dogru\n");
	c1=='t'; /* control1 */          }
	else            
	fprintf(out,"x=1 için yanlıs\n");
			 
	x=0; 
	if(conj(x,0)==0)                {
        fprintf(out,"x=0 için dogru\n");
	c2=='t'; /* control2 */         }
	else
	fprintf(out,"x=0 için yanlıs\n");

	if(c1=='t' && c2=='t')
	fprintf(out,"\n8.Kural sağlandı!\n\n"); 

	fclose(out);
}


