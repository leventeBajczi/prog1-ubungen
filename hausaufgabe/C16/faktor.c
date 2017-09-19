/*Ergänzen Sie das Progamm um die Faktorisierung einer ganzen Zahl in geschlossener Form zurückzugeben.
Zum Beispiel ist der folgende Ausdruck für 40 auf dem Bildschirm zu sehen: 40 = 2^3 * 5 oder 4400 = 2^4 * 5^2 * 11.
Wegen des automatischen Testes achten Sie sehr auf printf-Befehl und folgen Sie dieser Konvention:
input = number1^exp1 * number2^exp2 * ... * numberN^expN.*/
#include <stdio.h>
#include <stdlib.h>

enum boolean{false, true};

enum boolean is_prime(int);

int main(){

     int number, i = 2, j = 0, faktoranzahl = 0;
     int* faktoren = (int *)malloc(sizeof(int)*(32)); //maximum 32 bits
     scanf("%d",&number);
     if(number<2) return 0;
     printf("%d =", number);

     while (number!=1){
         if(is_prime(i) == true && number%i == 0){
            faktoranzahl++;
            faktoren[faktoranzahl-1] = i;
            number /= i;
         }else{
             i++;
         }
     }
     faktoren[faktoranzahl] = -1;
     for(i = 1; i<=faktoranzahl; i++){
         j=1;
         while(faktoren[i] == faktoren[i-1]){
             j++;
             i++;
         }
         if(j>1)printf(" %d^%d", faktoren[i-1], j);
         else printf(" %d", faktoren[i-1]);
         if(i!=faktoranzahl)printf(" *");
     }
     
     free(faktoren);
     return 0;

}
enum boolean is_prime(int n){
    for(int i = 2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}