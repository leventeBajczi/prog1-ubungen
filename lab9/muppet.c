#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <search.h>

struct critter  
{
  char name[30];
  char species[30];
  int age;
};

/* Ein Array von Strukturen */
struct critter muppets[] =  {
	{"Kermit", "frog", 5},
	{"Piggy", "pig", 20},
	{"Gonzo", "whatever", 33},
	{"Fozzie", "bear", 21},
	{"Sam", "eagle", 12},
	{"Robin", "frog", 22},
	{"Animal", "animal", 54},
	{"Camilla", "chicken", 84},
	{"Sweetums", "monster", 34},
	{"Dr. Strangepork", "pig", 83},
	{"Link Hogthrob", "pig", 2},
	{"Zoot", "human", 4},
	{"Dr. Bunsen Honeydew", "human", 6},
	{"Beaker", "human", 9},
	{"Swedish Chef", "human", 4}
};

int cmp(const void* a, const void*b)
{
    return (((struct critter*)a)->age - ((struct critter*)b)->age);
}

char* age(struct critter * muppet)
{
    return muppet->name;
}

int main(void)
{
    int i;
    qsort(muppets, sizeof(muppets)/sizeof(struct critter), sizeof(struct critter), cmp);
    printf("The oldest animal is %s\n", age(&(muppets[sizeof(muppets)/sizeof(struct critter)-1])));
    return 0;
}