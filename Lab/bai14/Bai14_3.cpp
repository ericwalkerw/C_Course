#include <stdio.h>
#define FILENAME "testlab14_1.txt"
int main(){
	FILE *fp = NULL;
	char ch;
	int linesCount = 1;
	
	fp = fopen(FILENAME, "r");
	
	if(fp == NULL){
		printf("File does not exist\n");
		return -1;
	}
	
	while((ch = fgetc(fp)) != EOF){
		if(ch =='\n')
			linesCount++;
	}
	
	fclose(fp);
	fp = NULL; 
	
	printf("so dong trong file: %d", linesCount);
	return 0;
}
