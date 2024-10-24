#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <centimetres>\n", argv[0]);
        return 1;
    }

    double centimetres = atof(argv[1]);
    double inches = centimetres / 2.54;

    printf("%.2f\n", inches);

    return 0;
}