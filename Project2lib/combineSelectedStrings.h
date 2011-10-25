char* combineSelectedStrings(char* first, char* second){
	char* tempString = (char*)malloc(sizeof(first)+sizeof(second)+sizeof(char));
	strcpy(tempString, first);
	strcat(tempString, " ");
	strcat(tempString, second);
	return tempString;
}
