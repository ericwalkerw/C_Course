#include <stdio.h>
#include <math.h>

// Prototype
int UCLN(int a, int b);
float giatrituyetdoi(float x);
unsigned long long giaithua(int n);
float khoangcach(float x1, float y1, float x2, float y2);

int main() {
    int choice;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Tim UCLN cua 2 so nguyen\n");
        printf("2. Tinh gia tri tuyet doi\n");
        printf("3. Tinh giai thua\n");
        printf("4. Tinh khoang cach giua 2 diem (A, B)\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int a, b;
                printf("Nhap 2 so nguyen khong am a va b: ");
                scanf("%d%d", &a, &b);
                printf("UCLN(%d, %d) = %d\n", a, b, UCLN(a, b));
                break;
            }

            case 2: {
                float x;
                printf("Nhap so thuc: ");
                scanf("%f", &x);
                printf("Gia tri tuyet doi: %.2f\n", giatrituyetdoi(x));
                break;
            }

            case 3: {
                int n;
                printf("Nhap so nguyen n (n >= 0): ");
                scanf("%d", &n);
                if (n < 0)
                    printf("Khong tinh duoc giai thua cho so am.\n");
                else
                    printf("%d! = %llu\n", n, giaithua(n));
                break;
            }

            case 4: {
                float x1, y1, x2, y2;
                printf("Nhap toa do diem A (x1 y1): ");
                scanf("%f%f", &x1, &y1);
                printf("Nhap toa do diem B (x2 y2): ");
                scanf("%f%f", &x2, &y2);
                printf("Khoang cach AB = %.2f\n", khoangcach(x1, y1, x2, y2));
                break;
            }

            case 0:
                printf("Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }

    } while (choice != 0);

    return 0;
}

// Ham tim uoc chung lon nhat
int UCLN(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Ham tinh gia tri tuyet doi
float giatrituyetdoi(float x) {
    return (x < 0) ? -x : x;
}

// Ham tinh giai thua
unsigned long long giaithua(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Ham tinh khoang cach giua 2 diem
float khoangcach(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

