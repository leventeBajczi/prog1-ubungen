/*Wir speichern die x-Koordinaten von Kreismittelpunkten in einem double-Array xk. Die y-Koordinaten sind
ähnlicherweise in einem double-Array yk gespeichert. In einem dritten double-Array rk sind die Radien
dieser Kreise gespeichert.
Definieren Sie die drei Arrays, und füllen Sie diese mit Daten von vier Kreisen auf. Schreiben Sie ein
C-Programm, das die Arrayindizen solcher Kreise ausgibt, die vollständig nur in der positiven x-Halbebene
liegen. Z. B. ein Kreis mit Mittelpunkt (x = 1, y = 1) und Radius 0,4 liegt da, ein Kreis mit Mittelpunkt
(x = 1, y = 0) und Radius 2 erstreckt sich auch in die negative x-Halbebene.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int main(){
    double *xk, *yk, *rk;
    int i = 0;
    xk = (double *)malloc(sizeof(double)*SIZE);
    yk = (double *)malloc(sizeof(double)*SIZE);
    rk = (double *)malloc(sizeof(double)*SIZE);
    for(i = 0; i<SIZE; i++){
        printf("Geben Sie eine X-Koordinat ein: ");
        scanf("%lf", &xk[i]);
        printf("Geben Sie eine Y-Koordinat ein: ");
        scanf("%lf", &yk[i]);
        printf("Geben Sie eine Radius ein: ");
        scanf("%lf", &rk[i]);
        printf("\n");
    }
    for(i = 0; i<SIZE; i++){
        if(xk[i] - rk[i] >= 0)printf("\n%d: (x - %.2lf) ^ 2 + (y - %.2lf) ^ 2 = %.2lf", i, xk[i], yk[i], rk[i] * rk[i]);
    }
    return 0;
}