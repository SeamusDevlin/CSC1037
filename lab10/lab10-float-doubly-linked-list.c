/*
Author: Seanus Devlin
Date: 14/11/24
Description: Forming a doubly linked list from command line arguments and printing the contents reversed
*/

// include relevant libraries
#include <stdio.h>
#include <stdlib.h>

// defines alias name for structure
typedef struct linkedlist linkedlist;

// defines structure for doubly linked list node
struct linkedlist {
    float value; // float that stores each value in node
    linkedlist *next; // pointer to next node
    linkedlist *prev; // pointer to previous node
};

// function prototypes
linkedlist* get_values(float *array, int length); // initialises linked list from array
void printreverse(linkedlist *last); // prints list in reverse order

// main function
int main(int argc, char*argv[]) {
    linkedlist *start = NULL; // start is a pointer at the start of linked list initially set to NULL
    int n = atoi(argv[1]); // number of floating point numbers in the command line
    float arg_array[argc - 1]; // an array of floats that holds the floating point values from the command line
    int length = argc - 1; // number of elements in arg_array

// converts arguments from argv[2] onwards to floats and stores them in arg_array
    int j = 0;
    for(int i = 2; i < argc; i++) {
        *(arg_array + j) = atof(argv[i]);
        j++;
    }

// create linked list from arg_array and return pointer of last node in list    
    start = get_values(arg_array, length);
    printreverse(start);

    return 0;
}

// an array of floats and its length, creating a doubly linked list
linkedlist* get_values(float *array, int length) {
    linkedlist *current, *first, *prev; // initialises three pointers
    first = (linkedlist*)calloc(1, sizeof(linkedlist)); // memory for first node allocated using calloc
    current = first;
    current->value = array[0];
    current->prev = NULL;

// iterates through array creating new nodes for each element
    for(int i = 1; i < length - 1; i++) {
        current->next = (linkedlist*)calloc(1, sizeof(linkedlist));
        prev = current;
        current = current->next;
        current->value = array[i];
        current->prev = prev;
    }

    current->next = NULL;
    return current;
}

// takes pointer to the last node in linked list and prints each nodes value in reverse
void printreverse(linkedlist *last)
{
    linkedlist* p = NULL;
    for(p = last; p != NULL; p = p->prev)
    {
        printf("%.2f\n", p->value);
    }
}