#include <joao.h>


void testaReferencia(float vet[], int tam, float *proxMedia, float *media)
{
    *media = 0;
    *proxMedia = vet[0];
    int i;

    for(i = 0; i < tam; i++)
    {
        *media += vet[i];
    }

    *media /= tam;

    for(i = 1; i < tam; i++)
    {
        if(fabs(vet[i] - *media) < fabs(*proxMedia - *media))
            *proxMedia = vet[i];
    }

}
main()
{
float vet[13] = {2,3,4,2,3,4,1,5,3.4,2,3,5.1,5.6,7.3}, media, numpm;

testaReferencia(vet, 13, &numpm, &media);

printf("%f %f", media, numpm);



}
