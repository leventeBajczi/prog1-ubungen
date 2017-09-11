 /* F.1.3.3 Gegeben sei eine int-Variable. Schreiben Sie ein Programm, das die binäre Darstellung dieser Variable auf
den Bildschirm schreibt zusammen mit der invertierten Binärzahl. Die Bits sollen von MSB nach LSB gehen
von links nach rechts, und nach jedem vierten Bit soll eine Leerstelle eingefügt werden. Zum Beispiel: 15 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* get_binar_form(int);

int size_mal;

int main(int argc, char** argv){
    int n;
    int* binar;
    printf("Geben Sie eine ganze Zahl ein: \n");
    scanf("%d", &n);
    size_mal = (((int)log2(n))/4+1)*4;
    binar = get_binar_form(n);
    
    for(int i = 0; i < size_mal; i++){
        printf("%d", binar[i]);
        if((i+1)%4 == 0)printf(" ");
    }
    printf("\n");
    for(int i = 0; i < size_mal; i++){
        printf("%d", (1 + binar[i])%2);
        if((i+1)%4 == 0)printf(" ");
    }

    return 0;
}

int* get_binar_form(int n){
    int* binar = (int*) malloc(sizeof(int)*size_mal);
    int i = 0;
    
    while(n/2 > 0){
        binar[size_mal - i - 1] = n%2;
        n /= 2;
        i++;
    }
    binar[size_mal - i - 1] = 1;
    i++;
    for(i; i<size_mal; i++){
        binar[size_mal - i - 1] = 0;
    }
    return binar;
}
