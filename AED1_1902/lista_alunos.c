#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

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

int main(int argc, char const *argv[]){
    int numero_alunos;
    scanf("%d", &numero_alunos);
    aluno_t alunos[numero_alunos];
    aluno_stats_t alunos_stats[numero_alunos];

    for (int i = 0; i < numero_alunos; i++){
        alunos[i] = get_aluno();
        alunos_stats[i] = calcula_medias(alunos[i]);
    }
    mostra_resultados(numero_alunos, alunos_stats);
    printf("Aprovados:%d\n", conta_por_aprovacao(true, numero_alunos, alunos_stats));
    printf("Reprovados:%d", conta_por_aprovacao(false, numero_alunos, alunos_stats));
    
    return 0;
}
