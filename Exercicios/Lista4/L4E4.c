//a) imprima quantos s ̃ao pares e quantos s ̃ao  ́ımpares, (b) imprima a soma dos nu ́meros pares e (c) imprima a m ́edia dos nu ́meros  ́ımpares.


#include <stdio.h>

main(){
    while(1){

    int i, in = 0, pa = 0, im = 0, sp = 0, si = 0, r = 10;

        for(i=0; i<r; i++){
            printf("\ninsira um numero:");
            scanf("%d", &in);

            if (in % 2 == 0){
                pa++;
                sp += in;
            }
            else{
                im++;                                                   RSTRYERTEE          ÷EEEEEEEEEEEEEEEEEEEEEEY768
                si += in;
            }
        }
        printf("foram %d # pares, que somam %d, %d # impares cuja media é %d", pa, sp, im, si/im);
    }
}
