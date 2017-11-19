#include <string.h>

int isPalindrome(const char* s)
{
    for(int i = 0; i<strlen(s) / 2; i++)    //Falls s gerade lang ist, dann testen fuer die erste einhalb, anderns halb-ein
    {
        if(s[i] != s[strlen(s) - i - 1]) return 0;
    }
    return 1;
}

#include <stdio.h>
      
      int main() {
      
      	char string[50];
      
      	printf("Enter a string: ");
      	scanf("%s", string);
      
      	if (isPalindrome(string) == 0) printf("Not palindrome");
      	else printf("Palindrome");
      
      	return 0;
      
      }