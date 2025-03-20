#include <stdio.h>
void lab11_1(){
	char x = 0;
	int y = 1;
	float z = 2.0;
	
	char *px = &x;
	int *py = &y;
	float *pz = &z;
	
	printf("Dia chi px: %p, dia chi va gia tri cua bien x: %p, %d\n", &px, px, *px);
	printf("Dia chi py: %p, dia chi va gia tri cua bien y: %p, %d\n", &py, py, *py);
	printf("Dia chi pz: %p, dia chi va gia tri cua bien z: %p, %d\n", &pz, pz, *pz);
}

void lab11_2(){
	int a = 51;
	int *ptr = (int*) &a;
	printf("%d\n", a);
	*ptr = 100;
	printf("%d", a);
}

void lab11_3(){
	int num1 = 0, num2 = 1;
	int *ptr1 = &num1;
	int *ptr2 = &num2;
	
	if(*ptr1 > *ptr2){
		printf("So %d lon hon so %d\n", *ptr1, *ptr2);
	} else if(*ptr1 < *ptr2){
		printf("so %d nho hon so %d\n", *ptr1, *ptr2);
	} else {
		printf("Hai so bang nhau");
	}
}

void lab11_4(){
	int num1 = 0, num2 = 0;
    int *pnum1 = &num1;
    int *pnum2 = &num2;

    printf("Nhap so thu nhat: ");
    scanf("%d", pnum1);

    printf("Nhap so thu hai: ");
    scanf("%d", pnum2);

    printf("Tong cua %d + %d = %d\n", *pnum1, *pnum2, (*pnum1 + *pnum2));
}

void lab11_5(){
    int num1 = 31;
    int num2 = 45;

    int *pnum1 = &num1;
    int *pnum2 = &num2;

    printf("Truoc khi hoan doi:\n");
    printf("num1 = %d, num2 = %d\n", *pnum1, *pnum2);

    int temp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = temp;

    printf("Sau khi hoan doi:\n");
    printf("num1 = %d, num2 = %d\n", *pnum1, *pnum2);
}
int main(){
	lab11_1();
//	lab11_2();
//	lab11_3();
//	lab11_4();
//	lab11_5();
	return 0;
}
