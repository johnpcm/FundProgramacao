#include <joao.h>


float testaReferencia(float vet[], int tam, float *proxMedia)
{
    float media = 0;
    *proxMedia = vet[0];
    int i;

    for(i = 0; i < tam; i++)
    {
        media += vet[i];
    }

    media /= tam;

    for(i = 1; i < tam; i++)
    {
        if(fabs(vet[i] - media) < fabs(*proxMedia - media))
            *proxMedia = vet[i];
    }
    return media;

}
main()
{
float vet[13] = {2,3,4,2,3,4,1,5,3.4,2,3,5.1,5.6,7.3}, media, numpm;


printf("%f %f", testaReferencia(vet, 13, &numpm), numpm);



}
