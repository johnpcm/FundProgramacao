#include <stdio.h>

main(){
    while (1){
        int inum;

        printf("Insira o numero:");
        scanf("%d", &inum);

        if (inum % 2 == 0){
            printf("%d Ž par\n", inum);
        }
        else {
            printf("%d Ž impar\n", inum);
        }
    }
}
