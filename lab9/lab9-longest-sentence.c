/*
Author: Seamus Devlin
Date: 11/11/2024
Description: Prints the longest strings from command line
*/
/* Relevant libraries  & description */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the longest string length
int find_longest_length(char** strings, int count) {
    int max_length = 0;
    for (int i = 0; i < count; i++) {
        int length = strlen(strings[i]);
        if (length > max_length) {
            max_length = length;
        }
    }
    return max_length;
}

// Function to store and print the longest strings
void print_longest_strings(char** strings, int count, int max_length) {
    for (int i = 0; i < count; i++) {
        if (strlen(strings[i]) == max_length) {
            printf("%s\n", strings[i]);
        }
    }
}

int main(int argc, char* argv[]) {
    // Check if there are enough arguments
    if (argc < 2) {
        printf("Usage: %s <strings...>\n", argv[0]);
        return 1;
    }

    // Calculate the number of strings
    int count = argc - 1;

    // Dynamically allocate memory for string pointers
    char** strings = (char**)malloc(count * sizeof(char*));
    if (strings == NULL) {
        perror("Failed to allocate memory for strings");
        return 1;
    }

    // Store each input string in the dynamically allocated array
    for (int i = 0; i < count; i++) {
        strings[i] = argv[i + 1];
    }

    // Find the maximum length of the strings
    int max_length = find_longest_length(strings, count);

    // Print the longest strings
    print_longest_strings(strings, count, max_length);

    // Free the dynamically allocated memory
    free(strings);

    return 0;
}