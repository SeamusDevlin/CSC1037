/*
Name: Seamus Devlin
Student Number: 23389013
Date: 31/10/2024

Description:
This program accepts info about the inventory. Using a struct it groups all the info together.
This program reads each product etc. in one line and then outputs if it is discounted dedpending if 
final argument is 1 or 0.
*/

// includes relevant libraries
#include <stdio.h>
#include <stdlib.h>

// define Inventory as a type name for inventory
typedef struct Inventory Inventory;

// defines Location struct with group variables.
struct Inventory{
    char *name;
    unsigned int stock;
    float price;
    int discount;
};

// does not return vlaue
void inventory_print(char *name, unsigned int stock, float price, int discount);

// main function
int main(int argc, char*argv[]) {
    Inventory inventory[20];
    
    int lcount = 0;
    for (int i = 1; i < argc; i += 4) {
        inventory[lcount].name = argv[i];
        inventory[lcount].stock = atoi(argv[i + 1]);
        inventory[lcount].price = atof(argv[i + 2]);
        inventory[lcount].discount = atoi(argv[i + 3]);

        lcount++;
    }

    for (int i = 0; i < lcount; i++) {
        inventory_print(inventory[i].name, inventory[i].stock, inventory[i].price, inventory[i].discount);
    }

    return 0;
}

void inventory_print(char *name, unsigned int stock, float price, int discount) {
    printf("%s,%u,%.2f,%s\n", name, stock, price, discount ? "Discounted" : "No Discount");
}

 