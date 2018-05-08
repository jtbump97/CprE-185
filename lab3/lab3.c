// CprE 185: Lab 3;
// Problem 1: Mysterious Output;

#include <stdio.h>

int main()
{
	int integerResult;
	double decimalResult;

	decimalResult = 77.0 / 5.0;
	printf("The value of 77/5 is %lf\n", decimalResult);//changed to decimalResult instead of integerResult to get a value instead of 0
	integerResult = 2 + 3;
	printf("The value of 2+3 is %d\n",integerResult);
	decimalResult = 1.0/22.0;
	printf("The value of 1.0/22.0 is %lf\n", decimalResult);//should be using lf/n not d/n since it is double not integer
	
	return 0;
}

