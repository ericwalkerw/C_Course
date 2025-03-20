#include <stdio.h>
#define max 10000

int main() {
    char str[max] = "";
    FILE* file = NULL;

    file = fopen("testlab14_1.txt", "r");

    if (file != NULL) {
        while (fgets(str, max, file) != NULL) {
            printf("%s", str);
        }
        fclose(file);
    } 
    
    return 0;
}
