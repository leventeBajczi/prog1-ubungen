#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI              3.141592653
#define SPEICHENANZAHL  4.0
#define SPEICHENLAENGE  1.0
#define WINKELTEILUNG   1000.0
#define SPEICHENTEILUNG 1000.0
#define DT              1E-3
#define V               1.0

void test_normal();
void test_besoffen();
double test(double, double);

typedef struct ort ort;
struct ort{
    double winkel;
    double vom_ende;
    double zeit;
};

typedef struct punkt punkt;
struct punkt{
    double x;
    double y;
};


int main()
{
    test_normal();
    test_besoffen();
    return 0;
}


void test_normal()
{
    ort max = {0, 0, 0}; 
    double t;
    for(int i = 0; i<=WINKELTEILUNG; i++)
    {
        for(int j = 0; j<=SPEICHENTEILUNG; j++)
        {
            /*
            die optimale Punkt muss bei einem Speiche sein, weil anderwegs muesste eine laengere Strecke existieren
            wegen Symmetrie muss nur eine Speiche getestet werden
            */
            t = test(2*PI/SPEICHENANZAHL/WINKELTEILUNG*i, SPEICHENLAENGE/SPEICHENTEILUNG*j);
            if(max.zeit < t)
            {
                max.zeit = t;
                max.vom_ende = SPEICHENLAENGE/SPEICHENTEILUNG*j;
                max.winkel = 2*PI/SPEICHENANZAHL/WINKELTEILUNG*i;
            }
            /* Statusanzeige, aber Haweb magt \b nicht
            printf("\b\b\b\b\b\b");
            printf("%5.1lf%%", ((double)i*SPEICHENTEILUNG+j)/((double)WINKELTEILUNG * SPEICHENTEILUNG + SPEICHENTEILUNG) * 100);
            */

        }
    }
    printf("\nWenn eine der Speichen %lfrad Winkel zu den vertikalen Achse hat, soll der Finger entlang dieser Speiche (%lfm weit von dem Endpunkt) gesteckt werden, damit er für %lf Sekunden nicht abgeschnitten wird.\n", max.winkel, max.vom_ende, max.zeit);
}

double test(double winkel, double vom_ende)
{
    int i = 0;
    punkt unsere_punkt = {0.0, 0.0};
    punkt mittelpunkt  = {-1.0*sin(winkel)*(SPEICHENLAENGE - vom_ende), cos(winkel)*(SPEICHENLAENGE - vom_ende)};
    do
    {
        mittelpunkt.x += DT*V;
        winkel += DT * V / SPEICHENLAENGE;
        i++;
    } while( winkel <= 2*PI && ((mittelpunkt.x - unsere_punkt.x)*(mittelpunkt.x - unsere_punkt.x) + (mittelpunkt.y - unsere_punkt.y)*(mittelpunkt.y - unsere_punkt.y) < SPEICHENLAENGE*SPEICHENLAENGE && //inside the circle
    (tan(PI/2 - winkel)*unsere_punkt.x - unsere_punkt.y) < (tan(PI/ 2 - winkel)*mittelpunkt.x - mittelpunkt.y)) );                                                                                       //before the next rod
    return i * DT;
}

void test_besoffen(){
    printf("Falls man besoffen ist, wird der Finger jemals abgeschnitten. :-) \n");
    
}
