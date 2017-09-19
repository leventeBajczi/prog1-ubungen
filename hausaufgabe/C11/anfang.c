#include<stdio.h>

int main()
{
    int i;
    printf("Please enter a positive integer\n");
    scanf("%d", &i);

    for(int j = 1; j <= i; j++){
        if(i%j == 0) printf("%d ", j);
    }

    return 0;
}