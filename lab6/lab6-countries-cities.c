/*
This program accepts info about a given amount of countries and find the largest of the cities and print it.
Author: Seamus Devlin
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct City {
    char *name;
    float size;
} City;

typedef struct Country {
    char *name;
    City cities[3];
} Country;

void find_largest_city(Country country);

int main(int argc, char *argv[]) {

    int country_count = (argc - 1) / 8; // Each country has 1 name + 3 cities + 3 sizes
    Country countries[country_count];
    int arg_index = 1;  // Start at the first country name

    // Parse the input arguments into Country and City structures
    for (int i = 0; i < country_count; i++) {
        countries[i].name = argv[arg_index];  // Store country name

        // Store the 3 cities and their sizes
        for (int j = 0; j < 3; j++) {
            countries[i].cities[j].name = argv[arg_index + 1];       // City name
            countries[i].cities[j].size = atof(argv[arg_index + 2]); // City size
            arg_index += 2; // Move to the next city name and size
        }
        arg_index++; // Move to the next country
    }

    // Find and print the largest city for each country
    for (int i = 0; i < country_count; i++) {
        find_largest_city(countries[i]);
    }

    return 0;
}

// Function to find the largest city in a country
void find_largest_city(Country country) {
    City largest_city = country.cities[0]; // Assume the first city is the largest

    // Compare all cities to find the largest
    for (int i = 1; i < 3; i++) {
        if (country.cities[i].size > largest_city.size) {
            largest_city = country.cities[i];
        }
    }

    // Print the result for the country and its largest city
    printf("%s: %s\n", country.name, largest_city.name); // Include a newline for correct output formatting
}