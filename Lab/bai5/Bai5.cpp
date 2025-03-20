#include <stdio.h>
void lab5_1(){
	int number;
    
    printf("Nhap mot so nguyen: ");
    scanf("%d", &number);

    int bit3 = (number >> 2) & 1;

    printf("Bit thu 3 la bit %d\n", bit3);
}

void lab5_2(){
    int number, result;
    printf("Nhap mot so nguyen: ");
    scanf("%d", &number);
    result = number | (1 << 4);

    printf("Gia tri moi sau khi dat bit thu 5 la: %d\n", result);
}

void lab5_3(){
	int songay, sonam, sotuan, ngayconlai;

    printf("Nhap vao so ngay: ");
    scanf("%d", &songay);

    sonam = songay / 365;
    sotuan = (songay - sonam * 365) / 7;
    ngayconlai = songay - sonam * 365 - sotuan * 7;

    printf("So nam: %d\n", sonam);
    printf("So tuan: %d\n", sotuan);
    printf("So ngay: %d\n", ngayconlai);
}

void lab5_4(){
	    long sophut;
    int songay, sonam, ngayconlai;
    
    printf("Nhap vao so phut: ");
    scanf("%ld", &sophut);

    songay = sophut / (60 * 24);
    sonam = songay / 365;
    ngayconlai = songay % 365;

    printf("So nam: %d\n", sonam);
    printf("So ngay: %d\n", ngayconlai);
}

void lab5_5(){
	printf("Kich thuoc cua char      : %lu byte\n", sizeof(char));
    printf("Kich thuoc cua int       : %lu byte\n", sizeof(int));
    printf("Kich thuoc cua long      : %lu byte\n", sizeof(long));
    printf("Kich thuoc cua long long : %lu byte\n", sizeof(long long));
    printf("Kich thuoc cua float     : %lu byte\n", sizeof(float));
    printf("Kich thuoc cua double    : %lu byte\n", sizeof(double));
}

void lab5_6(){
	int a,b;

	printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    printf("Nhap so thu hai: ");
    scanf("%d", &b);
    
    printf("So thu nhat: %d\n", a);
    printf("So thu hai: %d\n", b);
    
    float ketqua = (float)a / b;
    printf("Ket qua phep chia: %.2f\n", ketqua);
}

void lab5_7(){
	float a, b, c, d, trungbinh;

    printf("Nhap so thu nhat: ");
    scanf("%f", &a);
    printf("Nhap so thu hai: ");
    scanf("%f", &b);
    printf("Nhap so thu ba: ");
    scanf("%f", &c);
    printf("Nhap so thu tu: ");
    scanf("%f", &d);

    trungbinh = (a + b + c + d) / 4;

    printf("Trung binh cong cua 4 so la: %.2f\n", trungbinh);
}

void lab5_8(){
	int a, b, c, d;

    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    printf("Nhap so thu hai: ");
    scanf("%d", &b);
    printf("Nhap so thu ba: ");
    scanf("%d", &c);
    printf("Nhap so thu tu: ");
    scanf("%d", &d);

    printf("Binh phuong cua %d la %d\n", a, a * a);
    printf("Binh phuong cua %d la %d\n", b, b * b);
    printf("Binh phuong cua %d la %d\n", c, c * c);
    printf("Binh phuong cua %d la %d\n", d, d * d);
}

void lab5_9(){
	unsigned int id_nv, sogio, tien_moigio, tien_thang;

    printf("Nhap ID nhan vien: ");
    scanf("%u", &id_nv);

    printf("Nhap tong so gio lam viec trong thang: ");
    scanf("%u", &sogio);

    printf("Nhap tien luong moi gio: ");
    scanf("%u", &tien_moigio);

    tien_thang = sogio * tien_moigio;

    printf("ID nhan vien: %u\n", id_nv);
    printf("Tien luong nhan duoc trong thang: %u\n", tien_thang);
}

int main() {
//	lab5_1();
//	lab5_2();
//	lab5_3();
//	lab5_4();
//	lab5_5();
//	lab5_6();
//	lab5_7();
//	lab5_8();
	lab5_9();
    return 0;
}

