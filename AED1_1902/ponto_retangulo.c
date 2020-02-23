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

int retangulo_contem_ponto(Ponto inf_esq, Ponto sup_dir, Ponto ponto){
    if(esta_contido(inf_esq.x, sup_dir.x, ponto.x) && esta_contido(inf_esq.y, sup_dir.y, ponto.y)){
        return 1;
    }
    return 0;

}

int main(int argc, char const *argv[])
{
    Ponto p, r1, r2;
    scanf("%f %f", &p.x, &p.y);
    scanf("%f %f", &r1.x, &r1.y);
    scanf("%f %f", &r2.x, &r2.y);

    printf("%d", retangulo_contem_ponto(r1, r2, p));
    return 0;
}
