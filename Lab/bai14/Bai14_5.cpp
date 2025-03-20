#include <stdio.h>

void renameFile() {
    char oldname[100], newname[100];
    int re;

    printf("Nhap ten file can doi ten: ");
    scanf("%s", oldname);

    printf("Nhap ten file moi: ");
    scanf("%s", newname);

    re = rename(oldname, newname);

    if (re == 0)
        printf("Doi ten file thanh cong!\n");
    else
        printf("Doi ten file that bai!\n");
}

void removeFile() {
    char filename[100];
    int rem;

    printf("Nhap ten file can xoa: ");
    scanf("%s", filename);

    rem = remove(filename);

    if (rem == 0)
        printf("Xoa file thanh cong!\n");
    else
        printf("Xoa file that bai!\n");
}

int main() {
    renameFile();
//    removeFile();
    return 0;
}

