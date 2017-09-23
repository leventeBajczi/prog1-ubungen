/*Wir wollen ''ganz vollkommene Zahlen'' suchen. Nehmen wir eine Zahl n, schreiben wir alle Teiler dieser Zahl auf.
Jetzt addieren wir diese Teiler, und schreiben wir die Teiler dieser Summe auf. Summieren wir jetzt diese neuen Teiler,
und wenn wir so 2 * n bekommen, heißt n eine ganz vollkommene Zahl.

Z. B. verfügt 16 über diese Eigenschaft, denn die Summe ihrer Teiler (inkl. 1 und 16) ist 1 + 2 + 4 + 8 + 16 = 31, und die Summe
der Teiler von 31 ergibt 32. Geben Sie ein C-Programm an, das alle solche Zahlen n unter 1000 findet, und schreiben Sie diese Zahlen
mit Leertasten zertrennt aus! Außer den Zahlen darf nichts auf den Bildschirm ausgegeben werden!

*/

#include <stdio.h>
#include <stdlib.h>

void teilern(int, int*);
int sum(int*);

int main() {
    int r[512]; //max Groesse ist sum(binomial(9, n)) from 0 to 9 weil max Anzahl der Primteilern ist die Anzahl der Ziffern eines Zahles in seinem binaere Darstellung (Ueberschaetzung)
    int first = 1;
    for(int i = 1; i<1000; i++){
        teilern(i, r);
        teilern(sum(r), r);
        if(sum(r) == i*2){
            if(!first)printf(" ");
            first = 0;
            printf("%d", i);
        }
    }
    return 0;   
}

void teilern(int n, int* r){
    int i = 0;
    for(int j = 1; j<=n; j++){
        if(n%j == 0){
            r[i] = j;
            i++;
        }
    }
    for(i; i<512; i++)r[i] = 0;
}

int sum(int* r){
    int sum = 0;
    for(int i = 0; i<512; i++){
        sum+=r[i];
    }
    return sum;
}