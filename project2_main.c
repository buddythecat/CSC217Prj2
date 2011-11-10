#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Project2lib/getStringsFromInput.h"
#include "Project2lib/getMode.h"
#include "Project2lib/combineSelectedStrings.h"
#include "Project2lib/buildIndicies.h"
/* MAXSIZE  - this is the maximum amount of strings that might be passed to this function*/
#define MAXSIZE 50

/*
 * CSC217Prj2 -
 * 		this program's function is to read input from a user, break up the input into
 * 		single words, and then to randomly(unless specified) find the mode of those two
 * 		words.
 * __USAGE:
 * 		CSC217Prj2 [first] [last] [-i]
 * 	WHERE:
 * 		-first 	: this is the first word we will find the mode of [OPTIONAL]
 * 		-second : this is the second word we will find the mode of  [OPTIONAL]
 * 		-i 		: specifies that when searching for the mode, we should be case-insensitive [OPTIONAL]
 * =======================================================================================
 * @param 	int 	argc 		- the number of arguments that have been passed to the program on the cmd line
 * @param 	char* 	argv[] 		- an array of strings storing the arguments that have been passed to the program on the cmd line
 * @return 	int 	success 	- returns 0 upon completion, and -1 upon an error
 * =======================================================================================
 * written by Rich "Dances With Caterpillars" Tufano
 */
int main(int argc, char *argv[]){
	/* seed the random number generator */
	srand ( time(NULL) );
	/* declare the space we'll use to store the current character while reading */
	int c;
	/*
	 * declare our flags:
	 * 	start -> the starting word to check
	 * 	end -> the ending word to check
	 * 	caseSensitive -> the flag to decide whether we compare case sensitively
	 */
	int start = 0, end = 0, lineno = 0, caseSensitive = 1;
	/* declare the array of strings */
	char * line[MAXSIZE];
	/* loop through the array and instantiate the space for each string */
	int i;
	for(i=0; i<MAXSIZE; i++){
		line[i] = malloc(11*sizeof(char));
	}
	/*
	 * loop through the command-line arguments -
	 * when the loop reads a char between '0' and '9', it'll know that
	 * we're reading a index (either start or end), or it'll read '-',
	 * which then means we might be flagged for case-sensitivity.
	 *
	 * The loop will short-circuit after all of the args have been read.
	 *
	 */
	while ( --argc > 0 && ((*++argv)[0] == '-' || (*argv)[0] >= '0' && (*argv)[0]<='9') ){
		/* c is going to get the current char being read */
		c = *argv[0];
		/* check to see if c is between '0' and '9' */
		if((c>'0') && (c<'9')){
			/** if start isn't assigned, asign it the value of *argv (the whole string) */
			if(!start){
				start = atoi(*argv);
			}
			/** if start IS assigned, but end isn't, assign end the value of *argv (the whole string) */
			else if(!end){
				end = atoi(*argv);
			}
			/** if start and end have been assigned, but we have another number on the command line, throw an error */
			else{
				printf("Too many indices: %d, %d, %c", start, end, c);
			}
		}
		/** if c is a '-', check to make sure that the 'i' flag follows; if not, throw an error		 */
		else if(c=='-'){
			if((c = *++argv[0])=='i'){
				caseSensitive = 0;
			}
			/** throw the error here and set argc to 0 to break the loop*/
			else{
				printf("Illegal argument %c\n"
						"Usage: project2 [<start> <end>] [-i]\n", c);
				argc=0;
			}
		}

	}
	/*
	* Now, check that we have a the string on the line
	*/
	if(argc != 0)
		return -1;
	/*
	* At this point, the argument check has succeeded.  Now it's time to start
	* doing the dirty work
	*/
	else{
		/* first get the strings from the user; passing in the char* array [line] */
		lineno = getStringsFromUser(line);
		/* once we have the array of Strings, build the indicies (the indexes of the two numbers to compare */
		if(buildIndicies(&start, &end, &lineno)==-1){
			/* if buildIndicies returns -1, it failed, and it should print out 'error' */
			/* end the program */
			return -1;
		}
		int printLoop;
		printf("Getting Words From User\n------------------------------------------------\n");
		for(printLoop = 0; printLoop<lineno; printLoop++){
			printf("%s\n",line[printLoop]);
		}
		printf("------------------------------------------------\nAmount of Lines: %d\n", lineno);
		/* print the starting index and ending index */
		printf("index of first word [%d] -- index of second word [%d] \n",start, end);
		printf("------------------------------------------------\n");
		/* create a temp string that holds the two strings we'll be checking the mode of */
		char* tempString = combineSelectedStrings(line[start-1], line[end-1]);

		/* Print the concat'd string (for testing) */
		//printf("%s \n", tempString);

		/*
		 * find the mode of the string by calling findModeOfString, passing in the string
		 * and the caseSensitive flag.  Assign the mode of the string to a storage char, mode
		 */
		char mode = findModeofString(tempString, caseSensitive);
		/*
		 * if the mode of the string exists, print out the String, with it's mode.
		 * if no mode exists, just print out the string and inform the user there is no mode
		 */
		if(mode)
			printf("Combined String:\n \"%s\""
					"\n------------------------------------------------\n"
					"Mode of String: %c\n"
					"------------------------------------------------\n"
					,tempString, mode);
		else
			printf("Combined String:\n \"%s\""
					"\n------------------------------------------------\n"
					"Mode of String: No Mode\n"
					"------------------------------------------------\n"
					,tempString);
	}
	/* exit the main method with a succesful completion status */
	return 0;

}
