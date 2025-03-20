#include <stdio.h>
#include <stdbool.h>

int strLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void strConcat(char dest[], const char src1[], const char src2[]) {
    int i = 0, j = 0;

    while (src1[i] != '\0') {
        dest[i] = src1[i];
        i++;
    }

    while (src2[j] != '\0') {
        dest[i] = src2[j];
        i++;
        j++;
    }

    dest[i] = '\0'; 
}

bool strCompare(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

int main() {
    char s1[] = "Hello";
    char s2[] = "World";
    char result[100];

    // Test strLength
    printf("Do dai chuoi s1: %d\n", strLength(s1));

    // Test strConcat
    strConcat(result, s1, s2);
    printf("Chuoi sau khi noi: %s\n", result);

    // Test strCompare
    if (strCompare(s1, s2)) {
        printf("Hai chuoi giong nhau.\n");
    } else {
        printf("Hai chuoi khac nhau.\n");
    }

    return 0;
}

