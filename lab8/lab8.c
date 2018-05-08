
#include <stdio.h>


#define MAXPOINTS 10000

int read_acc(double* a_x, double* a_y, double* a_z,  int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT,int* time);
// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}
	
	int time, Button_UP, Button_DOWN,Button_LEFT,Button_RIGHT,b5,j;
	double ax, ay, az, avg_x, avg_y, avg_z, xmin, xmax, ymin, ymax,zmin, zmax;
	int i;
	for(i=0; i<lengthofavg; i++)
	{
			scanf("%d,%lf,%lf,%lf,%d,%d,%d,%d,%d,%d",&time,&ax,&ay,&az,&Button_UP,&Button_DOWN,&Button_LEFT,&Button_RIGHT,&b5,&j);
			updatebuffer(x, lengthofavg, ax);
			updatebuffer(y, lengthofavg, ay);
			updatebuffer(z, lengthofavg, az);
	}
	

	while(Button_LEFT!=1) {
	scanf("%d,%lf,%lf,%lf,%d,%d,%d,%d,%d,%d",&time,&ax,&ay,&az,&Button_UP,&Button_DOWN,&Button_LEFT,&Button_RIGHT,&b5,&j);
	updatebuffer(x, lengthofavg, ax);
	maxmin(x, lengthofavg, &xmin, &xmax);
	avg_x= avg(x, lengthofavg);
	
	
	updatebuffer(y, lengthofavg, ay);
	maxmin(y, lengthofavg, &ymin, &ymax);
	avg_y = avg(y, lengthofavg);
	
	updatebuffer(z, lengthofavg, az);
	maxmin(z, lengthofavg, &zmin, &zmax);
	avg_z = avg(z, lengthofavg);
	
	printf("%lf,%lf,%lf,%lf,%lf,%lf\n",ax,ay,az,avg_x,avg_y,avg_z);
	fflush(stdout);
	
	
	
	}
}


// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items) {
	int i;
	double tot=0;
	
		for(i=0; i < num_items; i++){
			tot = tot + buffer[i];
		}
		return tot/num_items;
}

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* min, double* max) {
	int x;
	*max=array[0];
	*min=array[0];
	for (x=0; x<num_items; x++) {
		
		if (array[x]>*max) {
			*max=array[x];	
		}
		if(array[x]<*min) {
			*min=array[x];
		}
	}
	
}

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item) {
	int z;
	for(z=length-1; z>0;z--) {
		buffer[z]=buffer[z-1];	
	}
	buffer[0]=new_item;
	
}

