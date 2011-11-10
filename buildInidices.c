#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * int buildIndicies -
 * the buildIndicies method takes parameters for the first index to use
 * for, the second index to use, and the number of lines in the parsed text.
 * All of these parameters are passed into the function as pointers, so that they
 * can be manipulated by the function __BECAUSE__
 * 		if start, or end, are passed into the function as 0, we have to actually
 * 		  randomly come up with values for one or both of these indices.
 * Therefor, this method will first:
 * 	check to make sure start and end are within the range of [0, lines]
 *  check to see if start is non-zero -> if it isn't we will deterimine a value for start
 *  check to see if end is non-zero -> if it isn't, we will determine a value for start
 * The function will then return 0 upon safe completion
 * =======================================================================================
 * @param 	int* start 	- the first index to use for mode-comparison
 * @param 	int* end 	- the second index to use for mode-comparison
 * @param 	int* lines 	- the number of lines the program has parsed
 * @return 	int			- 0 for a clean completion, -1 for an error
 * =======================================================================================
 * written by Rich "Dances With Caterpillars" Tufano
 */
int buildIndicies(int* start, int* end, int* lines){
	/*
	 * first check is to make sure that start and end are in the valid domain
	 * this domain is [0, lines}.
	 * if one of them isn't, the method will print out the correct usage,
	 * and then return with a value of -1 (error)
	 */
	if((*start>*lines) || (*end>*lines) || (*start<0) || (*end<0)){
		printf("Error: start must be less then the ending point, "
				"which must be less then the total number of lines\n"
				"Usage: project2 [<start> <end>] [-i]\n");
		return -1;
	}
	/*
	 * if both start and end are valid, we're going to check to see if they've been
	 * specified by the user.
	 */
	else{
		/* if start is 0, we need to create a value for the starting index */
		if(!(*start)){
			/* to do this, we're going to create a random number between 1, and lineNo-1
			 * by getting a random number, and finding the remainder of random/(lines-1)
			 * we then need to add 1 to the value to make sure it's indexed properly (the
			 * instructions were to have it index the strings in a human-readable format).
			 */
			*start = (rand() % (*lines-1))+1;
		}
		/* do the same for the ending value as we did for the starting value, if end is 0 */
		if(!(*end)){
			/* same thing as above */
			*end = (rand() % (*lines - 1))+1;
		}
		/* return zero upon succesful completion */
		return 0;
	}
}
