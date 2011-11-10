#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * char* combineSelectedStrings -
 * this method takes two strings and concats them into one string,
 * and then returns the new string.
 * =======================================================================================
 * @param char* first - the first string to combine
 * @param char* second - the second string to combine
 * @return char* result - the result of the combination
 * =======================================================================================
 * written by Rich "Dances With Caterpillars" Tufano
 */
char* combineSelectedStrings(char* first, char* second){
	/* allocate the memory for the new string */
	char* tempString = (char*)malloc(sizeof(first)+sizeof(second)+sizeof(char));
	/* copy the contents of the first string into temp */
	strcpy(tempString, first);
	/* concat a space onto the temp string to seperate the two words */
	strcat(tempString, " ");
	/* concat the second word onto the temp string */
	strcat(tempString, second);
	/* return the temp string */
	return tempString;
}
