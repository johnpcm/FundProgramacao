#include <stdio.h>
#include <stdlib.h>

struct tab{
    char* mem; // vetor din^amico
    long max; //tamanho do vetor
    long nb; //posi ̧c~oes ocupadas do vetor
};

struct tab* criar_tab(void)
{
  struct tab* t = malloc(sizeof(struct tab));
  t->nb = 0; //indica que nenhuma posição está preenchida
  t->max = 16; //Config inicial
  t->mem = malloc(16*sizeof(char));//memoria alocada inicial
  return t;
}
void destruir_tab(struct tab* t)
{
  free(t->mem);
  free(t);
}
void adicionar_char(struct tab* t, char c)
{
  //testa se é preciso redimensionar vetor
  if (t->nb >= t->max) {
    t->max *= 2;
    t->mem = (long*) realloc(t->mem, t->max*sizeof(char));
  }
  //insere caracter
  t->mem[t->nb] = c;
  t->nb++;
}
void adicionar_string(struct tab* t, char* s)
{
    long i;

    for(i = 0; i < strlen(s); i++)
        adicionar_char(t, s[i]);
}
void esvaziar_tab(struct tab* t)
{
  t->nb = 0;
}
void imprimir_tab(struct tab* t)
{
  long i;
  for (i=0; i<t->nb; i++)
    printf("%-2c", t->mem[i]);
  fputc('\n', stdout); //pula uma linha
}

struct tab* subst(struct tab* arg)
{
  struct tab* res = criar_tab();
  long i;
  for (i=0; i<strlen(arg->mem); i++) {
    char c = arg->mem[i];
    if      (c=='X')
        adicionar_string(res,"XlYal");
    else if (c=='Y')
        adicionar_string(res,"raXrY");
    else
        adicionar_char(res,c);
  }
  return res;
}

struct tab* calculo(long nb)
{
  long i;
  struct tab*t = criar_tab();
  adicionar_char(t, 'X');
  for (i=0; i < nb; i++) {
    struct tab* r = subst(t);
    destruir_tab(t);
    t = r;
  }
  return t;
}

void gerar_postscript(struct tab* t,char* arq_out)
{
  FILE* out = fopen(arq_out, "w");
  long i;
  if (!out) {
    fprintf(stderr,"ERRO -impossivel criar arquivo %s !\n",arq_out);
    exit(1);
  }
  fprintf(out, "%%!postscript\n");
  fprintf(out, "297 419 moveto\n");
  for (i=0; i<t->nb; i++) {
     fflush(stdin);
     getchar();
    char c = t->mem[i];
    if      (c=='r')
        fprintf(out, "90 rotate\n");
    else if (c=='l')
        fprintf(out, "-90 rotate\n");
    else if (c=='a')
        fprintf(out, "1 0 rlineto\n");
  }
  fprintf(out, "stroke showpage\n"); /* affichage final */
  fclose(out);
}



long main(void)
{

  long N;
  char arq_out[500];

  fprintf(stderr,"Digite o nome do arquivo de saida:");
  gets(arq_out);

  //Força a leitura de um valor positivo
  do{
  	fprintf(stderr,"Digite o numero de iteracoes para gerar o fractal:");
  	scanf("%d",&N);
  }while( (N <0) );

  struct tab* t;
  t = calculo(N);
  gerar_postscript(t,arq_out);
  return 0;
}

