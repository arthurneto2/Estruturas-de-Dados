#include"doubly_list.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct sNode{
    struct sNode *next;
    struct sNode *previos;
    int val;
}Node;

typedef struct sHead{
    Node *begin;
    Node *end;
    size_t size;
}Head;

Head* creat_Head(){
    Head *list = (Head*) calloc(1, sizeof(Head));
    return list;
}

Node* creat_Node(int val){
    Node* new_node = (Node*) calloc(1, sizeof(Node));
    new_node->val = val;
    return new_node;
}

void free_list(Head **list){
    if(!empty_list(*list)){
        Node *current = (*list)->begin;
        while (current->next != NULL){
            current = current->next;
            free(current->previos);
        }
        free(current);
    }
    free(*list);
    (*list) = NULL;
}

bool empty_list(Head *list){
    return list->size == 0;
}

size_t size_list(Head *list){
    return list->size;
}

int first_node(Head *list){
    if(empty_list(list)){
        printf("\nLIST IS EMPTY...\n");
        return -1;
    } else{
        return list->begin->val;
    }
}

int last_node(Head *list){
    if(empty_list(list)){
        printf("\nLIST IS EMPTY...\n");
        return -1;
    } else{
        return list->end->val;
    }
}

void addFirst(Head *list, int val){
    Node *new_node = creat_Node(val);
    
    if(empty_list(list)){
        list->end = new_node;        
    } else{
        new_node->next = list->begin;
        list->begin->previos = new_node;
    }
    list->begin = new_node;
    list->size++;
}

void addLast(Head *list, int val){
    Node *new_node = creat_Node(val);

    if(empty_list(list)){
        list->begin = new_node;        
    } else{
        list->end->next = new_node;
        new_node->previos = list->end;
    }
    list->end = new_node;
    list->size++;

}

void remove_node(Head *list, int val){
    Node *current = list->begin;

    if(!empty_list(list)){
        while(current != NULL && current->val != val){
            current = current->next;
        }
        if(current == NULL){
            printf("\nValor [ %d ] nao encontrado na lista...\n", val);
        }else{
            if(size_list(list) != 1){
                if(list->end == current){
                    list->end = current->previos;
                    list->end->next = NULL;
                }
                if(list->begin == current){
                    list->begin = current->next;
                    list->begin->previos = NULL;
                }else{
                    current->previos->next = current->next;
                    current->next->previos = current->previos;
                }
            }else{
                list->begin = NULL;
                list->end = NULL;
            }
            free(current);
            list->size--;
        }
    }
}


void print_list(Head *list){
    Node *current = list->begin;

    if(empty_list(list)){
        printf("\n\nLista vazia...\n");
    }else{
        printf("\nLIST -> ");
        while(current != NULL){
            printf("[ %d ] ", current->val);
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

void invertPrint_list(Head *list){
    Node *current = list->end;

    if(empty_list(list)){
        printf("\n\nLista vazia...\n");
    }else{
        printf("\nLIST -> ");
        while(current != NULL){
            printf("[ %d ] ", current->val);
            current = current->previos;
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



