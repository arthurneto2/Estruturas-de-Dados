#include<stdio.h>
#include<stdlib.h>

#define TAM 5

typedef struct sNo{
    int elem;
    struct sNo *prox;
}No;

typedef struct sLista{
    No *inicio;
    No *fim;
    int tamLista;
}Lista;

Lista* creatLista(){
    Lista *lista = (Lista*) calloc(1, sizeof(Lista));
    return lista;
}

No* creatNo(int elem){
    No *novoNo = (No*) calloc(1, sizeof(No));
    novoNo->elem = elem;
    return novoNo;
}

int listaVazia(Lista *lista){
    return lista->tamLista == 0;
}

void inserirNo(Lista *lista, int elem){
    No *novo = creatNo(elem);

    if(listaVazia(lista)){
        lista->inicio = lista->fim = novo;
    } else{
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->tamLista++;
}

int menorElem(Lista *lista){
    No *aux = lista->inicio;

    if(!listaVazia(lista)){
        int menor = lista->inicio->elem;

        while (aux != NULL){
            if(menor > aux->elem){
                menor = aux->elem;
            }
            aux = aux->prox;
        }
        return menor;
    }else{
        printf("\nLISTA VAZIA...\n");
        return -1;
    }
}

float mediana(Lista *lista){
    int cont = 1;
    No *aux = lista->inicio;
    float mediana;

    if(!listaVazia(lista)){
        while(cont != (lista->tamLista / 2)){
                aux = aux->prox;
                cont ++;
        }
        if((lista->tamLista % 2) == 0){
            mediana = (float)(aux->elem + aux->prox->elem) / 2;
        }else{
            mediana = aux->prox->elem;
        }
    }else{
        printf("LISTA VAZIA...");
    }
    return mediana;
}

void ordenarLista(Lista *lista){
    Lista *ordList = creatLista();
    No *aux = lista->inicio;
    
    if (!listaVazia(lista)){
        while(aux != NULL){
          No *auxNo = creatNo(aux->elem);
          if(listaVazia(ordList)){
            ordList->inicio = auxNo;
          }else{
            No *aux2 = ordList->inicio;
            while (aux2 != NULL){
                if(aux2)
            }
          }
                        
          ordList->inicio  
        }
    }
    


}


    void printLista(Lista *lista){
        No *aux = lista->inicio;
        if(!listaVazia(lista)){
            puts("");
            while(aux != NULL){
                printf("[%d]->", aux->elem);
                aux = aux->prox;
            }
            printf("NULL\n");
        }else{
        printf("\nLISTA VAZIA...\n");
    }
    printf("Tamanho da Lista: %d elementos\n", lista->tamLista);
    puts("");
}

int main(){
    Lista *lista = creatLista();

    for (int i = -5; i < TAM; i++){
        inserirNo(lista, i);
    }
    printLista(lista);

    printf("\nMenor valor: [%d]\n", menorElem(lista));
    printf("Mediana: [%.2f]\n", mediana(lista));
    printLista(lista);

    printLista(lista);
    return 0;
}