/*
Name: Seamus Devlin
Date: 11/11/24
Description: Calculates the dot product of two vectors while allocating the correct amount of memory.
*/

// include relevant libraries
#include <stdio.h>
#include <stdlib.h>

// function prototype
int calc_dot_prod(int *pNumbers, int vec_size);

// main function
int main(int argc, char*argv[]) {

    // statements
    int length = argc - 2;
    int *pNumbers = NULL;
    int *pResult = NULL;
    int vec_size = 0;
    int j = 0;

    vec_size = atoi(argv[1]);

    pNumbers = (int*)malloc(length*(sizeof(int)));
    if(!pNumbers) {
        printf("Failed to allocate memory");
        return 0;
    }

    for(int i = 2; i < argc; i++) {
        *(pNumbers + j) = atoi(argv[i]);
        j++;
    }

     pResult = (int*)malloc(1*(sizeof(int))); // Allocating the size of memory
     *pResult = calc_dot_prod(pNumbers, vec_size);

      printf("%d\n", *pResult);

    // Free the memory
    free(pResult);
    free(pNumbers);

    return 0;
}

/* actual implementation of the functions */
int calc_dot_prod(int *pNumbers, int vec_size)
{
    //statements
    int product = 0;

    // Getting the total of the dot product for the two vectors
    for(int i = 0; i < vec_size; i++)
    {
        product += *(pNumbers + i) * *(pNumbers + (i + vec_size));
    }
    return product;
}