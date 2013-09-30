#include <stdio.h>

main(){
    int idade;
    float peso;
    int altura;
    char letra;

    printf("Insira seus dados:\n Idade:");
    scanf("%d",&idade);
    printf("Peso (kg):");
    scanf("%f",&peso);
    printf("Altura (cm):");
    scanf("%d",&altura);
    printf("A primeira letra do seu nome:");
    scanf("%c",&letra);

    printf("A primeira letra do seu nome é %c, você tem %d anos, pesa %6.2f kg e mede %d de altura.", letra, idade, peso, altura);


}
