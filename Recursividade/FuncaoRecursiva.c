#include <stdio.h>

void imprimirDecrescente( int x){
    if(x == 0){
        printf("%d ", x);
    }else{
        printf("%d ", x);
        imprimirDecrescente(x - 1);
    }
}


void imprimirCrescente( int x){
    if(x == 0){
        printf("%d ", x);
    }else{
        imprimirCrescente(x - 1);
        printf("%d ", x);
    }
}

int main(){
    int n;
    printf("Digite um valor: ");
    scanf("%d", &n);
    imprimirDecrescente(n);
    puts("");
    imprimirCrescente(n);
    puts("");
    return 0;
}