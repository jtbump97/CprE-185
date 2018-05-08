// Joshua Bump Section E 1/27/17
#include <stdio.h>

//This program is meant to calculate the area of the rectangle when given a height and width

int main(int argc, char* argv[]){
	
	
int x,y;
printf("Enter a width:");
scanf("%d",&x);
printf("Enter a height:");
scanf("%d",&y);
printf("A %d by %d rectangle's area is %d\n", x,y,x*y);

return 0;
}