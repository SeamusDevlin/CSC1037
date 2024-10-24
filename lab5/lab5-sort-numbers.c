#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// comparing the functions

int compare_asc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int compare_desc(const void* a, const void* b) { return (*(int*)b - *(int*)a); }

typedef int (*compare_func)(const void*, const void*);

int main(int argc, char *argv[]) {
    int num_count = atoi(argv[1]);
    int *numbers = malloc(num_count * sizeof(int));
    for (int i = 0; i < num_count; i++) numbers[i] = atoi(argv[i + 2]);

    compare_func comparator = strcmp(argv[argc - 1], "asc") == 0 ? compare_asc : compare_desc;
    qsort(numbers, num_count, sizeof(int), comparator);

    printf("Sorted numbers: ");
    for (int i = 0; i < num_count; i++) {
        printf("%d", numbers[i]);
        if (i < num_count - 1) printf(" ");
    }
    printf("\n");

    free(numbers);
    return 0;
}