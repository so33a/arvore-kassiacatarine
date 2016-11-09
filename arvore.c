#include <stdio.h>
#include "arvore.c"
#include "arvore.h"

/*
 *           55
 *      44        66
 *   33   45  64     77
 *
 *   em ordem = 33 44 45 55 64 66 77
 *   pos ordem = 33 45 44 64 77 66 55
 *   pre ordem = 55 44 33 45 66 64 77
 *   em largura = 55 44 66 33 45 64 77
 *
 *
 *   rotR (55) =>
 *
 *              44
 *          33     55
 *               45  66
 *                  64 77
 *
 *   em largura: 44 33 55 45 66 64 77
 *
 */
int main () {
  ARVORE a = novaArvore();
  link x;/*
  inserir(a, 55);
  inserir(a, 44);
  inserir(a, 33);
  inserir(a, 66);
  inserir(a, 77);
  inserir(a, 45);
  inserir(a, 64);
  printf ("pre: ");
  imprimePreOrdem(a);
  printf ("\n");
  printf ("pos: ");
  imprimePosOrdem(a);
  printf ("\n");
  printf ("em: ");
  imprimeEmOrdem(a);
  printf ("\n");
  printf ("largura: ");
  imprimeEmLargura(a);
  printf ("\n");

  x = busca(a, 45);
  if (x == NULL)
    printf ("Nao achou\n");
  else
    printf ("Achou %d \n", x->key);


  x = busca(a, 1);
  if (x == NULL)
    printf ("Nao achou\n");
  else
    printf ("Achou %d \n", x->key);


   x = busca(a, 55);
   a->raiz = rotR(a, x);
   printf ("Em largura depois de rotR(55)\n");
   imprimeEmLargura(a);
   printf("\n");

   a->raiz = rotL(a, a->raiz);
   printf ("Em largura depois de rotL(44)\n");
   imprimeEmLargura(a);
   printf("\n");

   inserirNaRaiz(a, 46);
   printf ("Insere na Raiz o elemento 46\n");
   imprimeEmLargura(a);
   printf("\n");

   printf("Remove o 46 que possui 2 filhos\n");
   remover (a, 46);
   imprimeEmLargura(a);
   printf("\n");

   printf("Remove o 77 que nao possui filhos\n");
   remover (a, 77);
   imprimeEmLargura(a);
   printf("\n");

   printf("Remove o 66 que possui 1 filhos\n");
   //remover (a, 66);
   imprimeEmLargura(a);
   printf("\n");
   */
   inserir(a, 55);
   inserir(a, 44);
   inserir(a, 33);
   inserir(a, 66);
   inserir(a, 77);
   inserir(a, 45);
   inserir(a, 64);
    imprimeEmLargura(a);
    printf("\n");
    printf ("pre: ");
  imprimePreOrdem(a);
  printf ("\n");
  printf ("pos: ");
  imprimePosOrdem(a);
  printf ("\n");
  printf ("em: ");
  imprimeEmOrdem(a);
  printf ("\n");
  printf ("largura: ");
  imprimeEmLargura(a);
  printf ("\n");
   printf("Remove o 33 que possui 0 filhos\n");
   remover (a, 33);
   imprimeEmLargura(a);
   printf("\n");
   printf("Remove o 44 que possui 1 filhos\n");
   remover (a, 44);
   imprimeEmLargura(a);
   printf("\n");
   printf("Remove o 55 que possui 2 filhos\n");
   remover (a, 55);
   imprimeEmLargura(a);
   printf("\n");
    printf("Remove o 66 que possui 1 filhos\n");
   remover (a, 66);
   imprimeEmLargura(a);
   printf("\n");
   /*
   printf("Remove o 64 que possui 2 filhos\n");
   remover (a, 64);
   imprimeEmLargura(a);
   printf("\n");
    printf("Remove o 77 que possui 2 filhos\n");
   remover (a, 44);
   imprimeEmLargura(a);
   printf("\n");
   printf("Remove o 66 que possui 1 filhos\n");
   remover (a, 66);
   imprimeEmLargura(a);
   printf("\n");
   printf("Remove o 33 que nao possui filhos\n");
   remover (a, 33);
   imprimeEmLargura(a);
   printf("\n");
    */

   return 0;
}
