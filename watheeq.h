#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

double linear(char* input)
{
	// input format ax+c=0
	// x=-c/a
	
	double a,c;
	
	sscanf(input,"%lgx+%lg=0", &a,&c);
	
	
	return -c/a;
}


void dy_dx(char*input , char* output  )
{    // gives the first derivative of the input
	
	static int instance=1; 
	
	if(*input=='\0') // input is empty and end of recursion
	{
	
		// check for output if it begins with +
		
		if(*output=='+')
		{   // remove leading + +ax^n-->ax^n
			
			char* duplicate=malloc(sizeof(output));
			
			*duplicate='\0'; // for strcat
			
			strcat(duplicate, output+1);
			
			strcpy(output, duplicate);
			
		}
		
		return;
	}
	
	
	
	
	// adding + for first term  if it begins with x or a digit
	
	if(*input=='x' || isdigit(*input))
	{   char* buffer=(char*) malloc(strlen(input)+10);
		*buffer='\0';
		
		strcat(buffer, "+");
		strcat(buffer, input);
		
	  input=buffer;
	}
	 	 
	char result[100];
	char operand[100];
	double coefficient;
	int len_result; //length of result
	int power;
	int status;
	
	/*divide into terms separated by + or-
	each term is a substring
	cx^n=c*nx^n-1
	strcat to string
	repeat till end
	
	*/
	
	// so that strcat strts from beginning
	if(instance==1)
	{
		*output='\0';
	}
	
    status=	sscanf(input, "%lgx^%d",&coefficient,&power);
	
	#ifdef TEST
	SHOWi(status);
	#endif
	
	/* 1= present 0=absent
	   11 2 normal cx^n
	   10 1 constant or ax
	   01 0 x^n
	   00 0 x
	
	*/
	
  
  switch(status)
  {
  	case 2: // normal 5x^4
  	
  	sprintf(operand, "%+lgx^%d",coefficient,power);
  	
  	sprintf(result, "%+lgx^%d",coefficient*power,power-1);
  	
  	len_result=strlen(operand);
  	
  	break;
  	
  	case 1: // ax or constant 
  	{
  		
  	char ch;
    sscanf(input, "%*lg %c",&ch);
  	if(ch=='x') //ax form
  	{
  		sprintf(operand, "%+lgx",coefficient);
  		sprintf(result, "%+lg",coefficient);
  		
  	}
  	
  	else //constant
  	{sprintf(operand, "%+lg",coefficient);
  	sprintf(result, "+0");
  	}
  		break;
  		
  	}// case 1
  	
  	case 0: // +x^n or -x^n or +x or -x
 { 	 
 	char sign;
  	status=sscanf(input, "%cx^%d",&sign,&power);
  	
  	if(sign=='+') coefficient=1;
 	else if(sign=='-') coefficient=-1;
 	
 	if(status==2) // +x^n or -x^n
 	{
 		
 		sprintf(operand, "%+lgx^%d",coefficient,power);
 		sprintf(result, "%+lgx^%d",coefficient*power,power-1);
 	}
 	
 	else if(status==1) //+x or -x
 	{
 		
 		sprintf(operand, "%+lgx",coefficient);
 		sprintf(result, "%+lg",coefficient);
 		
 		
 	}
 	
 }//case 0
  	break;
  	
  }//switch
  
  
    //check for ..^1
  
  int len=strlen(result);
  
  if(*(result+len-2)=='^' && *(result+len-1)=='1')
  *(result+len-2)='\0';
  
printf("Differenting %s gives %s \n",operand,result);

	
  
  
  
	strcat(output,result);
	
  
  
  
  
 
  instance++;
 dy_dx(input+strlen(operand), output);//recursion
  
  
  
	
}



 long long int ranint (int max)
 {  int static instance=0;
    int static x;
    int multiplier=7*7*7*7*7;
    int increment=0;
    int m=2147483647;
    int seed=(unsigned)time(0);
    if(instance==0) x=seed;
    x=(multiplier*x+increment) % m;
    instance++;
    return x%(max);
 
 }