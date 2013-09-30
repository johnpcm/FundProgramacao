#include <joao.h>


#define LIM 1000

main(){

    int i, j;
    char s[LIM], vogais[] = "eiouaEIOUA", cont[5] = {0};

    printf("insira uma string:\n");
    fgets(s, LIM-1, stdin);

    printf("\n");
    for (i=0; i < strlen(s); i++){
        for(j=0; j < strlen(vogais); j++)
             cont[j%5] += s[i] == vogais[j] ? 1 : 0;

    for(i=0; i < 5; i++){
        for(j=0;j<cont[i])
    }
}
