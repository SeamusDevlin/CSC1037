#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    if (argc > 1) 
    {
        printf("Hello\n%s\n", argv[1]);
    } else {
        printf("Hello\n");
    }
    return 0;
}