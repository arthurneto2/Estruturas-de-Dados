#include<stdio.h>
#include<stdlib.h>


typedef struct sNo{
    int elem;
    struct sNo *prox;
}No;


typedef struct sFila{
    No *inicio;
    No *fim;
    int tamFila;
}Fila;

Fila* creatFila(){
    Fila *fila = (Fila*) calloc(1, sizeof(Fila));
    return fila;
}

No* creatNo(int elem){
    No *novoNo = (No*) calloc(1, sizeof(No));
    novoNo->elem = elem;
    return novoNo;
}

int filaVazia(Fila *fila){
    return fila->tamFila == 0;
}

void enfileirar(Fila *fila, int elem){
    No *novo = creatNo(elem);

    if(filaVazia(fila)){
        fila->inicio = fila->fim = novo;
    } else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    fila->tamFila++;
}

int desinfilerar(Fila *fila){
    int elem = -1;

    if(!filaVazia(fila)){
        No *aux = fila->inicio;

        fila->inicio = aux->prox;
        elem = aux->elem;
        free(aux);

        if(filaVazia(fila)){
            fila->fim = NULL;
        }
        fila->tamFila--;
    }
    return elem;
}

void juntarFilas(Fila *filaOrd1, Fila *filaOrd2, Fila *filaFinal){
    if(!filaVazia(filaOrd1) && !filaVazia(filaOrd2)){

        if((filaOrd1->inicio->elem) < (filaOrd2->inicio->elem)){
            while(!filaVazia(filaOrd1)){
                enfileirar(filaFinal, desinfilerar(filaOrd1));
            }

            while(!filaVazia(filaOrd2)){
                enfileirar(filaFinal, desinfilerar(filaOrd2));
            }

        }else{
             while(!filaVazia(filaOrd2)){
                enfileirar(filaFinal, desinfilerar(filaOrd2));
            }

            while(!filaVazia(filaOrd1)){
                enfileirar(filaFinal, desinfilerar(filaOrd1));
            }
        }
    }
    while(!filaVazia(filaOrd1)){
        enfileirar(filaFinal, desinfilerar(filaOrd1));
    }
    while(!filaVazia(filaOrd2)){
        enfileirar(filaFinal, desinfilerar(filaOrd2));
    }
}

void intercalarFilas(Fila *fila1, Fila *fila2, Fila *filaFinal){
    int cont = 0;
    if(!filaVazia(fila1) && !filaVazia(fila2)){

        while(!filaVazia(fila1) && !filaVazia(fila2)){
            if(cont % 2 == 0){
                enfileirar(filaFinal, desinfilerar(fila1));
            }else{
                enfileirar(filaFinal, desinfilerar(fila2));
            }
            cont++;
        }
    }
       
    while(!filaVazia(fila1)){
        enfileirar(filaFinal, desinfilerar(fila1));
    }
    while(!filaVazia(fila2)){
        enfileirar(filaFinal, desinfilerar(fila2));
    }
}

void printFila(Fila *fila){
    No *aux = fila->inicio;
    if(!filaVazia(fila)){
        puts("");
        while(aux != NULL){
            printf("[%d]->", aux->elem);
            aux = aux->prox;
        }
        printf("NULL\n");
    }else{
        printf("\nFILA VAZIA...\n");
    }
    printf("Tamanho da fila: %d elementos\n", fila->tamFila);
    puts("");
}

int main(){
    Fila *fila1 = creatFila();
    Fila *fila2 = creatFila();
    Fila *filaFinal = creatFila();


    for (int i = 0; i < 10; i++){
        enfileirar(fila1, i);
    }
    for (int i = 5; i < 15; i++){
        enfileirar(fila2, i);
    }

    printFila(fila1);
    printFila(fila2);

    juntarFilas(fila1, fila2, filaFinal);    
    printFila(filaFinal);


    while(!filaVazia(filaFinal)){
        desinfilerar(filaFinal);
    }
 
    for (int i = 0; i < 5; i++){
        enfileirar(fila1, i);
    }
    for (int i = 5; i < 10; i++){
        enfileirar(fila2, i);
    }
    
    intercalarFilas(fila1, fila2, filaFinal);
    printFila(filaFinal);

    return 0;
}
