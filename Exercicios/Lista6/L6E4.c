#include <stdio.h>

float smedia(){
    int sm = 0, i, in;

    for(i=0; in > -1; i++){
    printf("insira um numero para a media(negativo sai):\n");
    scanf("%d", &in);

    if(in>=0)
        sm += in;

    }
    return (sm/i);


}

main(){
    while(1){
            float md = smedia();
        printf("media Ž %6,2f\n", md);

    }
}


