#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ponto {
    float x;
    float y;
} Ponto;

bool esta_contido (float min, float max, float x){
    return (x > min && x < max);
}

bool retangulo_contem_ponto(Ponto inf_esq, Ponto sup_dir, Ponto ponto){
    if(esta_contido(inf_esq.x, sup_dir.x, ponto.x) && esta_contido(inf_esq.y, sup_dir.y, ponto.y)){
        return true;
    }
    return false;
}

int qtd_pontos_retangulo(int n, Ponto *pontos, Ponto r1, Ponto r2){
    int cont = 0;
    for (int i = 0; i < n; i++){
        if(retangulo_contem_ponto(r1, r2, pontos[i])){
            cont ++;
        }
    }
    return cont;
}

int main(int argc, char const *argv[]){
    Ponto r1, r2;
    int n;
    scanf("%d", &n);
    Ponto pontos[n];

    for (int i = 0; i < n; i++){
        scanf("%f %f", &pontos[i].x, &pontos[i].y);
    }
    
    scanf("%f %f", &r1.x, &r1.y);   
    scanf("%f %f", &r2.x, &r2.y);

    printf("%d", qtd_pontos_retangulo(n, pontos, r1, r2));
    return 0;
}
