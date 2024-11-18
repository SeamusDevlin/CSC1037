/*
Author: Seamus Devlin
Date: 18/11/2024
Description: The program creates a singly linked list from command-line arguments,
performs two “pop” operations to remove the last two nodes, and then adds two new nodes at the end of the list.
Finally, it prints the updated list of integers, showing the changes after the pop and push operations.
*/
// include relevant libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strlen() and strcopy

// alias for structure node
typedef struct Node Node;

// defines node in singly linked list
struct Node { 
    int value; // stores integer that each node holds
    Node *next; // pointer to the next node in the list
};

Node* fill(char *argv[], int length); // create and return linked list based on arguments
void pop(Node *start); // remove last node form linked list
Node* addItem(Node *start, int val1, int val2); // add two new nodes with values val1 and val2
void print(Node *start); // print linked list starting from first node

// main function
int main(int argc, char*argv[]) {
    int length = atoi(argv[1]); // converts the first command-line argument
    Node *LinkedList = NULL; // Initializes the pointer LinkedList to NULL before it is assigned any linked list
    LinkedList = fill(argv, length); // Calls the fill function to create a linked list using the command-line arguments argv and the number length
    pop(LinkedList); // Calls the pop function, which will remove the last node of the linked list
    pop(LinkedList);
    LinkedList = addItem(LinkedList, atoi(argv[argc - 2]), atoi(argv[argc - 1])); // This adds two new nodes at the end of the list, with values from the last two command-line arguments
    print(LinkedList);

    return 0; // The program ends and returns 0, indicating successful execution
}

Node* fill(char *argv[], int length) {
	Node *current, *first; // Declares two pointers of type Node. first will point to the first node, and current will be used to traverse and build the list
    first = (Node*)calloc(1,sizeof(Node)); // Allocates memory for the first node of the list using calloc. It initializes the memory to zero. This node will hold the first value in the list.
	current = first; // Sets current to point to the first node.
    current->value = atoi(argv[2]); // Sets the value of the first node to the third command-line argument (argv[2]), converting it from a string to an integer.
    
    // This loop iterates through the rest of the command-line arguments (from argv[3] onwards) and creates nodes for each one
    for (int i = 0; i < length - 1; i++) {
        current->next = (Node*)calloc(1,sizeof(Node));
	    current = current->next;

        current->value = atoi(argv[i + 3]);
    }

    return first;
}

void pop(Node *start) {
	Node* p = start;

	for(p = start; p != NULL; p = p->next) {
		if(p->next->next == NULL) {
			free(p->next); // Added free to avoid memory leak
			p->next = NULL;
			break;
		}
	}
}

Node* addItem(Node *start, int val1, int val2) {
	Node *current, *first;
    first = start;
	current = first;
    for (current = first; current != NULL; current = current->next) {
        if(current->next == NULL) {
            current->next = (Node*)calloc(1,sizeof(Node));
            current = current->next;
            current->value = val1;

            current->next = (Node*)calloc(1,sizeof(Node));
            current = current->next;
            current->value = val2;
            break;
		}
    }

    return first;
}

void print(Node *start) {
	Node* p = NULL;
	for(p = start; p != NULL; p = p->next) {
		printf("%d\n", p->value);
	}
}