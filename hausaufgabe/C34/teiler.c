#define EPS 1e-12
#include <stdio.h>

double find_teiler(double, double);
int find_gcd(int, int);
int pow_10(int);

int main() {

    double result, x, y;

	printf("Add the first number:");
	scanf("%lf", &x);
	printf("Add the second number:");
	scanf("%lf", &y);

	result = find_teiler(x, y);

	printf("%3.5f", result);
	return 0;

}

double find_teiler(double x, double y){
    int counter = 0;
    while(x - (int)x > EPS && y - (int)y > EPS){
        x*=10;
        y*=10;
        counter++;
    }
    return find_gcd((int)x, (int)y) * 1.0 / pow_10(counter);
}

int find_gcd(int a, int b){
    int c = 0;
    if(a==b)return a;
    else if (a<b){
        while(b%a != 0){
            c = a;
            a = b - (b/a)*a;
            b = c;
        }
        return a;
    }
    else{                  
        while(a%b != 0){    
            c = b;          
            b = a - (a/b)*b;
            a = c;          
        }
        return b;
    }
}

int pow_10(int p){
    int r = 1;
    for(int i = 0; i<p; i++)r*=10;
    return r;
}
