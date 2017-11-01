#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCHLUESSEL 4
#define L 20

int* zufalltext();
int* xoren(int*, int*);
void display(char*, int*);

int main()
{
    int schluessel[SCHLUESSEL] = {12, 31, 24, 37};
    int* klartext = (int*)malloc(sizeof(int) * L);
    srand(time(0));
    klartext = zufalltext();
    display("Klartext: \t", klartext);
    klartext = xoren(klartext, schluessel);
    display("\nGeheimtext: \t", klartext);
    klartext = xoren(klartext, schluessel);
    display("\nEntschluesselt: ", klartext);
    free(klartext);
    return 0;
}

int* zufalltext()
{
    int* rueckgabe = (int*)malloc(sizeof(int)*L);
    for(int i = 0; i<L; i++)
    {
        rueckgabe[i] = 1 + (int) (100.0 * (rand() / (RAND_MAX + 1.0))); 
    }
    return rueckgabe;
}
int* xoren(int* was, int* womit)
{
    for(int i = 0; i<L; i++)
    {
        was[i] ^= womit[i%SCHLUESSEL];
    }
    return was;
}
void display(char* base, int* zahlen){
    char* base_helper = (char*)malloc(sizeof(char) * L * 3 + sizeof("\nEntschluesselt: "));
    sprintf(base_helper, "%s", base);
    for(int i = 0; i<L; i++)
    {
        sprintf(base_helper, "%s\t%d", base_helper, zahlen[i]);
    }
    printf("%s", base_helper);
}