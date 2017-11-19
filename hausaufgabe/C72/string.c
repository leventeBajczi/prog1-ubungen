#include <string.h>

char *sortString(char *str)
{
    int done = 0, count = 0;
    while(!done)
    {
        done = 1;
        for(int i = 0; i<strlen(str)-1-count; i++)
        {
            if(str[i] > str[i+1])
            {
                done = 0;
                str[i] ^= str[i+1];
                str[i+1] ^= str[i];
                str[i] ^= str[i+1];
            }
        }
        count++;
    }
    return str;
}

#include <stdio.h>
      
      int main() {
      
      	char string[50];
      
      	printf("Enter a string: ");
      	scanf("%s", string);
      	printf("Sorted string: %s", sortString(string));
      
      	return 0;
      
      }