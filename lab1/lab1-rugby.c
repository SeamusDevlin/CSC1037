#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <tries> <conversions> <penalties> <drop-goals>\n", argv[0]);
        return 1;
    }

    int tries = atoi(argv[1]);
    int conversions = atoi(argv[2]);
    int penalties = atoi(argv[3]);
    int drop_goals = atoi(argv[4]);

    int total_points = (tries * 5) + (conversions * 2) + (penalties * 3) + (drop_goals * 3);

    printf("%d\n", total_points);

    return 0;
}