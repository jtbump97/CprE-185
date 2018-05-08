/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define TRUE 1

/* Put your lab 4 functions prototypes here, as well as the prototype for lab 5 */
double mag(double ax,double ay,double az);
bool close_to(double tolerance, double point, double value);

int main(void) {
int t, b1, b2, b3, b4, b5, s;
double ax, ay, az, tolerance, point, value; 
int x=0;
	while (TRUE) {
		
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s);
		
	if (b2==1) 
		return 0;
	tolerance=.15;
	point=1;
	
	if (close_to(0.025, point, mag(ax, ay, az))) {

	if (close_to(tolerance, point, ax)==true && x!=1)  {
			printf("Left\n");
			x=1;
}	point=-1;
	if (close_to(tolerance, point, ax)==true && x!=2) {
			printf("Right\n");
			x=2;
}	point=1;
	if (close_to(tolerance, point, ay)==true && x!=3) {
			printf("Top\n");
			x=3;
}	point=-1;
	if (close_to(tolerance, point, ay)==true && x!=4) {
			printf("Bottom\n");
			x=4;
}	point=1;
	if (close_to(tolerance, point, az)==true && x!=5)	{
			printf("Up\n");
			x=5;
}	point=-1;
	if (close_to(tolerance, point, az)==true && x!=6) {
			printf("Down\n");
			x=6;
}
	}
	
	
	fflush(stdout);
	
	}	
	
	
		return 0;

		}


double mag(double ax,double ay,double az)
 {
	double y= sqrt(ax*ax+ay*ay+az*az);
	return y;
}

bool close_to(double tolerance, double point, double value) {
	
	 if(point-tolerance<=value && value<=point+tolerance){
		return true;
		}
	else {
		return false;
	}
	
}



