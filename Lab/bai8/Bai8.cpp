#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12
#define YEARS 5

void lab8_1(){
    int arr[5] = {1,2,3,4,5}; 
    printf("Cac gia tri da luu trong mang la:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void lab8_2(){
	int arr[5]; 
	int i;
    for (i = 0; i < 5; i++) {
        printf("Nhap gia tri phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang theo thu tu nguoc lai:\n");
    for (i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
}

void lab8_3(){
	unsigned int primes[100] = {0};    
    unsigned int primeIndex = 2;       
    bool isPrime;
    int p, i;

    primes[0] = 2;
    primes[1] = 3;

    for (p = 4; p <= 100; p++) {
        isPrime = true;

        for (i = 0; i < primeIndex; i++) {
            if (p % primes[i] == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes[primeIndex++] = p;
        }
    }

    printf("Cac so nguyen to tu 1 den 100:\n");
    for (i = 0; i < primeIndex; i++) {
        printf("%d ", primes[i]);
    }
}

void lab8_4(){
	    // initialize rainfall data for 2011-2015
    float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };

    int year = 0, month = 0;
    float subtot = 0.0, total = 0.0;

    printf("YEAR\t\tRAINFALL  (inches)\n");

    for (year = 0, total = 0; year < YEARS; year++)
    {
        for(month = 0, subtot = 0; month < MONTHS; month++)
        {
            subtot += rain[year][month];
        }
        printf("%5d \t%15.1f\n", 2010 + year, subtot);
        total += subtot;
    }

    printf("\nThe yearly average is %.1f inches.\n\n",total/YEARS);

    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

    for (month = 0; month < MONTHS; month++)
    {
        for (year = 0, subtot = 0; year < YEARS; year++)
            subtot += rain[year][month];

        printf("%4.1f ", subtot/YEARS);
    }

    printf("\n");
}

void lab8_5(){
	int a[100];
    int n;
    int i, j, temp;

    do {
        printf("Nhap so luong phan tu (1 - 100): ");
        scanf("%d", &n);
    } while(n <= 0 || n > 100);

    for(i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }

	// <<---- GIAM DAN
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] < a[j]) {
                // Hoán v?
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nMang sau khi sap xep giam dan:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

	// ---->> TANG DAN
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nMang sau khi sap xep tang dan:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main(){
	lab8_1();
//	lab8_2();
//	lab8_3();
//	lab8_4();
//	lab8_5();
	return 0;	
}
