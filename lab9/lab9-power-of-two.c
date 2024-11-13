/*
Author: Seamus Devlin
Date: 11/11/24
Description:
*/

#include <stdio.h>
#include <stdlib.h>

int is_power_of_two(int n) {
    // Check if n is positive and only one bit is set
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main(int argc, char* argv[]) {
    // Check if there is an input argument
    if (argc != 2) {
        printf("Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    // Convert input argument to an integer
    int n = atoi(argv[1]);

    // Check if the integer is a power of two and print the result
    if (is_power_of_two(n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}