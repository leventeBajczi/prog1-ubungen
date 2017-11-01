/*Schreiben Sie ein Programm, das mit der Hilfe des Siebes von Eratosthenes die Primzahlen bis zu einem bestimmten Wert N sucht. Erstens versuchen Sie die möglichst
einfachste Lösung zu finden. Wie kann man an Effizienz verbessern? Das Ziel ist es, eine so großes N zu erreichen wie möglich, bzw. die Speicherbelegung zu minimalisieren.
( http://de.wikipedia.org/wiki/Sieb_des_Eratosthenes )*/

#include <stdio.h>
#include <stdlib.h>

#define N 1000000

void auskreuzen(unsigned long long, unsigned long long*);

int main()
{
    static unsigned long long zahlen_bis_N[N-1]; //Null-inizialisiert
    for(unsigned long long i = 2; i<=N; i++){
        if(zahlen_bis_N[i-2] != 1)
        {
            zahlen_bis_N[i-2] = i;
            auskreuzen(i-2, zahlen_bis_N);
            printf("%llu ", i);
        }
    }
    return 0;
}

void auskreuzen(unsigned long long index, unsigned long long* zahlen)
{
    for(unsigned long long i = index + zahlen[index]; i<=N; i+=zahlen[index]){
        zahlen[i] = 1;
    }
}