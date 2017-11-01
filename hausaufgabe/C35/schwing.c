#include <stdio.h>

#define DT 1e-6 // [s]
#define M 2     // [kg]
#define G 10    // [m/s^2]
#define D 10    // [N/m]
#define X 1     // [m]

#define ANZAHL 1000000

void calculate(double *, double*);

int main()
{
    double v = 0, a, x = X;
    for(int i = 0; i<ANZAHL; i++){
        calculate(&v, &x);
        printf("%lf\t%lf\n", (i+1)*DT, x);
    }
    return 0;
}

void calculate(double* v, double *x){
    double kraft = (*x) * D - M * G;       //Kraft aufwerts
    double a = kraft / M;
    *v += a * DT;
    *x -= *v * DT;
}