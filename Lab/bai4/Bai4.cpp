#include <stdio.h>
void lab4_1(){
	float chieudai, chieurong, chuvi, dientich;
	
    chieudai = 10.5;
    chieurong = 5.2;
    
    chuvi = 2 * (chieudai + chieurong);
    dientich = chieudai * chieurong;

    printf("Chieu dai: %.2f\n", chieudai);
    printf("Chieu rong: %.2f\n", chieurong);
    printf("Chu vi: %.2f\n", chuvi);
    printf("Dien tich: %.2f\n", dientich);
}

enum Company { // lab 4.2
	GOOGLE, // 0
	FACEBOOK, // 1
	XEROX = 10, 
	YAHOO, // = 11
	EBAY, // = 12
	MICROSOFT
};

void lab4_3(){
	enum Company google = GOOGLE;
    enum Company facebook = FACEBOOK;
    enum Company xerox = XEROX;
    enum Company yahoo = YAHOO;
    enum Company ebay = EBAY;
    enum Company microsoft = MICROSOFT;

    printf("The value of google is: %d\n", google);
    printf("The value of facebook is: %d\n", facebook);
    printf("The value of xerox is: %d\n", xerox);
    printf("The value of yahoo is: %d\n", yahoo);
    printf("The value of ebay is: %d\n", ebay);
    printf("The value of microsoft is: %d\n", microsoft);
    //ph?n t? du?c gán giá tr? c? th? thì các ph?n t? sau nó s? t? d?ng tang lên t? dó
    //Phan tu duoc gan gia tri thi cac phan tu sau do se tu dong tang tiep tuc. vi du gan phan tu Ebay = 10, thi microsoft = 11
}

int main() {
//	lab4_1();
	lab4_3();
    return 0;
}

