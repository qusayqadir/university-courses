#include <stdio.h>
#include "MacUILib.h"
#include "myStringLib.h"   // This is your first custom C library

// [TODO] Import the required library for rand() and srand()
#include <stdlib.h> 
// [TODO] Import the required library for accessing the current time - for seeding random number generation
#include <time.h> 





// PREPROCESSOR DIRECTIVE CONSTANTS
// ================================
// For program-wide constants, define them here using #define.  Add as seen needed.

// [COPY AND PASTE FROM PPA2] Copy your additional preprocessor constants from PPA2 and paste them below
#define row 10
#define col 20


// [TODO] Then, define more constants here as seen needed.





// GLOBAL VARIABLES
// ================================

// [COPY AND PASTE FROM PPA2] Copy your additional global from PPA2 and paste them below


int exitFlag; // Program Exiting Flag - old stuff

// For storing the user input - from PPA1
char input; 


char board[row][col]; 
char speed_display; 


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

struct objPos player_current_pos; 
struct objPos *itemBin; 

// [TODO] Declare More Global Variables as seen needed.

char global_string [] = "McMaster-ECE"; 
int move_item_count; 

// [TODO] Declare Global Pointers as seen needed / instructed in the manual.
char *mystery_string; 


// FUNCTION PROTOTYPES
// ================================
// Declare function prototypes here, so that we can organize the function implementation after the main function for code readability.

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// [TODO] In PPA3, you will need to implement this function to generate random items on the game board
//        to set the stage for the Scavenger Hunter game.
// list[]       The pointer to the Item Bin
// listSize     The size of the Item Bin (5 by default)
// playerPos    The pointer to the Player Object, read only.
// xRange       The maximum range for x-coordinate generation (probably the x-dimension of the gameboard?)
// yRange       The maximum range for y-coordinate generation (probably the y-dimension of the gameboard?)
// str          The pointer to the start of the Goal String (to choose the random characters from)
void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str);




// MAIN PROGRAM
// ===============================
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
// ===============================
void Initialize(void)
{
    MacUILib_init();

    MacUILib_clearScreen();

    // [COPY AND PASTE FROM PPA2] Copy your initialization routine from PPA2 and paste them below

    input = 0; // NULL
    exitFlag = 0;  // not exiting 

    player_current_pos.x = 4; 
    player_current_pos.y = 9; 
    player_current_pos.symbol = 64;   
    speed = speed_1; 
    speed_display = 49; 
    
    // [TODO] Initialize any global variables as required.
    exitFlag = 0;  // 0 - do not exit, non-zero - exit the program

    
    // [TODO] Allocated heap memory for on-demand variables as required.  Initialize them as required.
    mystery_string = malloc(my_strlen(global_string+1)*sizeof(char)); 
    int string_length = (my_strlen(global_string) + 1); 
    int i; 
    for(i = 0; i < string_length; i++)
    {
        mystery_string[i] = '?'; 
    }
    mystery_string[string_length-1] = '\0'; 
    itemBin = malloc(5 * ( sizeof(int) + sizeof(char) + sizeof(int)));

    srand(time(NULL)); 

    GenerateItems(itemBin, 5, &player_current_pos, row, col, global_string);

    // [TODO] Seed the random integer generation function with current time.

    // [TODO] Generate the initial random items on the game board at the start of the game.

    
}




// INPUT COLLECTION ROUTINE
// ===============================
void GetInput(void)
{

    // Asynchronous Input - non blocking character read-in
    
    // [COPY AND PASTE FROM PPA2] Copy your input collection routine from PPA2 and paste them below
    if ( MacUILib_hasChar() == 1) 
    {
        input = MacUILib_getChar(); 

    }

    // [TODO] Though optional for PPA3, you may insert any additional logic for input processing.

   
}




// MAIN LOGIC ROUTINE
// ===============================
void RunLogic(void)
{
    // [COPY AND PASTE FROM PPA2] Copy your main logic routine from PPA2 and paste them below

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
                if ( dir != UP ){
                    dir = DOWN; 
                }
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
   
    switch (dir)
    {
        case UP: 
            player_current_pos.x --; 
            move_item_count++; 
            break;
        
        case DOWN:
            player_current_pos.x++; 
            move_item_count++; 
            break;
        
        case RIGHT: 
            player_current_pos.y ++; 
            move_item_count++; 
            break; 
        
        case LEFT: 
            player_current_pos.y --; 
            move_item_count++; 
            break; 
    
        default:
            break;
    }

    if( player_current_pos.x == 0)
    {
        player_current_pos.x = row -1;
    }
    else if ( player_current_pos.x == row-1)
    {
        player_current_pos.x = 1; 
    }
    else if (player_current_pos.y == col-1)
    {
        player_current_pos.y = 1; 
    }
    else if ( player_current_pos.y == 0)
    {
        player_current_pos.y = col-1;
    }


    // [TODO]   Implement the Object Collision logic here
    //
    //      Simple Collision Algorithm
    //      1. Go through all items on board and list_check their (x,y) against the player object x and y.
    //      2. If a match is found, use the ASCII symbol of the collided character, and 
    //         find all the occurrences of this ASCII symbol in the Goal String
    //      3. For every occurrence, reveal its ASCII character at the corresponding location in the
    //         Collected String
    //      4. Then, determine whether the game winning condition is met.
    int k; 
    for (k = 0; k < 5; k++)
    {
        if (player_current_pos.x == itemBin[k].x && player_current_pos.y == itemBin[k].y)
        {   
            char collide_symbol = itemBin[k].symbol;
            int i; 
            for (i = 0; i < my_strlen(global_string); i++)
            {
                if (global_string[i] == collide_symbol)
                {
                    mystery_string[i] = collide_symbol;

                }
            }
            GenerateItems(itemBin, 5, &player_current_pos, row, col, global_string);

        }
    }
    // [TODO]   Implement Game Winning list_Check logic here
    //
    //      Game Winning list_Check Algorithm
    //      1. list_Check if the contents of the Collected String exactly matches that of the Goal String.
    //         YOU MUST USE YOUR OWN my_strcmp() function from Lab 3.
    //      2. If matched, end the game.
    //      3. Otherwise, discard the current items on the game board, and 
    //         generate a new set of random items on the board.  Game continues.
    if(my_strcmp(mystery_string, global_string) == 1 )
    {
        exitFlag = 1; 
    }
    
}



// DRAW ROUTINE
// ===============================
void DrawScreen(void)
{
       
    // [COPY AND PASTE FROM PPA2] Copy your draw logic routine from PPA2 and paste them below

    MacUILib_clearScreen(); 

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
            else if ( i == player_current_pos.x && j == player_current_pos.y )
            { 
                board[player_current_pos.x][player_current_pos.y] = player_current_pos.symbol;
                MacUILib_printf("%c", board[player_current_pos.x][player_current_pos.y]);
            }
            else
            {
            
                int item_found = 1;
                int k;
                for (k = 0; k < 5; k++)
                {
                    if (i == itemBin[k].x && j == itemBin[k].y)
                    {
                        board[i][j] = itemBin[k].symbol;
                        item_found = 0;
                        break;
                    }
                }
                if (item_found)
                {
                    board[i][j] = ' ';
                }

                MacUILib_printf("%c", board[i][j]);
            }
        }
        MacUILib_printf("\n");
    }
   
    // [TODO]   Insert somewhere in the draw routine to draw the randomly generated items on the board.

    // [TODO]   Display the "Mystery String" contents at the bottom of the game board
    //          To help players keep track of their game progress.
    MacUILib_printf("Use WASD to move, use 1-5 keys to increase/decrease speed\n\n"); 
    MacUILib_printf("Mystery-String: %s\n", mystery_string); 
    MacUILib_printf("Move item_count: %d\n", move_item_count); 
    MacUILib_printf("Current Speed: %c", speed_display); 
    
    
}



// DELAY ROUTINE
// ===============================
void LoopDelay(void)
{
    MacUILib_Delay(100000); // 0.1s delay
        
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





// TEAR-DOWN ROUTINE
// ===============================
void CleanUp(void)
{
    // [TODO]   To prevent memory leak, free() any allocated heap memory here
    //          Based on the PPA3 requirements, you need to at least deallocate one heap variable here.

    // Insert any additional end-game actions here.
    
    free(mystery_string); 
    free(itemBin); 
    MacUILib_uninit();
}




// The Item Generation Routine
////////////////////////////////////
void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str)
{
    

    // Random Non-Repeating Item Generation Algorithm
    ////////////////////////////////////////////////////

    // Use random number generator function, rand(), to generate a random x-y coordinate and a random choice of character from the Goal String as the ASCII character symbol.
    //      The x and y coordinate range should fall within the xRange and yRange limits, which should be the x- and y-dimension of the board size.
    // This will then be a candidate of the randomly generated Item to be placed on the game board.
// how many items have been generated

    srand(time(NULL)); 
    int item_count = 1; 
    do{
        int valid = 0; 
        int randX = (rand() % (xRange-2)) + 1; 
        int randY = ( rand() % (yRange-2))+ 1; 
        int rand_symbol_index = rand() % (my_strlen(global_string));



        int j; 
        for (j = 0; j < item_count; j++)
        {   
            if ((randX == (*playerPos).x && randY == (*playerPos).y)||(list[j].x == randX && list[j].y == randY) || (list[j].symbol == global_string[rand_symbol_index]))
            {
                valid = 1; 
                break; 
            }
        }
        if ( valid == 0)
        {
            list[item_count-1].x = randX; 
            list[item_count-1].y = randY; 
            if ((item_count-1) <=5)
            {
                list[item_count-1].symbol = global_string[rand_symbol_index]; 
            }
         
            item_count++;
        }
    }while(item_count <= listSize);

         // In order to make sure this candidate is validated, it needs to meet both criteria below:
        //  1. Its coordinate and symbol has not been previously generated (no repeating item)

        //  2. Its coordinate does not overlap the Player's position
        // Thus, for every generated item candidate, list_check whether its x-y coordinate and symbol has previously generated.  
        //  Also, list_check if it overlaps the player position
        //      If yes, discard this candidate and regenerate a new one
        //      If no, this candidate is validated.  Add it to the input list[]

        // There are many efficient ways to do this question
         //  We will take a deep dive into some methods in 2SI.
}
