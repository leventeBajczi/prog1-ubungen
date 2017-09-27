/*Schreiben Sie ein Programm, das die Kubikwurzel von A durch eine iterative Annäherung berechnet.
Die Formel, nach welcher der nächste Wert xn+1 aus xn berechnet wird:

xn+1 = (2xn + A / xn2) / 3,

d. h. xn bezeichnet den Wert unserer Annäherung für Kubikwurzel von A nach n Iterationen.
Wählen Sie als Anfangswert x0 = A / 3, wenn |A| >= 1 ist, sonst sei x0 = 3 * A. Mit der Berechnung soll dann aufgehört
werden, wenn der Unterschied zwischen dem Glied xi und dem Glied xi+1 kleiner als 10-5 wird. Verwenden Sie das folgende Programm dazu:*/

#include <stdio.h>

float last_wert = 0.0f, wert;

float get_wert(double x, double A){
	wert = (2*x + A / (x*x)) / 3.0;
	if(last_wert - wert <= -10E-5 || last_wert - wert >= 10E-5){
		last_wert = wert;
		return get_wert(wert, A);
	}
	return wert;
}

float root3(double x){
	if(x == 0) return 0;
	double i = 0;
	if(x <= -1 || x>= 1) i = x / 3.0;
	else i = 3.0 * x;
	return get_wert(i, x);
}

int main() {

	double x;

	printf("Add x: ");
	scanf("%lf", &x);
	printf("%1.5f\n", root3(x));
	return 0;

}