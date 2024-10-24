#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <Name> <Capital> <Population (in million)> <Size (in km2)>\n", argv[0]);
        return 1;
    }

    // putting info from command line
    
    char *name = argv[1];
    char *capital = argv[2];
    double population = atof(argv[3]);
    int size = atoi(argv[4]);

    // printing each info line by line

    printf("%s\n", name);
    printf("%s\n", capital);
    printf("%.2f million people\n", population);
    printf("%d km2\n", size);

    return 0;
}