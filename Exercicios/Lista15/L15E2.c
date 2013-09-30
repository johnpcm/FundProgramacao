#include <joao.h>


typedef struct {

    int horas;
    int minutos;
    int segundos;

}Tempo;

void quebraSeg (int in, Tempo (*p)){
    (*p).horas = in/3600;
    (*p).minutos = in%3600/60;
    (*p).segundos = in%60;
}

main(){

    int in;
    Tempo saida;

    scanf("%d", &in);

    quebraSeg(in,&saida);

    printf("%d h %d min %d seg", saida.horas,saida.minutos,saida.segundos);

}

