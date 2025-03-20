#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int tinhDoDaiChuoi(char str[]);
bool kiemTraChuoiCon(char str[], char sub[]);

int main() {
    char str[80], sub[20];

    printf("Nhap chuoi da cho: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Nhap chuoi con: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = '\0';

    int lenStr = tinhDoDaiChuoi(str);
    int lenSub = tinhDoDaiChuoi(sub);

    if (lenSub > lenStr) {
        printf("Khong xet truong hop chuoi con co kich thuoc lon hon chuoi da cho.\n");
    } else {
        if (kiemTraChuoiCon(str, sub)) {
            printf("Chuoi con xuat hien trong chuoi da cho.\n");
        } else {
            printf("Chuoi con khong xuat hien trong chuoi da cho.\n");
        }
    }

    return 0;
}

int tinhDoDaiChuoi(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

bool kiemTraChuoiCon(char str[], char sub[]) {
    int lenStr = tinhDoDaiChuoi(str);
    int lenSub = tinhDoDaiChuoi(sub);
    int i, j, found;

    for (i = 0; i <= lenStr - lenSub; i++) {
        found = 1;
        for (j = 0; j < lenSub; j++) {
            if (str[i + j] != sub[j]) {
                found = 0;
                break;
            }
        }
        if (found) return true;
    }
    return false;
}

