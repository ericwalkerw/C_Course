#include <stdio.h>

void lab6_1(){
	float sothunhat, sothuhai;
	
    printf("Nhap so thu nhat va so thu hai:\n");
    scanf("%f %f", &sothunhat, &sothuhai);

    if ((sothunhat != (int)sothunhat) || (sothuhai != (int)sothuhai)) {
        printf("So nhap vao khong phai so nguyen\n");
    } else {
        if (sothunhat == sothuhai) {
            printf("So thu nhat bang so thu hai\n");
        } else if (sothunhat > sothuhai) {
            printf("So thu nhat lon hon so thu hai\n");
        } else {
            printf("So thu nhat nho hon so thu hai\n");
        }
    }
}

void lab6_2(){
	int so;
    printf("Nhap mot so nguyen: ");
    scanf("%d", &so);
    
    if (so % 2 == 0) {
        printf("So %d la so chan.\n", so);
    } else {
        printf("So %d la so le.\n", so);
    }
}

void lab6_3(){
	float nhietdo;
    printf("Nhap nhiet do: ");
    scanf("%f", &nhietdo);
    
    if (nhietdo < 0) {
        printf("Thoi tiet lanh cong\n");
    } else if (nhietdo >= 0 && nhietdo <= 10) {
        printf("Thoi tiet rat lanh\n");
    } else if (nhietdo > 10 && nhietdo <= 20) {
        printf("Thoi tiet lanh\n");
    } else if (nhietdo > 20 && nhietdo <= 30) {
        printf("Thoi tiet nong\n");
    } else if (nhietdo > 40) {
        printf("Thoi tiet rat nong\n");
    } else {
        printf("Thoi tiet binh thuong\n");
    }
}

void lab6_4(){
	float giolam, gioluong = 12.0;
    float gross = 0, thue = 0, net = 0;
    float bhxh, bhyt, bhtn, tongbaohiem;
    
    printf("Nhap so gio lam viec trong tuan: ");
    scanf("%f", &giolam);

    if (giolam <= 40) {
        gross = giolam * gioluong;
    } else {
        gross = 40 * gioluong + (giolam - 40) * gioluong * 1.5;
    }

    if (gross <= 300) {
        thue = gross * 0.15;
    } else if (gross <= 450) {
        thue = gross * 0.20;
    } else {
        thue = gross * 0.25;
    }
    
    bhxh = gross * 0.08;  // BHXH 8%
    bhyt = gross * 0.015; // BHYT 1.5%
    bhtn = gross * 0.01;  // BHTN 1%
    tongbaohiem = bhxh + bhyt + bhtn;

    net = gross - tongbaohiem - thue;
    
    printf("\n--- Bang tinh luong ---\n");
    printf("Luong gross: %.2f USD\n", gross);
    printf("Thue TNCN: %.2f USD\n", thue);
    printf("Tong cac khoan bao hiem (BHXH + BHYT + BHTN): %.2f USD\n", tongbaohiem);
    printf("Luong net: %.2f USD\n", net);
}

int main(){
	lab6_1();
//	lab6_2();
//	lab6_3();
//	lab6_4();
	return 0;
}
