#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

#define SIZE_NOME 20
#define PESO_PROVAS 0.35
#define PESO_ATV 0.30

typedef struct aluno{
    int ra;
    char nome[SIZE_NOME];
    float p1;
    float p2;
    float atv;
} aluno_t;

typedef struct aluno_stats{
    aluno_t aluno;
    float media;
    bool aprovado;
} aluno_stats_t;

typedef struct medidas {
    float media;
    float variancia;
    float desvio_padrao;
} medidas_t;

aluno_t get_aluno(){
    aluno_t aluno;
    scanf("%d", &aluno.ra);
    scanf("%s", aluno.nome);
    scanf("%f", &aluno.p1);
    scanf("%f", &aluno.p2);
    scanf("%f", &aluno.atv);

    return aluno;
}

aluno_stats_t calcula_medias(aluno_t aluno){
    aluno_stats_t resultados;
    resultados.aluno = aluno;
    resultados.media = (PESO_PROVAS*aluno.p1) + (PESO_PROVAS*aluno.p2) + (PESO_ATV*aluno.atv);
    resultados.aprovado = (resultados.media >= 5.0);

    return resultados;
}

void mostra_resultados(int n, aluno_stats_t res[n]){
    for (int i = 0; i < n; i++){
        printf("%d %s %.2f %s\n", res[i].aluno.ra, res[i].aluno.nome, res[i].media, res[i].aprovado ? "Aprovado" : "Reprovado");
    }
}

int conta_por_aprovacao(bool aprovado_flag, int n, aluno_stats_t res[n]){
    int cont = 0;
    for (int i = 0; i < n; i++){
        if(res[i].aprovado == aprovado_flag) cont ++;
    }
    return cont;
}

float variancia(int n, float media, float valores[n]){
    float quad_diff = 0.0;

    for (int i = 0; i < n; i++){
        quad_diff += pow((valores[i] - media), 2);    
    }
    return quad_diff/(n);
    
}

float media (int n, float valores[n]){
    float soma = 0.0;
    for (int i = 0; i < n; i++){
        soma += valores[i];
    }
    return soma/n;
    
}

medidas_t calcula_medidas(int n, aluno_stats_t alunos[n]){
    float medias_alunos[n];
    medidas_t stats_medidas;

    for (int i = 0; i < n; i++){
        medias_alunos[i] = alunos[i].media;
    }
    stats_medidas.media = media(n, medias_alunos);
    stats_medidas.variancia = variancia(n, stats_medidas.media, medias_alunos);
    stats_medidas.desvio_padrao = sqrt(stats_medidas.variancia);

    return stats_medidas;
}

int main(int argc, char const *argv[]){
    int numero_alunos;
    scanf("%d", &numero_alunos);
    aluno_t alunos[numero_alunos];
    aluno_stats_t alunos_stats[numero_alunos];
    medidas_t estatisticas;

    for (int i = 0; i < numero_alunos; i++){
        alunos[i] = get_aluno();
        alunos_stats[i] = calcula_medias(alunos[i]);
    }
    mostra_resultados(numero_alunos, alunos_stats);
    printf("Aprovados:%d\n", conta_por_aprovacao(true, numero_alunos, alunos_stats));
    printf("Reprovados:%d\n", conta_por_aprovacao(false, numero_alunos, alunos_stats));
    estatisticas = calcula_medidas(numero_alunos, alunos_stats);
    printf("Media:%.2f\n", estatisticas.media);
    printf("Variancia:%.2f\n", estatisticas.variancia);
    printf("Desvio padrao:%.2f\n", estatisticas.desvio_padrao);
    
    return 0;
}
