#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


// this is the very first question without hints in the comments.  read the manual to develop your own algorithm

// Read Questions.h to understand the definition of Q3Struct

void efficient(const int source[], struct Q3Struct effVector[], int size)
{
    int vector_index = 0; 
    int i; 
    for ( i=0; i < size; i++) {
        if(source[i] != 0 ) {
            effVector[vector_index].val = source[i]; 
            effVector[vector_index].pos = i;
            vector_index++;  
        }
    }
    
}

void reconstruct(int source[], int m, const struct Q3Struct effVector[], int n)
{
    // m represents size array of source
    // n represents is size of array effVector ( .val and .pos will have the same size)
    int j; 
    for ( j= 0; j <m; j++ ) 
    {
        source[j] = 0; 
    }
    for (int k = 0; k < n; k++) 
    {
        if(effVector[k].val != 0 ) 
        {
            source[effVector[k].pos] = effVector[k].val; 
        }
    }
}
