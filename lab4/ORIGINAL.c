/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>


int mag(double ax,double ay,double az);



int main(void) {
	int t;
	double  ax, ay, az; 
	


	while (1) {
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);	

/* CODE SECTION 0 */
		printf("Echoing output: %8.3d, %7.4f, %7.4f, %7.4f\n", t, ax, ay, az);

/* 	CODE SECTION 1 */
		printf("At %d ms, the acceleration's magnitude was: %lf\n", 
			t, mag(ax, ay, az));  
/* 	CODE SECTION 2 
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", minutes(t), seconds(t), millis(t)); */
		
	
	
		


	}
	
return 0;
}
int mag(double ax,double ay,double az) { 
return  sqrt(ax*ax*ay*ay*az*az);
}


