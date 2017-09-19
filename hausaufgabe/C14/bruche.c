/* Gegeben sei das folgende Programm mit vier Variablen (a, b, c, d). Diese Variablen stellen den Zähler bzw.
den Nenner zweier Bruchzahlen a / b bzw. c / d dar. Ergänzen Sie das Programm, damit es den Ausdruck a / b + c / d berechnet,
und den resultierenden Bruch so viel möglich gekürzt und auf dem Bildschirm ausgegeben. Sie dürfen beliebig viele neue Variablen
definieren und annehmen, dass weder b noch d Null ist.*/

#include <stdio.h>

int find_gcd(int, int);

int main() {

	int a, b, c, d, gcd;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);

	// a/b + c/d = (a*d+c*b)/b*d 

    a = (a*d+c*b); //numerator
    b = b*d;        //denominator

    gcd = find_gcd(a, b);
    a = a / gcd;
    b = b / gcd;

	printf("%d / %d", a, b);


	return 0;

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