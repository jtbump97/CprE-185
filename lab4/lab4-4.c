

/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>


int main(void) {
	int b1,b2,b3,b4,b5,b6,buttons;

	while (1) {
		
		
		scanf("%d,%d,%d,%d,%d,%d", &b1, &b2, &b3, &b4, &b5, &b6);	

		buttons = 0;
		
		if(b1 == 1){
			buttons = buttons + 1;
		}
		if(b2 == 1){
			buttons = buttons + 1;
		}
		if(b3 == 1){
			buttons = buttons + 1;
		}
		if(b4 == 1){
			buttons = buttons + 1;
		}
		if(b5 == 1){
			buttons = buttons + 1;
		}
		

		printf("Number of buttons is %d\n", buttons);
		fflush(stdout);

	}
return 0;
}


