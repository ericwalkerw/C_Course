#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
#define FILENAME1 "test1.txt"
#define FILENAME2 "test2.txt"
#define FILENAME3 "test3.txt"

void getContentFromFile(const char *fileName, char *str) {
    FILE *fp = fopen(fileName, "r");
    char temp[MAX];

    if (fp == NULL) {
        printf("Cannot open file %s\n", fileName);
        return;
    }

    while (fgets(temp, MAX, fp) != NULL) {
        strcat(str, temp);
    }

    fclose(fp);
}

void writeContentToFile(const char *fileName, char *str){
	FILE *fp = fopen(fileName, "w");
	if (fp == NULL) {
    	printf("Cannot create file %s\n", fileName);
    	return;
    }

    fputs(str, fp);
    fclose(fp);
}

int main() {
    char str1[MAX] = "", str2[MAX] = "", str3[MAX] = "";

    getContentFromFile(FILENAME1, str1);
    getContentFromFile(FILENAME2, str2);

    strcpy(str3, str1);
    strcat(str3, str2);

	writeContentToFile(FILENAME3, str3);
	
    printf("Ghi noi dung vao file 3 thanh cong!\n", FILENAME1, FILENAME2, FILENAME3);
    return 0;
}

