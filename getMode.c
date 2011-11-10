#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * char getModeofString -
 * getModeOfString takes in a string, and a flag caseSensitive, and then searches
 * the string for the most common character.
 * if caseSensitive is true (1), the method will search case sensitively.
 * if caseSensitive is false (0), the method will search insensitively.
 * the method will return the mode of the string as a char
 * =======================================================================================
 * @param 	char* 	targetString	- the string to search
 * @param 	int 	caseSensitive   - the sensitivity flag (0 insensitive; 1 sensitive)
 * @return 	char 	mode 		    - the mode of this string
 * =======================================================================================
 * written by Rich "Dances with Caterpillars" Tufano
 */
char findModeofString(char* targetString, int caseSensitive){
	/* specify the function toLower whose parameter is int, and who returns an int */
	int tolower(int c);
	/* int i is the index of the character being read */
	int i;
	/*
	 * numThisChars - counter for the number current character foudn
	 * mostCharsFound - counter for the character most found
	 */
	int numThisChars, mostCharsFound = 0;
	/**
	 * current - the current character being read
	 * most - the character who's been found the most
	 */
	char current, most;
	/* start the loop, and run it for as long as i is less then the length of the target string	 */
	for(i=0; i<strlen(targetString); i++){
		/* set the number this character has been found to 0 */
		numThisChars = 0;
		/* set current to the character at index i in the target string */
		current = targetString[i];
		/*if current is not equal to a space, we'll check and see how many times it appears */
		if(current != ' '){
			/*
			 * this is the check to see whether or not we're searching sensitively.
			 * if we're note case sensitive, and the current character is an uppercase
			 * char, we're going to convert the current character it's lowercase brethren.
			 * If we are case sensitive, simply step over this loop and do nothing.
			 */
			if((!caseSensitive) && (current>='A') && (current<='Z'))
				current = tolower(current);
			/* declare an index for the inner loop (to search for the current char) */
			int j;
			/* this loop will start from index 0, and will run as long as j is less then the length of the target string */
			for(j=0; j<strlen(targetString); j++){
				/* assign a temporary character to store the value targetstring at index j */
				char temp = targetString[j];
				/*
				 * another case sensitivity check.
				 * If we're searching sensitively, skip this check.
				 * if we're searching insensitively, convert the temporary char to it's
				 * lower case brother.
				 */
				if((!caseSensitive) && (temp>='A') && (temp<='Z'))
					temp = tolower(temp);
				/* now check to see if the current character we're looking for is equal to the character we've found at position j */
				if(current == temp)
					/* if it is, increment the number of the current character found */
					numThisChars++;
			}
			/* check to see if the number of this character found is greater then the most character found */
			if(numThisChars>mostCharsFound){
				/* if it is, then this character is currently the mode of the string */
				mostCharsFound = numThisChars;
				most = current;
			}

		}
	}
	/* if mostCharsFound is still equal to one at the end of this loop, then there is no mode; return 0 */
	if(mostCharsFound==1)
		return 0;
	/* for any other result, return the character that's been found the most */
	else
		return most;
}
