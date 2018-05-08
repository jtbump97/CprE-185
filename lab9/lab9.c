// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
//Updated for Esplora 2013 TeamRursch185


// Headers
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include<stdlib.h>
// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLUMNS for the screen height and width (set by system)
// MAXIMUMS
#define COLUMNS 100
#define ROWS 80

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define SPACE ' '

// Number of samples taken to form an average for the accelerometer data
// Feel free to tweak this.  You may actually want to use the moving averages
// code you created last week 
#define NUM_SAMPLES 10  


// 2D character array which the maze is mapped into
char MAZE[COLUMNS][ROWS];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty);

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void);

// PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

// PRE: -1.0 < y_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the pitch function written in previous labs.  
double calc_roll(double x_mag);

// Main - Run with './explore.exe -t -a -b' piped into STDIN
void main(int argc, char* argv[])
{
	int difficulty= 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &difficulty );
		printf("You entered a difficulty of %d\n", difficulty);
	}
	else {
		printf("Enter a difficulty on the command line\n");
	}
	if (difficulty <0 || difficulty >100) {
		printf("Invalid difficulty\n");
	}
	
	// setup screen    
	initscr();
	refresh();
	
	// Generate and draw the maze, with initial avatar
	generate_maze(difficulty);
	int i=0,t;
	int x=50;
	int y=0;
	int lose=0;
	double ax,ay,az,x_mag;

  
draw_maze();//draws the maze on the screen
	
	do
	{
		scanf(" %d, %lf, %lf, %lf", &t,&ax,&ay,&az); //scanning in values from esplora
		if (i++ % 300 == 0) {                         //timer in order to delay the falling
			draw_character(x,y,SPACE);
		if(ax>0.3 && MAZE[x-1][y] != WALL && x>=0) {   //should I move left?
				x--;
				draw_character(x, y, AVATAR);
				draw_character(x+1,y-1,SPACE);
			}
		else if(ax<-0.3 && MAZE[x+1][y] != WALL && x<100) {   //should I move right?
				x++;
			draw_character(x, y, AVATAR);
			draw_character(x-1,y-1,SPACE);
			}
			else{                          //replaces the previous avatar with a space
			 draw_character( x, y, AVATAR);
			 draw_character(x,y-1,SPACE);
			}	
		if(MAZE[x][y+1] != WALL) {         //Can I move down?
			draw_character( x, y, SPACE);
			y++;
			draw_character( x, y, AVATAR);
		}
			
			
		if (MAZE[x][y+1] == WALL && MAZE[x+1][y] == WALL && MAZE[x-1][y] == WALL) {  //Am I in a bucket, if so quit the while loop
			lose = 1;     //tells int outside of loop to print "You lose"
			break;
		}
		
		else {
			lose = 0;
		}
	}
	
	} while(y!=80 && x!=100 && lose!=1); // game ends when y reaches the bottom or when you have lost
	endwin();
	// Print the win message
	if (lose==0){
	
	printf("YOU WIN!\n");
	}
	//print the lose message
	else if (lose==1) {
		printf("YOU LOSE");
	}
}



// PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//YOU DO NOT NEED TO CHANGE THIS FUNCTION.
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}
void generate_maze(int difficulty) { //generate the maze itself
	int i,j;
	for(i=0;i<ROWS;i++) {				//nested for loop to create the array
		for(j=0;j<COLUMNS;j++){
			if(rand()%100<difficulty){  //calculates random placement of walls based on difficulty selected
				MAZE[j][i]=WALL;
			}
			else {
				MAZE[j][i]=SPACE;
			}
		}
	}
	
}
void draw_maze(void) {
	int i,j;
	for(i=0;i<COLUMNS;i++){          //draws the maze based on data from generate_maze again using a nested for loop
		for(j=0;j<ROWS;j++){
			draw_character(i,j,MAZE[i][j]);
		}
	}
}
