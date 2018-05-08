#include <stdio.h>
#include <math.h>
#define TRUE 1
double x1(double t);
double mag (double ax, double ay, double az);
int close_to(double tolerance, double point, double value);
const double g = 9.8; 


	int main(void) {

		int t, i;
		int timer=0;
		double ax, ay, az;
		double fallingtime=0;
		scanf("%d,%lf,%lf,%lf",&t,&ax,&ay,&az);	
		printf("Ok, Im now receiving data.\n");
		printf("I'm waiting");
		fflush(stdout);
	
		
				while( close_to(.25, 1.0, mag(ax,ay,az)) ) 
				{
					scanf("%d, %lf, %lf, %lf",&t,&ax,&ay,&az);
					if (t>=timer+500) {
						printf(".");
						fflush(stdout);
						timer=t;
					}
				}
				
				int t1=t;
				printf("Help me! Im falling");
				fflush(stdout);
				
				double x=0, v=0;
				int ti=t;
				
				while((mag(ax,ay,az)<=1)) 
				{
					scanf("%d,%lf,%lf,%lf",&t,&ax,&ay,&az);
					v = v + (9.8 * (1-mag(ax, ay, az)) * (t-ti) / 1000.0);
					
					x= x+ v*(t-ti)/1000.0;
					ti=t;
					if(t>=timer+50) 
					{
						printf("!");
						fflush(stdout);
						timer=t;
				    }
				}
				double ts=(t-t1)/1000.0;
				fallingtime=(t-fallingtime)/1000.0;
					printf("\nOuch! I fell %lf meters in %lf seconds.\n", x1(ts), ts);
					printf("Compensating for air resistance, the fall was %lf meters\n This is %lf%% less than computed before",x, ((x1(ts))-x)/x*100);
	


	return 0;
	}

/* Lab 6 Function */

double x1(double t) {

double x = 9.8 * t * t * 0.5;

return x;

}

double mag(double ax, double ay, double az) {

double mag = sqrt(ax*ax+ay*ay+az*az);

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
