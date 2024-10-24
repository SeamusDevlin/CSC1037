#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {

    int length = argc - 1;
    int numbers[length];
    int odd = 0;
    for (int i = 0; i < length; i++)
    {
        numbers[i] = atoi(argv[i+1]);
    }
    for(int i = 0; i < length; i++)
    {
        if (numbers[i] % 2 != 0) {
            odd ++;
        }
    }
    printf("%d\n", odd);
    return 0;
}