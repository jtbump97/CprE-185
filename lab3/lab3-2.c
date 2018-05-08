#include <stdio.h>

int main()
{

int integerResult;
double decimalResult;

integerResult=6427+1725;
printf("6427+1725= %d\n", integerResult);

integerResult=(6971*3925)-95;
printf("(6427*3925)-95= %d\n", integerResult);

decimalResult=79.00+(12.00/5.00);
printf("79+12/5= %.2f\n",decimalResult);//comes out wrong so needed decimals around 12/5 and needed two decimal places on each number

decimalResult=3640.0/107.9;
printf("3640.0/107.9= %.2f\n", decimalResult);

decimalResult=(22.00/3.00)*3.00;//comes out wrong so needs to be a double in order to include decimal places on the 22/3 in order to get the right answer
printf("(22/3)*3= %.2f\n", decimalResult);

decimalResult=22.00/(3.00*3.00);
printf("22/(3*3)= %.2f\n", decimalResult);//comes out wrong so needs to be a double in order to include the decimal points and the input walues need decimal places

decimalResult=22.00/(3.00*3.00);
printf("22/(3*3)= %.2f\n",decimalResult);//comes out wrong so needs to become a double and needs decimal places in input values

decimalResult=22.00/3.00*3.00;
printf("22/3*3= %.f\n", decimalResult);//comes out wrong so needs to be double in order to take into account the decimals when calculating 22/3 first

decimalResult=(22.0/3)*3.0;
printf("(22.0/3)*3.0=%.2f\n", decimalResult);

decimalResult=22.00/(3.00*30);//needs to be a double based on 22/90 that is done during solving this equation
printf("22.0/(3*30)= %.2f\n", decimalResult);

decimalResult=22.0/3.0*3.0;
printf("22.0/3.0*3.0= %.2f\n", decimalResult);

decimalResult=(23.567*23.567)/(4*3.14);//in order to solve for area in terms of circumference I used the equation A=C^2/(4pi)
printf("The area of a circle with a circumference of 23.567 is %.2f\n", decimalResult);

decimalResult=14*(.3048);//number of feet multiplied by .3048 meters would give feet in units of meters
printf("14 feet is %.2f meters\n",decimalResult);

decimalResult=(76-32)/1.8;//76 degrees was put into the equation given to calculate degrees farenheit in units of celcius
printf("76 degrees Farenheit is %.2f degrees celcius.",decimalResult);

}