#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int main(int argc, char *argv[])
{

	float radius = 0;
	float area = 0;

    if (radius >=0)
    {

        radius = radius*radius;
        area = radius*PI;

        printf("%.2f\n", area);

    }

    else
    {

        radius = (radius * -1);
        radius = radius * radius;
        area = radius*PI;
        printf("You've entered a Negative Number! Computing with a Positive:\n%.2f\n",area);

    }



    return (0);
}
