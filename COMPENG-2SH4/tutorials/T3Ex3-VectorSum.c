#include <stdio.h>
#define SIZE 10

// Add const qualifiers in front of parameters that you don't want to accidentally alter in the function
//  Notice that the output array is NOT const restricted, becase we INTEND TO CHANGE IT :)
void vectorSum(const int array1[], const int array2[], int arrayOut[], const int size)
{
    // we will try use do-while-loop for this algorithm
    int i; 
    for(i=0; i<size; i++){
        arrayOut[i] = array1[i] + array2[i]; 
    }
    
    do{
        arrayOut[i] = array1[i] + array2[i];
        i++
    }while(i<size); 

}

// Add const qualifiers for all parameters in printArray because this function is only intended to read and display.
void printArray(const int array[], const int size)
{
    // WYSIWYG!!  Deploy this function so you can print the array contents to visually confirm the contents
    
    // copy your printArray from Ex1 :)
}

int main(void)
{

    int numBuf1[SIZE] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};	
    int numBuf2[SIZE] = {1, 2, 3, 2, 1, 2, 3, 2, 1, 2};	
    int numBufResult[SIZE] = {0};  // this is how you can initialize all elements in an array to be zero.

    printf("Array 1 Content is: \n");
    printArray(numBuf1, SIZE);
    printf("Array 2 Content is: \n");
    printArray(numBuf2, SIZE);

    vectorSum(numBuf1, numBuf2, numBufResult, SIZE);
        
    printf("Vector Sum of the two arrays is: \n");
    printArray(numBufResult, SIZE);

    return 0;
}