/*In einem 10-Elementigen double-Array mit dem Namen ptx werden die x Koordinaten von geometrischen Punkten gespeichert. In einem anderen Array pty werden die
y Koordinaten von denselben Punkten gespeichert. Suchen Sie die zwei Punkte, die am nächsten zueinander sind. Der Arrayindex dieses Punktpaares soll ausgegeben werden.
Das Array ist mit Testdaten aufzufüllen. Die Punkten liegen in derselben Ebene.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   10

typedef struct map map;
struct map{
    double wert;
    int index1;
    int index2;
};

typedef struct xy xy;
struct xy{
    double x;
    double y;
};

void fuell(xy*);
int choose(int*, int, int, int, int);
int nCr(int, int);
void get_naechste2();

int k = 0;
xy* punkte;
map* laenge;

int main()
{
    int *chosen = (int*)malloc(sizeof(int)*2); 

    punkte = (xy*)malloc(sizeof(xy)*N);
    laenge = (map*)malloc(sizeof(map)*nCr(N, 2));

    srand(time(0));

    fuell(punkte);

    choose(chosen, 0, 2, 0, N);

    get_naechste2();
    return 0;
}

void fuell(xy* array)
{
    for(int i = 0; i<N; i++)
    {
        array[i].x = rand()*10.0/RAND_MAX - 5.0;      //es ist uns nicht wichtig, wovon wir diese Werte bekommen
        array[i].y = rand()*10.0/RAND_MAX - 5.0;
    }
}

void get_naechste2()
{
    map naechste = {100.0, 0, 0};                   //so lang, dass keine zwei Vektoren diese weit entfernt sein koennen
    for(int i = 0; i<nCr(N, 2); i++)
    {
        if(laenge[i].wert<naechste.wert)
        {
            naechste = laenge[i];
        }
    }
    printf("Punkt %d (%lf; %lf) und Punkt %d (%lf; %lf) sind %lf weit voneinander.\n", naechste.index1, punkte[naechste.index1].x, punkte[naechste.index1].y, naechste.index2, punkte[naechste.index2].x, punkte[naechste.index2].y, naechste.wert);
}


int choose(int* jetzt, int n, int goal, int j, int max) 
{
        int i;
        int count = 0;
        if (n == goal) {
                double distx = 0, disty = 0;
                if (!jetzt) return 1;
                if(jetzt[0] == jetzt[1]) return 1;
                for (i = 0; i < goal; i++)
                {
                    distx += (1-2*i)*punkte[jetzt[i]].x;
                    disty += (1-2*i)*punkte[jetzt[i]].y;
                }
                laenge[k].wert = distx*distx + disty*disty;
                laenge[k].index1 = jetzt[0];
                laenge[k].index2 = jetzt[1];
                k++;
                return 1;
        }
 
        for (i = j; i < max; i++) {
                if (jetzt) jetzt[n] = i;
                count += choose(jetzt, n + 1, goal, i, max);
        }
        return count;
}

int nCr(int a, int b)
{
    if (b == 0) return 1;
    return (a * nCr(a - 1, b - 1)) / b;
}