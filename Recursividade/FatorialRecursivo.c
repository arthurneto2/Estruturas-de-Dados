#include <stdio.h>

int fatorial(int x){
    if(x > 1){
        printf("%d x ", x);
        x = x * fatorial(x - 1);    
    }else{
        printf("%d ", x);
    }
    return x;
}

int main(){
    int n;
    int result;

    printf("\nDigite um valor para o fatorial: ");
    scanf("%d", &n);
    printf("%d! = ", n);
    result = fatorial(n);
    printf("= %d\n\n", result);
    return 0;
}