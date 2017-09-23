/*Mersenne-Primen sind: M_p = 2^p -1*/

#include <stdio.h>

#define N 62

long pow_2(short);
short is_mersenne_prim(short);
short is_prime(long);

short main(int argc, char** argv){
    for(short i = 2; i<N; i++){
        if(is_mersenne_prim(i)) printf("%ld\n", pow_2(i) - 1);
    }
    return 0;
}

short is_mersenne_prim(short a){
    return (is_prime(a) && is_prime(pow_2(a) - 1)) ? 1 : 0;
}

short is_prime(long a){
    for(int i = 2; i*i<a; i++){
        if(!(a%i))return 0;
    }
    return 1;
}

long pow_2(short b){
    return (long)1 << b; // 2^b, weil 0b00000001 wird beim b links geschiftet
}