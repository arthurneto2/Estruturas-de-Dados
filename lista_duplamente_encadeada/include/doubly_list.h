#ifndef DOUBLY_LIST
#define DOUBLY_LIST

#include<stdbool.h>
#include<stddef.h>

typedef struct sNode Node;
typedef struct sHead Head;

Head* creat_Head();
Node* creat_Node(int val);
void free_list(Head **list);
bool empty_list(Head *list);
size_t size_list(Head *list);
int first_node(Head *list);
int last_node(Head *list);
void addFirst(Head *list, int val);
void addLast(Head *list, int val);
void remove_node(Head *list, int val);
void print_list(Head *list);
void invertPrint_list(Head *list);
#endif
