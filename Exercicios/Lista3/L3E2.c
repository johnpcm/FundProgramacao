#include <stdio.h>

main(){
    while (1){
        int inum;

        printf("Insira o numero:");
        scanf("%d", &inum);

        if (inum % 2 == 0){
            printf("%d � par\n", inum);
        }
        else {
            printf("%d � impar\n", inum);
        }
    }
}
