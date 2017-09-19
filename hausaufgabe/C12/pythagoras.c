/* Schreiben Sie ein C-Programm, das solche ganzen Zahlen zwischen 1 und 100 auf den Bildschirm schreibt,
welche die Pythagoras-Kriterien erfüllen. Für die Pythagoras-Zahlentripel (x;y;z) gilt der folgende Zusammenhang: x2 + y2 = z2.
Das Programm soll jeden Zahlentripel in eine Zeile auf den Bildschirm mit der folgenden Bedingung schreiben,
dass jeder Zahlentripel nur einmal vorkommen darf: z.B. (3;4;5) ist identisch mit (5;4;3).
*/

#include<stdio.h>

int main()
{
    for(int i = 1; i<=100; i++){
        for(int j = 1; j<i; j++){
            for(int k = 1; k<j; k++){
                if(i*i == j*j + k*k)printf("(%d;%d;%d)\n", i, j, k);
            }
        }
    }

    return 0;
}