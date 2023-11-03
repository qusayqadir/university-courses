#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr [])
{


    // This is the first programming (scripting) question without any initial setup as hints.

    // This is also the first question requiring you to come up with an algorithm on paper 
    // with mathematical analysis before implementing the code.

    // High Level Hint:
    //  Assume a 3x3 square matrix, look at the SUM of the row and column indices of each element.
    //  You should be able to see a numerical pattern after doing so.
    int size = 0; 
    //Pesudocode: 
    
    for(int i=0; i<N3; i++) {
        int row = 0;  
        int col = i; 
        while(col >= 0) { 
            arr[size] = mat[row][col];  
            row ++; 
            col --; 
            size++; 
        }
    }
    for ( int j = 1; j<=N3-1; j++){
        int row2 = j; 
        int col2 = N3-1; 
        while ( row2 <= N3-1) {
            arr[size] = mat[row2][col2]; 
            col2 --; 
            row2 ++; 
            size ++; 
        }
    } 
}
