#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void find(uint32_t);
uint64_t pow_a_b(uint64_t a, uint64_t b);
uint64_t choose(uint64_t*, uint32_t, uint32_t, uint32_t, uint32_t);
int cmpfunc (const void *, const void *);

uint64_t k = 0;
uint64_t min_zahl, max_zahl;
uint64_t *zahlen;
uint64_t *gute_zahlen;

uint32_t main() {
    uint32_t N;
	printf("Add the number of the digits: ");
	scanf("%d", &N);

	find(N);
	return 0;

}

//Für die qsort() Funktion
int cmpfunc (const void * a, const void * b) {
    return (int)( *(uint32_t*)a - *(uint32_t*)b );
 }
 
//Hauptfunktionalität, sucht nach passende N-ziffrige zahlen
void find(uint32_t n){
    uint64_t *chosen = (uint64_t*)malloc(sizeof(uint64_t)*n);   //Die Array, in der die Variationen gespeichert werden
    uint64_t sum, zahl;                                         //nötige Veränderlichen für die Gleichungstest später
    zahlen = (uint64_t*)malloc(sizeof(uint64_t)*10);            //
    for(uint64_t i = 0; i<10; i++){                             //Generation von dem a^n aus den 10 Ziffern 
        zahlen[i] = pow_a_b(i, n);                              //
    }

    min_zahl = pow_a_b(10, n-1);                                //Die erste N-ziffrige Zahl
    max_zahl = pow_a_b(10, n);                                  //Die erste N+1-ziffrige Zahl
    

    choose(chosen, 0, n, 0, 10);                                //Gute Variationen generieren

    qsort(gute_zahlen, k, sizeof(uint64_t), cmpfunc);           //Gute Variationen im Ordnung stehen lassen
    
    for(uint64_t i = 0; i<k;i++){                               //Suche nach den wirklich guten Zahlenfolgen (die als Summe die Zahl selbst geben) 
        zahl = 0;
        sum = gute_zahlen[i];
        for(uint32_t j = 0; j<n;j++){
            zahl += zahlen[sum%10];
            sum/=10;
        }
        if(zahl == gute_zahlen[i])printf("%llu ", zahl);     
    }

    free(zahlen);
    free(chosen);
    free(gute_zahlen);
}


//Variationen generieren, weil nur solche Zahlen getestet werden sollen, die von N Ziffern so zusammenstellbar sind, dass die einzige Ziffern auf der N-ten Potenz stehen.
uint64_t choose(uint64_t * jetzt, uint32_t n, uint32_t goal, uint32_t j, uint32_t max)
{
        uint32_t i;
        uint64_t count = 0;
        if (n == goal) {                    //hier haben wir eine neue, gute Variation
                uint64_t sum = 0, zahl = 0;
                if (!jetzt) return 1;
                for (i = 0; i < goal; i++)
                {
                    sum +=zahlen[jetzt[i]]; //um eine Zahl aus dem Zahlenfolge zusammenzustellen brauchen wir diese Schleife
                }
                if(sum >= min_zahl && sum<max_zahl) {   //Falls die zusammengestellte Zahl in der gute Menge is (min<=Zahl<max
                    if(k%100 == 0)gute_zahlen = (uint64_t*)realloc(gute_zahlen, sizeof(uint64_t)*100*(k/100 + 1)); //Nach jeder hunderten gute Zahl verwenden wir eine realloc() Funktion, um Prozessorzeit zu sparen (wir können uns leisten, 100*64 bits zu speichern)
                    gute_zahlen[k] = sum;     //wir addieren die neue gute Zahl zu dem List
                    k++;
                }
                return 1;
        }
 
        for (i = j; i < max; i++) {          //Rekursiv zurücktreten, um Variationen zu generieren
                if (jetzt) jetzt[n] = i;
                count += choose(jetzt, n + 1, goal, i, max);
        }
        return count;
}

//Funktion für a hoch b
uint64_t pow_a_b(uint64_t a, uint64_t b){
    if(b == 0) return 1;
    else return a*pow_a_b(a, b-1);
}