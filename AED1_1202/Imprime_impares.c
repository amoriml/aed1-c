#include <stdio.h>


int main(){
    int n = 0, cont_impar = 0, i = 0;
    scanf("%d", &n);
    while(cont_impar < n){
        if(i % 2 != 0){
            printf("%d ", i);
            cont_impar ++;
        }
        i ++;
    }
    return 0;
}