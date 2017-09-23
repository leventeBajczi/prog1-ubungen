/*Die Zahl 3025 hat die folgende interessante Eigenschaft: wenn man sie in zwei gleiche Teile (30 und 25) trennt,
diese Teile summiert, und dann die Summe quadriert, erhält man wieder 3025: (30 + 25)^2 = 3025.

Schreiben Sie eine Funktion in das angegegenen Program, die jede solche Zahl findet. Das Ergebniss soll mit Leertasten
getrennt und aufsteigend sortiert ausgegeben werden. Das Programm soll für 2, 4, 6 und 8-stellige Ziffern funktionieren,
sonst die angegebene Fehlermeldung ist auszuschreiben. Die Anzahl der Ziffern soll als Eingangsparameter der Funktion angegeben werden!*/

#include <stdio.h>

void dividedNumbers(int);
long long pow_10(int);
int eigenschaft(long long, int);

int main() {

	int digits;
	printf("Add the number of digits: ");
    scanf("%d", &digits);
    if(digits > 0 && digits <10 && digits%2 == 0)
	dividedNumbers(digits);
    else printf("Not valid number of digits.");
	return 0;	 

}

void dividedNumbers(int n){
    int first = 1;
    for(long long l = pow_10((n-1)/2); l < pow_10(n/2); l++){   //nur Quadratzahlen sollen getestet werden
        if(l*l<pow_10(n-1)) continue;                           //10^((n-1)/2) ist immer 10^(etwas + 0.5), deshalb brauchen wird diesen Test
        if(eigenschaft(l*l, n)){
            if(!first)printf(" ");
            first = 0;
            printf("%lld", l*l);
        }
    }
}

long long pow_10(int p){
    long long r = 1;
    for(int i = 0; i<p; i++)r*=10;
    return r;
}

int eigenschaft(long long n, int digits){
    long long a = n / (pow_10(digits/2)) + n % (pow_10(digits/2));
    if(a*a == n) return 1;
    return 0;
}