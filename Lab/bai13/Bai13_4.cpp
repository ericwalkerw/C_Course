#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hocsinh {
    char hoten[50];
    int tuoi;
    char diachi[128];
    float gpa;
};

// ==== Function declarations ====
void nhapHocSinh(struct hocsinh ds[], int *count);
void xuatHocSinh(struct hocsinh ds[], int count);
void timKiemHocSinh(struct hocsinh ds[], int count);

int main() {
    struct hocsinh dsHocsinh[100];
    int count = 0;
    int choice = -1;

    do {
        printf("\n=========== MENU ===========");
        printf("\n0 : Thoat chuong trinh");
        printf("\n1 : Nhap thong tin hoc sinh");
        printf("\n2 : Xuat thong tin hoc sinh");
        printf("\n3 : Tim kiem hoc sinh theo ten");
        printf("\n===========================\n");

        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                nhapHocSinh(dsHocsinh, &count);
                break;
            case 2:
                xuatHocSinh(dsHocsinh, count);
                break;
            case 3:
                timKiemHocSinh(dsHocsinh, count);
                break;
            case 0:
                printf("Dang thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}

void nhapHocSinh(struct hocsinh ds[], int *count) {
    if (*count >= 100) {
        printf("Danh sach da day, khong the them hoc sinh moi.\n");
        return;
    }

    printf("\n====  Nhap thong tin hoc sinh  ====\n");

    printf("Ho ten: ");
    fgets(ds[*count].hoten, sizeof(ds[*count].hoten), stdin);
    ds[*count].hoten[strcspn(ds[*count].hoten, "\n")] = '\0';

    printf("Tuoi: ");
    scanf("%d", &ds[*count].tuoi);
    getchar();

    printf("Dia chi: ");
    fgets(ds[*count].diachi, sizeof(ds[*count].diachi), stdin);
    ds[*count].diachi[strcspn(ds[*count].diachi, "\n")] = '\0';

    printf("GPA: ");
    scanf("%f", &ds[*count].gpa);
    getchar();

    (*count)++;
}

void xuatHocSinh(struct hocsinh ds[], int count) {
    if (count == 0) {
        printf("Chua co hoc sinh nao trong danh sach.\n");
        return;
    }

    printf("\n====  Danh sach hoc sinh  ====\n");
    for (int i = 0; i < count; i++) {
        printf("Ho ten: %s\n", 	ds[i].hoten);
        printf("Tuoi: %d\n", 	ds[i].tuoi);
        printf("Dia chi: %s\n", ds[i].diachi);
        printf("GPA: %.2f\n", 	ds[i].gpa);
        printf("-------------------------\n");
    }
}

void timKiemHocSinh(struct hocsinh ds[], int count) {
    if (count == 0) {
        printf("Chua co hoc sinh nao trong danh sach.\n");
        return;
    }

    char tenTim[50];
    printf("Nhap ten hoc sinh can tim: ");
    fgets(tenTim, sizeof(tenTim), stdin);
    tenTim[strcspn(tenTim, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(ds[i].hoten, tenTim) == 0) {
            printf("\nTim thay hoc sinh:\n");
            printf("Ho ten: %s\n", 	ds[i].hoten);
            printf("Tuoi: %d\n", 	ds[i].tuoi);
            printf("Dia chi: %s\n", ds[i].diachi);
            printf("GPA: %.2f\n", 	ds[i].gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay hoc sinh co ten \"%s\".\n", tenTim);
    }
}

