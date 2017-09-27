/*Schreiben Sie zwei Funktionen, welche die folgende unendliche Reihe annähern:

f(x) = ln((1 + x) / (1 - x)) ≈ 2x + 2x3 / 3 + 2x5 / 5 + ... + 2x2n-1 / (2n - 1) + ...,

wo -1 < x < 1.

Mit der Berechnung soll aufgehört werden, wenn der Unterschied zwischen den i-ten und i + 1-ten Glieder kleiner
als 10-7 wird. Beachten Sie die Vorzeichen! Sie müssen zwei Varianten (also zwei verschiedene Funktionen) entwickeln:
zuerst eine Version, die alle Glieder vollständig neu berechnet; zweitens eine Effiziente, die aus dem i-ten Glied das
i + 1-te Glied effizient ableitet. Die Funktionen sind double f3(double x) und double f3_eff(double x) zu nennen und ins
nachfolgende Programm einzubauen. Es ist verboten math.h-Header zu benützen!*/

#include <stdio.h>

#define GRENZWERT 1E-7


double powx(double x, int y){
    double a = x;
    for(int i = 1; i<y; i++){
        x*=a;
    }
    return x;
}


double get_wert(int n, double x){
    return (2*powx(x, 2*n - 1) / (2*n - 1));
}

double f3(double x){
    int n = 1;
    double sum = 0.0f, i = get_wert(n, x), i_plus = get_wert(++n, x);
    while(i - i_plus >= GRENZWERT || i - i_plus <= -1 * GRENZWERT){
        sum+=i;

        i = i_plus;
        i_plus = get_wert(++n, x);
    }
    return sum;
}
double f3_eff(double x){
    int n = 1;
    double sum = 0.0f, i = get_wert(n, x), i_plus = i * x * x / (2.0f*n + 1.0f) * (2.0f*n - 1.0f);
    while(i - i_plus >= GRENZWERT || i - i_plus <= -1 * GRENZWERT){
        n++;
        sum+=i;
        i = i_plus;
        i_plus = i * x * x / (2.0f*n + 1.0f) * (2.0f*n - 1.0f);
    }
    return sum;
}

int main() {

	double x;

	printf("Add x: ");
	scanf("%lf", &x);
	printf("%1.7f\n", f3(x));
	printf("%1.7f\n", f3_eff(x));
	return 0;

}