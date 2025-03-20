#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define EPSILON 0.0001

// Dinh nghia cau truc luu toa do diem
struct Points {
    int x, y;
};

// Ham nhap toa do diem tu ban phim
struct Points inputPointValue(char name) {
    struct Points p;
    printf("\nInput x: ");
    scanf("%d", &p.x);
    printf("Input y: ");
    scanf("%d", &p.y);
    printf("\ntoa do diem %c: (%d,%d)\n", name, p.x, p.y);
    return p;
}

// Ham kiem tra 3 diem co tao thanh tam giac hay khong
int kiemtra_tamgiac(struct Points A, struct Points B, struct Points C) {
    int cross = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
    return cross != 0;
}

// Ham tinh do dai canh tam giac tu 2 diem
float canh_tamgiac(struct Points A, struct Points B, char name[]) {
    float distance = sqrtf((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
    printf("\nChieu dai canh %s : %.2f (%s)", name, distance, "cm");
    return distance;
}

// Ham tinh goc cua tam giac theo dinh su dung dinh ly cosine
float goc_tamgiac(float AB, float AC, float BC, char goc) {
    float cosA = (AB*AB + AC*AC - BC*BC) / (2 * AB * AC);
    if (cosA > 1) cosA = 1;
    if (cosA < -1) cosA = -1;
    float angle = acos(cosA) * 180.0 / PI;
    printf("\nGoc %c: %.2f", goc, angle);
    return angle;
}

// Ham tinh do dai duong trung tuyen tu 1 dinh
float tinh_trung_tuyen(float a, float b, float c, char name[]) {
    float trung_tuyen = 0.5 * sqrtf(2 * b * b + 2 * c * c - a * a);
    printf("\nDo dai duong trung tuyen %s: %.2f", name, trung_tuyen);
    return trung_tuyen;
}

// Ham tinh do dai duong cao tu 1 dinh
float tinh_duong_cao(float a, float b, float c, char name) {
    float s = (a + b + c) / 2.0;
    float S = sqrtf(s * (s - a) * (s - b) * (s - c));
    float h = (2 * S) / a;
    printf("\nDuong cao tu dinh %c: %.2f (%s)", name, h, "cm");
    return h;
}

// Ham tinh dien tich tam giac theo day va chieu cao
float tinh_dientich(float day, float cao) {
    float s = 0.5 * day * cao;
    printf("\nDien tich tam giac ABC: %.2f (%s)", s, "cm^2");
    return s;
}

// Kiem tra tam giac deu (3 canh bang nhau)
int la_tamgiac_deu(float AB, float AC, float BC) {
    return fabs(AB - AC) < EPSILON && fabs(AB - BC) < EPSILON;
}

// Kiem tra tam giac can (co 2 canh bang nhau)
int la_tamgiac_can(float AB, float AC, float BC) {
    return fabs(AB - AC) < EPSILON || fabs(AB - BC) < EPSILON || fabs(AC - BC) < EPSILON;
}

// Kiem tra goc vuong
char goc_vuong(float A, float B, float C) {
    if (fabs(A - 90) < EPSILON) return 'A';
    if (fabs(B - 90) < EPSILON) return 'B';
    if (fabs(C - 90) < EPSILON) return 'C';
    return '\0';
}

// Kiem tra goc tu
char goc_tu(float A, float B, float C) {
    if (A > 90) return 'A';
    if (B > 90) return 'B';
    if (C > 90) return 'C';
    return '\0';
}

// Xac dinh dinh doi dien voi 2 canh bang nhau trong tam giac can
char dinh_can(float AB, float AC, float BC) {
    if (fabs(AB - AC) < EPSILON) return 'B';
    if (fabs(AB - BC) < EPSILON) return 'C';
    if (fabs(AC - BC) < EPSILON) return 'A';
    return '\0';
}

// Xac dinh dinh co goc lon nhat
char goc_lon_nhat(float A, float B, float C) {
    if (A >= B && A >= C) return 'A';
    if (B >= A && B >= C) return 'B';
    return 'C';
}

// Ham phan loai tam giac dua tren do dai canh va do lon goc
void xet_loai_tamgiac(float AB, float AC, float BC, float A, float B, float C) {
    int deu = la_tamgiac_deu(AB, AC, BC);
    int can = la_tamgiac_can(AB, AC, BC);
    char vuong = goc_vuong(A, B, C);
    char tu = goc_tu(A, B, C);
    char canhCan = dinh_can(AB, AC, BC);
    char nhon = goc_lon_nhat(A, B, C);

    if (deu) {
        printf("ABC la tam giac deu\n");
    } else if (vuong && can) {
        printf("ABC la tam giac vuong can tai dinh %c\n", vuong);
    } else if (tu && can) {
        printf("ABC la tam giac tu va can tai dinh %c\n", tu);
    } else if (!vuong && !tu && can) {
        printf("ABC la tam giac can tai dinh %c\n", canhCan);
    } else if (vuong) {
        printf("ABC la tam giac vuong tai dinh %c\n", vuong);
    } else if (tu) {
        printf("ABC la tam giac tu tai dinh %c\n", tu);
    } else {
        printf("ABC la tam giac nhon tai dinh %c\n", nhon);
    }
}

// Ham tinh va in toa do trong tam tam giac
void tinh_trongtam(struct Points A, struct Points B, struct Points C) {
    float xG = (A.x + B.x + C.x) / 3.0;
    float yG = (A.y + B.y + C.y) / 3.0;
    printf("\nToa do trong tam: [%.2f, %.2f]\n", xG, yG);
}

// Ham tong hop de giai ma tam giac: tinh canh, goc, phan loai, duong cao, trung tuyen, dien tich, trong tam
void giaima_tamgiac(struct Points A, struct Points B, struct Points C) {
    if (!kiemtra_tamgiac(A, B, C)) {
        printf("Toa do 3 diem nhap vao khong tao thanh 1 tam giac\n");
        return;
    }

    printf("Toa do 3 diem nhap vao tao thanh 1 tam giac\n");

    printf("\n---- GOC, CANH TAM GIAC ----");
    float AB = canh_tamgiac(A, B, "AB");
    float BC = canh_tamgiac(B, C, "BC");
    float CA = canh_tamgiac(C, A, "CA");

    float angleA = goc_tamgiac(AB, CA, BC, 'A');
    float angleB = goc_tamgiac(AB, BC, CA, 'B');
    float angleC = goc_tamgiac(CA, BC, AB, 'C');

    printf("\n\n---- PHAN LOAI TAM GIAC ----\n");
    xet_loai_tamgiac(AB, CA, BC, angleA, angleB, angleC);

    printf("\n---- TINH DUONG CAO, TRUNG TUYEN ----");
    float hA = tinh_duong_cao(BC, AB, CA, 'A');
    float hB = tinh_duong_cao(CA, AB, BC, 'B');
    float hC = tinh_duong_cao(AB, CA, BC, 'C');

    float tA = tinh_trung_tuyen(BC, AB, CA, "tA");
    float tB = tinh_trung_tuyen(CA, AB, BC, "tB");
    float tC = tinh_trung_tuyen(AB, CA, BC, "tC");

    printf("\n\n---- TINH DIEN TICH  ----");
    float sABC = tinh_dientich(BC, hA);

    printf("\n\n---- TINH TRONG TAM ----");
    tinh_trongtam(A, B, C);
}

// Chuong trinh chinh
int main() {
    struct Points A, B, C;

    do {
        printf("\n");
        A = inputPointValue('A'); // Nhap toa do diem A
        B = inputPointValue('B'); // Nhap toa do diem B
        C = inputPointValue('C'); // Nhap toa do diem C

        printf("\n-----------------------------------\n");
        giaima_tamgiac(A, B, C); // Giai ma tam giac
    } while (!kiemtra_tamgiac(A, B, C)); // Neu khong tao thanh tam giac thi nhap lai

    return 0;
}

