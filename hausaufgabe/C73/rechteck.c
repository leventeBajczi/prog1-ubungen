#include <stdio.h>

int latin[6][2] = {{1, 2}, {2, 4}, {3, 6}, {4, 1}, {5, 3}, {6, 5}};


int istGut(int[6][2], int, int);

int main()
{
    if(istGut(latin, 6, 2)) printf("Ja");
    else printf("Nein");
    return 0;
}
int istGut(int array[6][2], int zeile, int spalten)
{
    int test = 0;
    for(int i = 0; i < zeile; i++)
    {
        test &= 0xffffff00;
        for(int j = 0; j < spalten; j++)
        {
            test ^= (1 << array[i][j]); 
            test ^= (1 << ((j+1)*8 + array[i][j]));
        }
        if((test & 0x000000ff) == 0) return 0;
    }
    if((test & 0x0000ff00) != (0x7e << 8)) return 0;    //0x7e = 0b01111110
    if((test & 0x00ff0000) != (0x7e << 16)) return 0;
    return 1;
}