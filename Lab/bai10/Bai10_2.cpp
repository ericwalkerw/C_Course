#include <stdio.h>
#include <string.h>

void nhapChuoi(char name[][50], int n);
void sapXepChuoi(char name[][50], int n);
void inChuoi(char name[][50], int n);

int main() {
    int n;
    char name[25][50];

    printf("Nhap so luong chuoi: ");
    scanf("%d", &n);
    getchar();

    nhapChuoi(name, n);
    sapXepChuoi(name, n);
    inChuoi(name, n);

    return 0;
}

void nhapChuoi(char name[][50], int n) {
    printf("Nhap cac chuoi:\n");
    for (int i = 0; i < n; i++) {
        printf("Chuoi %d: ", i + 1);
        fgets(name[i], 50, stdin);
    }
}

void sapXepChuoi(char name[][50], int n) {
    char temp[50];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(name[j], name[j + 1]) > 0) {
                strcpy(temp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], temp);
            }
        }
    }
}

void inChuoi(char name[][50], int n) {
    printf("\nCac chuoi sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        puts(name[i]);
    }
}

