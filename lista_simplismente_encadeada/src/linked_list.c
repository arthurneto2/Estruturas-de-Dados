#include "linked_list.h"
#include<stdlib.h>


typedef struct sNode{
    int num;
    struct sNode *next;
}Node;

typedef struct sHead{
    Node *begin;
    Node *end;
    size_t size;
}Head;

Head* creat_head(){
    Head *list = (Head*) calloc(1, sizeof(Head));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;
    return list;
}

Node* creat_node(int val){
    Node *new_node;
    new_node = (Node*) calloc(1, sizeof(Node));
    new_node->next = NULL;
    new_node->num = val;
    return new_node;
}

bool empty_list(Head *list){
    return list->size == 0;
}

size_t size_list(Head *list){
    return list->size;
}   

void addLast_node(Head *list, int val){
    Node *new_node = creat_node(val);

    if(empty_list(list)){
        list->begin = new_node;
        list->end = new_node;
    } else{
        list->end->next = new_node;
        list->end = new_node;
    }
    list->size++;
}

void addFirst_node(Head *list, int val){
    Node *new_node = creat_node(val);

    if(empty_list(list)){
        list->begin = new_node;
        list->end = new_node;
    } else{
        new_node->next = list->begin;
        list->begin = new_node;
    }
    list->size++;
}

void addMid_node(Head *list, int val, int index){
    Node *new_node = creat_node(val);
    Node *current = list->begin;
    int cont = 1;
    

    if(index <= 0 || index >= size_list(list)){
        printf("\nINDEX OUT OF RANGE OR EMPTY LIST...\n");
        printf("TRY A INDEX BETWEEN [0] and [%lu]\n", size_list(list));
    } else{
        while(cont != index){
            current = current->next;
            cont++;
        }
        new_node->next = current->next;
        current->next = new_node;
        list->size++;
    }
}

void removeFirst_node(Head *list, int val){
    Node *current = list->begin;
    Node *previos = NULL;
    
    if(!empty_list(list)){
        while(current != NULL && current->num != val){
            previos = current;
            current = current->next;
        }
        if(current == NULL){
            printf("\nValor [ %d ] nao encontrado na lista...\n", val);
        }else{
            if(list->end == current){
                list->end = previos;
            }
            if(list->begin == current){
                list->begin = current->next;
            }else{
                previos->next = current->next;
            }
            free(current);
            list->size--;
        }
    }
}


void removeAll_node(Head *list, int val){
    Node *current = list->begin;
    Node *previos = NULL;
    Node *eliminate = NULL;
    int cont = 0;

    while (current != NULL){
        if(current->num == val){
            if(list->end == current){
                list->end = previos;
            }
            if(list->begin == current){
                list->begin = current->next;
            }else{
                previos->next = current->next;
            }
            eliminate = current;
            current = current->next;
            free(eliminate);
            list->size--;
            cont++;
        }else{
            previos = current;
            current = current->next;
        }
    }
    if(cont == 0){
        printf("\nValor [ %d ] nao encontrado na lista...\n\n", val);
    }else{
        printf("Foram apagados %d valores [ %d ]!!!\n", cont, val);
    }
}

int first_node(Head *list){
    if(empty_list(list)){
        printf("\nLIST IS EMPTY...\n");
        return -1;
    } else{
        return list->begin->num;
    }
}

int last_node(Head *list){
    if(empty_list(list)){
        printf("\nLIST IS EMPTY...\n");
        return -1;
    } else{
        return list->end->num;
    }
}

int get_node(Head *list, int index){
    Node *current = list->begin;
    int cont = 0;
    if(index < 0 || index > size_list(list) || empty_list(list)){
        printf("\nIndex not found or empty list...\n");
        return -1;
    } else{
        while(cont != index){
            current = current->next;
            cont++;
        }
        return current->num;
    }
}

void reverse_list(Head *list){
    Node *current = list->begin;
    Node *previos = NULL;
    Node *next = NULL;

    if(list->begin == NULL){
        printf("\nLIST IS EMPTY...\n");
    }else{
        previos = current;
        current = current->next;
        list->end = previos;
        previos->next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = previos;
            previos = current;
            current = next;
        }
        list->begin = previos;
    }
}

void print_list(Head *list){
    Node *current = list->begin;

    if(empty_list(list)){
        printf("\n\nLista vazia...\n");
    }else{
        printf("\nLIST -> ");
        while(current != NULL){
            printf("[ %d ] ", current->num);
            current = current->next;
        }
        printf("\n");
    }
    printf("SIZE = %lu \n", size_list(list));
    if(list->end == NULL && list->begin == NULL){
        printf("list->begin == NULL\n\n");
        printf("list->end == NULL\n\n");
    }else{
        printf("list->begin == %d\n", first_node(list));
        printf("list->end == %d\n", last_node(list));
    }
}

void free_list(Head **list){
    Node *current = (*list)->begin;
    Node *eliminate = NULL;

    while(current != NULL){
        eliminate = current;
        current = current->next;
        free(eliminate);
    }
    free(*list);
    *list = NULL;
}

