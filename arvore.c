#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "fila.c"

ARVORE novaArvore() {
  ARVORE a = malloc(sizeof(struct arvore));//Aloca espaço para arvore
  a->z = malloc(sizeof(struct node));
  a->raiz = a->z;//Aponta para final
  a->raiz->left = a->raiz->right = a->z;
  a->z->left = a->z->right = a->z;
  return a;
}

void imprimePreOrdemR(ARVORE a, link h) {//Sempre Imprime a direita
  if (h != a->z) {
    printf ("%d ", h->key);
    imprimePreOrdemR(a, h->left);
    imprimePreOrdemR(a, h->right);
  }
}

int contaNosR (ARVORE a, link h) {
  if(h == a->z) return 0;// Se for vazio
  return 1 + contaNosR(a, h->left) + contaNosR(a, h->right);//
}

int contaParesR (ARVORE a, link h) {
  if(h == a->z)
    return 0;
  if (h->key %2 == 0)
    return 1 + contaParesR(a, h->left) + contaParesR(a, h->right);
  else
    return  contaParesR(a, h->left) + contaParesR(a, h->right);
}

void imprimePreOrdem (ARVORE a) {
  imprimePreOrdemR(a, a->raiz);
}
void imprimePosOrdemR(ARVORE a, link h) {
  if (h != a->z) {
    imprimePosOrdemR(a, h->left);
    imprimePosOrdemR(a, h->right);
    printf ("%d ", h->key);
  }
}

void imprimePosOrdem (ARVORE a) {
  imprimePosOrdemR(a, a->raiz);
}


void imprimeEmOrdemR (ARVORE a, link h) {
   if (h != a->z) {
     imprimeEmOrdemR(a, h->left);
     printf("%d ", h->key);
     imprimeEmOrdemR(a, h->right);
   }
}

void imprimeEmOrdem (ARVORE a) {
   imprimeEmOrdemR(a, a->raiz);
}

link buscaR (ARVORE a, link h, int key) {
  if(h == a->z) return NULL;
  if(h->key == key) return h;
  if( h->key < key)
    return buscaR(a, h->right, key);
  return buscaR(a, h->left, key);
}


link busca (ARVORE a, int key){
  return buscaR(a, a->raiz, key);
}

link novoNo(int key, link l, link r) {
  link x = malloc(sizeof(struct node));
  x->key = key;
  x->left = l;
  x->right = r;
  return x;
}
link inserirR (ARVORE a, link h, int key) {
  if(h == a->z)
    return novoNo(key, a->z, a->z);
  if(h->key == key) return h;
  if(h->key < key)
    h->right = inserirR(a, h->right, key);
  else
    h->left = inserirR(a, h->left, key);
  return h;
}
link inserirT (ARVORE a, link h, int key) {
  if(h == a->z)
    return novoNo(key, a->z, a->z);
  if(h->key == key) return h;
  if(h->key < key)  {
    h->right = inserirT(a, h->right, key);
    h = rotL(a, h);
  }
  else {
    h->left = inserirT(a, h->left, key);
    h = rotR(a, h);
  }
  return h;
}

void inserirNaRaiz(ARVORE a, int key) {
  a->raiz = inserirT(a, a->raiz, key);
}

void inserir (ARVORE a, int key){
  a->raiz = inserirR(a, a->raiz, key);
}

void imprimeEmLargura (ARVORE a) {
  link aux;
  FILA f = novaFila();
  enfilar(f, a->raiz);
  while (f->primeiro != NULL) {
    aux = desenfilar(f);
    printf ("%d ", aux->key);
    if (aux->left != a->z)  {
      enfilar (f,aux->left);
    }
    if (aux->right != a->z) {
      enfilar (f,aux->right);
    }
  }
  destroiFila(f);
}

link rotL(ARVORE a, link h) {
  link x = h->right;
  h->right = x->left;
  x->left = h;
  return x;
}
link rotR(ARVORE a, link h) {
  link x = h->left;
  h->left = x->right;
  x->right = h;
  return x;
}
void remover (ARVORE a, int key){
    removerNo (a,busca(a,key));
}
void removerNo (ARVORE a, link node){
    link no = a->raiz;
    link aux = node;
    link pai = node;

    if(node->right != a->z && node->left != a->z){//Possuir 2 filhos
        node = node->right;//Vai para direita
        if(node->left == a->z){
            pai->right = a->z;
            if(node->right != a->z)//Se possui filho para direita
                pai->right = node->right;//O Pai pega os filhos
            else if(node->right == a->z)
                pai->right = a->z;//O pai aponta para NULL
        }else{
            while(node->left != a->z){//Enquanto for diferente de NULL
                pai = node;//Pai recebe o que era filho
                node = node->left;//Filho vai para o proximo
            }
            if(node->right != a->z)//Se possui filho para direita
                pai->left = node->right;//O Pai pega os filhos
            else if(node->right == a->z)
                pai->left = a->z;//O pai aponta para NULL
        }
        aux->key = node->key;//node recebe o valor do menor no
    }else{
        if(node == a->raiz){
            if(node->left == a->z && node->right == a->z){//Se não tiver Nenhum filho
                no = a->z;//Vai apontar para o NULL
                printf("\nExcluiu o ultimo elemento\n");
            }else if(node->left == a->z && node->right != a->z)//Se tiver 1 filho
                no = node->right;
            else if(node->right == a->z && node->left != a->z)//1 filho
                no = node->left;
        }else{
            while(no != node){//enquanto não chegar no nó
                if(node->key > no->key){//Se o que quer excluir for maior que o nó
                    if(no->right == node){//Se o da direita for igual ao nó
                        if(node->left == a->z && node->right == a->z)//Se não tiver Nenhum filho
                            no->right = a->z;//Vai apontar para o NULL
                        else if(node->left == a->z && node->right != a->z)//Se tiver 1 filho
                            no->right = node->right;
                        else if(node->right == a->z && node->left != a->z)//1 filho
                            no->right = node->left;
                        break;//Parar o while
                    }else
                        no = no->right;//vai para o proximo
                }else if(node->key < no->key){//Se o que quer excluir for menor que o nó
                    if(no->left == node){
                        if(node->left == a->z && node->right == a->z)//Se não tiver Nenhum filho
                            no->left = a->z;//Vai apontar para o NULL
                        else if(node->left == a->z && node->right != a->z)//Se tiver 1 filho
                            no->left = node->right;
                        else if(node->right == a->z && node->left != a->z)//1 filho
                            no->left = node->left;
                        break;//Parar o while
                    }else
                        no = no->left;//vai para o proximo
                }
            }
        }
    }
    free(node);//Libera o node
}



#if 0
void remover (ARVORE a, int key);
void removerNo (ARVORE a, link node);
void destroiArvore(ARVORE a);
#endif
