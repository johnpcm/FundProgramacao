
#include <stdio.h>
#include <time.h>

main(){
    while(1){

        int mag = srand(time(NULL)) % 501, in, i=0;

        while (mag != in){

            printf("\ntente descobrir o numero:\n");
            scanf("%d",&in);

            if (in > mag)
                printf("\nmenos");
            else if (in < mag)
                printf("\nmais");
            i++;
        }

        if (i <= 3)
            printf("\nparabens, voce Ž muito sortudo!");
        else if (i <= 6)
            printf("\nparabens, voce Ž sortudo!");
        else if (i <= 10)
            printf("\nparabens, voce Ž normal!");
        else if (i > 10)
            printf("\nparabens, mas tente novamente");


    }
}


