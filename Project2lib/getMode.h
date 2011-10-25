char findModeofString(char* targetString, int caseSensitive){
	int tolower(int c);
	int i;
	int numThisChars, mostCharsFound = 0;
	char current, most;
	for(i=0; i<strlen(targetString); i++){
		numThisChars = 0;
		current = targetString[i];

		if(current != ' '){

			if((!caseSensitive) && (current>='A') && (current<='Z'))
				current = tolower(current);
			int j;
			for(j=0; j<strlen(targetString); j++){
				char temp = targetString[j];
				if((!caseSensitive) && (temp>='A') && (temp<='Z'))
					temp = tolower(temp);
				if(current == temp)
					numThisChars++;
			}
			if(numThisChars>mostCharsFound){
				mostCharsFound = numThisChars;
				most = current;
			}

		}
	}
	if(mostCharsFound==1)
		return 0;
	else
		return most;
}
