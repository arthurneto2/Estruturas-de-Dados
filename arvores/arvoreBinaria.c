#include <stdio.h>
#include <stdlib.h>

typedef struct sNoArvore{
    int info;
    struct sNoArvore *direita;
    struct sNoArvore *esquerda;
}NoArvore;

void addArvore(NoArvore **raiz, int info){
    if(*raiz == NULL){
        *raiz = (NoArvore*) calloc(1, sizeof(NoArvore));
        (*raiz)->info = info;
    }else{
        if(info < (*raiz)->info){
           addArvore(&(*raiz)->esquerda, info);
        }else{
            addArvore(&(*raiz)->direita, info);
        }
    }
}

int maxInfo(NoArvore* raiz) {
    if (raiz==NULL) {
        printf("vazia\n");
        return -1; 
    }

    while (raiz->direita!=NULL) {
        raiz=raiz->direita;
    }
    return raiz->info;
}

void printArvore(NoArvore *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->info);
        if(raiz->esquerda != NULL){
            printArvore(raiz->esquerda);  
        }
        if(raiz->direita != NULL){
            printArvore(raiz->direita);
        }
    }else{
        printf("\nArvore vazia!!!\n");
    }
}

void printArvoreOrd(NoArvore *raiz){
     if(raiz != NULL){
        if(raiz->esquerda != NULL){
            printArvoreOrd(raiz->esquerda);  
        }
        printf("%d ", raiz->info);
        if(raiz->direita != NULL){
            printArvoreOrd(raiz->direita);
        }
    }else{
        printf("\nArvore vazia!!!\n");
    }
}

int main(){
    NoArvore *raiz = NULL;
    puts("");
    printArvoreOrd(raiz);
    puts("");
    printf("O maior valor encontrado na arvore foi: %d", maxInfo(raiz));
    puts("");
    return 0;
}
