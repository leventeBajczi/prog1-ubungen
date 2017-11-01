#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 100
#define MAX 100

void a_uebung(int**);
void b_uebung(int**);

int main(){
    int *a = (int*)malloc(sizeof(int)*N);
    srand(time(0));
    a_uebung(&a);
    b_uebung(&a);
    free(a);
    return 0;
}

void a_uebung(int** a){
    for(int i = 0; i<N; i++) (*a)[i] = rand()%(MAX + 1);
}

void b_uebung(int** b){
    int min = (MAX + 1);
    double avg = 0.0;
    for(int i = 0; i<N; i++){
        if((*b)[i]< min) min = (*b)[i];
        avg+=((double)(*b)[i])/N;
    }
    printf("min: %d\tavg: %lf", min, avg);
}