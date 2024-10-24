#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
    int day_n = atoi(argv[1]);
    char weekday[7][100] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    printf("%s\n", weekday[day_n - 1]);
    return 0;
}