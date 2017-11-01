/*Wir werfen Pfeile ohne Zielen in ein Quadrat mit Seitenlänge 2 Einheiten. Wir zählen die getroffenen Punkte,
die innerhalb des Quadrates liegen, und weniger als 1 Einheit vom Mittelpunkt des Quadrates entfernt sind.
Was für ein Ergebnis bekommen wir, wenn wir die Anzahl der im Innen liegenden Punkte durch die Anzahl
der im Quadrat liegenden Punkte teilen?*/

//erwarteten Ergebnis ist in der Nähe von pi*1^2 / 4 = 0.785398163
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000

int werf_pfeile();

int main(){
    int ergebnis = 0;
    int i = 0;
    srand(time(0));

    for(i = 0; i<N; i++) if (werf_pfeile())ergebnis++;

    printf("%f", ergebnis*1.0 /(i));

    return 0;
}

int werf_pfeile(){
    float x = (float)rand()/RAND_MAX*2 - 1, y = (float)rand()/RAND_MAX*2 - 1;

    if(x*x + y*y < 1) return 1;

    return 0;
}