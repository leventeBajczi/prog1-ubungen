#include <stdio.h>

/* Schreibt die erste N (angegebene Zahl) auf den Bildschirm aus */

int sqrt_i(int n);

int main(int argc, char** argv){
    int n;
    printf("Geben Sie eine ganze Zahl ein!\n");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("%d\n", sqrt_i(i));
    }
    return 0;
}

int sqrt_i(int n){
    return n*n;
}