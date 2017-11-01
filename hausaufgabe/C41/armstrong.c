#include <stdio.h>
#include <stdlib.h>


void find(int);
unsigned long pow_a_b(unsigned long a, unsigned long b);
unsigned long long choose(unsigned long long*, int, int, int, int);
int cmpfunc (const void *, const void *);

unsigned long long k = 0;
unsigned long long min_zahl, max_zahl;
unsigned long long *zahlen;
unsigned long long *gute_zahlen;



int main() {
    int N;
	printf("Add the number of the digits: ");
	scanf("%d", &N);

	find(N);
	return 0;

}


int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
 }
 

void find(int n){
    unsigned long long *chosen = (unsigned long long*)malloc(sizeof(unsigned long long)*n);
    unsigned long long sum, zahl;
    zahlen = (unsigned long long*)malloc(sizeof(unsigned long long)*10);
    for(unsigned long i = 0; i<10; i++){
        zahlen[i] = pow_a_b(i, n);
    }

    min_zahl = pow_a_b(10, n-1);
    max_zahl = pow_a_b(10, n);
    

    choose(chosen, 0, n, 0, 10);

    qsort(gute_zahlen, k, sizeof(unsigned long long), cmpfunc);
    
    for(unsigned long long i = 0; i<k;i++){
        zahl = 0;
        sum = gute_zahlen[i];
        for(int j = 0; j<n;j++){
            zahl += zahlen[sum%10];
            sum/=10;
        }
        if(zahl == gute_zahlen[i])printf("%llu ", zahl);
    }

    free(zahlen);
    free(chosen);
    free(gute_zahlen);
}

unsigned long long choose(unsigned long long * jetzt, int n, int goal, int j, int max)
{
        int i;
        unsigned long long count = 0;
        if (n == goal) {
                unsigned long long sum = 0, zahl = 0;
                if (!jetzt) return 1;
                for (i = 0; i < goal; i++)
                {
                    sum +=zahlen[jetzt[i]];
                }
                if(sum >= min_zahl && sum<max_zahl) {
                    if(k%100 == 0)gute_zahlen = (unsigned long long*)realloc(gute_zahlen, sizeof(unsigned long long)*100*(k/100 + 1));
                    gute_zahlen[k] = sum;
                    k++;
                }
                return 1;
        }
 
        for (i = j; i < max; i++) {
                if (jetzt) jetzt[n] = i;
                count += choose(jetzt, n + 1, goal, i, max);
        }
        return count;
}

unsigned long pow_a_b(unsigned long a, unsigned long b){
    if(b == 0) return 1;
    else return a*pow_a_b(a, b-1);
}