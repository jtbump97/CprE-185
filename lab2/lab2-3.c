// Joshua Bump Section E 1/27/17
#include <stdio.h>

//This program is meant to calculate the volume of the rectanglar prism when given a length, height and width

int main(int argc, char* argv[]){
	
	
int x,y,z;
printf("Enter a width:");
scanf("%d",&x);
printf("Enter a height:");
scanf("%d",&y);
printf("Enter a length:");
scanf("%d", &z);
printf("A %d by %d by %d rectangular prism's volume is %d\n", x,y,z,x*y*z);

return 0;
}