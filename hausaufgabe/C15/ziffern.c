/*Ergänzen Sie das Programm, das die Summe der Ziffern einer natürlichen Zahl mit positiven und mit wechselnden Vorzeichen
auf den Bildschirm schreibt (die Ziffer an der kleinsten Stelle muss ein positives Vorzeichen haben).

Zum Beispiel betrachten wir 1234: die Summe der Ziffern, wo alle Ziffern ein positives Vorzeichen haben,
ist 1 + 2 + 3 + 4 = 10. Die Summe der Ziffern mit wechselnden Vorzeichen ist - 1 + 2 - 3 + 4 = 2.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int number = 0, sum = 0, sumMinus = 0;
    short int * ziffern = (short int *) malloc(sizeof(short int)*0);
    short int length = 0, vorzeichen = 1;
    scanf("%d", &number);
	while(number != 0){
        length++;
        ziffern = (short int *) realloc(ziffern, sizeof(short int)*length);
        ziffern[length-1] = number%10;
        number /= 10;
    }
	for(int i = 0; i<length; i++){
        sum += ziffern[i];
        sumMinus += vorzeichen*ziffern[i];
        vorzeichen *= -1;
    }
    free(ziffern);

	printf("%d %d", sum, sumMinus);
        return 0;

}