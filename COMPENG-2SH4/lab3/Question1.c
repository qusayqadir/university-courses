#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"


int my_strlen(const char * const str1)
{
	// Returns the length of the string - the number of characters, but IGNORING the terminating NULL character
	int i, size = 0; 
	for (i = 0;  str1[i]!= '\0'; i++)
	{
		size++; 
	}
	return size; // had forgotten the return command that is why it was not working
}

int my_strcmp(const char * const str1, const char * const str2)
{
	// Return 0 if the two strings are not identical.  Return 1 otherwise.
	
	// Criteria 1: Check their lenghts.  If not the same length, not equal
	int i; 
	int str1_size = my_strlen(str1); 
	int str2_size = my_strlen(str2); 
	if ( str1_size != str2_size)
		return 0;
	
	// Criteria 2: Check their contents char-by-char.  If mismatch found, not equal
	else
	{
		// this can be done because the first check determines wheather the first 
		// and second string are the same size or not, and because they are,
		//they will move on to this check and they will be comapred at equal elements
		for ( i =0; i <= str1_size; i++) 
		{
			if (str1[i] != str2[i])
				return 0; 
		}
	}
	// if passing the two criteria, strings equal
	return 1; 
}


int my_strcmpOrder(const char * const str1, const char * const str2)
{
	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/
	int i; 
	for ( i =0; i < my_strlen(str1); i++)
	{
		if ( str2[i] < str1[i]){
			return 1; 
		}
		if (str2[i] > str1[i])
			return 0; 
	}

	// if two strings are completely identical in order, return -1.'

	if (my_strcmp(str1, str2))
	{
		return -1; 
	}
	// We are NOT looking for any custom alphabetical order - just use the integer values of ASCII character

}


char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL; 
	// Allocate a character array capable of holding the combined string contents of str1 and str2 on the heap
	z = malloc((my_strlen(str1) + my_strlen(str2) ) * sizeof(char) + 1); 
	// the 1 is for the null character
		
	/*write your implementation here*/
	
	int i, j; 
	for ( i = 0; str1[i]!= '\0'; i++)
	{
		z[i] = str1[i]; 
	}
	for ( j = 0; str2[j] != '\0'; j++)
	{
		z[i+j] = str2[j]; 
	}
	z[i+j] = '\0';
	/* finally, return the string*/
	return z; 
	
	// IMPORTANT!!  Where did the newly allocated memory being released?
	// THINK ABOUT MEMORY MANAGEMENT
	
}