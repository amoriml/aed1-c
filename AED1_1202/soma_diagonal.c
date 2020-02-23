#include<stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    int matriz[n][n];

    //le matriz
    for(int linha = 0; linha < n; linha ++){
        for(int coluna = 0; coluna < n; coluna ++){
            int valor;
            scanf("%d", &valor);
            matriz[linha][coluna] = valor;
        }
    }

    //soma diagonal
    int soma = 0;
    for(int linha = 1; linha < n; linha ++){
        for(int coluna = 0; coluna < linha; coluna ++)
            soma += matriz[linha][coluna];
    }
    printf("%d", soma);

    return 0;
}
