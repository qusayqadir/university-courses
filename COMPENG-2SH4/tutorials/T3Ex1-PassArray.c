#include <stdio.h>
#define SIZE 10

void scalarMultiply(int array[], const int size, const int scalar)
{
    // we will use standard for-loop for this algorithm
    int i;
    for(i=0; i < size; i++)
    {
        array[i] = array[i]*scalar; 
    }
    

}

void printArray(const int array[], const int size)
{
    // WYSIWYG!!  Deploy this function so you can print the array contents to visually confirm the contents

}

int main(void)
{
    int numBuf[SIZE] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};	
    printf("Array Contents before Scaling is: \n");
    printArray(numBuf, SIZE);


    // Scale vector by 3
    scalerMultiply(numBuf, SIZE, 3);
    
    
    printf("Array Contents after Scaling is: \n");
    printArray(numBuf, SIZE);

    return 0;
}