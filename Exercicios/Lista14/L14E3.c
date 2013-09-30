#include <joao.h>



main()
{

    int **m, l, c;

    scanf("%d %d", &l, &c);

    m = allocMatriz(l , c);

    randMatriz(m,l,c,10);

    printMI(m,l,c);

}




 + 1
