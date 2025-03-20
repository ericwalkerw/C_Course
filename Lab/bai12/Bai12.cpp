#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void lab12_1(){
    char str[] = "Lap trinh C co ban";
    char *ptr = str;

    int i = 0;
    while (*(ptr + i)!= '\0') {
        i++;
    }
    i--; 

    int j;
    for (j = i; j >= 0; j--) {
        printf("%c", *(ptr + j));
    }

    printf("\n");
}

bool compare(const char s1[], const char s2[]) {
    int i = 0;
    const char *ptr1 = s1;
    const char *ptr2 = s2;
    bool isEquals = false;

    while (*(ptr1 + i) == *(ptr2 + i) &&
           *(ptr1 + i) != '\0' &&
           *(ptr2 + i) != '\0') {
        i++;
    }

    if (*(ptr1 + i) == '\0' && *(ptr2 + i) == '\0') {
        isEquals = true;
    }

    return isEquals;
}

void lab12_2(){
	printf("%s\n", compare("hoang", "hoang") ? "True" : "False");
    printf("%s\n", compare("hello", "world") ? "True" : "False");
}

void lab12_3(){
	int n;
	printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    int arr[n];          
    int *ptr = arr;      

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", ptr + i); 
    }

    int max = *ptr;       
    for (int i = 1; i < n; i++) {
        if (max < *(ptr + i)) {
            max = *(ptr + i);
        }
    }

    printf("So lon nhat trong mang la: %d\n", max);
}

void search(int *x, int *y) {
    int i, f = 0;
    
    for (i = 0; i < 5; i++) {
        if (*(x + i) == *y) {
            f = 1;
            break;
        }
    }

    if (f == 1)
        printf("Da tim thay.\n");
    else
        printf("Khong tim thay.\n");
}

void lab12_4(){
	int arr[5];       
    int value;       
    int *ptr = arr;   
    int *target = &value; 

    printf("Nhap 5 phan tu cho mang:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", ptr + i);
    }

    printf("Nhap gia tri can tim: ");
    scanf("%d", target);

    search(ptr, target);
}

void lab12_5(){
	int a[6] = {1, 2, 3, 4, 5, 6};
    int b[3] = {10, 20, 30};
    int i, temp;

    int *ptr1 = a;
    int *ptr2 = b;  

    for (i = 0; i < 3; i++) {
        temp = *(ptr2 + i);
        *(ptr2 + i) = *(ptr1 + i);
        *(ptr1 + i) = temp;
    }

    printf("Mang a sau khi hoan doi:\n");
    for (i = 0; i < 6; i++) {
        printf("%d ", *(ptr1 + i));
    }

    printf("\n");

    printf("Mang b sau khi hoan doi:\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", *(ptr2 + i));
    }

    printf("\n");
}

int add(int *pnum1, int *pnum2) {
    return (*pnum1 + *pnum2);
}

void lab12_6(){
	int a = 5, b = 10, result;
    result = add(&a, &b);
    printf("Tong cua %d va %d la: %d\n", a, b, result);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void lab12_7(){
	int x = 5, y = 10;

    printf("Truoc khi hoan doi: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Sau khi hoan doi: x = %d, y = %d\n", x, y);
}

void findFact(int n, int *f) {
    int i;
    *f = 1;

    for (i = 1; i <= n; i++) {
        *f = *f * i;
    }
}

void lab12_8(){
	int num, fact;

    printf("Nhap so de tinh giai thua: ");
    scanf("%d", &num);
    findFact(num, &fact);
    printf("Giai thua cua %d la: %d\n", num, fact);
}

void JsonExtract(char json[], char hoten[], char gioitinh[], char sodienthoai[], char email[]) {
    char info[4][100];
    int i = 0;

    char* token = strtok(json, ",");
    while (token != NULL && i < 4) {
        strcpy(info[i], token);
        ++i;
        token = strtok(NULL, ",");
    }
	//TRICH XUAT HO TEN
    char* hoten_token = strtok(info[0], ":");
    strcpy(hoten, strtok(NULL, ":"));

	//TRICH XUAT GIOI TINH
    strtok(info[1], ":");
    strcpy(gioitinh, strtok(NULL, ":"));
    
	//TRICH XUAT SO DIEN THOAI
    strtok(info[2], ":");
    strcpy(sodienthoai, strtok(NULL, ":"));

	//TRICH XUAT EMAIL
    strtok(info[3], ":"); 
    strcpy(email, strtok(NULL, ":"));

	//BO DAU ) nam o cuo email
    int len = strlen(email);
    if (email[len - 1] == '}')
        email[len - 1] = '\0';
}


void lab12_9(){
	char json[] = "{\"hoten\":\"Le Thi My Duyen\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0935777888\",\"email\":\"duyen86@gmail.com\"}";
    char hoten[100], gioitinh[100], sodienthoai[100], email[100];
    
    JsonExtract(json, hoten, gioitinh, sodienthoai, email);
    
    printf("Thong tin cua doi tuong JSON: \n");
    printf("Ho ten    : %s\n", hoten);
    printf("Gioi tinh : %s\n", gioitinh);
	printf("Dien thoai: %s\n", sodienthoai);
	printf("Email 	  : %s\n", email);
}

char* multi_tok(char *input, const char *delimiter) {
    static char *string;
    if (input != NULL)
        string = input;

    if (string == NULL)
        return NULL;

    char *end = strstr(string, delimiter);
    if (end == NULL) {
        char *temp = string;
        string = NULL;
        return temp;
    }

    char *temp = string;
    
    *end = '\0';
    string = end + strlen(delimiter);
    return temp;
}

void lab12_10() {
    char json[] = "[{\"hoten\":\"Le Thi My Duyen\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0935777888\",\"email\":\"duyen86@gmail.com\"},"
                  "{\"hoten\":\"Tran Trung Thanh\",\"gioitinh\":\"nam\",\"sodienthoai\":\"0976333444\",\"email\":\"thanhtt95@gmail.com\"},"
                  "{\"hoten\":\"Huynh Anh Hoang\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0939745220\",\"email\":\"hahoang88@gmail.com\"},"
                  "{\"hoten\":\"Nguyen Minh Khoi\",\"gioitinh\":\"nam\",\"sodienthoai\":\"0703666777\",\"email\":\"khoimaster@gmail.com\"}]";

	char hoten[100], gioitinh[100], sodienthoai[100], email[100];
	char khachhang[500];
	char hoten_nam[10][100];
	int sl_nam = 0;
	int sl_khachhang = 0;
	int i = 0;
	
	char* token = multi_tok(json, "},{");
	
	while(token != NULL){
		strcpy(khachhang, token);
		JsonExtract(khachhang, hoten, gioitinh, sodienthoai, email);
		if(strcmp(gioitinh, "\"nam\"") == 0){
			strcpy(hoten_nam[i], hoten);
			sl_nam++;
			i++;
		}
		sl_khachhang++;
		token = multi_tok(NULL, "},{");
	}
	
	printf("Co tong cong %d khach hang nam / tong so so %d khach hang\n", sl_nam, sl_khachhang);
	if(sl_nam > 0){
		printf("Ho ten cac khach hang nam: \n");
		for(i=0; i < sl_nam; i++){
			printf("%d, %s \n", i+1, hoten_nam[i]);
		}
	}
}

int main() {
//	lab12_1();
//	lab12_2();
//	lab12_3();
//	lab12_4();
//	lab12_5();
//	lab12_6();
//	lab12_7();
//	lab12_8();
//	lab12_9();
	lab12_10();
    return 0;
}

