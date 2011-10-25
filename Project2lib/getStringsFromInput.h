int getStringsFromUser(char * lines[]){
	printf("getting string\n");
	int i = 0, j = 0, inSpecialString=0;
	char c;
	char * temp = (char*)malloc(128 * sizeof (char));
	while((c = getchar())!=EOF){
		if(	(!inSpecialString) && (c==0x0A || c==' ')){
			if(j!=0){
				*(temp+j) = '\0';
				lines[i]=temp;
				temp = (char*)malloc(128 * sizeof (char));
				printf("line: %s\n", lines[i]);
				i++;
				j=0;
			}
		}
		else if(c == '\"' && (!inSpecialString)){
			inSpecialString = 1;
			if(j>0){
				*(temp+j) = '\0';
				lines[i] = temp;
				temp = (char*)malloc(128*sizeof(char));
				printf("line: %s\n", lines[i]);
				i++;
				j=0;
			}
			//*(temp+j) = c;
		}
		else if(c == '\"' && (inSpecialString)){
			*(temp+j) = '\0';
			lines[i] = temp;
			temp = (char*)malloc(128*sizeof(char));
			printf("line: %s\n", lines[i]);
			i++;
			j=0;
			inSpecialString = 0;
		}
		else if(inSpecialString){
			*(temp+j) = c;
			j++;
		}
		else{
			*(temp+j)=c;
			j++;
		}
	}
	return i;
}

