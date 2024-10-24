/*
This program accepts info aout a given amount of countries and sorts them from largest size.
Author: Seamus Devlin
*/

#include <stdio.h>
#include <stdlib.h>

// define Location as type name for struct
typedef struct Location Location;

// defines Location struct which groups variables
struct Location {
    char *country;
    char *capital;
    float population;
    int size;
};

// does not return value
void location_print(char *country, char *cap, float pop, int s);
void bub_sort(Location list[50], int size); // defining bubble sort

// main function
int main(int argc, char *argv[]) {
    if ((argc - 1) % 4 != 0)
    {
        printf("Error: Incorrect number of arguments. Please provide data in sets of 4 (country, capital, population, size).\n");
        return 1;
    }

    Location location[50];
    int lcount = 0;

    for (int i = 1; i < argc; i += 4) {
        location[lcount].country = argv[i];
        location[lcount].capital = argv[i + 1];
        location[lcount].population = atof(argv[i + 2]);
        location[lcount].size = atoi(argv[i + 3]);

        lcount++;
    }

// calling bubble sort
    bub_sort(location, lcount);

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    for (int i = 0; i < lcount; i++) {
        location_print(location[i].country, location[i].capital, location[i].population, location[i].size);
    }

    return 0;
}

void location_print(char *country, char *cap, float pop, int s) {
    printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country, cap, s, pop);
}

// function sorts by bubble sort
void bub_sort(Location location[50], int size) {
    int i = 0;
    int j = 0;
    Location temp;
    for(i = 0; i < size; i++) {
        for(j = 0; j < (size - 1); j++) {
            if(location[j].population < location[j + 1].population) {
                temp = location[j];
                location[j] = location[j + 1];
                location[j + 1] = temp;
            }
        }
    }
}