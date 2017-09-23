/*Schreiben Sie eine C-Funktion, die als Parameter eine Zahl nimmt, und die Fakultät der Zahl zurückgibt.
Diese Funktion schreibt nichts auf den Bildschirm. Mit ihrer Hilfe schreiben Sie die ersten 10 Zeilen des
Pascal-Dreiecks auf den Bildschirm. Das k-te Element der n-ten Zeile is das folgende:

(n über k) = n! / ( k! * (n-k)! )

wo n = 0, 1, 2... und k = 0, 1, 2... Benützen Sie unsigned long als Variable für die Aufgaben.
Auf den Bildschirm zu schreiben, ist %lu als Formatierungszeichnen zu benützen. Bei prunsigned longf() bestimmt eine ganze Zahl zwischen
dem Prozentzeichen und dem Formatierungszeichen die Länge der ausgegebenen Zahl. Ist die Zahl kürzer, wird der verbliebende
Platz mit Leerzeichen aufgefüllt. In der Aufgabe verwenden Sie %5lu das richtige Ergebnis zu bekommen, nur das Dreieck darf
auf dem Bildschirm sein:*/

#include<stdio.h>


unsigned long fakultaet(unsigned long);

int main() {
    for(unsigned long i = 0; i <= 10; i++){
        for(unsigned long j = 0; j<=i; j++){
            printf("%5lu", fakultaet(i)/fakultaet(j)/fakultaet(i-j));
        }
        printf("\n");
    }
    return 0;   
}

unsigned long fakultaet(unsigned long i){
    if(i == 0) return 1;
    for(unsigned long j = i - 1; j>0; j--)i*=j;
    return i;
}  