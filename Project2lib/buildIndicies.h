int buildIndicies(int* start, int* end, int* lines){
	if((*start>*lines) || (*end>*lines)){
		printf("Error: start must be less then the ending point, "
				"which must be less then the total number of lines\n"
				"Usage: project2 [-s <start> -e <end>]\n");
		return -1;
	}
	else{
		if(!(*start)){
			*start = (rand() % (*lines-1))+1;
			//create random number between 1 and lineno-1
		}
		if(!(*end)){
			*end = (rand() % (*lines - 1))+1;
			//create random number between start+1 and lineno
		}
		return 0;
	}
}
