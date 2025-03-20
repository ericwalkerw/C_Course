#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Prototype
void nhapChuoi(char str[]);
void loaiKyTuKhongHopLe(char str[]);
void xuatChuoi(char str[]);

int main() {
    char str[100];

    nhapChuoi(str);
    loaiKyTuKhongHopLe(str);
    xuatChuoi(str);

    return 0;
}

void nhapChuoi(char str[]) {
    printf("Nhap chuoi: ");
    fgets(str, 100, stdin);
    
	str[strcspn(str, "\n")] = '\0';
}

void loaiKyTuKhongHopLe(char str[]) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        while (!isalnum(str[i]) && str[i] != '\0') { 
            for (j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1]; 
            }
        }
    }
}

void xuatChuoi(char str[]) {
    printf("Chuoi sau khi loai bo ky tu dac biet: %s\n", str);
}

