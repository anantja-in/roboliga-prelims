/* Worries:
1. Leaving a junction in the dirn of opposite of original head is a u-turn 
2. Detect the circle
3. Check if two consec can be both black => we are done. O/w all can go white while still on the line.. so don't u turn.
*/

#include <avr/io.h>

#define MAX 25

#define BLACK 0
#define WHITE 1

/*
We here have:
C0 - Sensor #4
C1 - Sensor #3
C2 - Sensor #2
C3 - Sensor #1 // LeftMost
C4 - Sensor #5 // Rightmost
*/

int sense(int index) {
	if(index==1) {
		ADMUX = 0x43;
	}
	if(index==2) {
                ADMUX = 0x42; 
        }
	if(index==3) {
                ADMUX = 0x41; 
        }
	if(index==4) {
                ADMUX = 0x40; 
        }
	if(index==5) {
                ADMUX = 0x44; 
        }
	ADCSRA = 0xE7;
	while(!(ADCSRA & (1<<ADIF)));
	if(ADC>200)
		return BLACK;
	else
		return WHITE;
}
void fwd() {
	PORTB = 0x0A;
}
void left() {
	PORTB = 0x12;
}
void right() {
	PORTB = 0x0C;
}
void back() {
	PORTB = 0x014;
}

void uturn() {


}

/* Global variables */

/* Assuming 50 junctions at maximum */
/* Sensor 1 is leftmost */

char dir[4] = {'n','w','s','e'};
int curHead =0 ;
/* Default current heading of the bot is always north*/
/bin/bash: l: command not found
int curMazeIndex = 0;
/* indicating no junction is encountered yet */

/* We are backtracking after a u-turn or after leaving a junction with curHead = opposite of first head. */
char isBackTracking = 0;

char isBlack[5] = {'n','n','n','n','n'};

int main(void) {
	
	int found = 0;
	
	/* Initialize the motors: */

	DDRB=0x1E;
        PORTB = 0x1E;

	int x,y,z;
	
	int dirn[MAX];
	for(x=0;x<MAX;x++)
		dirn[x]=0;
	
	while(found == 0) {
		
		if(sense(3) == WHITE) {
			// correct the path
			if(sense(4)==BLACK) {
				/* Give a right push until sense(3) = BLACK*/
				
			}
			else if(sense(2)==BLACK) {
				/* Give a left push until Sense(3) = BLACK*/
			}
		}
		else {
			// check if there's a turn or junction
			if(sense(1)==BLACK) {
				/* Check if it's a T or + or just a left turn. Sense(3) = BLACK and Sense(1) = BLACK */
				/* A total of four poss., but we will take a left no matter what */
				
			}			
			else {
				if(sense(5)==BLACK) {
					/* Check if it's a right turn or a T with only a right and front W*B*B is the pattern vis*/
				}
				else {
					/* No turn or junction, just move forward */
				}
			}
		}
		
		
	}

}
 
