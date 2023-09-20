#include <stdio.h>
#define SIZE 10

// Add const qualifiers in front of parameters that you don't want to accidentally alter in the function
int dotProduct(const int array1[], const int array2[], const int size)
{
    // we will try use while-loop for this algorithm

    int i, sum=0; 
    for(i=0; i < size; i++) 
    {
        sum = sum + (array1[i]*array2[i]); 
    
    }
    /*
    while (i<size)
    {
        sum = sum + (array1[i]*array2[i]); 
        i++; 

    }
    
    */

}

void printArray(const int array[], const int size)
{
    // WYSIWYG!!  Deploy this function so you can print the array contents to visually confirm the contents
    int i; 
    for (i=0; i<size; i++)
    {
        printf("%d\n", array[i]);

    }
    // copy your printArray from Ex1 :)
}

int main(void)
{
    int numBuf1[SIZE] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};	
    int numBuf2[SIZE] = {1, 2, 3, 2, 1, 2, 3, 2, 1, 2};	
    int result = 0;

    printf("Array 1 Content is: \n");
    printArray(numBuf1, SIZE);
    printf("Array 2 Content is: \n");
    printArray(numBuf2, SIZE);

    result = dotProduct(numBuf1, numBuf2, SIZE);
        
    printf("Dot Product of the two arrays is: %d\n", result);
    
    return 0;
}