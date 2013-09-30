#include <joao.h>


#define LIM 1000

main(){

    int i, j;
    char s[LIM], vogais[] = "aeiouAEIOU";

    printf("insira uma string:\n");
    fgets(s, LIM-1, stdin);

    printf("\n");
    for (i=0; i < strlen(s); i++){
        for(j=0; j < strlen(vogais); j++)
             s[i] = s[i] == vogais[j] ? '*' : s[i];
        printf("%c", s[i]);

    }
}

