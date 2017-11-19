#include <stdio.h>
#include <stdlib.h>
      
int* getPrimes(unsigned int);

int main() {
     
   	int *parray=NULL, N, i;
      
   	printf("Add the number of primes: ");
   	scanf("%d", &N);
      
   	parray = getPrimes(N);
      
   	for (i = 0; i < N; i++) printf("%d ", parray[i]);
   
   	free(parray);
   
   	return 0;
    
}

int* getPrimes(unsigned int N)
{
    int* primes = (int*)malloc(sizeof(int)*N);
    int i = 0, j = 2, isprime = 1;
    while(i<N)
    {
        isprime = 1;
        for(int k = 2; k<j; k++)
        {
            if(j % k == 0)isprime = 0;
        }
        if(isprime)
        {
            primes[i] = j;
            i++;
        }
        j++;
    }
    return primes;
}