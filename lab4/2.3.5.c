/*Schreiben Sie eine Funktion, die die folgende unendliche Reihe annähert:

Der Prototyp der Funktion sei void unend(double x, double eps, double *ergebnis). Mit der Berechnung
soll aufgehört werden wenn der Unterschied zwischen dem i-ten und i + 1-ten Glied kleiner wird im
Betrag als der Eingangsparameter eps.*/

#include <stdio.h>
#include <math.h>

void unend(double, double, double *);
void parse(double*, char*);
double wert(int, double);
double fakultaet(int);

int main(int argc, char** argv){
    if(argc<3) return 0;
    double x = 0.0, eps = 0.0, ergebnis = 0;
    parse(&x, argv[1]);
    parse(&eps, argv[2]);
    unend(x, eps, &ergebnis);
    
    return 0;
}

void parse(double* a, char* b){
    int i = 0, j = 0;
    *a = 0;
    while(b[i] != '\0'){
        if(b[i] == '.'){
            j = i;
            i++;
            continue;
        }
        *a = (*a)*10 + b[i] - '0';
        i++;
    }
    *a /= pow(10, ((i-1-j)));
}

void unend(double x, double eps, double *ergebnis){
    int i = 0;
    while(fabs(wert(i+1, x) - wert(i, x)) >= eps ){
        *ergebnis+=wert(i, x);
        i++;
        printf("%lf\n", *ergebnis);

    }
}

double wert(int i, double x){
    return pow(-1, i)*(pow(x, 2*i+1))/(double)((2.0*i+1)*fakultaet(i));
}

double fakultaet(int i){
    if(i == 0) return 1;
    for(unsigned long j = i - 1; j>0; j--)i*=j;
    return (double)i;
}  