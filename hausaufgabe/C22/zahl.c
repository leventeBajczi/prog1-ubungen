/*
Suchen Sie die Zahl zwischen 1 und 250, die den längsten ,,Weg'' zur Zahl 4 hat, und schreiben Sie dafür eine Funktion!
Einen ,,Weg'' bekommt man auf dieser Weise:

Wenn die aktuelle Zahl ungerade ist, soll man sie mit 3 multiplizieren dann mit 1 addieren.
Wenn die aktuelle Zahl gerade ist, soll man sie durch 2 dividiert werden.
Diese Schritte sollen solange wiederholt werden, bis man die Zahl 4 erreicht, und inzwischen soll man die Schritte zählen. Man erreicht immer die Zahl 4. Z.B.: Von der Zahl 6 ausgegangen brauchen wir 6 Schritte: 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4. Falls es mehrere Lösungen gibt mit denselben Schrittanzahl dann sollen Sie die grösste Zahl ausschreiben!

(Mehr information zum Thema unter http://mathworld.wolfram.com/CollatzProblem.html )*/

#include <stdio.h>

#define N 250

int longestWay();
int get_schritten(int);
int main() {
	
	printf("%d has the longest way to 4.", longestWay());

	return 0;

}

int longestWay(){
    int longest[2] = {0, 0}, j = 0;
    for(int i = 1; i<N; i++){
        j = get_schritten(i);
        if(j >= longest[0]){
            longest[0] = j;
            longest[1] = i;
        }
    }
    return longest[1]; 
}

int get_schritten(int i){
    int j = 0;
    while(i != 4){
        if(i%2) i = 3*i + 1;
        else i/=2;
        j++;
    }
    return j;
}