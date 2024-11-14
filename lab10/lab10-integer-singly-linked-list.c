/*
Author: Seamus Devlin
Date: 14/11/24
Description: Forming a singly linked list by taking arguments from the command line
*/

// include relevant libraries
#include <stdio.h>
#include <stdlib.h>

// defines alias name for structure
typedef struct Linkedlist Linkedlist;

// defines structure for singly linked list node
struct Linkedlist {
    int value; // holds value of node
    Linkedlist *next; // points to next node in the linked list
};

// prototypes
Linkedlist* get_values(int *array, int length); // accepts array of integers and number of elements
void printlinkedlist(Linkedlist *start); // takes head of the linked lost and prints each element

// main function
int main(int argc, char*argv[]) {
    // statements
    Linkedlist *start = NULL;
    int n = atoi(argv[1]);

    int arg_array[argc - 1]; // stores integer values stored
    int length = argc - 1;

    int j = 0;
    // loops through command line arguments starting from argv[2] to argv[argc - 1]
    for(int i = 2; i < argc; i++) {
        *(arg_array + j) = atoi(argv[i]);
        j++;
    }

    start = get_values(arg_array, length);
    printlinkedlist(start);
    
    return 0;
}

// creates linked list from array of integers
Linkedlist* get_values(int *array, int length) {
    Linkedlist *current, *first; // declared pointers to initialise struct
    
    first = (Linkedlist*)calloc(1, sizeof(Linkedlist));
    current = first;

    current->value = array[0]; // setting the value

// loop to add all other values to the struct
    for(int i = 1; i < length - 1; i++) {
        current->next = (Linkedlist*)calloc(1, sizeof(Linkedlist));
        current = current->next;

        current ->value = array[i];
    }
    current->next = NULL; // setting last value to NULL, end of linked list
    return first; // returning head of the linked list
}

void printlinkedlist(Linkedlist *start) {
    Linkedlist* p = NULL;
    for(p = start; p != NULL; p = p->next) {
        printf("%d\n", p->value);
    }
}


