#include <stdio.h>
#include <math.h>

int roots(double, double, double, double*, double*);

int main() {
   
  	double a, b, c, r1, r2;
   	int nr;
    
   	printf("Add a: ");
   	scanf("%lf", &a);
   	printf("Add b: ");
   	scanf("%lf", &b);
   	printf("Add c: ");
   	scanf("%lf", &c);
      
   	nr = roots(a, b, c, &r1, &r2);
      
   	if (nr == 2) printf("Two real roots: %.3f and %.3f.", r1, r2);
   	else if (nr == 1) printf("One real root: %.3f.", r1);
   	else printf("No real root!");
      
   	return 0;
      
}

int roots(double a, double b, double c, double* r1, double* r2)
{
    double det = b * b - 4.0 * a * c;
    if(det < 0)return 0;
    else if (det == 0) 
    {
        *r1 = (-1.0*b) / 2.0 / a;
        return 1;
    }
    else  
    {
        *r1 = (-1.0 * b + sqrt(det)) / 2.0 / a;
        *r2 = (-1.0 * b - sqrt(det)) / 2.0 / a;
        return 2;
    }
}