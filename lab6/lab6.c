#include <stdio.h>
#include <math.h>
#define TRUE 1

double x1(double t);
int mag (double ax, double ay, double az);
int close_to(double tolerance, double point, double value);
const double g = 9.8; 


	int main(void) {

		int t, i;
		int timer=0;
		double g, ax, ay, az, tolerance, point, value;
		double fallingtime=0;
	
		printf("Ok, Im now receiving data.\n");
		printf("I'm waiting");
		fflush(stdout);
		scanf("%d,%lf,%lf,%lf",&t,&ax,&ay,&az);		
				while( close_to(.25, 1.0, mag(ax,ay,az)) ) {	
				
				
				
				scanf("%d, %lf, %lf, %lf",&t,&ax,&ay,&az);
				
				
				
				if (t>=timer+500) {
				printf(".");
				fflush(stdout);
				timer=t;
				}
				}
				
				fallingtime=t;
				printf("\nHelp me! Im falling");
				fflush(stdout);
				
				while((mag(ax,ay,az)<=0.80)) {
				scanf("%d,%lf,%lf,%lf",&t,&ax,&ay,&az);
				if(t>=timer+50) {
					printf("!");
					fflush(stdout);
					timer=t;
					}
				}
				fallingtime=(t-fallingtime)/1000.0;
					printf("\nOuch! I fell %lf meters in %lf seconds.", x1(fallingtime), fallingtime);
					


	return 0;
	}

/* Lab 6 Function */

double x1(double t) {

double x = 9.8 * t * t * 0.5;

return x;

}

int mag(double ax, double ay, double az) {

int mag = sqrt(ax*ax+ay*ay+az*az);

return mag;

}
int close_to(double tolerance, double point, double value) {
	
	 if(point-tolerance<=value && value<=point+tolerance){
		return 1;
		}
	else {
		return 0;
	}

}
