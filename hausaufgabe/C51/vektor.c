/*Schreiben Sie ein Programm, das ein aus 20 Elementen bestehend double-Array mit Zufallszahlen auffüllt, die zwischen -1 und 1 liegen.
Das Programm soll das Element, welches die größte Abweichung vom Durchschnitt aller Elemente hat, auf dem Bildschirm ausschreiben.
Es soll weiterhin das größte und das kleinste Element des Arrays auch ausgeben.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   20

void fuell(double*);
void get_durchschnitt(double*, double*);
void get_werte(double*, double*);

typedef struct map map;
struct map{
    double wert;
    int index;
};

int main()
{
    double *array = (double*)malloc(sizeof(double)*N);
    double durchschnitt;

    srand(time(0));

    fuell(array);
    get_durchschnitt(array, &durchschnitt);
    get_werte(array, &durchschnitt);
    return 0;
}

void fuell(double* array)
{
    for(int i = 0; i<N; i++)
    {
        array[i] = rand()*2.0/RAND_MAX - 1.0;
    }
}
void get_durchschnitt(double* array, double* durchschnitt)
{
    for(int i = 0; i<N; i++)
    {
        *durchschnitt += array[i]/N;
    }
}
void get_werte(double* array, double* durchschnitt)
{
    map max = {-2.0, 0}, min = {2.0, 0}, groesste = {-2.0, 0};
    for(int i = 0; i<N; i++)
    {
        if((*durchschnitt - array[i])*(*durchschnitt - array[i]) > groesste.wert)     //falls die Abweichung am groessten ist, ist auch die Quadrat dieses Wertes am groessten, aber muessen wir uns nicht mit dem Vorzeichen beschaeftigen
        {
            groesste.wert = (*durchschnitt - array[i])*(*durchschnitt - array[i]);
            groesste.index = i;
        }
        if(array[i] > max.wert)   
        {
            max.wert = array[i];
            max.index = i;
        }
        if(array[i] < min.wert)     
        {
            min.wert = array[i];
            min.index = i;
        }
    }
    printf("Groesste Abweichung von dem Durschnitt (%lf): array[%d] = %lf\n", *durchschnitt, groesste.index, groesste.wert);
    printf("Groesste Element der Array: array[%d] = %lf\n", max.index, max.wert);
    printf("Kleinste Element der Array: array[%d] = %lf\n", min.index, min.wert);
}