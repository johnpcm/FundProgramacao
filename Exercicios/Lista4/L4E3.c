#include <stdio.h>

main(){
    //while(1){

    /*Chico tem 1,50 metro e cresce 2 cent ́ımetros por ano, enquanto Z ́e tem 1,10 metro e
    cresce 3 cent ́ımetros por ano. Construa um programa que calcule e imprima quantos anos ser ̃ao necess ́arios
     para que Z ́e seja maior que Chico.*/

     int c, z, a;

     for (c=150, z= 110, a=0; c>z; z+=3, c+=2, a++);

     printf("%d", a);

  //  }
}
