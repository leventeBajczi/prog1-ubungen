#include <stdio.h>

#define MAX 100

unsigned int get_palindrome(unsigned int);
short is_palindrome(unsigned int);
unsigned int pow_10(unsigned int);

int main() {
    unsigned int number, pal, k = 0;
	printf("Add a number: ");
	scanf("%u", &number);

    pal = number;
    while(k<MAX && !is_palindrome(pal))
    {
        pal+= get_palindrome(pal);
        k++;
    }

	printf("Number of steps to get palindrom from %u: %u\n", number, k);

	return 0;

}

unsigned int get_palindrome(unsigned int n)
{
    unsigned int r = 0, k = 0;
    while(n){
       
        if(!(n%10)){
            k++;
        }
        else{
            
            r = (n%10) + r*pow_10(k+1); 
            k = 0;
        }
        n/=10;
    }
    
    return r;
}
short is_palindrome(unsigned int n){
    if(n == get_palindrome(n))return 1;
    return 0;
}

unsigned int pow_10(unsigned int p){
    unsigned int r = 1;
    for(unsigned int i = 0; i<p; i++)r*=10;
    return r;
}