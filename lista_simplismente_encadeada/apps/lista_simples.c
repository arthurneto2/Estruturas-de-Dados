#include"linked_list.h"
#include<stdio.h>

int main(){
    Head *list = creat_head();

    for(int i = 0; i < 4; i++){
        addLast_node(list, i);
    }
    
    for(int i = 0; i < 4; i++){
        addFirst_node(list, i);
    }
    print_list(list);
    printf("List[5] == %d\n", get_node(list, 5));
    for(int i = 0; i < 4; i++){
        removeAll_node(list, i);
        print_list(list);
    }
    
    for(int i = 0; i < 5; i++){
        addLast_node(list, i);
    }
    
    addMid_node(list, 99, 3);
    print_list(list);

    reverse_list(list);
    print_list(list);

    free_list(&list);
    return 0;
}