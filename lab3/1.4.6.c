/*(Glückliche Zahlen) Nennen wir eine Zahl glücklich, wenn ihre Ziffern so in zwei Gruppen geteilt werden
können so, dass die Summe der Ziffern in beiden Gruppen gleich ist. Eine solche Zahl ist z. B. 32843, denn
8 + 2 = 3 + 4 + 3. Schreiben Sie ein Programm, das alle Zahlenpaare findet, wo beide Zahlen glücklich sind,
und die Differenz der zwei Zahlen 1 ist.*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 1000

enum boolean{false, true};

enum boolean ist_gluecklich(int);
int summe(short*, short*);

int main(int argc, char ** argv)
{
    for(int i = 1; i<N; i++){
        if(ist_gluecklich(i) && ist_gluecklich(i+1))printf("%d\t%d\n", i, i+1);
    }
    return 0;
}

enum boolean ist_gluecklich(int n){
    int summe1 = 0, summe2 = 0, size = ((int)log10(n)+1), j = 1, k = 0, l =0;
    short *ziffern = (short*)malloc(sizeof(short)*size);
    short *index = (short*)malloc(sizeof(short)*size);
    for(int i = 0; i<size; i++){
        ziffern[size-i-1] = n%10;
        n/=10;
        summe1 += ziffern[size-i-1];
    }
    if(summe1%2 != 0)return false; //falls die Zahl ungerade ist, koennen die Ziffern nicht in zwei egale Teile geteilt werden
    summe2 = summe1/2;

    for(k = 1; k<pow(2, size); k++){
        for(j = 0; j<size; j++){
            index[j] = 0;
        }
        j = k;
        l = 1;
        do{
            index[size-l] = j%2;
            l++;
            j/=2;
        }while(j/2 != 0);
        if(summe(ziffern, index) == summe2) return true;
    }
    
    return false;

}

int summe(short* ziffern, short* index){
    int summe = 0;
    for(int i = 0; i<sizeof(ziffern)/sizeof(short); i++){
        summe += index[i]*ziffern[i];
    }
    return summe;
}