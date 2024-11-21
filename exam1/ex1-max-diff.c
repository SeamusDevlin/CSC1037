/*
Name: Seamus Devlin
Student Number: 23389013
Date: 31/10/2024

Description:
Takes arguments from the command line and converts them into elements within
an array. Using a for loop to check the minimum and maximum value within the
array, it then takes it away from from each other finding the maximum difference
*/

// include nescessary libraries
#include <stdio.h>
#include <stdlib.h>

// main functions
int main(int argc, char *argv[]) {
    // checking to see if at least more than 2 arguments
    if (argc < 3) {
        printf("Nah\n");
        return 1;
    }
    // checking to see if under 100 arguments
    else if (argc > 100) {
        printf("Too much\n"); 
    }

    // using for loop to convert command line arguments into an array of integers
    int array[argc - 1];
    for (int i = 1; i < argc; i++) {
        array[i - 1] = atoi(argv[i]);
    }

    // finding the min_array in code as well as the max_array in code
    int min_array = array[0];
    int max_array = array[0];
    for (int i = 1; i < argc - 1; i++) {
        if (array[i] < min_array) min_array = array[i];
        if (array[i] > max_array) max_array = array[i];
    }

    int max_diff = max_array - min_array; // calculating the sum
    printf("%d\n", max_diff);

    return 0;
}
