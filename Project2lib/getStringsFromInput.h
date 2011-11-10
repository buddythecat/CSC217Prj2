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
	printf("Getting Words From User\n------------------------------------------------\n");
	//printf("getting string\n");
	/** the number of strings read */
	int i = 0;
	/** int j is a counter for the characters */
	int j = 0;
	/** inSpecialString is a flag for the  quotation based string */
	int inSpecialString=0;
	/** c is a temporary storage variable for the current character being read */
	char c;
	/** allocate the space for each string (max length 128 bytes) */
	char * temp = (char*)malloc(128 * sizeof (char));
	/**
	 * initialize the first loop.  This loop will run until the
	 * EOF is read from the input
	 */
	while((c = getchar())!=EOF){
		/** Check that we're not in a quoted-string, that c IS '\n' OR c is ' ' */
		if(	(!inSpecialString) && (c==0x0A || c==' ')){
			/** make sure that we're not in an empty word*/
			if(j!=0){
				/** attach the null character to the end of the string */
				*(temp+j) = '\0';
				/** assign the temporary string a spot in the array */
				lines[i]=temp;
				/** re-allocate the temporary array with spaces */
				temp = (char*)malloc(128 * sizeof (char));
				/** print out the word */
				printf("%s\n", lines[i]);
				/** increment the amount of words */
				i++;
				/** reset the char-counter */
				j=0;
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
				lines[i] = temp;
				/* reallocate all of our memory for the temp string */
				temp = (char*)malloc(128*sizeof(char));
				/* print out this special string */
				printf("%s\n", lines[i]);
				/* increment the character index */
				i++;
				/* reset our (in word) flag */
				j=0;
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
			lines[i] = temp;
			/* re-allocate our memory */
			temp = (char*)malloc(128*sizeof(char));
			/* print out the word */
			printf("%s\n", lines[i]);
			/* increment the number of word's */
			i++;
			/* set the char counter to zero */
			j=0;
			/* clear the inspecialString flag */
			inSpecialString = 0;
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
	printf("------------------------------------------------\nAmount of Lines: %d\n", i);
	/* return the number of words we've read in */
	return i;
}

