#include <stdio.h>
#include <math.h>

#define FUNKTION(x) exp(3 * x) - 4 * sin(2 * x / 29) + 4 * x * x * x - 7 * x - 8 
#define LOW 0.0
#define HIGH 1.0
#define LOESUNG 0.0


int main()
{
    short result = 1, steigend = 0;
    double x = LOW, last_low = LOW, last_high = HIGH, y;
    if(FUNKTION(last_high) > FUNKTION(last_low)) steigend = 2;
    while(result)
    {
        y = FUNKTION(x);

        if(y == LOESUNG) result = 0;
        else if (y * (steigend - 1) < 0)   //falls steigend, multiplizieren wir mit 1 (machen wir nichts), falls nicht, dann mit (-1), was ergibt eine > aus <
        {

            last_low = x;
            x = (x + last_high) / 2.0;
        }
        else
        {
            last_high = x;
            x = (x + last_low) / 2.0;
        }
    }
    printf("%lf", x);
    return 0;
}

//Note: Die angegebene Funktion ist NICHT monoton, also dieses Algoritmus ergibt die richtige Loesung, weil obwohl in [0:1] sie eine lokale Minimumstelle hat, in [0.5:1] hat sie keine. 