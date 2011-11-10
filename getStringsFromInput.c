#include <stdio.h>
#include <stdlib.h>
#include "Project2lib/getWord.h"
/*
 * int geStringsFromUser -
 * this method is responsible for reading lines coming from the user.
 * The method accepts an array of char* that's used for storing all
 * of the strings being read from the user, and it returns the number
 * words that have been read.
 * =======================================================================================
 * @param 	char** 	lines 	- the array of strings to store the input
 * @return 	int 	lineNum - the number of lines read in by this method
 * =======================================================================================
 * written by Rich "Dances With Caterpillars" Tufano
 */
int getStringsFromUser(char * lines[]){
	//printf("getting string\n");
	/** the number of strings read */
	int i = 0;
	int finished = 0;
	/** c is a temporary storage variable for the current character being read */
	char * temp = (char*)malloc(128 * sizeof (char));
	char c;
	while(!finished && (c=getchar())!=EOF){
		//printf("here%d\n",finished);
		temp = getWord(c, &finished);
		if(temp!=""){
			lines[i]=temp;
			//printf("%s", lines[i]);
			i++;
		}
	}
	/* return the number of words we've read in */
	return i;
}

