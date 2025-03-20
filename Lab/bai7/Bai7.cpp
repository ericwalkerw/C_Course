#include <stdio.h>
void lab7_1(){
	int n;
    printf("Nhap mot so tu nhien: ");
    scanf("%d", &n);

    printf("Cac so chan tu 1 den %d la:\n", n);

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
}

void lab7_2(){
	int a = 65; 
    int b = 0; 

    printf("So can doan la co 2 chu so.\n");

    while (a != b) {
        printf("Nhap so ban doan: ");
        scanf("%d", &b);

        if (a != b) {
            printf("Sai roi, thu lai nhe!\n");
        }
    }

    printf("Xin chuc mung, ban da doan dung!\n");
}

int main() {
	lab7_1();
//	lab7_2();
    return 0;
}

