/*Die folgende Reihe

1 / (3 * 5) + 1 / (7 * 9) + 1 / (11 * 13) + ... + 1 / ((4n - 1) * (4n + 1))

strebt gegen einen bestimmten Wert. Berechnen Sie diesen Wert mit einer Genauigkeit von 10-12,
also die Berechnung ist dann abzubrechen, wenn der Unterschied der letzten zwei Summen kleiner
als der Grenzwert ist. Wenden Sie das nachfolgende Programm an:*/

#include <stdio.h>
#include <math.h>

#define GRENZWERT 1E-12

float get_wert(int);

int main() {
    int n = 1;
	float sum = get_wert(n), sumlast = 0.0f;
    while(fabs(sum-sumlast) >= GRENZWERT){
        sumlast = sum;
        sum+=get_wert(++n);
    }
	printf("%3.12f", sum);
	return 0;

}

float get_wert(int n){
    return 1.0f / (16*n*n-1); //((4n - 1) * (4n + 1)) = (4^2*n^2 - 1^2)
}
