#include <stdio.h>

#define NUM_ALUNOS 5

typedef struct {
    char nome[100];
    int numeroMatricula;
    char curso[100];
} Aluno;

int main() {
    Aluno alunos[NUM_ALUNOS];

    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("Digite o número de matrícula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].numeroMatricula);
        getchar();

        printf("Digite o curso do aluno %d: ", i + 1);
        fgets(alunos[i].curso, sizeof(alunos[i].curso), stdin);

        printf("\n");
    }

    printf("Dados dos alunos:\n");
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s", alunos[i].nome);
        printf("Número de Matrícula: %d\n", alunos[i].numeroMatricula);
        printf("Curso: %s", alunos[i].curso);
        printf("\n");
    }

    return 0;
}
