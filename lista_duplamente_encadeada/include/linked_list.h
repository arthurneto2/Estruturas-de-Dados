#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdio.h>
#include<stdbool.h>
#include<stddef.h>

typedef struct sNode Node;
typedef struct sHead Head;

Head* creat_head();
Node* creat_node(int val);
bool empty_list(Head *list);
size_t size_list(Head *list);
void addLast_node(Head *list, int val);
void addFirst_node(Head*list, int val);
void addMid_node(Head *list, int val, int index);
void removeFirst_node(Head *list, int val);
void removeAll_node(Head *list, int val);
int first_node(Head *list);
int last_node(Head *list);
int get_node(Head *list, int index);
void reverse_list(Head *list);
void print_list(Head *list);
void free_list(Head **list);

#endif