#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Project2lib/getStringsFromInput.h"
#include "Project2lib/getMode.h"
#include "Project2lib/combineSelectedStrings.h"
#include "Project2lib/buildIndicies.h"
/* MAXSIZE  - this is the maximum amount of strings that might be passed to this function*/
#define MAXSIZE 120


/**
 * ==============================================================================
 * function main -
 * this function is the main method for the project.
 * on the command-line, the user may supply two switches:
 * -s x :: word to start from
 * -e y :: word to end from
 * "argument" :: the text to parse
 *
 * x must be less then the number of words in the string AND less then y, if y is provided
 * y musMAXLINEt be less then the number of words in the string, and greater then x if x is provided
 * ==============================================================================
 */
int main(int argc, char *argv[]){
	srand ( time(NULL) );
	int c;
	int start = 0, end = 0, lineno = 0, caseSensitive = 1;
	char * line[MAXSIZE];
	int i;
	for(i=0; i<MAXSIZE; i++){
		line[i] = malloc(11*sizeof(char));
	}
	/*
	 * loop through the arguments passed on the cmd line, break on '-' or when argc > 0
	 * if the argv[0] is '-', check the following letter for 's' or 'e', if it's either
	 * of these, store the value in either start or end.
	 *
	 * if the loop hits '-', it gets the character after, and if that character is 's' or 'e',
	 * it increments argv and gets the next string on the command line, which should be the number to
	 * stop/start at.
	 *
	 * at the top of the loop, argv will be incremented again, and will therefor have another chance
	 * to hit another argument, or '-'.
	 *
	 * The loop will short-circuit after all of the args have been read.
	 *
	 */
	while ( -- argc > 0 && (*++argv)[0] == '-'){
		/* c is going to get the char after the - */
		switch ( (c = *++argv[0])){
		/* if c is 's', the next string on the line is the index to start at */
		case 's':
			start = atoi(*++argv);
			--argc;
			break;
		/* if c is 'e', the next string on the line is the index to stop at */
		case 'e':
			end = atoi(*++argv);
			--argc;
			break;
		case 'i':
			caseSensitive = 0;
			break;
		default:
			printf("Illegal argument %c\n", c);
			argc = 0;
			break;
		}
	}
	/*
	* Now, check that we have a the string on the line
	*/
	if(argc != 0)
		printf("error");
	/*
	* Read the last line in
	*/
	else{
		lineno = getStringsFromUser(line);

		buildIndicies(&start, &end, &lineno);

		printf("start %d, end %d \n",start, end);

		char* tempString = combineSelectedStrings(line[start-1], line[end-1]);
		/* Concat the two selected Strings */

		/* Print the concat'd string (for testing) */
		printf("%s \n", tempString);

		char mode = findModeofString(tempString, caseSensitive);

		if(mode)
			printf("The mode is %c\n",mode);
		else
			printf("There is no mode in this string.\n");
	}
	return 0;

}
