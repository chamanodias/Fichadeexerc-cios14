#include <stdio.h>

#define NUM_ALUNOS 5

typedef struct {
    int matricula;
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
} Aluno;

int main() {
    Aluno alunos[NUM_ALUNOS];

    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite a matrícula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        getchar();

        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("Digite a nota da primeira prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);

        printf("Digite a nota da segunda prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);

        printf("Digite a nota da terceira prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota3);

        getchar();
        printf("\n");
    }

    int indiceMaiorNota1 = 0;
    int indiceMaiorMedia = 0;
    int indiceMenorMedia = 0;
    float maiorMedia = (alunos[0].nota1 + alunos[0].nota2 + alunos[0].nota3) / 3;
    float menorMedia = maiorMedia;

    for (int i = 1; i < NUM_ALUNOS; i++) {
        float mediaAtual = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;

        if (alunos[i].nota1 > alunos[indiceMaiorNota1].nota1) {
            indiceMaiorNota1 = i;
        }

        if (mediaAtual > maiorMedia) {
            maiorMedia = mediaAtual;
            indiceMaiorMedia = i;
        }

        if (mediaAtual < menorMedia) {
            menorMedia = mediaAtual;
            indiceMenorMedia = i;
        }
    }

    printf("Aluno com a maior nota na primeira prova: %s", alunos[indiceMaiorNota1].nome);
    printf("Nota: %.2f\n\n", alunos[indiceMaiorNota1].nota1);

    printf("Aluno com a maior média geral: %s", alunos[indiceMaiorMedia].nome);
    printf("Média: %.2f\n\n", maiorMedia);

    printf("Aluno com a menor média geral: %s", alunos[indiceMenorMedia].nome);
    printf("Média: %.2f\n\n", menorMedia);

    for (int i = 0; i < NUM_ALUNOS; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        printf("Aluno: %s", alunos[i].nome);
        printf("Média: %.2f - ", media);
        if (media >= 6) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }

    return 0;
}
