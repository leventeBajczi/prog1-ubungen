/*Die folgende Reihe

1 / (3 * 5) + 1 / (7 * 9) + 1 / (11 * 13) + ... + 1 / ((4n - 1) * (4n + 1))

strebt gegen einen bestimmten Wert. Berechnen Sie diesen Wert mit einer Genauigkeit von 10-12,
also die Berechnung ist dann abzubrechen, wenn der Unterschied der letzten zwei Summen kleiner
als der Grenzwert ist. Wenden Sie das nachfolgende Programm an:*/

#include <stdio.h>

#define GRENZWERT 1E-12

double get_wert(int);

int main() {
    int n = 0;
	double sum = 0.0;
    do{
        sum+=get_wert(++n);
    }while(get_wert(n) >= GRENZWERT);
	printf("%3.12f", sum);
	return 0;

}

double get_wert(int n){
    return 1.0 / (16.0*n*n-1.0); //((4n - 1) * (4n + 1)) = (4^2*n^2 - 1^2)
}