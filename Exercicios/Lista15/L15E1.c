#include <joao.h>


typedef struct {

    int horas;
    int minutos;
    int segundos;

}Tempo;


main(){

    int in;
    Tempo saida;

    scanf("%d", &in);

    saida.horas = in/3600;
    saida.minutos = in%3600/60;
    saida.segundos = in%60;

    printf("%d h %d min %d seg", saida.horas,saida.minutos,saida.segundos);

}

