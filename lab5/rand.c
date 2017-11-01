#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(0)); //seed eingeben
    printf("%d", rand());
    return 0;
}