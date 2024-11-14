#include"doubly_list.h"
#include<stdio.h>

int main(){
    Head *list = creat_Head();
    

    for(int i = 0; i < 3; i++){
        addFirst(list, i);
    }
    for(int i = 0; i < 3; i++){
        addLast(list, i);
    }

    print_list(list);
    
    for(int i = 0; i < 3; i++){
        remove_node(list, i);
    }

    print_list(list);
    invertPrint_list(list);

    for(int i = 0; i < 3; i++){
        remove_node(list, i);
        print_list(list);

    }


    free_list(&list);

    return 0;
}
