#include <stdio.h>
#include <math.h>

#define N 250;

/* F.1.1.14 Berechnen Sie die Summe der ersten 250 ungeraden Primzahlen! */

enum boolean {true, false};

enum boolean is_prime(int);

int main(int argc, char** argv){
    int c = 0, i = 3, summe = 0;
    while(c<250){
        if(is_prime(i) == true){
            printf("%d. %d\n", c, i);
            c++;
            summe += i;
        }
        i++;
    }
    printf("Die Summe der ersten 250 Primzahlen: %d\n", summe);
}

enum boolean is_prime(int n){
    for(int i = 2; i <= sqrt((double)n); i++){
        if (n%i == 0) return false;
    }
    return true;
}