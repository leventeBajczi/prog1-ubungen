/*Schreiben Sie ein ANSI C Programm, das das folgende Integral I numerisch berechnet: I = int_2^3(sin^2(2x) + 0.1e^-x) dx*/

#include <stdio.h>
#include <math.h>

#define A 2
#define B 3
#define N 1000

void parse(int*, char*);

double get_wert(double);

int n = 0, a = 0, b = 0;

int main(int argc, char** argv){
    double integral = 0.0;
    
    if(argc == 2){
        parse(&n, argv[1]);
        a = A;
        b = B;
    }
    else if(argc>3){
        parse(&a, argv[1]);
        parse(&b, argv[2]);
        parse(&n, argv[3]);
    }
    else{
        n = N;
        a = A;
        b = B;
    }
    for(int i = 0; i<n; i++){
        integral += get_wert(((double)i + 0.5)/(double)n);
    }
    printf("%f\n", integral);
    return 0;
}

void parse(int* a, char* b){
    int i = 0;
    *a = 0;
    while(b[i] != '\0'){
        *a = (*a)*10 + b[i] - '0';
        i++;
    }
}

double get_wert(double d){
    return (pow(sin(2*(a + d)), 2) + 0.1*exp(-a-d))*(b-a)/n;
}