/*Für den kranken Albert Einstein hat einer seiner Freunde die folgende Aufgabe erfunden: falls wir um 12 Uhr den Minutenzeiger und den Stundenzeiger vertauschen,
erhalten wir denselben Zeichpunkt. Im Gegenteil, wenn man das um 6 Uhr macht, bekommen wir einen solchen Zustand der Zeiger, der normalerweise nie auftritt
(bei einer richtig funktionierenden Uhr darf es nie passieren, dass der Stundenzeiger auf 12 und der Minutenzeiger auf 6 steht).

Die Frage ist es, wann und wie oft kann es passieren, dass die beiden Zeiger in einem Zustand sind, bei dem der vertauschte Zustand der Zeiger auch gültig ist.
Schreiben Sie dafür ein C-Programm! Lösen Sie die Aufgabe so, dass wir es zuerst berechnen, in welchen Zeitpunkten der Uhr- und Minutenzeiger übereinander sind.*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define UHR 12
#define MINUTEN 60
#define ANZAHL UHR*MINUTEN

/*Es wird angenommen, dass die Zeiger sich diskret bewegen (anhand der Minutenzeiger, also gibt es keine Unterschied zwischen 12:00:00 und 12:00:59), und das bedeutet, dass
die Uhrenzeiger sich jede 12 Minuten bewegt. 
Die Zeit wird folgenderweis dargestellt: 00xxxxxx 00yyyyyy, wo xxxxxx bezeichnet die Uhrzeiger, und yyyyyy die Minutenzeiger*/
void get_zeitpunkte(uint16_t *);

int main()
{   
    uint16_t *zeit = (uint16_t*) malloc(sizeof(uint16_t)*ANZAHL);
    for(uint8_t i = 0; i<UHR; i++)
    {
        for(uint8_t j = 0; j<MINUTEN; j++)
        {
            zeit[i*MINUTEN+j] = (i*5 + j/12 << 8) | j; //jede Zeitmöglichkeiten von 0:00 bis 11:59
        }
    }
    get_zeitpunkte(zeit);
    return 0;
}

void get_zeitpunkte(uint16_t *zeit)
{
    for(uint16_t i = 0; i<ANZAHL; i++)
    {


        for(uint16_t j = 0; j<=i; j++)
        {
            if(zeit[j] == (zeit[i] >> 8 | (zeit[i] & ((1<<8) - 1)) << 8))
            {
                printf("Die Zeit   %02u:%02u   ist mit   %02u:%02u   vertauschbar\n", (zeit[i]>>8)/5, zeit[i] & ((1<<8) - 1), (zeit[j]>>8)/5, zeit[j] & ((1<<8) - 1));
                break;
            }
        }

    }
}