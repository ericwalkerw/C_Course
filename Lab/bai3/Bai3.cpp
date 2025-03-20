#include <stdio.h>
void lab3_1(){
	printf("Name: Pham Ngoc An\n");
	printf("DOB: Jenuary, 10, 2001\n");
	printf("Mobile: 0386505047");
}

void lab3_2(){
	char bien;
	scanf("%c", &bien);
	printf("%c", bien);
}

void lab3_3(){
	char ten[32];
	printf("What's your name? : ");
	scanf("%s", &ten);
	printf("Hello %s, How are you?", ten);	
}


int main(){
//	lab3_1();
//	lab3_2();
	lab3_3();
	return 0;
}
