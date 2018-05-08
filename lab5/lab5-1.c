/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define TRUE 1

/* Put your lab 4 functions prototypes here, as well as the prototype for lab 5 */
double mag(double ax,double ay,double az);
bool close_to (double tolerance, double point, double value);

int main(void) {
  
double ax, ay, az; 
double tolerance, point, value;    


    while (TRUE) {
	
        scanf("%lf, %lf, %lf", &ax, &ay, &az);    
           
        if ((close_to(tolerance, point, az))==true) {
        	printf("Top\n");    
    		}	
        if ((close_to(tolerance, point, az))==true) {
        	printf("Bottom\n");    
       		}
        if ((close_to(tolerance, point, ax))==true) {
        	printf("left\n");    
        	}
        if ((close_to(tolerance, point, ax))==true) {
        	printf("Right\n");    
        	}
        if ((close_to(tolerance, point, ay))==true) {
        	printf("Up\n");    
        	}
        if ((close_to(tolerance, point, ay))==true) {
			printf("Down\n");    
			}
		fflush(stdout);
		}
		return 0;

		}


double mag(double ax,double ay,double az) {
	return sqrt(ax*ax*ay*ay*az*az);
	}

bool close_to(double tolerance, double point, double value) {
	
	if((value-point)<(tolerance)){
		return true;
		}

	if(fabs(value-point)<(tolerance)) {
		return true;
		}
}

