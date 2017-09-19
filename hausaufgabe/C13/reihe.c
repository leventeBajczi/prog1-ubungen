/*Schreiben Sie ein C-Programm, das die folgende Summe berechnet und ausgibt.
Verwenden Sie das folgende Schema und ergänzen Sie es so damit der automatische Test richtig läuft.
33 + 1*2 + 2*3 + 3*4 + ... + 98*99 + 99*100*/

#include<stdio.h>

int main() {
    int sum = 33;
    for(int i = 1; i<100; i++)sum += i*(i+1);
    printf("%d", sum);
    return 0;   
}
