#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
    int length = argc - 1;
    int numbers[length];
    int even = 0;

    for(int i = 0; i < length; i++) {
        numbers[i] = atoi(argv[i+1]);
    }

    for (int i = 0; i < length; i++) {
        if (numbers[i] % 2 == 0) {
            even++;
            printf("%d - %d\n", i, numbers[i]);
        }
    }

    if (even == 0) {
        printf("Not found!\n"); 
    }

    return 0;
}