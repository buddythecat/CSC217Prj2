#include <stdio.h>
#include <stdlib.h>

/*
 * char* getWord
 * this function is used to actually get a word from the user's input.  It has will, on normal completion
 * return a string containing the word.  However, if this method reaches the end of the file
 * (or gets called on an empty input), it will flag the finished parameter as true, and return a null string.
 * ===============================================================
 * @param char first - the first character being read (by the calling method)
 * @param int* finished - a flag, false if not finished, true if finished
 */
char* getWord(char first, int* finished){
	/** int j is a counter for the characters */	
	int j = 0;
	/** inSpecialString is a flag for the  quotation based string */
	int inSpecialString=0;
	char c;

	char * temp = (char*)malloc(128 * sizeof (char));
	if(first!='\"'){
		*(temp+j)=first;
		j++;
	}
	else if(first=='\"'){
		inSpecialString=1;

	}
	while((c = getchar())!=EOF){
		/** Check that we're not in a quoted-string, that c IS '\n' OR c is ' ' */
		if(	(!inSpecialString) && (c==0x0A || c==' ')){
			/** make sure that we're not in an empty word*/
			if(j!=0){
				/** attach the null character to the end of the string */
				*(temp+j) = '\0';
				return temp;
			}
		}
		/**
		 * check if the current character is a '"'
		 * If it is, toggle that we're in a quoted-string,
		 * and we have to go into the special string loop.
		 */
		else if(c == '\"' && (!inSpecialString)){
			/** set the flag */
			inSpecialString = 1;
			/*
			 * this check is in here in case a quoted-string comes right after (no spaces)
			 * a non quoted string.  These two should be seperated, so therefor we should
			 * push the last word onto the list of words
			 */
			if(j>0){
				/* add the null character to the end */
				*(temp+j) = '\0';
				/* add the temp string into the array of strings */
				return temp;
			}
			//*(temp+j) = c;
		}
		/*
		 * check if c is a '"' and we ARE in a quoted-string
		 * this means that we're at the end of quoted-string
		 */
		else if(c == '\"' && (inSpecialString)){
			/*
			 * add the string to the list of strings
			 */
			*(temp+j) = '\0';
			/* put it in the array */
			return temp;
		}
		/*
		 * if we're in a special string, but not at the end,
		 * we should simply add the char being read to the
		 * end of the temporary string
		 */
		else if(inSpecialString){
			/* assign c to the next spot in the temporary string */
			*(temp+j) = c;
			/* inrement the number of chars */
			j++;
		}
		/*
		 * we're not in a special string, we haven't hit any watched characters...
		 * this condition simply adds the next char to the temporary string
		 */
		else{
			*(temp+j)=c;
			j++;
		}
	}
	//If we've reached here, then we've hit the end of the file.
	temp = "";
	*finished = 1;
	return temp;
}
