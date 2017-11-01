#include <stdio.h>
#include <math.h>

#define PI 3.141592653
#define M  1.0 //[kg]
#define H  1.0 //[m]
#define A  PI/6 //[rad]
#define V  5.0 //[m/s]
#define DT 1E-2 //[s]
#define G  10.0 //[m/s^2]
#define F(v) v * v / 10.0
#define ANZAHL 2000

double calc_d_coordinate(double, double, double*);

int main(){
    double x = 0, y = H, vx = cos(A) * V, vy = sin(A) * V, z;
    for(int i = 0; i<ANZAHL; i++){
        x+= calc_d_coordinate(F(vx), 0.0, &vx);
        z = calc_d_coordinate(F(vy), G, &vy);
        y+=z;
        printf("%lf\t%lf\t%lf\n", (i+1)*DT, x, y);
    }
    return 0;
}

double calc_d_coordinate(double wiederstand, double gforce, double * speed){
    double force = ((*speed>0) ? (wiederstand + gforce) : (-1.0*wiederstand + gforce));
    *speed -= force/M * DT;
    return (*speed)*DT - force/M/2.0 * DT * DT;
}