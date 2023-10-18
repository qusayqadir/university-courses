#include <stdio.h>
#include "MacUILib.h"

// PPA2 GOAL: 
//       Construct the game backbone where the player can control an object 
//       to move freely in the game board area with border wraparound behaviour.

// Watch Briefing Video and Read Lab Manual before starting on the activity!



// PREPROCESSOR CONSTANTS DEFINITION HERE
/////////////////////////////////////////
#define row 10
#define col 20


// GLOBAL VARIABLE DEFINITION HERE
/////////////////////////////////////////

int exitFlag; // Program Exiting Flag - old stuff

// For storing the user input - from PPA1
char input; 


char board[row][col]; 
char speed_display; 

// [TODO] : Define objPos structure here as described in the lab document

struct objPos
{
    /* data */
    int x; 
    int y; 
    char symbol; 
};

enum {
    STILL, //the value is 0 
    LEFT, //the value for this is 1
    RIGHT, // value for this is 2
    DOWN, // value for this is 3 
    UP  // value for this is 4
}dir; 

enum {
    speed_1, 
    speed_2, 
    speed_3, 
    speed_4, 
    speed_5
}speed; 

// [TODO] : Define the Direction enumeration here as described in the lab document
//          This will be the key ingredient to construct a simple Finite State Machine
//          For our console game backbone.

struct objPos current_pos; 


// FUNCTION PROTOTYPING DEFINITION HERE
/////////////////////////////////////////

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



// You may insert additional helper function prototypes below.
// 
// As a good practice, always insert prototype before main() and implementation after main()
// For ease of code management.



// MAIN PROGRAM LOOP
/////////////////////////////////////////
// This part should be intuitive by now.
// DO NOT TOUCH

int main(void)
{
 
    Initialize();

    while(!exitFlag)  
    {
        GetInput();

        RunLogic();

        DrawScreen();

        LoopDelay();
    }

    CleanUp();

}


// INITIALIZATION ROUTINE
/////////////////////////////////////////
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    input = 0; // NULL
    exitFlag = 0;  // not exiting 

    current_pos.x = 4; 
    current_pos.y = 9; 
    current_pos.symbol = 64;   
    speed = speed_1; 
    speed_display = 49;  
   
    // [TODO] : Initialize more variables here as seen needed.
    //          PARTICULARLY for the structs!!

}


// INPUT PROCESSING ROUTINE
/////////////////////////////////////////
void GetInput(void)
{
    // [TODO] : Implement Asynchronous Input - non blocking character read-in    
    //          (Same as PPA1)
    if ( MacUILib_hasChar() == 1) 
    {
        input = MacUILib_getChar(); 

    }

}


// PROGRAM LOGIC ROUTINE
/////////////////////////////////////////
void RunLogic(void)
{
    // [TODO] : First, process the input by mapping
    //          WASD to the corresponding change in player object movement direction
    

    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case '\t':  // exit
                exitFlag = 1;
                break;
            case 119: //w (up)
                if (dir != DOWN){
                    dir = UP; 
                }
                break; 

            case 115: //s (down)
                if ( dir != UP )
                    dir = DOWN; 
                break;

            case 100: //d (right)
                if (dir!= LEFT)
                    dir = RIGHT;  
                break; 

            case 97: //a (left)
                if ( dir != RIGHT)
                    dir = LEFT; 
                break; 
            case 49: 
                speed = speed_1; 
                speed_display = 49; 
                break; 
            case 50: 
                speed = speed_2; 
                speed_display = 50; 
                break; 
            case 51: 
                speed = speed_3; 
                speed_display = 51; 
                break; 
            case 52:    
                speed = speed_4; 
                speed_display = 52; 
                break; 
            case 53: 
                speed = speed_5; 
                speed_display = 53; 
                break;

            // Add more key processing here
            // Add more key processing here
            // Add more key processing here    
            default:
                break;
        }
 
        input = 0;
        
    }
   

    // [TODO] : Next, you need to update the player location by 1 unit 
    //          in the direction stored in the program


    switch (dir)
    {
        case UP: 
            current_pos.x --; 
            break;
        
        case DOWN:
            current_pos.x++; 
            break;
        
        case RIGHT: 
            current_pos.y ++; 
            break; 
        
        case LEFT: 
            current_pos.y --; 
            break; 
    
        default:
            break;
    }

    // [TODO] : Heed the borders wraparound!!!
    if( current_pos.x == 0)
    {
        current_pos.x = row -1;
    }
    else if ( current_pos.x == row-1)
    {
        current_pos.x = 1; 
    }
    else if (current_pos.y == col-1)
    {
        current_pos.y = 1; 
    }
    else if ( current_pos.y == 0)
    {
        current_pos.y = col-1;
    }
    
}



// SCREEN DRAWING ROUTINE
/////////////////////////////////////////
void DrawScreen(void)
{
    
    // [TODO] : Implement the latest drawing logic as described in the lab manual
    //
    //  1. clear the current screen content
    MacUILib_clearScreen(); 
    //  2. Iterate through each character location on the game board
    //     using the nested for-loop row-scanning setup.
    int i, j; 
    for ( i =0; i < row; i++) 
    {
        for(j=0; j < col; j++)
        {

            if( i == 0 || j == 0 || i == row-1 || j == col -1) 
            {
                board[i][j] = 35; 
                MacUILib_printf("%c", board[i][j]); 
            }

            else if ( i == current_pos.x && j == current_pos.y )
            { 
                board[current_pos.x][current_pos.y] = current_pos.symbol;
                MacUILib_printf("%c", board[current_pos.x][current_pos.y]);
            }
            else{
                board[i][j] = ' '; 
                MacUILib_printf("%c", board[i][j]); 
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("To move around use WASD\n");
    MacUILib_printf("To Change Speed Press Numbers: 1, 2, 3, 4, or 5\n");
    MacUILib_printf("The Current Speed this is Operating at is: %c", speed_display);      
    //  3. For every visited character location on the game board
    //          If on border on the game board, print a special character
    //          If at the player object position, print the player symbol
    //          Otherwise, print the space character
    //     Think about how you can format the screen contents to achieve the
    //     same layout as presented in the lab manual

    //  4. Print any debugging messages as seen needed below the game board.
    //     As discussed in class, leave these debugging messages in the program
    //     throughout your dev process, and only remove them when you are ready to release
    //     your code. 


}


// PROGRAM LOOOP DELAYER ROUTINE
/////////////////////////////////////////
void LoopDelay(void)
{
    // Change the delaying constant to vary the movement speed.
    
    if (speed == speed_1)
        MacUILib_Delay(400000);
    else if (speed == speed_2)
    {
        MacUILib_Delay(225000);
    }
    else if (speed == speed_3)
    {
        MacUILib_Delay(125000);
    }
    else if (speed == speed_4) 
    {
        MacUILib_Delay(100000);
    }
    else if (speed == speed_5)
    {
        MacUILib_Delay(60000);
    } 
}


// PROGRAM CLEANUP ROUTINE
/////////////////////////////////////////
// Recall from PPA1 - this is run only once at the end of the program
// for garbage collection and exit messages.
void CleanUp(void)
{
    MacUILib_uninit();
}



