#include <stdio.h>

#define MAX 8*sizeof(unsigned int) - 1

int main() {

    unsigned int num1, num2, xorproduct, distance = 0;

	printf("Add the first number: ");
	scanf("%u", &num1);
	printf("Add the second number: ");
    scanf("%u", &num2);
    
	printf("Different digits:");

    xorproduct = num1 ^ num2;
    
    for(int i = 0; i<=MAX; i++)
    {
        if (xorproduct << i & (1 << MAX))
        {
            distance++;
            printf(" %lu", MAX - i);
        }
        
    }

	printf("\nHamming-distance: %u", distance);
	return 0;

}
