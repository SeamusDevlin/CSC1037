
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   
   int try,conversion,penalty,dropgoal;
   int totalscore = 0;

    printf("Enter the number of Tries: \n");
    scanf("%i", &try);

    printf("Enter the number of Conversions: \n");
    scanf("%i", &conversion);

    printf("Enter the number of Penalties: \n");
    scanf("%i", &penalty);

    printf("Enter the number of Drop Goals: \n");
    scanf("%i", &dropgoal);

  

    if (try >= 0 && conversion >= 0 && penalty >= 0 && dropgoal >= 0){

        totalscore = try*5 + conversion*2 + penalty*3 + dropgoal*3;
        printf ("%.d\n",totalscore);
    }
    else{

        printf("Invalid Entry, Please try again.");
    }
    return 0;
}