/*Suchen Sie jede natürliche Zahl zwischen 100 und 999 (Zahlen mit 3 Ziffern), die durch 7 teilbar ist und
deren letzte zwei Ziffern identisch sind (z. B.:  133, 266, 322 usw..) Diese Zahlen sollen mit Leertasten
getrennt in eine Zeile geschrieben werden.*/
#include<stdio.h>

int main() {
    for(int i = 100; i<=999; i++){
        if(i%7 == 0){
           if(i%10 == (i/10)%10) printf("%d ", i);
           i += 6;
        }
    }
    printf("\b");
    return 0;   
}
