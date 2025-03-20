#include <stdio.h>

int main(){
	FILE *fp;
    char str[100];

    fp = fopen("testlab14_1.txt", "w");
    
    if (fp == NULL) {
        printf("cannot open file!\n");
        return 1;
    }

    printf("Nhap text can luu: ");
    fgets(str, sizeof(str), stdin);

    fprintf(fp, "Thong tin duoc ghi vao file: %s\n", str);

    fclose(fp);

    printf("Thong tin da duoc ghi thanh cong.\n");
    return 0;
}
