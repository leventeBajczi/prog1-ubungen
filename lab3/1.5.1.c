/*Schreiben Sie eine C-Funktion, die eine nicht negative Ganzzahl n als Parameter nimmt, und als Rückgabewert
die kleinste Potenz von 2 ergibt, die größer oder gleich n ist, also p = 2^m, p ≥ n gilt, wenn aber p = 2^(m−1)
,
dann p < n. Beispiel: n = 10, p = 2^4 = 16 und n = 8, p = 2^3 = 8).*/

#include <stdio.h>

int potenz(int ganzzahl){
    int a=1;
    while(a<ganzzahl){
        a*=2;
    }
    return a;
}