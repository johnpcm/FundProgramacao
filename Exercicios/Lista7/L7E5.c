#include <stdio.h>
#include <math.h>

float raiz (int in){
    float out=0, pri = 1;

    while (1){
        out = (pri + (in/pri))/2;
        if(fabs(out-pri) < 0.00001)
            break;
        pri = out;
    }
    return out;

}

main(){


    printf("%.23f", raiz (144));


}


