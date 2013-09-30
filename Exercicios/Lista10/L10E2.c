#include "main.h"

#define L 30
#define C 35

main(){
    while(1){
            int m[30][30], i, j;

    for(i = 0; i < L; i++)
        for(j = 0; j < C; j++)
            m[i][j] = rand()%2;
        printmi(m,23,23);

}
}
