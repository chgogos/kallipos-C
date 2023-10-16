# include <stdio.h>
int main()
{
	double *xpointer=NULL;
	printf("Starts with address %d\n",xpointer);
	xpointer=new double;
	printf("Now the address is %d\n",xpointer);
	*xpointer=100;
	printf("The value of the memory: %lf\n",*xpointer);
	*xpointer=*xpointer+100;
	printf("Now the value of the memory: %lf\n",*xpointer);
	delete xpointer;
	return 0;
} 
