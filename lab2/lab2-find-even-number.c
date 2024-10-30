#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
    int array[10];
    int even_found = 0;

    for (int i = 1; i < argc; i++) {
        array[i] = atoi(argv[i]);
    }

    for (int i = 1; i < argc; i++) {
        if (array[i] % 2 == 0) {
            printf("%d - %d\n", i - 1, array[i]);
            even_found = 1;
        }
    }
    if (!even_found) {
            printf("Not found!\n");
    }
    return 0;
}