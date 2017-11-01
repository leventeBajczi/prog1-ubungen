#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{

    double d1, d2, dd = 0;

    srand(12345678L); /* Start state of random generator */



    for(int i = 0; i<100;i++)
    {
        d1 = 0;
        d2 = 0;
        for(int j = 0; j<10; j++){
            d1 += rand() / (RAND_MAX + 1.0); /* Random number between 0 and 1 */
            d2 += -1 + 2.0 * (rand() / (RAND_MAX + 1.0)); /* Random number between -1 and 1 */
        }
        dd += sqrt(d1*d1 + d2*d2);
    }

    printf("%lf", dd / 100.0);
    return 0;
}