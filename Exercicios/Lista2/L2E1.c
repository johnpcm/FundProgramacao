#include <stdio.h>

main(){
    float base;
    float altura;
    printf ("Insira a base do retangulo:");
    scanf ("%f", &base);
    printf ("Agora, insira a altura:");
    scanf ("%f", &altura);

    printf ("\n\nA area do retangulo e:%6.2f \nO perimetro e:%6.2f", base*altura, base*2+altura*2);
}
