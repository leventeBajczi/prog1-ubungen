#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void fuellung(int **);
void show_array(int **);
void get_entfernende(int*);
void entfernen(int**, int*);
int next_gut_glied(int*, int*, int**, int*);

int main(){
    int *i_array = (int*)malloc(sizeof(int) * ARRAY_SIZE), a;
    printf("%d.: ", sizeof(*i_array));
    fuellung(&i_array);
    show_array(&i_array);
    get_entfernende(&a);
    entfernen(&i_array, &a);
    show_array(&i_array);
    
    return 0;
}

void fuellung(int ** array){
    for(int i = 0; i<ARRAY_SIZE; i++){
        printf("%d.: ", i);
        scanf("%d", &(*array)[i]);
    }
}

void show_array(int ** array){
    printf("\n");
    for(int i = 0; i<ARRAY_SIZE; i++)printf("[%d].: %d    ", i, (*array)[i]);
}

void get_entfernende(int * n){
    printf("\nGeben Sie die entfernende Zahl ein: ");
    scanf("%d", n);
}

void entfernen(int** array, int* n){
    int i, j = 0;
    for(i = 0; i<ARRAY_SIZE; i++){
        (*array)[i] = next_gut_glied(&i, &j, array, n);
    }
}

int next_gut_glied(int* i, int* j, int** array, int* n){
    
    if((*i+*j)<ARRAY_SIZE && (*array)[*i+*j] != *n){
        return (*array)[*i + *j];
    }
    else if((*i+*j)<ARRAY_SIZE){
        (*j)++;
        return next_gut_glied(i, j, array, n);
    }
    else return 0;
}