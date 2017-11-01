/* Schreiben Sie eine void C-Funktion, die 2 char Arrays (ein1, ein2) als Parameter bekommt und ein char
Array liefert. Die Funktion soll den Inhalt der ersten zwei Arrays ins dritte Array kopieren so, dass die Worten
vom ersten bzw. zweiten Array abwechselnd kopiert werden. Die Worten werden durch Whitespace-Zeichen
getrennt. Sie können annehmen, dass beide Arrays die gleiche Anzahl von Worten beinhalten. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mischen(char*, char*);

int main(int argc, char** argv)
{
    if (argc>=3) mischen(argv[1], argv[2]);
    else if (argc == 2) mischen(argv[1], "");
    else printf("Nicht genug Parametern\n");
    return 0;
}

void mischen(char* a, char* b)
{
    char* c = (char*)malloc(sizeof(char)*(strlen(a) + strlen(b) + 2));
    if(b[0] == '\0') strcpy(c, a);
    else
    {
        char boolean = 0;
        int count_a = 0, count_b = 0;
        int i;
        for (i = 0; i<=strlen(a) + strlen(b); i++)
        {
            if ((boolean || (count_a > strlen(a)) && count_b <= strlen(b)) )
            {
                if (b[count_b] == '\0') c[i] = ' ';
                else c[i] = b[count_b];
                count_b++;
            }
            else
            {
                if (a[count_a] == '\0') c[i] = ' ';
                else c[i] = a[count_a];
                count_a++;
            }
    
            if (c[i] == ' ') boolean = ~boolean;
            
        }
        c[i+1] == '\0';
    }
    printf("%s\n", c);
    free(c);
}
