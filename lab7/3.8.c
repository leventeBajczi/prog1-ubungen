#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN      50
#define ALLOCUNIT   1

char* get_string(char*, char*);
uint8_t is_part(char, char*);

int main(){
    char* ergebnis;
    char* str = (char*)malloc(sizeof(char)*MAXLEN);
    char* delim = (char*)malloc(sizeof(char)*MAXLEN);
    printf("Geben Sie den Anfangszeichenkette ein: ");
    scanf("%s", str);
    printf("\nGeben Sie den Delimiterzeichenkette ein: ");
    scanf("%s", delim);
    ergebnis = get_string(str, delim);
    printf("\n%s", ergebnis);
    free(str);
    free(delim);
    free(ergebnis);
    return 0;
}

char* get_string(char* str, char* delim){
    char* string = NULL;
    uint8_t switcher = 0;
    int j = 0, k = 0;
    for(int i = 0; i<strlen(str); i++){
        if(switcher){
            if(k%ALLOCUNIT == 0) string = (char*)realloc(string, sizeof(char)*((k/ALLOCUNIT + 1)*ALLOCUNIT + 1));
            string[k] = str[i];
            k++;
        }
        if(is_part(str[i], delim)){
            switcher = ~switcher;
            if(switcher){
                if(k%ALLOCUNIT == 0) string = (char*)realloc(string, sizeof(char)*((k/ALLOCUNIT + 1)*ALLOCUNIT + 1));
                string[k] = str[i];
                k++;
            }
        }
    }
    string[k] = '\0';
    return string;

}

uint8_t is_part(char c, char* str){
    for(int i = 0; i<strlen(str); i++)
    {
        if(c == str[i])return 1;
    }
    return 0;
}
