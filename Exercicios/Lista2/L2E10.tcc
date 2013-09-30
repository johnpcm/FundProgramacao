#include <stdio.h>

main(){
    int seg;
    inicio:
    printf("Insira o numero de segundos:");
    scanf("%d", &seg);
    printf("Dias:%d Horas:%d Minutos:%d Segundos:%d\n",(seg/3600)/24 , (seg/3600)%24, (seg%3600)/60, seg%60);
    goto inicio;
}
