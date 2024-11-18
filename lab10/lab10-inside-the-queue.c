/*
Author: Seamus Devlin
Date: 18/11/2024
Description: The code creates a linked list from an array of integers,
adds a new integer after a specified value from the command line,
and then prints the updated list.
*/
// include relevant libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure
typedef struct Node Node;
struct Node {
    int value;  // Integer value that stores the data in the node
    Node *next; // Pointer to the next node in the list
};

// Function prototypes
Node* AddNumber(int num, int numAdd, Node *first); // Adds a new number after a specific node
Node* fill(int x[10]); // Fills the linked list with predefined values
void print(Node *start); // Prints the values of the linked list

int main(int argc, char*argv[]) {
    // Initialize an array of 10 integers to populate the linked list
    int x[10] = { 8, 7, 3, 4, 5, 6, 9, 2, 14, 12 };
    Node *start;

    // Fill the linked list with the array elements
    start = fill(x);

    // Add a number after the node with value 'num' (from command-line argument) 
    // and the value to add (from another command-line argument)
    start = AddNumber(atoi(argv[1]), atoi(argv[2]), start);

    // Print the updated linked list
    print(start);
    return 0;
}

// Function to fill the linked list with values from the array
Node* fill(int x[10]) {
    Node *current, *first;

    // Allocate memory for the first node
    first = (Node*)calloc(1,sizeof(Node));
    current = first;
    
    // Set the value of the first node
    current->value = x[0];

    // Fill the rest of the linked list with the remaining elements in the array
    for (int i = 1; i < 10; i++) {
        current->next = (Node*)calloc(1,sizeof(Node));  // Allocate memory for the next node
        current = current->next; // Move the current pointer to the new node
        current->value = x[i]; // Set the value of the new node
    }
    
    return first; // Return the head of the list
}

// Function to add a number after a specific node
Node* AddNumber(int num, int numAdd, Node *first)
{
    Node *current, *start;
    start = first; // Save the starting point of the list
    current = first; // Start from the first node

    // Loop through the list to find the node with the value 'num'
    for(int i = 0; i < 10; i++)
    {
        if(current->value == num) {  // If the value of the current node matches 'num'
            // Create a temporary pointer to hold the next node
            Node *tmp = current->next;

            // Allocate memory for a new node and insert it after the found node
            current->next = (Node*)calloc(1,sizeof(Node));
            current = current->next; // Move current to the new node

            // Set the value of the new node
            current->value = numAdd;

            // Point the new node to the next node (from tmp)
            current->next = tmp;
        }
        current = current->next; // Move to the next node in the list
    }

    return start; // Return the head of the list
}

// Function to print all values in the linked list
void print(Node *start)
{
    Node* p = NULL;
    
    // Traverse the linked list and print each node's value
    for(p = start; p != NULL; p = p->next)
    {
        printf("%d\n", p->value); // Print the value of each node
    }
}